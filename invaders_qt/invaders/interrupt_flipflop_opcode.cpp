#include "interrupt_flipflop_opcode.h"
#include "cpu_core.h"

ei_opcode::ei_opcode()
    : opcodes(1, 4, 4, "EI")
{}

void ei_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.enable_interrupt(true);
    cpu_8080.core_p().increase_pc(instr_size());
}

di_opcode::di_opcode()
    : opcodes(1, 4, 4, "DI")
{}

void di_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.enable_interrupt(false);
    cpu_8080.core_p().increase_pc(instr_size());
}
