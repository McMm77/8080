#include "carry_bit_opcode.h"
#include "cpu_core.h"


cmc_opcode::cmc_opcode()
    : opcodes(1, 4, 4, "CMC")
{}

void cmc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t c_bit = (cpu_8080.core_flag().get_c_flag() == 0) ? 1 : 0;

    cpu_8080.core_flag().set_c_flag(c_bit);

    cpu_8080.core_p().increase_pc(instr_size());
}

stc_opcode::stc_opcode()
    : opcodes(1, 4, 4, "STC")
{}

void stc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_flag().set_c_flag(1);

    cpu_8080.core_p().increase_pc(instr_size());
}
