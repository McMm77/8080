#ifndef CPU_CORE_H
#define CPU_CORE_H

#include <map>
#include "opcodes.h"
#include <QFile>
#include <QByteArray>
#include <QThread>

using namespace std;

class cpu_memory : public QByteArray
{
public:
    cpu_memory(QByteArray& arr)
        : QByteArray(arr)
    {}

public:
    uint8_t get_u8(int offset) {
        return this->operator [](offset);
    }

    void set_u8(int offset, uint8_t val) {
        this->operator [](offset) = val;
    }

    uint16_t get_u16(int offset) {
        return this->operator [](offset);
    }

    void set_u16(uint16_t addr, uint8_t hbit, uint8_t lbit) {
        this->operator []((int) addr) = lbit;
        this->operator []((int) addr+1) = hbit;
    }

    void set_u16(uint16_t addr, uint16_t val) {
        uint8_t lbit = (uint8_t) (val & 0x00FF);
        uint8_t hbit = (uint8_t) ((val >> 8) & 0x00FF);

        this->operator []((int) addr) = lbit;
        this->operator []((int) addr+1) = hbit;
    }
};

class cpu_core_status_flags
{
public:
    cpu_core_status_flags()
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

    void set_psw(uint8_t psw) {}
    uint8_t get_psw() { return 0; }


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

public:
    void execute();

public:
    void interrupt(int);

    void push_u16_on_the_stack(uint16_t);
    uint16_t pop_u16_from_the_stack();

    void push_on_the_stack(uint8_t);
    uint8_t pop_from_the_stack();

    void enable_interrupt(bool en) {
        interrupt_enable = en;
    }

    void cpu_running(bool en) {
        is_running = en;
    }

private:
    cpu_memory& memory;

    cpu_core                core;
    cpu_core_status_flags   flags;
    bool                    interrupt_enable;
    bool                    is_running;

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
    void screen_interrupt();

private:
    cpu         *cpu_8080;
    cpu_memory  *memory;
    QFile       rom_image;
public:
    void run() override;
};

#endif // CPU_CORE_H
