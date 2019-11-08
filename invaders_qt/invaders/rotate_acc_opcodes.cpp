#include "rotate_acc_opcodes.h".h"
#include "cpu_core.h"

rar_opcode::rar_opcode()
    : opcodes(1, 4, 4, "RAR")
{}

void rar_opcode::handle_opcode(cpu& cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t c_status_flag = cpu_8080.core_flag().get_c_flag();
    uint8_t lbit = ((reg_a & 0x01) !=0 );

    reg_a >>= 1;
    reg_a |= (c_status_flag << 7);
    cpu_8080.core_flag().set_c_flag(lbit);

    cpu_8080.core_p().increase_pc(instr_size());
}

rlc_opcode::rlc_opcode()
    : opcodes(1, 4, 4, "RLC")
{}

void rlc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t hbit = (reg_a & 0x80) != 0;

    reg_a <<= 1;
    reg_a |= hbit;

    cpu_8080.core_flag().set_c_flag(hbit);
    cpu_8080.core_p().set_reg_a(reg_a);

    cpu_8080.core_p().increase_pc(instr_size());
}

rrc_opcode::rrc_opcode()
    : opcodes(1, 4, 4, "RRC")
{}

void rrc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t lbit = ((reg_a & 0x01) != 0);

    reg_a <<= 1;
    reg_a |= (lbit << 7);

    cpu_8080.core_flag().set_c_flag(lbit);
}

ral_opcode::ral_opcode()
    : opcodes(1, 4, 4, "RAL")
{}

void ral_opcode::handle_opcode(cpu&)
{}
