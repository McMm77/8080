#include "data_transfer_opcodes.h"
#include "cpu_core.h"

stax_opcode::stax_opcode(QString ass_cmd)
    : opcodes(1, 7, 7, ass_cmd)
{}

void stax_opcode::store_acc_to_mem(cpu &cpu_8080, uint8_t reg_h, uint8_t reg_l)
{
    uint16_t address = (reg_h << 8) | reg_l;
    cpu_8080.rom().set_u16(address, cpu_8080.core_p().get_reg_a());
}

stax_b_opcode::stax_b_opcode()
    : stax_opcode("STAX B")
{}

void stax_b_opcode::handle_opcode(cpu &cpu_8080)
{
    store_acc_to_mem(cpu_8080, cpu_8080.core_p().get_reg_b(), cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

stax_d_opcode::stax_d_opcode()
    : stax_opcode("STAX D")
{}

void stax_d_opcode::handle_opcode(cpu &cpu_8080)
{
    store_acc_to_mem(cpu_8080, cpu_8080.core_p().get_reg_d(), cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

ldax_opcode::ldax_opcode(QString ass_cmd)
    : opcodes(1, 7, 7, ass_cmd)
{}

void ldax_opcode::retrieve_acc_from_mem(cpu &cpu_8080, uint8_t reg_h, uint8_t reg_l)
{
    uint16_t address = (reg_h << 8) | reg_l;
    cpu_8080.core_p().set_reg_a(cpu_8080.rom().get_u16(address));
}

ldax_b_opcode::ldax_b_opcode()
    : ldax_opcode("LDAX B")
{}

void ldax_b_opcode::handle_opcode(cpu &cpu_8080)
{
    retrieve_acc_from_mem(cpu_8080, cpu_8080.core_p().get_reg_d(), cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

ldax_d_opcode::ldax_d_opcode()
    : ldax_opcode("LDAX D")
{}

void ldax_d_opcode::handle_opcode(cpu &cpu_8080)
{
    retrieve_acc_from_mem(cpu_8080, cpu_8080.core_p().get_reg_d(), cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ---------- MOV B
mov_opcode::mov_opcode(QString ass_cmd, int cpu_cycles=5)
    : opcodes(1, cpu_cycles, cpu_cycles, ass_cmd)
{}

mov_bb_opcode::mov_bb_opcode()
    : mov_opcode("MOV B, B")
{}

void mov_bb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_bc_opcode::mov_bc_opcode()
    : mov_opcode("MOV B, C")
{}

void mov_bc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_bd_opcode::mov_bd_opcode()
    : mov_opcode("MOV B, D")
{}

void mov_bd_opcode::handle_opcode(cpu &cpu_8080)
{cpu_8080.core_p().increase_pc(instr_size());
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_be_opcode::mov_be_opcode()
    : mov_opcode("MOV B, E")
{}

void mov_be_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_bh_opcode::mov_bh_opcode()
    : mov_opcode("MOV B, H")
{}

void mov_bh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_bl_opcode::mov_bl_opcode()
    : mov_opcode("MOV B, L")
{}

void mov_bl_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_bm_opcode::mov_bm_opcode()
    : mov_opcode("MOV B, M", 7)
{}

void mov_bm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);
    cpu_8080.core_p().set_reg_b(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ba_opcode::mov_ba_opcode()
    : mov_opcode("MOV B, A")
{}

void mov_ba_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ------------ MOV C
mov_cb_opcode::mov_cb_opcode()
    : mov_opcode("MOV C, B")
{}

void mov_cb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_cc_opcode::mov_cc_opcode()
    : mov_opcode("MOV C, C")
{}

void mov_cc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_cd_opcode::mov_cd_opcode()
    : mov_opcode("MOV C, D")
{}

void mov_cd_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ce_opcode::mov_ce_opcode()
    : mov_opcode("MOV C, E")
{}

void mov_ce_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ch_opcode::mov_ch_opcode()
    : mov_opcode("MOV C, H")
{}

void mov_ch_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_cl_opcode::mov_cl_opcode()
    : mov_opcode("MOV C, L")
{}

void mov_cl_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_cm_opcode::mov_cm_opcode()
    : mov_opcode("MOV C, M", 7)
{}

void mov_cm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_c(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ca_opcode::mov_ca_opcode()
    : mov_opcode("MOV C, A")
{}

void mov_ca_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// --------------- MOV D
mov_db_opcode::mov_db_opcode()
    : mov_opcode("MOV D, B")
{}

void mov_db_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_dc_opcode::mov_dc_opcode()
    : mov_opcode("MOV D, C")
{}

void mov_dc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_dd_opcode::mov_dd_opcode()
    : mov_opcode("MOV D, D")
{}

void mov_dd_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_de_opcode::mov_de_opcode()
    : mov_opcode("MOV D, E")
{}

void mov_de_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_dh_opcode::mov_dh_opcode()
    : mov_opcode("MOV D, H")
{}

void mov_dh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_dl_opcode::mov_dl_opcode()
    : mov_opcode("MOV D, L")
{}

void mov_dl_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_dm_opcode::mov_dm_opcode()
    : mov_opcode("MOV D, M", 7)
{}

void mov_dm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_d(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_da_opcode::mov_da_opcode()
    : mov_opcode("MOV D, A")
{}

void mov_da_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}


// ------------- MOV E
mov_eb_opcode::mov_eb_opcode()
    : mov_opcode("MOV E, B")
{}

void mov_eb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ec_opcode::mov_ec_opcode()
    : mov_opcode("MOV E, C")
{}

void mov_ec_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ed_opcode::mov_ed_opcode()
    : mov_opcode("MOV E, D")
{}

void mov_ed_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ee_opcode::mov_ee_opcode()
    : mov_opcode("MOV E, E")
{}

void mov_ee_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_eh_opcode::mov_eh_opcode()
    : mov_opcode("MOV E, H")
{}

void mov_eh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_el_opcode::mov_el_opcode()
    : mov_opcode("MOV E, L")
{}

void mov_el_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_em_opcode::mov_em_opcode()
    : mov_opcode("MOV E, M", 7)
{}

void mov_em_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_e(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ea_opcode::mov_ea_opcode()
    : mov_opcode("MOV E, A")
{}

void mov_ea_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ----------c--- MOV H
mov_hb_opcode::mov_hb_opcode()
    : mov_opcode("MOV H, B")
{}

void mov_hb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_hc_opcode::mov_hc_opcode()
    : mov_opcode("MOV H, C")
{}

void mov_hc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_hd_opcode::mov_hd_opcode()
    : mov_opcode("MOV H, D")
{}

void mov_hd_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_he_opcode::mov_he_opcode()
    : mov_opcode("MOV H, E")
{}

void mov_he_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_hh_opcode::mov_hh_opcode()
    : mov_opcode("MOV H, H")
{}

void mov_hh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_hl_opcode::mov_hl_opcode()
    : mov_opcode("MOV H, L")
{}

void mov_hl_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_hm_opcode::mov_hm_opcode()
    : mov_opcode("MOV H, M", 7)
{}

void mov_hm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_h(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ha_opcode::mov_ha_opcode()
    : mov_opcode("MOV H, A")
{}

void mov_ha_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ------------- MOV L
mov_lb_opcode::mov_lb_opcode()
    : mov_opcode("MOV L, B")
{}

void mov_lb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_lc_opcode::mov_lc_opcode()
    : mov_opcode("MOV L, C")
{}

void mov_lc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ld_opcode::mov_ld_opcode()
    : mov_opcode("MOV L, D")
{}

void mov_ld_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_le_opcode::mov_le_opcode()
    : mov_opcode("MOV L, E")
{}

void mov_le_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_lh_opcode::mov_lh_opcode()
    : mov_opcode("MOV L, H")
{}

void mov_lh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ll_opcode::mov_ll_opcode()
    : mov_opcode("MOV L, L")
{}

void mov_ll_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_lm_opcode::mov_lm_opcode()
    : mov_opcode("MOV L, M", 7)
{}

void mov_lm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_l(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_la_opcode::mov_la_opcode()
    : mov_opcode("MOV L, A")
{}

void mov_la_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ------------- MOV M
mov_mb_opcode::mov_mb_opcode()
    : mov_opcode("MOV M, B")
{}

void mov_mb_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_mc_opcode::mov_mc_opcode()
    : mov_opcode("MOV M, C")
{}

void mov_mc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_md_opcode::mov_md_opcode()
    : mov_opcode("MOV M, D")
{}

void mov_md_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_me_opcode::mov_me_opcode()
    : mov_opcode("MOV M, E")
{}

void mov_me_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_mh_opcode::mov_mh_opcode()
    : mov_opcode("MOV M, H")
{}

void mov_mh_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ml_opcode::mov_ml_opcode()
    : mov_opcode("MOV M, L")
{}

void mov_ml_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ma_opcode::mov_ma_opcode()
    : mov_opcode("MOV M, A")
{}

void mov_ma_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ------------- MOV A
mov_ab_opcode::mov_ab_opcode()
    : mov_opcode("MOV A, B")
{}

void mov_ab_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ac_opcode::mov_ac_opcode()
    : mov_opcode("MOV A, C")
{}

void mov_ac_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ad_opcode::mov_ad_opcode()
    : mov_opcode("MOV A, D")
{}

void mov_ad_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ae_opcode::mov_ae_opcode()
    : mov_opcode("MOV A, E")
{}

void mov_ae_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_ah_opcode::mov_ah_opcode()
    : mov_opcode("MOV A, H")
{}

void mov_ah_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_al_opcode::mov_al_opcode()
    : mov_opcode("MOV A, L")
{}

void mov_al_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_am_opcode::mov_am_opcode()
    : mov_opcode("MOV A, M", 7)
{}

void mov_am_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_a(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

mov_aa_opcode::mov_aa_opcode()
    : mov_opcode("MOV A, A")
{}

void mov_aa_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}
