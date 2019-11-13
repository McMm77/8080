#include "rst_opcode.h"
#include "cpu_core.h"

rst_opcode::rst_opcode(QString ass_cmd)
    : opcodes(1, 11, 11, ass_cmd)
{}

rst0_opcode::rst0_opcode()
    : rst_opcode("RST0")
{}

void rst0_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(0*8);
}

rst1_opcode::rst1_opcode()
    : rst_opcode("RST1")
{}

void rst1_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.core_p().set_pc_to(0);
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(1*8);
}

rst2_opcode::rst2_opcode()
    : rst_opcode("RST2")
{}

void rst2_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(2*8);
}

rst3_opcode::rst3_opcode()
    : rst_opcode("RST3")
{}

void rst3_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(3*8);
}

rst4_opcode::rst4_opcode()
    : rst_opcode("RST4")
{}

void rst4_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(4*8);
}

rst5_opcode::rst5_opcode()
    : rst_opcode("RST5")
{}

void rst5_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(5*8);
}

rst6_opcode::rst6_opcode()
    : rst_opcode("RST6")
{}

void rst6_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(6*8);
}

rst7_opcode::rst7_opcode()
    : rst_opcode("RST7")
{}

void rst7_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(7*8);
}
