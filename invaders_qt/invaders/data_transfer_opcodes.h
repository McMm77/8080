#ifndef DATA_TRANSFER_OPCODES_H
#define DATA_TRANSFER_OPCODES_H

#include "opcodes.h"

class stax_opcode : public opcodes
{
protected:
    stax_opcode(QString);

protected:
    void store_acc_to_mem(cpu&, uint8_t, uint8_t);

};

class stax_b_opcode : public stax_opcode
{
public:
    stax_b_opcode();

public:
    void handle_opcode(cpu&);
};

class stax_d_opcode : public stax_opcode
{
public:
    stax_d_opcode();

public:
    void handle_opcode(cpu&);
};

class ldax_opcode : public opcodes
{
protected:
    ldax_opcode(QString);

protected:
    void retrieve_acc_from_mem(cpu&, uint8_t, uint8_t);
};

class ldax_b_opcode : public ldax_opcode
{
public:
    ldax_b_opcode();

public:
    void handle_opcode(cpu&);
};

class ldax_d_opcode : public ldax_opcode
{
public:
    ldax_d_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_opcode : public opcodes
{
protected:
    mov_opcode(QString, int);
};

class mov_bb_opcode : public mov_opcode
{
public:
    mov_bb_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_bc_opcode : public mov_opcode
{
public:
    mov_bc_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_bd_opcode : public mov_opcode
{
public:
    mov_bd_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_be_opcode : public mov_opcode
{
public:
    mov_be_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_bh_opcode : public mov_opcode
{
public:
    mov_bh_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_bl_opcode : public mov_opcode
{
public:
    mov_bl_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_bm_opcode : public mov_opcode
{
public:
    mov_bm_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ba_opcode : public mov_opcode
{
public:
    mov_ba_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_cb_opcode : public mov_opcode
{
public:
    mov_cb_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_cc_opcode : public mov_opcode
{
public:
    mov_cc_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_cd_opcode : public mov_opcode
{
public:
    mov_cd_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ce_opcode : public mov_opcode
{
public:
    mov_ce_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ch_opcode : public mov_opcode
{
public:
    mov_ch_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_cl_opcode : public mov_opcode
{
public:
    mov_cl_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_cm_opcode : public mov_opcode
{
public:
    mov_cm_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ca_opcode : public mov_opcode
{
public:
    mov_ca_opcode();
public:
    void handle_opcode(cpu&);
};

class mov_db_opcode : public mov_opcode
{
public:
    mov_db_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_dc_opcode : public mov_opcode
{
public:
    mov_dc_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_dd_opcode : public mov_opcode
{
public:
    mov_dd_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_de_opcode : public mov_opcode
{
public:
    mov_de_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_dh_opcode : public mov_opcode
{
public:
    mov_dh_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_dl_opcode : public mov_opcode
{
public:
    mov_dl_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_dm_opcode : public mov_opcode
{
public:
    mov_dm_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_da_opcode : public mov_opcode
{
public:
    mov_da_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_eb_opcode : public mov_opcode
{
public:
    mov_eb_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ec_opcode : public mov_opcode
{
public:
    mov_ec_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ed_opcode : public mov_opcode
{
public:
    mov_ed_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ee_opcode : public mov_opcode
{
public:
    mov_ee_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_eh_opcode : public mov_opcode
{
public:
    mov_eh_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_el_opcode : public mov_opcode
{
public:
    mov_el_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_em_opcode : public mov_opcode
{
public:
    mov_em_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ea_opcode : public mov_opcode
{
public:
    mov_ea_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_hb_opcode : public mov_opcode
{
public:
    mov_hb_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_hc_opcode : public mov_opcode
{
public:
    mov_hc_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_hd_opcode : public mov_opcode
{
public:
    mov_hd_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_he_opcode : public mov_opcode
{
public:
    mov_he_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_hh_opcode : public mov_opcode
{
public:
    mov_hh_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_hl_opcode : public mov_opcode
{
public:
    mov_hl_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_hm_opcode : public mov_opcode
{
public:
    mov_hm_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ha_opcode : public mov_opcode
{
public:
    mov_ha_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_lb_opcode : public mov_opcode
{
public:
    mov_lb_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_lc_opcode : public mov_opcode
{
public:
    mov_lc_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ld_opcode : public mov_opcode
{
public:
    mov_ld_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_le_opcode : public mov_opcode
{
public:
    mov_le_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_lh_opcode : public mov_opcode
{
public:
    mov_lh_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ll_opcode : public mov_opcode
{
public:
    mov_ll_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_lm_opcode : public mov_opcode
{
public:
    mov_lm_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_la_opcode : public mov_opcode
{
public:
    mov_la_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_mb_opcode : public mov_opcode
{
public:
    mov_mb_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_mc_opcode : public mov_opcode
{
public:
    mov_mc_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_md_opcode : public mov_opcode
{
public:
    mov_md_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_me_opcode : public mov_opcode
{
public:
    mov_me_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_mh_opcode : public mov_opcode
{
public:
    mov_mh_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ml_opcode : public mov_opcode
{
public:
    mov_ml_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ma_opcode : public mov_opcode
{
public:
    mov_ma_opcode();

public:
    void handle_opcode(cpu&);
};


class mov_ab_opcode : public mov_opcode
{
public:
    mov_ab_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ac_opcode : public mov_opcode
{
public:
    mov_ac_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ad_opcode : public mov_opcode
{
public:
    mov_ad_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ae_opcode : public mov_opcode
{
public:
    mov_ae_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_ah_opcode : public mov_opcode
{
public:
    mov_ah_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_al_opcode : public mov_opcode
{
public:
    mov_al_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_am_opcode : public mov_opcode
{
public:
    mov_am_opcode();

public:
    void handle_opcode(cpu&);
};

class mov_aa_opcode : public mov_opcode
{
public:
    mov_aa_opcode();

public:
    void handle_opcode(cpu&);
};
#endif // DATA_TRANSFER_OPCODES_H
