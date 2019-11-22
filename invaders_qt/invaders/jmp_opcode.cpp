#include "jmp_opcode.h"
#include "cpu_core.h"

pchl_opcode::pchl_opcode()
    : opcodes(1, 4, 4, "PCHL")
{}

void pchl_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_h = cpu_8080.core_p().get_reg_h();
    uint8_t reg_l = cpu_8080.core_p().get_reg_l();
    uint16_t counter = (reg_h << 8) | reg_l;

    cpu_8080.core_p().set_pc_to(counter);
}

jmp_opcode::jmp_opcode()
    : opcodes(3, 10, 10, "JMP")
{}

jmp_opcode::jmp_opcode(QString ass_cmd)
    : opcodes(3, 10, 10, ass_cmd)
{}

void jmp_opcode::handle_opcode(cpu& cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_pc_to(addr);
}

jpo_opcode::jpo_opcode()
    : jmp_opcode("JPO")
{}

void jpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

jpe_opcode::jpe_opcode()
    : jmp_opcode("JPE")
{}

void jpe_opcode::handle_opcode(cpu& cpu_8080)
{
    if(cpu_8080.core_flag().get_p_flag() == 1) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

jc_opcode::jc_opcode()
    : jmp_opcode("JC")
{}

void jc_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_c_flag() == 1) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

jnc_opcode::jnc_opcode()
    : jmp_opcode("JNC")
{}

void jnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_c_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

jz_opcode::jz_opcode()
    : jmp_opcode("JZ")
{}

void jz_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_z_flag() == 1) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

jnz_opcode::jnz_opcode()
    : jmp_opcode("JNZ")
{}

void jnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_z_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

jm_opcode::jm_opcode()
    : jmp_opcode("JM")
{}

void jm_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_s_flag() == 1) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

jp_opcode::jp_opcode()
    : jmp_opcode("JP")
{}

void jp_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_s_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}
