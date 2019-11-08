#ifndef CPU_CORE_H
#define CPU_CORE_H

#include "create_map.h"
#include "opcodes.h"
#include <QFile>
#include <QByteArray>
#include <QThread>
#include <QMutex>

using namespace std;

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
    }

public:
    uint8_t get_u8(int offset) {
        mutex_flag.lock();
        uint8_t val = this->operator [](offset);
        mutex_flag.unlock();

        return val;
    }

    void set_u8(int offset, uint8_t val) {
        mutex_flag.lock();
        this->operator [](offset) = val;
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

    void set_u16(uint16_t addr, uint8_t hbit, uint8_t lbit) {
        mutex_flag.lock();
        this->operator []((int) addr) = lbit;
        this->operator []((int) addr+1) = hbit;
        mutex_flag.unlock();
    }

    QByteArray copy_video_memory() {
        return mid(0x2400, 0x3FFF);
    }

    void set_u16(uint16_t addr, uint16_t val) {
        mutex_flag.lock();
        uint8_t lbit = (uint8_t) (val & 0x00FF);
        uint8_t hbit = (uint8_t) ((val >> 8) & 0x00FF);

        this->operator []((int) addr) = lbit;
        this->operator []((int) addr+1) = hbit;
        mutex_flag.unlock();
    }

private:
    QByteArray      extended_memory;
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
    void set_p_flag(uint8_t val)    { p_flag = (val & 0x01) ? 1 : 0; }
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
    void increase_pc(uint16_t n) { program_counter += n;   }
    void set_pc_to(uint16_t cnt) { program_counter = cnt;  }

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

class cpu
{
public:
    cpu(cpu_memory&);

private:
    void init();
    uint8_t extract_interrupt_opcode();

public:
    void execute();
    QString single_step();
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
    void reset();
    QString step();

    QByteArray get_screen_buffer();
    void screen_interrupt();

private:
    cpu         *cpu_8080;
    cpu_memory  *memory;
    QFile       rom_image;
    bool        is_running;
public:
    void run() override;
};

#endif // CPU_CORE_H
