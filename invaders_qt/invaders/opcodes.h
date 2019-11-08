#ifndef OPCODES_H
#define OPCODES_H

#include <QByteArray>
#include <QString>
// #include "cpu_core.h"

class cpu;
class cpu_debug;
class cpu_core;
class cpu_memory;
class cpu_core_status_flags;

class opcodes
{
protected:
    opcodes(uint8_t instr_size);
    opcodes(uint8_t _opcode_size, uint8_t _cycle_steps, uint8_t _max_cycle_steps, QString _cmd_string);

public:
    virtual void handle_opcode(cpu&);

public:
    void store_pre_debug_data(cpu&, cpu_debug&);
    void store_post_debug_data(cpu&, cpu_debug&);

private:
    QString convert_opcode_to_assembly(cpu&, uint16_t);

protected:
    uint8_t instr_size() const {
        return size;
    }

private:
    uint8_t size;
    uint8_t cycle_steps;
    uint8_t max_cycle_steps;
    QString assembly_command;

};

class nop_opcode : public opcodes
{
public:
    nop_opcode();

public:
    void handle_opcode(cpu&);
};


// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
class call_opcode : public opcodes
{
public:
    call_opcode()
        : opcodes(3)
    {}

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

class mvi_opcode : public opcodes
{
protected:
    mvi_opcode()
        : opcodes(2)
    {}
};

class mvi_b_opcode : public mvi_opcode
{
public:
    mvi_b_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class mvi_d_opcode : public mvi_opcode
{
public:
    mvi_d_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class mvi_h_opcode : public mvi_opcode
{
public:
    mvi_h_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class mvi_m_opcode : public mvi_opcode
{
public:
    mvi_m_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class mvi_c_opcode : public mvi_opcode
{
public:
    mvi_c_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class mvi_e_opcode : public mvi_opcode
{
public:
    mvi_e_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class mvi_l_opcode : public mvi_opcode
{
public:
    mvi_l_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class mvi_a_opcode : public mvi_opcode
{
public:
    mvi_a_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class sta_opcode : public opcodes
{
public:
    sta_opcode()
        : opcodes(3)
    {}

public:
    void handle_opcode(cpu&);
};

class lxi_opcode : public opcodes
{
protected:
    lxi_opcode()
        : opcodes(3)
    {}
};

class lxi_b_opcode : public lxi_opcode
{
public:
    lxi_b_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class lxi_d_opcode : public lxi_opcode
{
public:
    lxi_d_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class lxi_h_opcode : public lxi_opcode
{
public:
    lxi_h_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class lxi_sp_opcode : public lxi_opcode
{
public:
    lxi_sp_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class dcr_opcode : public opcodes
{
protected:
    dcr_opcode(QString);

protected:
    void dcr(cpu&, uint8_t&);
};

class dcr_b_opcode : public dcr_opcode
{
public:
    dcr_b_opcode();

public:
    void handle_opcode(cpu&);
};

class dcr_c_opcode : public dcr_opcode
{
public:
    dcr_c_opcode();

public:
    void handle_opcode(cpu&);
};

class dcr_d_opcode : public dcr_opcode
{
public:
    dcr_d_opcode();

public:
    void handle_opcode(cpu&);
};

class dcr_e_opcode : public dcr_opcode
{
public:
    dcr_e_opcode();

public:
    void handle_opcode(cpu&);
};

class dcr_h_opcode : public dcr_opcode
{
public:
    dcr_h_opcode();

public:
    void handle_opcode(cpu&);
};

class dcr_l_opcode : public dcr_opcode
{
public:
    dcr_l_opcode();

public:
    void handle_opcode(cpu&);
};

class dcr_m_opcode : public dcr_opcode
{
public:
    dcr_m_opcode();

public:
    void handle_opcode(cpu&);
};

class dcr_a_opcode : public dcr_opcode
{
public:
    dcr_a_opcode();

public:
    void handle_opcode(cpu&);
};

class in_opcode : public opcodes
{
public:
    in_opcode()
        : opcodes(2)
    {}

public:
    void handle_opcode(cpu&);
};



class lda_opcode : public opcodes
{
public:
    lda_opcode()
        : opcodes(3)
    {}

public:
    void handle_opcode(cpu&);
};

class daa_opcode : public opcodes
{
public:
    daa_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};


class ei_opcode : public opcodes
{
public:
    ei_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class di_opcode : public opcodes
{
public:
    di_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};


class shld_opcode : public opcodes
{
public:
    shld_opcode()
        : opcodes(3)
    {}

public:
    void handle_opcode(cpu&);
};


class inr_opcode : public opcodes
{
public:
    inr_opcode(QString);

public:
    void inr(cpu&, uint8_t&);
};

class inr_b_opcode : public inr_opcode
{
public:
    inr_b_opcode();

public:
    void handle_opcode(cpu&);
};

class inr_c_opcode : public inr_opcode
{
public:
    inr_c_opcode();

public:
    void handle_opcode(cpu&);
};

class inr_d_opcode : public inr_opcode
{
public:
    inr_d_opcode();

public:
    void handle_opcode(cpu&);
};

class inr_e_opcode : public inr_opcode
{
public:
    inr_e_opcode();

public:
    void handle_opcode(cpu&);
};

class inr_h_opcode : public inr_opcode
{
public:
    inr_h_opcode();

public:
    void handle_opcode(cpu&);
};

class inr_l_opcode : public inr_opcode
{
public:
    inr_l_opcode();

public:
    void handle_opcode(cpu&);
};

class inr_m_opcode : public inr_opcode
{
public:
    inr_m_opcode();

public:
    void handle_opcode(cpu&);
};

class inr_a_opcode : public inr_opcode
{
public:
    inr_a_opcode();

public:
    void handle_opcode(cpu&);
};





class lhld_opcode : public opcodes
{
public:
    lhld_opcode()
        : opcodes(3)
    {}

public:
    void handle_opcode(cpu&);
};

class ret_opcode : public opcodes
{
public:
    ret_opcode()
        : opcodes(1)
    {}

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
protected:
    sbb_opcode(int instr_size)
        : opcodes(instr_size)
    {}

public:
    void sbb(cpu&, uint8_t);
};

class sbb_b_opcode : public sbb_opcode
{
public:
    sbb_b_opcode()
        : sbb_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sbb_c_opcode : public sbb_opcode
{
public:
    sbb_c_opcode()
        : sbb_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sbb_d_opcode : public sbb_opcode
{
public:
    sbb_d_opcode()
        : sbb_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sbb_e_opcode : public sbb_opcode
{
public:
    sbb_e_opcode()
        : sbb_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sbb_h_opcode : public sbb_opcode
{
public:
    sbb_h_opcode()
        : sbb_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sbb_l_opcode : public sbb_opcode
{
public:
    sbb_l_opcode()
        : sbb_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sbb_m_opcode : public sbb_opcode
{
public:
    sbb_m_opcode()
        : sbb_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sbb_a_opcode : public sbb_opcode
{
public:
    sbb_a_opcode()
        : sbb_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sbi_opcode : public sbb_opcode
{
public:
    sbi_opcode()
        : sbb_opcode(2)
    {}

public:
    void handle_opcode(cpu&);
};

class sub_opcode : public opcodes
{
public:
    sub_opcode(int instr_size)
        : opcodes(instr_size)
    {}

public:
    void sub(cpu&, uint8_t);
};

class sub_b_opcode : public sub_opcode
{
public:
    sub_b_opcode()
        : sub_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sub_c_opcode : public sub_opcode
{
public:
    sub_c_opcode()
        : sub_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sub_d_opcode : public sub_opcode
{
public:
    sub_d_opcode()
        : sub_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sub_e_opcode : public sub_opcode
{
public:
    sub_e_opcode()
        : sub_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sub_h_opcode : public sub_opcode
{
public:
    sub_h_opcode()
        : sub_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sub_l_opcode : public sub_opcode
{
public:
    sub_l_opcode()
        : sub_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sub_m_opcode : public sub_opcode
{
public:
    sub_m_opcode()
        : sub_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sub_a_opcode : public sub_opcode
{
public:
    sub_a_opcode()
        : sub_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class sui_opcode : public sub_opcode
{
public:
    sui_opcode()
        : sub_opcode(2)
    {}

public:
    void handle_opcode(cpu&);
};

class add_opcode : public opcodes
{
public:
    add_opcode(int instr_size)
        : opcodes(instr_size)
    {}

protected:
    void add(cpu&, uint8_t);
};

class adi_opcode : public add_opcode
{
public:
    adi_opcode()
        : add_opcode(2)
    {}

public:
    void handle_opcode(cpu&);
};

class add_b_opcode : public add_opcode
{
public:
    add_b_opcode()
        : add_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class add_c_opcode : public add_opcode
{
public:
    add_c_opcode()
        : add_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class add_d_opcode : public add_opcode
{
public:
    add_d_opcode()
        : add_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class add_e_opcode : public add_opcode
{
public:
    add_e_opcode()
        : add_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class add_h_opcode : public add_opcode
{
public:
    add_h_opcode()
        : add_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class add_l_opcode : public add_opcode
{
public:
    add_l_opcode()
        : add_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class add_m_opcode : public add_opcode
{
public:
    add_m_opcode()
        : add_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class add_a_opcode : public add_opcode
{
public:
    add_a_opcode()
        : add_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class adc_opcode : public opcodes
{
public:
    adc_opcode(int inst_size)
        : opcodes(inst_size)
    {}

public:
    void adc(cpu&, uint8_t);
};

class adc_b_opcode : public adc_opcode
{
public:
    adc_b_opcode()
        : adc_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class adc_c_opcode : public adc_opcode
{
public:
    adc_c_opcode()
        : adc_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class adc_d_opcode : public adc_opcode
{
public:
    adc_d_opcode()
        : adc_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class adc_e_opcode : public adc_opcode
{
public:
    adc_e_opcode()
        : adc_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class adc_h_opcode : public adc_opcode
{
public:
    adc_h_opcode()
        : adc_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class adc_l_opcode : public adc_opcode
{
public:
    adc_l_opcode()
        : adc_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class adc_m_opcode : public adc_opcode
{
public:
    adc_m_opcode()
        : adc_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class adc_a_opcode : public adc_opcode
{
public:
    adc_a_opcode()
        : adc_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class aci_opcode : public adc_opcode
{
public:
    aci_opcode()
        : adc_opcode(2)
    {}

public:
    void handle_opcode(cpu&);
};

class ana_opcode : public opcodes
{
public:
    ana_opcode(int instr_size)
        : opcodes(instr_size)
    {}

public:
    void ana(cpu&, uint8_t);
};

class ana_b_opcode : public ana_opcode
{
public:
    ana_b_opcode()
        : ana_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ana_c_opcode : public ana_opcode
{
public:
    ana_c_opcode()
        : ana_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ana_d_opcode : public ana_opcode
{
public:
    ana_d_opcode()
        : ana_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ana_e_opcode : public ana_opcode
{
public:
    ana_e_opcode()
        : ana_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ana_h_opcode : public ana_opcode
{
public:
    ana_h_opcode()
        : ana_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ana_l_opcode : public ana_opcode
{
public:
    ana_l_opcode()
        : ana_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ana_m_opcode : public ana_opcode
{
public:
    ana_m_opcode()
        : ana_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ana_a_opcode : public ana_opcode
{
public:
    ana_a_opcode()
        : ana_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ani_opcode : public ana_opcode
{
public:
    ani_opcode()
        : ana_opcode(2)
    {}

public:
    void handle_opcode(cpu&);
};

class xra_opcode : public opcodes
{
public:
    xra_opcode(int instr_size)
        : opcodes(instr_size)
    {}

public:
    void xra(cpu&, uint8_t);
};

class xra_b_opcode : public xra_opcode
{
public:
    xra_b_opcode()
        : xra_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class xra_c_opcode : public xra_opcode
{
public:
    xra_c_opcode()
        : xra_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class xra_d_opcode : public xra_opcode
{
public:
    xra_d_opcode()
        : xra_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class xra_e_opcode : public xra_opcode
{
public:
    xra_e_opcode()
        : xra_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class xra_h_opcode : public xra_opcode
{
public:
    xra_h_opcode()
        : xra_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class xra_l_opcode : public xra_opcode
{
public:
    xra_l_opcode()
        : xra_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class xra_m_opcode : public xra_opcode
{
public:
    xra_m_opcode()
        : xra_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class xra_a_opcode : public xra_opcode
{
public:
    xra_a_opcode()
        : xra_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class xri_opcode : public xra_opcode
{
public:
    xri_opcode()
        : xra_opcode(2)
    {}

public:
    void handle_opcode(cpu&);
};

class ora_opcode : public opcodes
{
public:
    ora_opcode(int instr_size)
        : opcodes(instr_size)
    {}

public:
    void ora(cpu&, uint8_t);
};

class ora_b_opcode : public ora_opcode
{
public:
    ora_b_opcode()
        : ora_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ora_c_opcode : public ora_opcode
{
public:
    ora_c_opcode()
        : ora_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ora_d_opcode : public ora_opcode
{
public:
    ora_d_opcode()
        : ora_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ora_e_opcode : public ora_opcode
{
public:
    ora_e_opcode()
        : ora_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ora_h_opcode : public ora_opcode
{
public:
    ora_h_opcode()
        : ora_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ora_l_opcode : public ora_opcode
{
public:
    ora_l_opcode()
        : ora_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ora_m_opcode : public ora_opcode
{
public:
    ora_m_opcode()
        : ora_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ora_a_opcode : public ora_opcode
{
public:
    ora_a_opcode()
        : ora_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class ori_opcode : public ora_opcode
{
public:
    ori_opcode()
        : ora_opcode(2)
    {}

public:
    void handle_opcode(cpu&);
};

class cmp_opcode : public opcodes
{
public:
    cmp_opcode(int instr_size)
        : opcodes(instr_size)
    {}

public:
    void cmp(cpu&, uint8_t);
};

class cmp_b_opcode : public cmp_opcode
{
public:
    cmp_b_opcode()
        : cmp_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class cmp_c_opcode : public cmp_opcode
{
public:
    cmp_c_opcode()
        : cmp_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class cmp_d_opcode : public cmp_opcode
{
public:
    cmp_d_opcode()
        : cmp_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class cmp_e_opcode : public cmp_opcode
{
public:
    cmp_e_opcode()
        : cmp_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class cmp_h_opcode : public cmp_opcode
{
public:
    cmp_h_opcode()
        : cmp_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class cmp_l_opcode : public cmp_opcode
{
public:
    cmp_l_opcode()
        : cmp_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class cmp_m_opcode : public cmp_opcode
{
public:
    cmp_m_opcode()
        : cmp_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class cmp_a_opcode : public cmp_opcode
{
public:
    cmp_a_opcode()
        : cmp_opcode(1)
    {}

public:
    void handle_opcode(cpu&);
};

class cpi_opcode : public cmp_opcode
{
public:
    cpi_opcode()
        : cmp_opcode(2)
    {}

public:
    void handle_opcode(cpu&);
};


class pchl_opcode : public opcodes
{
public:
    pchl_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class out_opcode : public opcodes
{
public:
    out_opcode()
        : opcodes(2)
    {}

public:
    void handle_opcode(cpu&);
};

class stc_opcode : public opcodes
{
public:
    stc_opcode();

public:
    void handle_opcode(cpu&);
};

class stax_opcode : public opcodes
{
public:
    stax_opcode()
        : opcodes(1)
    {}

protected:
    void store_acc_to_mem(cpu&, uint8_t, uint8_t);

};

class stax_b_opcode : public stax_opcode
{
public:
    stax_b_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class stax_d_opcode : public stax_opcode
{
public:
    stax_d_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class ldax_opcode : public opcodes
{
public:
    ldax_opcode()
        : opcodes(1)
    {}

protected:
    void retrieve_acc_from_mem(cpu&, uint8_t, uint8_t);
};

class ldax_b_opcode : public ldax_opcode
{
public:
    ldax_b_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class ldax_d_opcode : public ldax_opcode
{
public:
    ldax_d_opcode()
    {}

public:
    void handle_opcode(cpu&);
};

class cma_opcode : public opcodes
{
public:
    cma_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class rst0_opcode : public opcodes
{
public:
    rst0_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class rst1_opcode : public opcodes
{
public:
    rst1_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class rst2_opcode : public opcodes
{
public:
    rst2_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class rst3_opcode : public opcodes
{
public:
    rst3_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class rst4_opcode : public opcodes
{
public:
    rst4_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class rst5_opcode : public opcodes
{
public:
    rst5_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class rst6_opcode : public opcodes
{
public:
    rst6_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class rst7_opcode : public opcodes
{
public:
    rst7_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};


class cmc_opcode : public opcodes
{
public:
    cmc_opcode();

public:
    void handle_opcode(cpu&);
};

class hlt_opcode : public opcodes
{
public:
    hlt_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};


class mov_opcode : public opcodes
{
public:
    mov_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_bb_opcode : public opcodes
{
public:
    mov_bb_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_bc_opcode : public opcodes
{
public:
    mov_bc_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_bd_opcode : public opcodes
{
public:
    mov_bd_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_be_opcode : public opcodes
{
public:
    mov_be_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_bh_opcode : public opcodes
{
public:
    mov_bh_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_bl_opcode : public opcodes
{
public:
    mov_bl_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_bm_opcode : public opcodes
{
public:
    mov_bm_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ba_opcode : public opcodes
{
public:
    mov_ba_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_cb_opcode : public opcodes
{
public:
    mov_cb_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_cc_opcode : public opcodes
{
public:
    mov_cc_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_cd_opcode : public opcodes
{
public:
    mov_cd_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ce_opcode : public opcodes
{
public:
    mov_ce_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ch_opcode : public opcodes
{
public:
    mov_ch_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_cl_opcode : public opcodes
{
public:
    mov_cl_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_cm_opcode : public opcodes
{
public:
    mov_cm_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ca_opcode : public opcodes
{
public:
    mov_ca_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_db_opcode : public opcodes
{
public:
    mov_db_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_dc_opcode : public opcodes
{
public:
    mov_dc_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_dd_opcode : public opcodes
{
public:
    mov_dd_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_de_opcode : public opcodes
{
public:
    mov_de_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_dh_opcode : public opcodes
{
public:
    mov_dh_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_dl_opcode : public opcodes
{
public:
    mov_dl_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_dm_opcode : public opcodes
{
public:
    mov_dm_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_da_opcode : public opcodes
{
public:
    mov_da_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_eb_opcode : public opcodes
{
public:
    mov_eb_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ec_opcode : public opcodes
{
public:
    mov_ec_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ed_opcode : public opcodes
{
public:
    mov_ed_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ee_opcode : public opcodes
{
public:
    mov_ee_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_eh_opcode : public opcodes
{
public:
    mov_eh_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_el_opcode : public opcodes
{
public:
    mov_el_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_em_opcode : public opcodes
{
public:
    mov_em_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ea_opcode : public opcodes
{
public:
    mov_ea_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_hb_opcode : public opcodes
{
public:
    mov_hb_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_hc_opcode : public opcodes
{
public:
    mov_hc_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_hd_opcode : public opcodes
{
public:
    mov_hd_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_he_opcode : public opcodes
{
public:
    mov_he_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_hh_opcode : public opcodes
{
public:
    mov_hh_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_hl_opcode : public opcodes
{
public:
    mov_hl_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_hm_opcode : public opcodes
{
public:
    mov_hm_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ha_opcode : public opcodes
{
public:
    mov_ha_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_lb_opcode : public opcodes
{
public:
    mov_lb_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_lc_opcode : public opcodes
{
public:
    mov_lc_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ld_opcode : public opcodes
{
public:
    mov_ld_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_le_opcode : public opcodes
{
public:
    mov_le_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_lh_opcode : public opcodes
{
public:
    mov_lh_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ll_opcode : public opcodes
{
public:
    mov_ll_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_lm_opcode : public opcodes
{
public:
    mov_lm_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_la_opcode : public opcodes
{
public:
    mov_la_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_mb_opcode : public opcodes
{
public:
    mov_mb_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_mc_opcode : public opcodes
{
public:
    mov_mc_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_md_opcode : public opcodes
{
public:
    mov_md_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_me_opcode : public opcodes
{
public:
    mov_me_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_mh_opcode : public opcodes
{
public:
    mov_mh_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ml_opcode : public opcodes
{
public:
    mov_ml_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ma_opcode : public opcodes
{
public:
    mov_ma_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};


class mov_ab_opcode : public opcodes
{
public:
    mov_ab_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ac_opcode : public opcodes
{
public:
    mov_ac_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ad_opcode : public opcodes
{
public:
    mov_ad_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ae_opcode : public opcodes
{
public:
    mov_ae_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_ah_opcode : public opcodes
{
public:
    mov_ah_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_al_opcode : public opcodes
{
public:
    mov_al_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_am_opcode : public opcodes
{
public:
    mov_am_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

class mov_aa_opcode : public opcodes
{
public:
    mov_aa_opcode()
        : opcodes(1)
    {}

public:
    void handle_opcode(cpu&);
};

#endif // OPCODES_H
