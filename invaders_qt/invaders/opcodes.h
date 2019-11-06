#ifndef OPCODES_H
#define OPCODES_H

#include <QByteArray>

class cpu;
class cpu_core;
class cpu_memory;
class cpu_core_status_flags;

class opcodes
{
public:
    opcodes();

public:
    virtual void handle_opcode(cpu&) = 0;

protected:
    uint8_t instr_size() const {
        return size;
    }

private:
    uint8_t size;
};

class node_opcode : public opcodes
{
public:
    node_opcode();

public:
    void handle_opcode(cpu&);


};

// ---------------------------------------------------------------------------
class jmp_opcode : public opcodes
{
public:
    jmp_opcode();
public:
    void handle_opcode(cpu&);
};

class jpo_opcode : public jmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class jpe_opcode : public jmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class jz_opcode : public jmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class jnz_opcode : public jmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class jc_opcode : public jmp_opcode
{
public:
    void handle_opcode(cpu&);
};


class jnc_opcode : public jmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class jp_opcode : public jmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class jm_opcode : public jmp_opcode
{
public:
    void handle_opcode(cpu&);
};

// ---------------------------------------------------------------------------
class call_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class cz_opcode : public call_opcode
{
public:
    void handle_opcode(cpu&);
};

class cnz_opcode : public call_opcode
{
public:
    void handle_opcode(cpu&);
};

class cnc_opcode : public call_opcode
{
public:
    void handle_opcode(cpu&);
};

class cc_opcode : public call_opcode
{
public:
    void handle_opcode(cpu&);
};

class cm_opcode : public call_opcode
{
public:
    void handle_opcode(cpu&);
};

class cp_opcode : public call_opcode
{
public:
    void handle_opcode(cpu&);
};

class cpo_opcode : public call_opcode
{
public:
    void handle_opcode(cpu&);
};

class cpe_opcode : public call_opcode
{
public:
    void handle_opcode(cpu&);
};

class mvi_b_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class mvi_d_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class mvi_h_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class mvi_m_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class mvi_c_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class mvi_e_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class mvi_l_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class mvi_a_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class sta_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class lxi_b_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class lxi_d_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class lxi_h_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class lxi_sp_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class dcr_opcode : public opcodes
{
public:
    void dcr(cpu&, uint8_t&);
};

class dcr_b_opcode : public dcr_opcode
{
public:
    void handle_opcode(cpu&);
};

class dcr_c_opcode : public dcr_opcode
{
public:
    void handle_opcode(cpu&);
};

class dcr_d_opcode : public dcr_opcode
{
public:
    void handle_opcode(cpu&);
};

class dcr_e_opcode : public dcr_opcode
{
public:
    void handle_opcode(cpu&);
};

class dcr_h_opcode : public dcr_opcode
{
public:
    void handle_opcode(cpu&);
};

class dcr_l_opcode : public dcr_opcode
{
public:
    void handle_opcode(cpu&);
};

class dcr_m_opcode : public dcr_opcode
{
public:
    void handle_opcode(cpu&);
};

class dcr_a_opcode : public dcr_opcode
{
public:
    void handle_opcode(cpu&);
};

class in_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class rrc_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};


class lda_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class daa_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class pop_b_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class pop_d_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class pop_h_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class pop_psw_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class push_b_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class push_d_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class push_h_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class push_psw_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class ei_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class di_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class mov_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class inx_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class shld_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class dcx_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class inr_opcode : public opcodes
{
public:
    void inr(cpu&, uint8_t&);
};

class inr_b_opcode : public inr_opcode
{
public:
    void handle_opcode(cpu&);
};

class inr_c_opcode : public inr_opcode
{
public:
    void handle_opcode(cpu&);
};

class inr_d_opcode : public inr_opcode
{
public:
    void handle_opcode(cpu&);
};

class inr_e_opcode : public inr_opcode
{
public:
    void handle_opcode(cpu&);
};

class inr_h_opcode : public inr_opcode
{
public:
    void handle_opcode(cpu&);
};

class inr_l_opcode : public inr_opcode
{
public:
    void handle_opcode(cpu&);
};

class inr_m_opcode : public inr_opcode
{
public:
    void handle_opcode(cpu&);
};

class inr_a_opcode : public inr_opcode
{
public:
    void handle_opcode(cpu&);
};

class rlc_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};


class dad_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class xchg_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};


class lhld_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};


class ret_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class rz_opcode : public ret_opcode
{
public:
    void handle_opcode(cpu&);
};

class rnz_opcode : public ret_opcode
{
public:
    void handle_opcode(cpu&);
};

class rp_opcode : public ret_opcode
{
public:
    void handle_opcode(cpu&);
};

class rm_opcode : public ret_opcode
{
public:
    void handle_opcode(cpu&);
};

class rpo_opcode : public ret_opcode
{
public:
    void handle_opcode(cpu&);
};

class rpe_opcode : public ret_opcode
{
public:
    void handle_opcode(cpu&);
};

class rnc_opcode : public ret_opcode
{
public:
    void handle_opcode(cpu&);
};

class rc_opcode : public ret_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbb_opcode : public opcodes
{
public:
    void sbb(cpu&, uint8_t);
};

class sbb_b_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbb_c_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbb_d_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbb_e_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbb_h_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbb_l_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbb_m_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbb_a_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sbi_opcode : public sbb_opcode
{
public:
    void handle_opcode(cpu&);
};

class sub_opcode : public opcodes
{
public:
    void sub(cpu&, uint8_t);
};

class sub_b_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class sub_c_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class sub_d_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class sub_e_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class sub_h_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class sub_l_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class sub_m_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class sub_a_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class sui_opcode : public sub_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_opcode : public opcodes
{
protected:
    void add(cpu&, uint8_t);

};

class adi_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_b_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_c_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_d_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_e_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_h_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_l_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_m_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class add_a_opcode : public add_opcode
{
public:
    void handle_opcode(cpu&);
};

class adc_opcode : public opcodes
{
public:
    void adc(cpu&, uint8_t);
};

class aci_opcode : public adc_opcode
{
public:
    void handle_opcode(cpu&);
};

class ana_opcode : public opcodes
{
public:
    void ana(cpu&, uint8_t);
};

class ana_b_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class ana_c_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class ana_d_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class ana_e_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class ana_h_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class ana_l_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class ana_m_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class ana_a_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class ani_opcode : public ana_opcode
{
public:
    void handle_opcode(cpu&);
};

class xra_opcode : public opcodes
{
public:
    void xra(cpu&, uint8_t);
};

class xra_b_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class xra_c_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class xra_d_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class xra_e_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class xra_h_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class xra_l_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class xra_m_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class xra_a_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class xri_opcode : public xra_opcode
{
public:
    void handle_opcode(cpu&);
};

class ora_opcode : public opcodes
{
public:
    void ora(cpu&, uint8_t);
};

class ora_b_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class ora_c_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class ora_d_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class ora_e_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class ora_h_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class ora_l_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class ora_m_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class ora_a_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class ori_opcode : public ora_opcode
{
public:
    void handle_opcode(cpu&);
};

class cmp_opcode : public opcodes
{
public:
    void cmp(cpu&, uint8_t);
};

class cmp_b_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class cmp_c_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class cmp_d_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class cmp_e_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class cmp_h_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class cmp_l_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class cmp_m_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class cmp_a_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class cpi_opcode : public cmp_opcode
{
public:
    void handle_opcode(cpu&);
};

class xthl_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class pchl_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class out_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class stc_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class stax_opcode : public opcodes
{
protected:
    void store_acc_to_mem(cpu&, uint8_t, uint8_t);

};

class stax_b_opcode : public stax_opcode
{
public:
    void handle_opcode(cpu&);
};

class stax_d_opcode : public stax_opcode
{
public:
    void handle_opcode(cpu&);
};

class ldax_opcode : public opcodes
{
protected:
    void retrieve_acc_from_mem(cpu&, uint8_t, uint8_t);
};

class ldax_b_opcode : public ldax_opcode
{
public:
    void handle_opcode(cpu&);
};

class ldax_d_opcode : public ldax_opcode
{
public:
    void handle_opcode(cpu&);
};

class cma_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class rst7_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class rar_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class cmc_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class hlt_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};

class push_opcode : public opcodes
{
public:
    void handle_opcode(cpu&);
};
#endif // OPCODES_H
