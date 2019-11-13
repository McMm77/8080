#include "direct_addr_opcode.h"
#include "cpu_core.h"

sta_opcode::sta_opcode()
    : opcodes(3, 13, 13, "STA")
{}

void sta_opcode::handle_opcode(cpu& cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_a(cpu_8080.rom()[addr]);
    cpu_8080.core_p().increase_pc(instr_size());
}

lda_opcode::lda_opcode()
    : opcodes(3, 13, 13, "LDA")
{}

void lda_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc()+1);

    cpu_8080.core_p().set_reg_a(cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

shld_opcode::shld_opcode()
    : opcodes(3, 16, 16, "SHLD")
{}

void shld_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc()+1);

    cpu_8080.core_p().set_reg_l(addr);
    cpu_8080.core_p().set_reg_h(addr+1);

    cpu_8080.core_p().increase_pc(instr_size());
}

lhld_opcode::lhld_opcode()
    : opcodes(3, 16, 16, "LHLD")
{}

void lhld_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc()+1);

    cpu_8080.core_p().set_reg_l(cpu_8080.rom().get_u8(addr));
    cpu_8080.core_p().set_reg_l(cpu_8080.rom().get_u8(addr+1));

    cpu_8080.core_p().increase_pc(instr_size());
}

