#include "call_opcode.h"
#include "cpu_core.h"

call_opcode::call_opcode()
    : opcodes(3, 17, 17, "CALL")
{}

call_opcode::call_opcode(QString ass_cmd)
    : opcodes(3, 11, 17, ass_cmd)
{}

void call_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t req_addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.push_u16_on_the_stack(cpu_8080.core_p().get_pc()+3);
    cpu_8080.core_p().set_pc_to(req_addr);
}

cpe_opcode::cpe_opcode()
    : call_opcode("CPE")
{}

void cpe_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

cpo_opcode::cpo_opcode()
    : call_opcode("CPO")
{}

void cpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

cz_opcode::cz_opcode()
    : call_opcode("CZ")
{}

void cz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

cnz_opcode::cnz_opcode()
    : call_opcode("CNZ")
{}

void cnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

cnc_opcode::cnc_opcode()
    : call_opcode("CNC")
{}

void cnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

cc_opcode::cc_opcode()
    : call_opcode("CC")
{}

void cc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

cm_opcode::cm_opcode()
    : call_opcode("CM")
{}

void cm_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

cp_opcode::cp_opcode()
    : call_opcode("CP")
{}

void cp_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}
