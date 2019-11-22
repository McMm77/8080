#ifndef CPU_CORE_H
#define CPU_CORE_H

#include "create_map.h"
#include "opcodes.h"
#include <QFile>
#include <QByteArray>
#include <QThread>
#include <QMutex>

using namespace std;
/*
class cpu_memory : public QByteArray
{
private:
    QMutex  mutex_flag;

public:

    cpu_memory(QByteArray& arr)
        : QByteArray(100, 1)
    {
        this->append(arr);
    }

public:
    uint8_t get_u8(int offset) {

        mutex_flag.lock();
        uint8_t val = this->operator [](offset);
        mutex_flag.unlock();

        return val;
    }

    void set_u8(int addr, uint8_t val) {

        mutex_flag.lock();
        this->operator [](addr) = val;
        mutex_flag.unlock();
    }

    uint16_t get_u16(int offset) {

        mutex_flag.lock();
        uint8_t lbit = this->operator[](offset);
        uint8_t hbit = this->operator[](offset+1);
        uint16_t val = ((hbit << 8) | lbit);
        mutex_flag.unlock();

        return val;
    }

private:
    int arr_size;
};
*/

class cpu_memory : public QByteArray
{
private:
    QMutex  mutex_flag;

public:

    cpu_memory(QByteArray& arr)
        : QByteArray(arr),
          extended_memory((8 * 1024), 0x00)
    {
        this->append(extended_memory);
        this->operator [](0x20c1) = 1;
//        this->operator [](0x20EB) = 12;
        this->arr_size = this->size();
    }

public:
    uint8_t get_u8(int offset) {

        mutex_flag.lock();
        uint8_t val = this->operator [](offset);
        mutex_flag.unlock();

        return val;
    }

    void set_u8(int addr, uint8_t val) {

        if (addr >= 0x2300 && addr <= 0x23BB)
            throw "Exception Memory";

        mutex_flag.lock();
        this->operator [](addr) = val;
        mutex_flag.unlock();
    }

    uint16_t get_u16(int offset) {

        mutex_flag.lock();
        uint8_t lbit = this->operator[](offset);
        uint8_t hbit = this->operator[](offset+1);
        uint16_t val = ((hbit << 8) | lbit);
        mutex_flag.unlock();

        return val;
    }

    QByteArray copy_video_memory() {
        return mid(0x2400, 0x3FFF);
    }

private:
    QByteArray      extended_memory;
    int arr_size;
};


class cpu_core_status_flags
{
public:
    cpu_core_status_flags()
        : z_flag(0),
          s_flag(0),
          p_flag(0),
          c_flag(0),
          ac_flag(0)
    {}

public:
    int get_z_flag()  { return z_flag;  }
    int get_s_flag()  { return s_flag;  }
    int get_p_flag()  { return p_flag;  }
    int get_c_flag()  { return c_flag;  }
    int get_ac_flag() { return ac_flag; }

public:
    void set_z_flag(uint8_t val)    { z_flag = (val == 0) ? 1 : 0;   }
    void set_s_flag(uint8_t val)    { s_flag = (val & 0x80) ? 1 : 0; }
    void set_p_flag(uint8_t val)    {
        uint8_t cnt = 0;
        for(int i = 0 ; i < 8 ; i++) {
            uint8_t bit = ((val >> i) & 0x01);
            cnt += ((bit == 1) ? 1 : 0);
        }

        p_flag = (cnt & 0x01) ? 0 : 1;
    }
    void set_c_flag(uint8_t val)    { c_flag = (val != 0) ? 1 : 0;   }
    void set_ac_flag(uint8_t val)   { ac_flag = (val != 0) ? 1 : 0;  }
    void set_c_flag(uint8_t reg, uint8_t val) {
        uint16_t res = reg + val;
        c_flag = (res & 0x0100) ? 1 : 0;
    }
    void set_ac_flag(uint8_t reg, uint8_t val) {
        uint8_t res = (reg & 0x0F) + (val & 0x0F);
        ac_flag = (res & 0x10) ? 1 : 0;
    }

    void set_psw(uint8_t psw) {
        c_flag = ((psw & 0x01) != 0);
        p_flag = ((psw & 0x04) != 0);
        ac_flag = ((psw & 0x10) != 0);
        z_flag = ((psw & 0x40) != 0);
        s_flag = ((psw & 0x80) != 0);
    }

    uint8_t get_psw() {
        uint8_t psw = 0x00;

        psw |= c_flag << 0;
        psw |= p_flag << 2;
        psw |= ac_flag << 4;
        psw |= z_flag << 6;
        psw |= s_flag << 7;

        return psw;
    }


private:
    int z_flag;
    int s_flag;
    int p_flag;
    int c_flag;
    int ac_flag;
};

class cpu_core
{
public:
    cpu_core()
        : reg_b(0),
        reg_c(0),
        reg_d(0),
        reg_e(0),
        reg_h(0),
        reg_l(0),
        accumulator(0),
        stack_pointer(0),
        program_counter(0)
    {}

public:
    /* program counter */
    uint16_t get_pc() const      { return program_counter; }
    void increase_pc(uint16_t n) {
        uint16_t temp_pc = program_counter;
        program_counter += n;
        if (program_counter >= 0x1A8E)
            temp_pc = 12;
    }

    void set_pc_to(uint16_t cnt)
    {
        uint16_t temp_pc = program_counter;
        if( cnt > 0x1A8E ) {
            program_counter++;
        }

        program_counter = cnt;
    }

    /* stack_pointer */
    void set_sp(uint16_t cnt)    { stack_pointer = cnt;    }
    uint16_t get_sp() const      { return stack_pointer;   }

    /* registers */
    void set_reg_a(uint8_t val)  { accumulator = val;  }
    void set_reg_b(uint8_t val)  { reg_b  = val; }
    void set_reg_c(uint8_t val)  { reg_c = val; }
    void set_reg_d(uint8_t val)  { reg_d = val; }
    void set_reg_e(uint8_t val)  { reg_e = val; }
    void set_reg_h(uint8_t val)  { reg_h = val; }
    void set_reg_l(uint8_t val)  { reg_l = val; }

    uint8_t get_reg_a() const { return accumulator; }
    uint8_t get_reg_b() const { return reg_b; }
    uint8_t get_reg_c() const { return reg_c; }
    uint8_t get_reg_d() const { return reg_d; }
    uint8_t get_reg_e() const { return reg_e; }
    uint8_t get_reg_h() const { return reg_h; }
    uint8_t get_reg_l() const { return reg_l; }

private:
    uint8_t accumulator;
    uint8_t reg_b;
    uint8_t reg_c;
    uint8_t reg_d;
    uint8_t reg_e;
    uint8_t reg_h;
    uint8_t reg_l;
    uint16_t program_counter;
    uint16_t stack_pointer;
};

class cpu_debug {

    public:
        QString curr_opcode_cmd;
        QString post_opcode_cmd;
        cpu_core curr_core;
        cpu_core post_core;
        cpu_core_status_flags curr_core_flags;
        cpu_core_status_flags post_core_flags;
};

class invaders;

class cpu
{
public:
    cpu(cpu_memory&, invaders&);

private:
    void init(invaders&);
    uint8_t extract_interrupt_opcode();
    QString log(cpu_debug&);

public:
    void execute(QFile&, QFile&);
    void single_step(cpu_debug&);
    void interrupt(unsigned long);

    void push_u16_on_the_stack(uint16_t);
    void push_on_the_stack(uint8_t);
    uint16_t pop_u16_from_the_stack();
    uint8_t pop_from_the_stack();
    void enable_interrupt(bool en);
    void cpu_running(bool en);


private:
    cpu_memory&             memory;

    cpu_core                core;
    cpu_core_status_flags   flags;
    bool                    interrupt_enable;
    bool                    is_running;
    bool                    is_interrupted;
    unsigned long           interrupt_command;


    map<uint8_t, opcodes*>  opcode_table;

public:
    cpu_core& core_p()                      { return core;   }
    cpu_core_status_flags& core_flag()      { return flags;  }
    cpu_memory& rom()                       { return memory; }
};

class invaders : public QThread
{
public:
    invaders();

public:
    uint8_t input_0_handler();
    uint8_t input_1_handler();
    uint8_t input_2_handler();
    uint8_t input_3_handler();

public:
    void coin_inserted(uint8_t);
    void start_p1_pressed();
    void start_p1_released();
    void start_p2_pressed();

public:
    void left_p1_pressed();
    void left_p1_released();
    void right_p1_pressed();
    void right_p1_released();
    void fire_p1_pressed();
    void fire_p1_released();

    void left_p2_pressed();
    void left_p2_released();
    void right_p2_pressed();
    void right_p2_released();
    void fire_p2_pressed();
    void fire_p2_released();

public:
    void reset();
    void step(cpu_debug&, int nSteps);
    void step_to(cpu_debug &debug_info, uint16_t pc_counter);
    void start_pressed();

    QByteArray get_screen_buffer();
    uint8_t get_pixel(int);
    void screen_interrupt();
    void rst_interrupt(int);
private:
    cpu         *cpu_8080;
    cpu_memory  *memory;
    QFile       rom_image;
    bool        is_running;
public:
    void run() override;

private:
    int coin;
    int start_b;
    uint8_t start_p2;

    uint8_t left_1;
    uint8_t left_2;
    uint8_t right_1;
    uint8_t right_2;
    uint8_t fire_1;
    uint8_t fire_2;
};

#endif // CPU_CORE_H
