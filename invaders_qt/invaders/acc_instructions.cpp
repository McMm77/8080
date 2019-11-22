#include "acc_instructions.h"
#include "cpu_core.h"

void add_instr::add(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();

    cpu_8080.core_flag().set_c_flag(reg_a, val);
    cpu_8080.core_flag().set_ac_flag(reg_a, val);

    reg_a += val;

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void adc_instr::adc(cpu &cpu_8080, uint8_t val)
{
    uint8_t cbit = cpu_8080.core_flag().get_c_flag();
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();

    cpu_8080.core_flag().set_c_flag(reg_a, val + cbit);
    cpu_8080.core_flag().set_ac_flag(reg_a, val + cbit);

    reg_a += (val + cbit);

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void sub_instr::sub(cpu &cpu_8080, uint8_t val)
{
    uint8_t two_qu = ~val + 1;
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();

//    cpu_8080.core_flag().set_c_flag(reg_a, two_qu);
    if(reg_a < val)
        cpu_8080.core_flag().set_c_flag(1);
    else
        cpu_8080.core_flag().set_c_flag(0);

    cpu_8080.core_flag().set_ac_flag(reg_a, two_qu);

    reg_a += two_qu;

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void sbb_instr::sbb(cpu &cpu_8080, uint8_t val)
{
    uint8_t cbit = cpu_8080.core_flag().get_c_flag();
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t two_qu = ~(val + cbit) + 1;

//    cpu_8080.core_flag().set_c_flag(reg_a, two_qu);

    if(reg_a < (val + cbit))
        cpu_8080.core_flag().set_c_flag(1);
    else
        cpu_8080.core_flag().set_c_flag(0);

    cpu_8080.core_flag().set_ac_flag(reg_a, two_qu);

    reg_a += two_qu;

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void ana_instr::ana(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a() & val;

    cpu_8080.core_flag().set_c_flag(0);
    cpu_8080.core_flag().set_ac_flag(0);

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void xra_instr::xra(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a() ^ val;

    cpu_8080.core_flag().set_c_flag(0);
    cpu_8080.core_flag().set_ac_flag(0);

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);

}

void ora_instr::ora(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a() | val;

    cpu_8080.core_flag().set_c_flag(0);
    cpu_8080.core_flag().set_ac_flag(0);

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);

}

void cmp_instr::cmp(cpu &cpu_8080, uint8_t val)
{
    uint8_t two_qu = ~val + 1;
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();


//    cpu_8080.core_flag().set_c_flag(reg_a, two_qu);
    if (reg_a < val)
        cpu_8080.core_flag().set_c_flag(1);
    else
        cpu_8080.core_flag().set_c_flag(0);

    cpu_8080.core_flag().set_ac_flag(reg_a, two_qu);

    reg_a += two_qu;

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);
}
