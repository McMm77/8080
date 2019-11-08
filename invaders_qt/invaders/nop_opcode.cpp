#include "opcodes.h"
#include "cpu_core.h"

nop_opcode::nop_opcode()
    : opcodes(1, 4, 4, "NOP")
{}

void nop_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().increase_pc(instr_size());
}
