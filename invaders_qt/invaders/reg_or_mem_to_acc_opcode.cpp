#include "reg_or_mem_to_acc_opcode.h"
#include "cpu_core.h"

// ============================================================
// ===================== ADD ==================================
add_opcode::add_opcode(QString ass_cmd, int cpu_cycle = 4)
    : opcodes(1, cpu_cycle, cpu_cycle, ass_cmd)
{}

add_b_opcode::add_b_opcode()
    : add_opcode("ADD B")
{}

void add_b_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

add_c_opcode::add_c_opcode()
    : add_opcode("ADD C")
{}

void add_c_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

add_d_opcode::add_d_opcode()
    : add_opcode("ADD D")
{}

void add_d_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

add_e_opcode::add_e_opcode()
    : add_opcode("ADD E")
{}

void add_e_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

add_h_opcode::add_h_opcode()
    : add_opcode("ADD H")
{}

void add_h_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

add_l_opcode::add_l_opcode()
    : add_opcode("ADD L")
{}

void add_l_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

add_m_opcode::add_m_opcode()
    : add_opcode("ADD M", 7)
{}

void add_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    add(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

add_a_opcode::add_a_opcode()
    : add_opcode("ADD A")
{}

void add_a_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

// ============================================================
// ===================== ADC ==================================
adc_opcode::adc_opcode(QString ass_cmd, int cpu_cycle = 4)
    : opcodes(1, cpu_cycle, cpu_cycle, ass_cmd)
{}

adc_b_opcode::adc_b_opcode()
    : adc_opcode("ADC B")
{}

void adc_b_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

adc_c_opcode::adc_c_opcode()
    : adc_opcode("ADC C")
{}

void adc_c_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

adc_d_opcode::adc_d_opcode()
    : adc_opcode("ADC D")
{}

void adc_d_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

adc_e_opcode::adc_e_opcode()
    : adc_opcode("ADC E")
{}

void adc_e_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

adc_h_opcode::adc_h_opcode()
    : adc_opcode("ADC H")
{}

void adc_h_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

adc_l_opcode::adc_l_opcode()
    : adc_opcode("ADC L")
{}

void adc_l_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

adc_m_opcode::adc_m_opcode()
    : adc_opcode("ADC M", 7)
{}

void adc_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    adc(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

adc_a_opcode::adc_a_opcode()
    : adc_opcode("ADC A")
{}

void adc_a_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

// ============================================================
// ===================== SUB ==================================
sub_opcode::sub_opcode(QString acc_cmd, int cpu_cycles = 4)
    : opcodes(1, cpu_cycles, cpu_cycles, acc_cmd)
{}

sub_b_opcode::sub_b_opcode()
    : sub_opcode("SUB B")
{}

void sub_b_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

sub_c_opcode::sub_c_opcode()
    : sub_opcode("SUB C")
{}

void sub_c_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

sub_d_opcode::sub_d_opcode()
    : sub_opcode("SUB D")
{}

void sub_d_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

sub_e_opcode::sub_e_opcode()
    : sub_opcode("SUB E")
{}

void sub_e_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

sub_h_opcode::sub_h_opcode()
    : sub_opcode("SUB H")
{}

void sub_h_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

sub_l_opcode::sub_l_opcode()
    : sub_opcode("SUB L")
{}

void sub_l_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

sub_m_opcode::sub_m_opcode()
    : sub_opcode("SUB M", 7)
{}

void sub_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    sub(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

sub_a_opcode::sub_a_opcode()
    : sub_opcode("SUB A")
{}

void sub_a_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

// ============================================================
// ===================== SBB ==================================
sbb_opcode::sbb_opcode(QString ass_cmd, int cpu_cycles=4)
    : opcodes(1, cpu_cycles, cpu_cycles, ass_cmd)
{}

sbb_b_opcode::sbb_b_opcode()
    : sbb_opcode("SBB B")
{}

void sbb_b_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

sbb_c_opcode::sbb_c_opcode()
    : sbb_opcode("SBB C")
{}

void sbb_c_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

sbb_d_opcode::sbb_d_opcode()
    : sbb_opcode("SBB D")
{}

void sbb_d_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

sbb_e_opcode::sbb_e_opcode()
    : sbb_opcode("SBB E")
{}

void sbb_e_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

sbb_h_opcode::sbb_h_opcode()
    : sbb_opcode("SBB H")
{}

void sbb_h_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

sbb_l_opcode::sbb_l_opcode()
    : sbb_opcode("SBB L")
{}

void sbb_l_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

sbb_m_opcode::sbb_m_opcode()
    : sbb_opcode("SBB M", 7)
{}

void sbb_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    sbb(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

sbb_a_opcode::sbb_a_opcode()
    : sbb_opcode("SBB A")
{}

void sbb_a_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

// ============================================================
// ===================== ANA ==================================
ana_opcode::ana_opcode(QString ass_cmd, int cpu_cycles=4)
    : opcodes(1, cpu_cycles, cpu_cycles, ass_cmd)
{}

ana_b_opcode::ana_b_opcode()
    : ana_opcode("ANA B")
{}

void ana_b_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

ana_c_opcode::ana_c_opcode()
    : ana_opcode("ANA C")
{}

void ana_c_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

ana_d_opcode::ana_d_opcode()
    : ana_opcode("ANA D")
{}

void ana_d_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

ana_e_opcode::ana_e_opcode()
    : ana_opcode("ANA E")
{}

void ana_e_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

ana_h_opcode::ana_h_opcode()
    : ana_opcode("ANA H")
{}

void ana_h_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

ana_l_opcode::ana_l_opcode()
    : ana_opcode("ANA L")
{}

void ana_l_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

ana_m_opcode::ana_m_opcode()
    : ana_opcode("ANA M", 7)
{}

void ana_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    ana(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

ana_a_opcode::ana_a_opcode()
    : ana_opcode("ANA A")
{}

void ana_a_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

// ============================================================
// ===================== XRA ==================================
xra_opcode::xra_opcode(QString ass_cmd, int cpu_cycles=4)
    : opcodes(1, cpu_cycles, cpu_cycles, ass_cmd)
{}

xra_b_opcode::xra_b_opcode()
    : xra_opcode("XRA B")
{}

void xra_b_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

xra_c_opcode::xra_c_opcode()
    : xra_opcode("XRA C")
{}

void xra_c_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

xra_d_opcode::xra_d_opcode()
    : xra_opcode("XRA D")
{}

void xra_d_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

xra_e_opcode::xra_e_opcode()
    : xra_opcode("XRA E")
{}

void xra_e_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

xra_h_opcode::xra_h_opcode()
    : xra_opcode("XRA H")
{}

void xra_h_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

xra_l_opcode::xra_l_opcode()
    : xra_opcode("XRA L")
{}

void xra_l_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

xra_m_opcode::xra_m_opcode()
    : xra_opcode("XRA M", 7)
{}

void xra_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    xra(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

xra_a_opcode::xra_a_opcode()
    : xra_opcode("XRA A")
{}

void xra_a_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

// ============================================================
// ===================== ORA ==================================
ora_opcode::ora_opcode(QString ass_cmd, int cpu_cycles=4)
    : opcodes(1, cpu_cycles, cpu_cycles, ass_cmd)
{}

ora_b_opcode::ora_b_opcode()
    : ora_opcode("ORA B")
{}

void ora_b_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

ora_c_opcode::ora_c_opcode()
    : ora_opcode("ORA C")
{}

void ora_c_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

ora_d_opcode::ora_d_opcode()
    : ora_opcode("ORA D")
{}

void ora_d_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

ora_e_opcode::ora_e_opcode()
    : ora_opcode("ORA E")
{}

void ora_e_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

ora_h_opcode::ora_h_opcode()
    : ora_opcode("ORA H")
{}

void ora_h_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

ora_l_opcode::ora_l_opcode()
    : ora_opcode("ORA L")
{}

void ora_l_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

ora_m_opcode::ora_m_opcode()
    : ora_opcode("ORA M", 7)
{}

void ora_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    ora(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

ora_a_opcode::ora_a_opcode()
    : ora_opcode("ORA A")
{}

void ora_a_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

// ============================================================
// ===================== CMP ==================================
cmp_opcode::cmp_opcode(QString ass_cmd, int cpu_cycles=4)
    : opcodes(1, cpu_cycles, cpu_cycles, ass_cmd)
{}

cmp_b_opcode::cmp_b_opcode()
    : cmp_opcode("CMP B")
{}

void cmp_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

cmp_c_opcode::cmp_c_opcode()
    : cmp_opcode("CMP C")
{}

void cmp_c_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

cmp_d_opcode::cmp_d_opcode()
    : cmp_opcode("CMP D")
{}

void cmp_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

cmp_e_opcode::cmp_e_opcode()
    : cmp_opcode("CMP E")
{}

void cmp_e_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

cmp_h_opcode::cmp_h_opcode()
    : cmp_opcode("CMP H")
{}

void cmp_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

cmp_l_opcode::cmp_l_opcode()
    : cmp_opcode("CMP L")
{}

void cmp_l_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

cmp_m_opcode::cmp_m_opcode()
    : cmp_opcode("CMP M", 7)
{}

void cmp_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cmp(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

cmp_a_opcode::cmp_a_opcode()
    : cmp_opcode("CMP A")
{}

void cmp_a_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}
