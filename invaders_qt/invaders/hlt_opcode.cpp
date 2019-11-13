#include "hlt_opcode.h"
#include "cpu_core.h"

hlt_opcode::hlt_opcode()
 : opcodes(1, 7, 7, "HLT")
{}

void hlt_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.cpu_running(false);
}
