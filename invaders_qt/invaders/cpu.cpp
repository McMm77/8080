#include "cpu_core.h"

cpu::cpu(cpu_memory& rom)
    : memory(rom),
      interrupt_enable(false),
      is_running(false)
{}

void cpu::interrupt(int flag) {

}

void cpu::execute()
{
    while(core.get_pc() < memory.size())
    {
        uint8_t opcode = memory[core.get_pc()];
        opcode_table[opcode]->handle_opcode(*this);
    }
}

void cpu::push_u16_on_the_stack(uint16_t)
{
}

uint16_t cpu::pop_u16_from_the_stack()
{
    return 0;
}

void cpu::push_on_the_stack(uint8_t)
{

}
uint8_t cpu::pop_from_the_stack()
{
    return 0;
}
