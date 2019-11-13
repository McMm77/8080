#include "ret_opcode.h"
#include "cpu_core.h"

ret_opcode::ret_opcode()
    : opcodes(1, 4, 4, "RET")
{}

ret_opcode::ret_opcode(QString ass_cmd)
    :  opcodes(1, 5, 11, ass_cmd)
{}

void ret_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t pc_counter = cpu_8080.pop_u16_from_the_stack();
    cpu_8080.core_p().set_pc_to(pc_counter);
}

rnz_opcode::rnz_opcode()
    : ret_opcode("RNZ")
{}

void rnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

rz_opcode::rz_opcode()
    : ret_opcode("RZ")
{}

void rz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

rnc_opcode::rnc_opcode()
    : ret_opcode("RNC")
{}

void rnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

rc_opcode::rc_opcode()
    : ret_opcode("RC")
{}

void rc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

rpo_opcode::rpo_opcode()
    : ret_opcode("RPO")
{}

void rpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

rpe_opcode::rpe_opcode()
    : ret_opcode("RPE")
{}

void rpe_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

rp_opcode::rp_opcode()
    : ret_opcode("RP")
{}

void rp_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

rm_opcode::rm_opcode()
    : ret_opcode("RM")
{}

void rm_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}
