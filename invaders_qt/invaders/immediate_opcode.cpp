#include "immediate_opcode.h"
#include "cpu_core.h"

mvi_opcode::mvi_opcode(QString ass_cmd, int cpu_cycle=7)
    : opcodes(2, cpu_cycle, cpu_cycle, ass_cmd)
{}

mvi_b_opcode::mvi_b_opcode()
    : mvi_opcode("MVI B")
{}

void mvi_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_b(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

mvi_d_opcode::mvi_d_opcode()
    : mvi_opcode("MVI D")
{}

void mvi_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_d(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

mvi_h_opcode::mvi_h_opcode()
    : mvi_opcode("MVI H")
{}

void mvi_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_h(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

mvi_m_opcode::mvi_m_opcode()
    : mvi_opcode("MVI M", 10)
{}

void mvi_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    uint8_t hreg = cpu_8080.core_p().get_reg_h();
    uint8_t lreg = cpu_8080.core_p().get_reg_l();
    uint16_t addr = (hreg << 8) | lreg;

    cpu_8080.rom().set_u8(addr, data);

    cpu_8080.core_p().increase_pc(instr_size());
}

mvi_c_opcode::mvi_c_opcode()
    : mvi_opcode("MVI C")
{}

void mvi_c_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_c(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

mvi_e_opcode::mvi_e_opcode()
    : mvi_opcode("MVI E")
{}

void mvi_e_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_e(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

mvi_l_opcode::mvi_l_opcode()
    : mvi_opcode("MVI L")
{}

void mvi_l_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_l(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

mvi_a_opcode::mvi_a_opcode()
    : mvi_opcode("MVI A")
{}

void mvi_a_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_a(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

lxi_opcode::lxi_opcode(QString ass_cmd)
    : opcodes(3, 10, 10, ass_cmd)
{}

lxi_b_opcode::lxi_b_opcode()
    : lxi_opcode("LXI B")
{}

void lxi_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1));
    cpu_8080.core_p().set_reg_b(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+2));
    cpu_8080.core_p().increase_pc(instr_size());
}

lxi_d_opcode::lxi_d_opcode()
    : lxi_opcode("LXI D")
{}

void lxi_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1));
    cpu_8080.core_p().set_reg_d(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+2));
    cpu_8080.core_p().increase_pc(instr_size());
}

lxi_h_opcode::lxi_h_opcode()
    : lxi_opcode("LXI H")
{}

void lxi_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1));
    cpu_8080.core_p().set_reg_h(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+2));
    cpu_8080.core_p().increase_pc(instr_size());
}

lxi_sp_opcode::lxi_sp_opcode()
    : lxi_opcode("LXI SP")
{}

void lxi_sp_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_sp(cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc()+1));
    cpu_8080.core_p().increase_pc(instr_size());
}

adi_opcode::adi_opcode()
    : opcodes(2, 7, 7, "ADI")
{}

void adi_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    add(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());

}

aci_opcode::aci_opcode()
    : opcodes(2, 7, 7, "CPI")
{}

void aci_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    adc(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());

}

sui_opcode::sui_opcode()
    : opcodes(2, 7, 7, "SUI")
{}

void sui_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    sub(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

sbi_opcode::sbi_opcode()
    : opcodes(2, 7, 7, "SBI")
{}

void sbi_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    sbb(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

ani_opcode::ani_opcode()
    : opcodes(2, 7, 7, "ANI")
{}

void ani_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    ana(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

xri_opcode::xri_opcode()
    : opcodes(2, 7, 7, "XRI")
{}

void xri_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    xra(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

ori_opcode::ori_opcode()
    : opcodes(2, 7, 7, "ORI")
{}

void ori_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    ora(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

cpi_opcode::cpi_opcode()
    : opcodes(2, 7, 7, "CPI")
{}

void cpi_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    cmp(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

