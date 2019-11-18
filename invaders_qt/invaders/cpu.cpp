#include "cpu_core.h"
#include "register_pair_opcodes.h"
#include "rotate_acc_opcodes.h"
#include "jmp_opcode.h"
#include "call_opcode.h"
#include "ret_opcode.h"
#include "direct_addr_opcode.h"
#include "interrupt_flipflop_opcode.h"
#include "immediate_opcode.h"
#include "reg_or_mem_to_acc_opcode.h"
#include "rst_opcode.h"
#include "data_transfer_opcodes.h"
#include "io_opcode.h"
#include "single_register_opcodes.h"
#include "hlt_opcode.h"
#include "carry_bit_opcode.h"
#include "nop_opcode.h"

void cpu::init(invaders& hw) {
    this->opcode_table[0x00] = new nop_opcode();
    this->opcode_table[0x01] = new lxi_b_opcode();
    this->opcode_table[0x02] = new stax_b_opcode();
    this->opcode_table[0x03] = new inx_b_opcode();
    this->opcode_table[0x04] = new inr_b_opcode();
    this->opcode_table[0x05] = new dcr_b_opcode();
    this->opcode_table[0x06] = new mvi_b_opcode();
    this->opcode_table[0x07] = new rlc_opcode();
    this->opcode_table[0x08] = new nop_opcode();
    this->opcode_table[0x09] = new dad_b_opcode();
    this->opcode_table[0x0A] = new ldax_b_opcode();
    this->opcode_table[0x0B] = new dcx_b_opcode();
    this->opcode_table[0x0C] = new inr_c_opcode();
    this->opcode_table[0x0D] = new dcr_c_opcode();
    this->opcode_table[0x0E] = new mvi_c_opcode();
    this->opcode_table[0x0F] = new rrc_opcode();
    this->opcode_table[0x10] = new nop_opcode();
    this->opcode_table[0x11] = new lxi_d_opcode();
    this->opcode_table[0x12] = new stax_d_opcode();
    this->opcode_table[0x13] = new inx_d_opcode();
    this->opcode_table[0x14] = new inr_d_opcode();
    this->opcode_table[0x15] = new dcr_d_opcode();
    this->opcode_table[0x16] = new mvi_d_opcode();
    this->opcode_table[0x17] = new ral_opcode();
    this->opcode_table[0x18] = new nop_opcode();
    this->opcode_table[0x19] = new dad_d_opcode();
    this->opcode_table[0x1A] = new ldax_d_opcode();
    this->opcode_table[0x1B] = new dcx_d_opcode();
    this->opcode_table[0x1C] = new inr_e_opcode();
    this->opcode_table[0x1D] = new dcr_e_opcode();
    this->opcode_table[0x1E] = new mvi_e_opcode();
    this->opcode_table[0x1F] = new rar_opcode();
    this->opcode_table[0x20] = new nop_opcode();
    this->opcode_table[0x21] = new lxi_h_opcode();
    this->opcode_table[0x22] = new shld_opcode();
    this->opcode_table[0x23] = new inx_h_opcode();
    this->opcode_table[0x24] = new inr_h_opcode();
    this->opcode_table[0x25] = new dcr_h_opcode();
    this->opcode_table[0x26] = new mvi_h_opcode();
    this->opcode_table[0x27] = new daa_opcode();
    this->opcode_table[0x28] = new nop_opcode();
    this->opcode_table[0x29] = new dad_h_opcode();
    this->opcode_table[0x2A] = new lhld_opcode();
    this->opcode_table[0x2B] = new dcx_h_opcode();
    this->opcode_table[0x2C] = new inr_l_opcode();
    this->opcode_table[0x2D] = new dcr_l_opcode();
    this->opcode_table[0x2E] = new mvi_l_opcode();
    this->opcode_table[0x2F] = new cma_opcode();
    this->opcode_table[0x30] = new nop_opcode();
    this->opcode_table[0x31] = new lxi_sp_opcode();
    this->opcode_table[0x32] = new sta_opcode();
    this->opcode_table[0x33] = new inx_sp_opcode();
    this->opcode_table[0x34] = new inr_m_opcode();
    this->opcode_table[0x35] = new dcr_m_opcode();
    this->opcode_table[0x36] = new mvi_m_opcode();
    this->opcode_table[0x37] = new stc_opcode();
    this->opcode_table[0x38] = new nop_opcode();
    this->opcode_table[0x39] = new dad_sp_opcode();
    this->opcode_table[0x3A] = new lda_opcode();
    this->opcode_table[0x3B] = new dcx_sp_opcode();
    this->opcode_table[0x3C] = new inr_a_opcode();
    this->opcode_table[0x3D] = new dcr_a_opcode();
    this->opcode_table[0x3E] = new mvi_a_opcode();
    this->opcode_table[0x3F] = new cmc_opcode();
    this->opcode_table[0x40] = new mov_bb_opcode();
    this->opcode_table[0x41] = new mov_bc_opcode();
    this->opcode_table[0x42] = new mov_bd_opcode();
    this->opcode_table[0x43] = new mov_be_opcode();
    this->opcode_table[0x44] = new mov_bh_opcode();
    this->opcode_table[0x45] = new mov_bl_opcode();
    this->opcode_table[0x46] = new mov_bm_opcode();
    this->opcode_table[0x47] = new mov_ba_opcode();
    this->opcode_table[0x48] = new mov_cb_opcode();
    this->opcode_table[0x49] = new mov_cc_opcode();
    this->opcode_table[0x4A] = new mov_cd_opcode();
    this->opcode_table[0x4B] = new mov_ce_opcode();
    this->opcode_table[0x4C] = new mov_ch_opcode();
    this->opcode_table[0x4D] = new mov_cl_opcode();
    this->opcode_table[0x4E] = new mov_cm_opcode();
    this->opcode_table[0x4F] = new mov_ca_opcode();
    this->opcode_table[0x50] = new mov_db_opcode();
    this->opcode_table[0x51] = new mov_dc_opcode();
    this->opcode_table[0x52] = new mov_dd_opcode();
    this->opcode_table[0x53] = new mov_de_opcode();
    this->opcode_table[0x54] = new mov_dh_opcode();
    this->opcode_table[0x55] = new mov_dl_opcode();
    this->opcode_table[0x56] = new mov_dm_opcode();
    this->opcode_table[0x57] = new mov_da_opcode();
    this->opcode_table[0x58] = new mov_eb_opcode();
    this->opcode_table[0x59] = new mov_ec_opcode();
    this->opcode_table[0x5A] = new mov_ed_opcode();
    this->opcode_table[0x5B] = new mov_ee_opcode();
    this->opcode_table[0x5C] = new mov_eh_opcode();
    this->opcode_table[0x5D] = new mov_el_opcode();
    this->opcode_table[0x5E] = new mov_em_opcode();
    this->opcode_table[0x5F] = new mov_ea_opcode();
    this->opcode_table[0x60] = new mov_hb_opcode();
    this->opcode_table[0x61] = new mov_hc_opcode();
    this->opcode_table[0x62] = new mov_hd_opcode();
    this->opcode_table[0x63] = new mov_he_opcode();
    this->opcode_table[0x64] = new mov_hh_opcode();
    this->opcode_table[0x65] = new mov_hl_opcode();
    this->opcode_table[0x66] = new mov_hm_opcode();
    this->opcode_table[0x67] = new mov_ha_opcode();
    this->opcode_table[0x68] = new mov_lb_opcode();
    this->opcode_table[0x69] = new mov_lc_opcode();
    this->opcode_table[0x6A] = new mov_ld_opcode();
    this->opcode_table[0x6B] = new mov_le_opcode();
    this->opcode_table[0x6C] = new mov_lh_opcode();
    this->opcode_table[0x6D] = new mov_ll_opcode();
    this->opcode_table[0x6E] = new mov_lm_opcode();
    this->opcode_table[0x6F] = new mov_la_opcode();
    this->opcode_table[0x70] = new mov_mb_opcode();
    this->opcode_table[0x71] = new mov_mc_opcode();
    this->opcode_table[0x72] = new mov_md_opcode();
    this->opcode_table[0x73] = new mov_me_opcode();
    this->opcode_table[0x74] = new mov_mh_opcode();
    this->opcode_table[0x75] = new mov_ml_opcode();
    this->opcode_table[0x76] = new hlt_opcode();
    this->opcode_table[0x77] = new mov_ma_opcode();
    this->opcode_table[0x78] = new mov_ab_opcode();
    this->opcode_table[0x79] = new mov_ac_opcode();
    this->opcode_table[0x7A] = new mov_ad_opcode();
    this->opcode_table[0x7B] = new mov_ae_opcode();
    this->opcode_table[0x7C] = new mov_ah_opcode();
    this->opcode_table[0x7D] = new mov_al_opcode();
    this->opcode_table[0x7E] = new mov_am_opcode();
    this->opcode_table[0x7F] = new mov_aa_opcode();
    this->opcode_table[0x80] = new add_b_opcode();
    this->opcode_table[0x81] = new add_c_opcode();
    this->opcode_table[0x82] = new add_d_opcode();
    this->opcode_table[0x83] = new add_e_opcode();
    this->opcode_table[0x84] = new add_h_opcode();
    this->opcode_table[0x85] = new add_l_opcode();
    this->opcode_table[0x86] = new add_m_opcode();
    this->opcode_table[0x87] = new add_a_opcode();
    this->opcode_table[0x88] = new adc_b_opcode();
    this->opcode_table[0x89] = new adc_c_opcode();
    this->opcode_table[0x8A] = new adc_d_opcode();
    this->opcode_table[0x8B] = new adc_e_opcode();
    this->opcode_table[0x8C] = new adc_h_opcode();
    this->opcode_table[0x8D] = new adc_l_opcode();
    this->opcode_table[0x8E] = new adc_m_opcode();
    this->opcode_table[0x8F] = new adc_a_opcode();
    this->opcode_table[0x90] = new sub_b_opcode();
    this->opcode_table[0x91] = new sub_c_opcode();
    this->opcode_table[0x92] = new sub_d_opcode();
    this->opcode_table[0x93] = new sub_e_opcode();
    this->opcode_table[0x94] = new sub_h_opcode();
    this->opcode_table[0x95] = new sub_l_opcode();
    this->opcode_table[0x96] = new sub_m_opcode();
    this->opcode_table[0x97] = new sub_a_opcode();
    this->opcode_table[0x98] = new sbb_b_opcode();
    this->opcode_table[0x99] = new sbb_c_opcode();
    this->opcode_table[0x9A] = new sbb_d_opcode();
    this->opcode_table[0x9B] = new sbb_e_opcode();
    this->opcode_table[0x9C] = new sbb_h_opcode();
    this->opcode_table[0x9D] = new sbb_l_opcode();
    this->opcode_table[0x9E] = new sbb_m_opcode();
    this->opcode_table[0x9F] = new sbb_a_opcode();
    this->opcode_table[0xA0] = new ana_b_opcode();
    this->opcode_table[0xA1] = new ana_c_opcode();
    this->opcode_table[0xA2] = new ana_d_opcode();
    this->opcode_table[0xA3] = new ana_e_opcode();
    this->opcode_table[0xA4] = new ana_h_opcode();
    this->opcode_table[0xA5] = new ana_l_opcode();
    this->opcode_table[0xA6] = new ana_m_opcode();
    this->opcode_table[0xA7] = new ana_a_opcode();
    this->opcode_table[0xA8] = new xra_b_opcode();
    this->opcode_table[0xA9] = new xra_c_opcode();
    this->opcode_table[0xAA] = new xra_d_opcode();
    this->opcode_table[0xAB] = new xra_e_opcode();
    this->opcode_table[0xAC] = new xra_h_opcode();
    this->opcode_table[0xAD] = new xra_l_opcode();
    this->opcode_table[0xAE] = new xra_m_opcode();
    this->opcode_table[0xAF] = new xra_a_opcode();
    this->opcode_table[0xB0] = new ora_b_opcode();
    this->opcode_table[0xB1] = new ora_c_opcode();
    this->opcode_table[0xB2] = new ora_d_opcode();
    this->opcode_table[0xB3] = new ora_e_opcode();
    this->opcode_table[0xB4] = new ora_h_opcode();
    this->opcode_table[0xB5] = new ora_l_opcode();
    this->opcode_table[0xB6] = new ora_m_opcode();
    this->opcode_table[0xB7] = new ora_a_opcode();
    this->opcode_table[0xB8] = new cmp_b_opcode();
    this->opcode_table[0xB9] = new cmp_c_opcode();
    this->opcode_table[0xBA] = new cmp_d_opcode();
    this->opcode_table[0xBB] = new cmp_e_opcode();
    this->opcode_table[0xBC] = new cmp_h_opcode();
    this->opcode_table[0xBD] = new cmp_l_opcode();
    this->opcode_table[0xBE] = new cmp_m_opcode();
    this->opcode_table[0xBF] = new cmp_a_opcode();
    this->opcode_table[0xC0] = new rnz_opcode();
    this->opcode_table[0xC1] = new pop_b_opcode();
    this->opcode_table[0xC2] = new jnz_opcode();
    this->opcode_table[0xC3] = new jmp_opcode();
    this->opcode_table[0xC4] = new cnz_opcode();
    this->opcode_table[0xC5] = new push_b_opcode();
    this->opcode_table[0xC6] = new adi_opcode();
    this->opcode_table[0xC7] = new rst0_opcode();
    this->opcode_table[0xC8] = new rz_opcode();
    this->opcode_table[0xC9] = new ret_opcode();
    this->opcode_table[0xCA] = new jz_opcode();
    this->opcode_table[0xCB] = new jmp_opcode();
    this->opcode_table[0xCC] = new cz_opcode();
    this->opcode_table[0xCD] = new call_opcode();
    this->opcode_table[0xCE] = new aci_opcode();
    this->opcode_table[0xCF] = new rst1_opcode();
    this->opcode_table[0xD0] = new rnc_opcode();
    this->opcode_table[0xD1] = new pop_d_opcode();
    this->opcode_table[0xD2] = new jnc_opcode();
    this->opcode_table[0xD3] = new out_opcode(hw);
    this->opcode_table[0xD4] = new cnc_opcode();
    this->opcode_table[0xD5] = new push_d_opcode();
    this->opcode_table[0xD6] = new sui_opcode();
    this->opcode_table[0xD7] = new rst2_opcode();
    this->opcode_table[0xD8] = new rc_opcode();
    this->opcode_table[0xD9] = new ret_opcode();
    this->opcode_table[0xDA] = new jc_opcode();
    this->opcode_table[0xDB] = new in_opcode(hw);
    this->opcode_table[0xDC] = new cc_opcode();
    this->opcode_table[0xDD] = new call_opcode();
    this->opcode_table[0xDE] = new sbi_opcode();
    this->opcode_table[0xDF] = new rst3_opcode();
    this->opcode_table[0xE0] = new rpo_opcode();
    this->opcode_table[0xE1] = new pop_h_opcode();
    this->opcode_table[0xE2] = new jpo_opcode();
    this->opcode_table[0xE3] = new xthl_opcode();
    this->opcode_table[0xE4] = new cpo_opcode();
    this->opcode_table[0xE5] = new push_h_opcode();
    this->opcode_table[0xE6] = new ani_opcode();
    this->opcode_table[0xE7] = new rst4_opcode();
    this->opcode_table[0xE8] = new rpe_opcode();
    this->opcode_table[0xE9] = new pchl_opcode();
    this->opcode_table[0xEA] = new jpe_opcode();
    this->opcode_table[0xEB] = new xchg_opcode();
    this->opcode_table[0xEC] = new cpe_opcode();
    this->opcode_table[0xED] = new call_opcode();
    this->opcode_table[0xEE] = new xri_opcode();
    this->opcode_table[0xEF] = new rst5_opcode();
    this->opcode_table[0xF0] = new rp_opcode();
    this->opcode_table[0xF1] = new pop_psw_opcode();
    this->opcode_table[0xF2] = new jp_opcode();
    this->opcode_table[0xF3] = new di_opcode();
    this->opcode_table[0xF4] = new cp_opcode();
    this->opcode_table[0xF5] = new push_psw_opcode();
    this->opcode_table[0xF6] = new ori_opcode();
    this->opcode_table[0xF7] = new rst6_opcode();
    this->opcode_table[0xF8] = new rm_opcode();
    this->opcode_table[0xF9] = new sphl_opcode();
    this->opcode_table[0xFA] = new jm_opcode();
    this->opcode_table[0xFB] = new ei_opcode();
    this->opcode_table[0xFC] = new cm_opcode();
    this->opcode_table[0xFD] = new call_opcode();
    this->opcode_table[0xFE] = new cpi_opcode();
    this->opcode_table[0xFF] = new rst7_opcode();
}


cpu::cpu(cpu_memory& rom, invaders& hw)
    : memory(rom),
      is_interrupted(false),
      interrupt_enable(true),
      is_running(false)
{
    init(hw);
}

void cpu::enable_interrupt(bool en)
{
    interrupt_enable = en;
}

void cpu::cpu_running(bool en)
{
    is_running = en;
}

void cpu::interrupt(unsigned long cmd) {
    if (interrupt_enable) {
        interrupt_command = cmd;
        is_interrupted = true;
    }
}

uint8_t cpu::extract_interrupt_opcode() {
    return ((uint8_t) (interrupt_command & 0x000000FF));
}

void cpu::single_step(cpu_debug& debug_info)
{
    uint8_t opcode = 0;
    if(core.get_pc() < memory.size()) {
        if (is_interrupted) {
            is_interrupted = false;
            opcode = extract_interrupt_opcode();
        }
        else {
            opcode = memory[core.get_pc()];
        }

        opcodes *ptr = opcode_table[opcode];

        ptr->store_pre_debug_data(*this, debug_info);
        ptr->handle_opcode(*this);
        ptr->store_post_debug_data(*this, debug_info);
    }
}

static QString mcm_convert_to_hex_u8(uint8_t reg_val)
{
    QString number;

    number.sprintf("0x%02x", reg_val);
    return number;
}

static QString mcm_convert_to_hex_u16(uint16_t reg_val)
{
    QString number;

    number.sprintf("0x%04x", reg_val);
    return number;
}

QString cpu::log(cpu_debug& debug_info) {
/*
    QString ass_cmd;
    ass_cmd.append(debug_info.curr_opcode_cmd);
    ass_cmd.append("\n");
    return ass_cmd;
*/
    QString ass_cmd("\n---------------------------------------------");

    ass_cmd.append(debug_info.curr_opcode_cmd);
    ass_cmd.append("\n\t a:");
    ass_cmd.append(mcm_convert_to_hex_u8(debug_info.curr_core.get_reg_a()));
    ass_cmd.append('\n');

    ass_cmd.append("\t b:");
    ass_cmd.append(mcm_convert_to_hex_u8(debug_info.curr_core.get_reg_b()));
    ass_cmd.append("\t c:");
    ass_cmd.append(mcm_convert_to_hex_u8(debug_info.curr_core.get_reg_c()));
    ass_cmd.append('\n');

    ass_cmd.append("\t d:");
    ass_cmd.append(mcm_convert_to_hex_u8(debug_info.curr_core.get_reg_d()));
    ass_cmd.append("\t e:");
    ass_cmd.append(mcm_convert_to_hex_u8(debug_info.curr_core.get_reg_e()));
    ass_cmd.append('\n');

    ass_cmd.append("\t h:");
    ass_cmd.append(mcm_convert_to_hex_u8(debug_info.curr_core.get_reg_h()));
    ass_cmd.append("\t l:");
    ass_cmd.append(mcm_convert_to_hex_u8(debug_info.curr_core.get_reg_l()));
    ass_cmd.append('\n');

    uint16_t stack_ptr = this->core_p().get_sp();
    for(int i = 0 ; i < 10 ; i++ ) {
        ass_cmd.append("\n\n");
        ass_cmd.append(mcm_convert_to_hex_u16(stack_ptr));
        ass_cmd.append(": ");
        uint16_t data = this->rom().get_u16(stack_ptr);
        ass_cmd.append(mcm_convert_to_hex_u16(data));
        stack_ptr += 2;
    }

    return ass_cmd;

}
void cpu::execute(QFile& log_file)
{
    uint8_t opcode = 0x00;
    opcodes *ptr = NULL;
    try {

        while(core.get_pc() < memory.size())
        {
            cpu_debug   debug_info;

            if (is_interrupted) {
                is_interrupted = false;
                opcode = extract_interrupt_opcode();
            }

            else {
                if (core.get_pc()  == 0x01EF || core.get_pc() == 0x1F5) {
                    log_file.close();


                }
                opcode = memory[core.get_pc()];
            }

            ptr = opcode_table[opcode];

            ptr->store_pre_debug_data(*this, debug_info);
            ptr->handle_opcode(*this);
            ptr->store_post_debug_data(*this, debug_info);

            QString  ass_cmd = log(debug_info);
            log_file.write(ass_cmd.toUtf8());
        }
    }

    catch(...)
    {
        cpu_debug d_info;
        ptr->store_pre_debug_data(*this, d_info);

        QString  ass_cmd = log(d_info);
        log_file.write(ass_cmd.toUtf8());

        log_file.close();
    }
}

void cpu::push_u16_on_the_stack(uint16_t val)
{
    uint16_t st_ptr = core_p().get_sp();
    uint8_t lbit = (val & 0x00FF);
    uint8_t hbit = (val >> 8) & 0x00FF;

    rom().set_u8(--st_ptr, hbit);
    rom().set_u8(--st_ptr, lbit);

    core_p().set_sp(st_ptr);
}

uint16_t cpu::pop_u16_from_the_stack()
{
    uint16_t st_ptr = core_p().get_sp();
    uint8_t lbit = rom().get_u8(st_ptr++);
    uint8_t hbit = rom().get_u8(st_ptr++);
    uint16_t val = (hbit << 8) | lbit;

    core_p().set_sp(st_ptr);

    return val;
}

void cpu::push_on_the_stack(uint8_t val)
{
    uint16_t st_ptr = core_p().get_sp();
    rom().set_u8(--st_ptr, val);
    core_p().set_sp(st_ptr);
}
uint8_t cpu::pop_from_the_stack()
{
    uint16_t st_ptr = core_p().get_sp();
    uint8_t val = rom().get_u8(st_ptr++);
    core_p().set_sp(st_ptr);

    return val;
}
