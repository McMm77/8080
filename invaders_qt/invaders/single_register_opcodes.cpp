#include "opcodes.h"
#include "cpu_core.h"

inr_opcode::inr_opcode(QString ass_cmd)
    : opcodes(2, 4, 4, ass_cmd)
{}

void inr_opcode::inr(cpu &cpu_8080, uint8_t& val)
{
    val++;

    cpu_8080.core_flag().set_p_flag(val);
    cpu_8080.core_flag().set_z_flag(val);
    cpu_8080.core_flag().set_s_flag(val);
}

inr_b_opcode::inr_b_opcode()
    : inr_opcode("INR B")
{}

void inr_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_b = cpu_8080.core_p().get_reg_b();
    inr(cpu_8080, reg_b);
    cpu_8080.core_p().set_reg_b(reg_b);

    cpu_8080.core_p().increase_pc(instr_size());
}

inr_c_opcode::inr_c_opcode()
    : inr_opcode("INR C")
{}

void inr_c_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_c = cpu_8080.core_p().get_reg_c();
    inr(cpu_8080, reg_c);
    cpu_8080.core_p().set_reg_c(reg_c);

    cpu_8080.core_p().increase_pc(instr_size());
}

inr_d_opcode::inr_d_opcode()
    : inr_opcode("INR D")
{}

void inr_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_d = cpu_8080.core_p().get_reg_d();
    inr(cpu_8080, reg_d);
    cpu_8080.core_p().set_reg_d(reg_d);

    cpu_8080.core_p().increase_pc(instr_size());
}

inr_e_opcode::inr_e_opcode()
    : inr_opcode("INR E")
{}

void inr_e_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_e = cpu_8080.core_p().get_reg_e();
    inr(cpu_8080, reg_e);
    cpu_8080.core_p().set_reg_e(reg_e);

    cpu_8080.core_p().increase_pc(instr_size());
}

inr_h_opcode::inr_h_opcode()
    : inr_opcode("INR H")
{}

void inr_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_h = cpu_8080.core_p().get_reg_h();
    inr(cpu_8080, reg_h);
    cpu_8080.core_p().set_reg_h(reg_h);

    cpu_8080.core_p().increase_pc(instr_size());
}

inr_l_opcode::inr_l_opcode()
    : inr_opcode("INR L")
{}

void inr_l_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_l = cpu_8080.core_p().get_reg_l();
    inr(cpu_8080, reg_l);
    cpu_8080.core_p().set_reg_l(reg_l);

    cpu_8080.core_p().increase_pc(instr_size());
}

inr_m_opcode::inr_m_opcode()
    : inr_opcode("INR M")
{}

void inr_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    inr(cpu_8080, val);

    cpu_8080.rom().set_u8(addr, val);

    cpu_8080.core_p().increase_pc(instr_size());
}

inr_a_opcode::inr_a_opcode()
    : inr_opcode("INR A")
{}

void inr_a_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    inr(cpu_8080, reg_a);
    cpu_8080.core_p().set_reg_h(reg_a);

    cpu_8080.core_p().increase_pc(instr_size());
}

// ---------------------------------------------------
// DCR Opcodes
dcr_opcode::dcr_opcode(QString ass_cmd)
    : opcodes(2, 4, 4, ass_cmd)
{}

void dcr_opcode::dcr(cpu &cpu_8080, uint8_t& val)
{
    val--;

    cpu_8080.core_flag().set_p_flag(val);
    cpu_8080.core_flag().set_z_flag(val);
    cpu_8080.core_flag().set_s_flag(val);
}

dcr_b_opcode::dcr_b_opcode()
    : dcr_opcode("DCR B")
{}

void dcr_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_b();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_b(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcr_c_opcode::dcr_c_opcode()
    : dcr_opcode("DCR C")
{}

void dcr_c_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_c();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_c(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcr_d_opcode::dcr_d_opcode()
    : dcr_opcode("DCR D")
{}

void dcr_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_d();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_d(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcr_e_opcode::dcr_e_opcode()
    : dcr_opcode("DCR E")
{}

void dcr_e_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_e();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_e(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcr_h_opcode::dcr_h_opcode()
    : dcr_opcode("DCR H")
{}

void dcr_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_h();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_h(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcr_l_opcode::dcr_l_opcode()
    : dcr_opcode("DCR L")
{}

void dcr_l_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_l();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_l(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcr_m_opcode::dcr_m_opcode()
    : dcr_opcode("DCR M")
{}

void dcr_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    dcr(cpu_8080, val);

    cpu_8080.rom().set_u8(addr, val);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcr_a_opcode::dcr_a_opcode()
    : dcr_opcode("DCR A")
{}

void dcr_a_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_a();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_a(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}
