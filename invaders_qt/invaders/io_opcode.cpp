#include "io_opcode.h"
#include "cpu_core.h"

out_opcode::out_opcode()
    : opcodes(2, 10, 10, "OUT")
{}

void out_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().increase_pc(instr_size());
}

in_opcode::in_opcode()
    : opcodes(2, 10, 10, "IN")
{}

void in_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().increase_pc(instr_size());
}
