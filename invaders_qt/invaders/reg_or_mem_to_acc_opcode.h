#ifndef REG_OR_MEM_TO_ACC_OPCODE_H
#define REG_OR_MEM_TO_ACC_OPCODE_H

#include "opcodes.h"
#include "acc_instructions.h"

class add_opcode : public opcodes, public add_instr
{
protected:
    add_opcode(QString, int);
};

class add_b_opcode : public add_opcode
{
public:
    add_b_opcode();

public:
    void handle_opcode(cpu&);
};

class add_c_opcode : public add_opcode
{
public:
    add_c_opcode();

public:
    void handle_opcode(cpu&);
};

class add_d_opcode : public add_opcode
{
public:
    add_d_opcode();

public:
    void handle_opcode(cpu&);
};

class add_e_opcode : public add_opcode
{
public:
    add_e_opcode();

public:
    void handle_opcode(cpu&);
};

class add_h_opcode : public add_opcode
{
public:
    add_h_opcode();

public:
    void handle_opcode(cpu&);
};

class add_l_opcode : public add_opcode
{
public:
    add_l_opcode();

public:
    void handle_opcode(cpu&);
};

class add_m_opcode : public add_opcode
{
public:
    add_m_opcode();

public:
    void handle_opcode(cpu&);
};

class add_a_opcode : public add_opcode
{
public:
    add_a_opcode();

public:
    void handle_opcode(cpu&);
};

class adc_opcode : public opcodes, public adc_instr
{
protected:
    adc_opcode(QString, int);
};


class adc_b_opcode : public adc_opcode
{
public:
    adc_b_opcode();

public:
    void handle_opcode(cpu&);
};

class adc_c_opcode : public adc_opcode
{
public:
    adc_c_opcode();

public:
    void handle_opcode(cpu&);
};

class adc_d_opcode : public adc_opcode
{
public:
    adc_d_opcode();

public:
    void handle_opcode(cpu&);
};

class adc_e_opcode : public adc_opcode
{
public:
    adc_e_opcode();

public:
    void handle_opcode(cpu&);
};

class adc_h_opcode : public adc_opcode
{
public:
    adc_h_opcode();

public:
    void handle_opcode(cpu&);
};

class adc_l_opcode : public adc_opcode
{
public:
    adc_l_opcode();

public:
    void handle_opcode(cpu&);
};

class adc_m_opcode : public adc_opcode
{
public:
    adc_m_opcode();

public:
    void handle_opcode(cpu&);
};

class adc_a_opcode : public adc_opcode
{
public:
    adc_a_opcode();

public:
    void handle_opcode(cpu&);
};

class sbb_opcode : public opcodes, public sbb_instr
{
protected:
    sbb_opcode(QString, int);
};

class sbb_b_opcode : public sbb_opcode
{
public:
    sbb_b_opcode();

public:
    void handle_opcode(cpu&);
};

class sbb_c_opcode : public sbb_opcode
{
public:
    sbb_c_opcode();

public:
    void handle_opcode(cpu&);
};

class sbb_d_opcode : public sbb_opcode
{
public:
    sbb_d_opcode();

public:
    void handle_opcode(cpu&);
};

class sbb_e_opcode : public sbb_opcode
{
public:
    sbb_e_opcode();

public:
    void handle_opcode(cpu&);
};

class sbb_h_opcode : public sbb_opcode
{
public:
    sbb_h_opcode();

public:
    void handle_opcode(cpu&);
};

class sbb_l_opcode : public sbb_opcode
{
public:
    sbb_l_opcode();

public:
    void handle_opcode(cpu&);
};

class sbb_m_opcode : public sbb_opcode
{
public:
    sbb_m_opcode();

public:
    void handle_opcode(cpu&);
};

class sbb_a_opcode : public sbb_opcode
{
public:
    sbb_a_opcode();

public:
    void handle_opcode(cpu&);
};

class sub_opcode : public opcodes, public sub_instr
{
protected:
    sub_opcode(QString, int);
};

class sub_b_opcode : public sub_opcode
{
public:
    sub_b_opcode();

public:
    void handle_opcode(cpu&);
};

class sub_c_opcode : public sub_opcode
{
public:
    sub_c_opcode();

public:
    void handle_opcode(cpu&);
};

class sub_d_opcode : public sub_opcode
{
public:
    sub_d_opcode();

public:
    void handle_opcode(cpu&);
};

class sub_e_opcode : public sub_opcode
{
public:
    sub_e_opcode();

public:
    void handle_opcode(cpu&);
};

class sub_h_opcode : public sub_opcode
{
public:
    sub_h_opcode();

public:
    void handle_opcode(cpu&);
};

class sub_l_opcode : public sub_opcode
{
public:
    sub_l_opcode();

public:
    void handle_opcode(cpu&);
};

class sub_m_opcode : public sub_opcode
{
public:
    sub_m_opcode();

public:
    void handle_opcode(cpu&);
};

class sub_a_opcode : public sub_opcode
{
public:
    sub_a_opcode();

public:
    void handle_opcode(cpu&);
};

class ana_opcode : public opcodes, public ana_instr
{
protected:
    ana_opcode(QString, int);
};

class ana_b_opcode : public ana_opcode
{
public:
    ana_b_opcode();
public:
    void handle_opcode(cpu&);
};

class ana_c_opcode : public ana_opcode
{
public:
    ana_c_opcode();

public:
    void handle_opcode(cpu&);
};

class ana_d_opcode : public ana_opcode
{
public:
    ana_d_opcode();

public:
    void handle_opcode(cpu&);
};

class ana_e_opcode : public ana_opcode
{
public:
    ana_e_opcode();

public:
    void handle_opcode(cpu&);
};

class ana_h_opcode : public ana_opcode
{
public:
    ana_h_opcode();

public:
    void handle_opcode(cpu&);
};

class ana_l_opcode : public ana_opcode
{
public:
    ana_l_opcode();

public:
    void handle_opcode(cpu&);
};

class ana_m_opcode : public ana_opcode
{
public:
    ana_m_opcode();

public:
    void handle_opcode(cpu&);
};

class ana_a_opcode : public ana_opcode
{
public:
    ana_a_opcode();

public:
    void handle_opcode(cpu&);
};

class xra_opcode : public opcodes, public xra_instr
{
protected:
    xra_opcode(QString, int);
};

class xra_b_opcode : public xra_opcode
{
public:
    xra_b_opcode();

public:
    void handle_opcode(cpu&);
};

class xra_c_opcode : public xra_opcode
{
public:
    xra_c_opcode();

public:
    void handle_opcode(cpu&);
};

class xra_d_opcode : public xra_opcode
{
public:
    xra_d_opcode();

public:
    void handle_opcode(cpu&);
};

class xra_e_opcode : public xra_opcode
{
public:
    xra_e_opcode();

public:
    void handle_opcode(cpu&);
};

class xra_h_opcode : public xra_opcode
{
public:
    xra_h_opcode();

public:
    void handle_opcode(cpu&);
};

class xra_l_opcode : public xra_opcode
{
public:
    xra_l_opcode();

public:
    void handle_opcode(cpu&);
};

class xra_m_opcode : public xra_opcode
{
public:
    xra_m_opcode();

public:
    void handle_opcode(cpu&);
};

class xra_a_opcode : public xra_opcode
{
public:
    xra_a_opcode();

public:
    void handle_opcode(cpu&);
};


class ora_opcode : public opcodes, public ora_instr
{
protected:
    ora_opcode(QString, int);
};

class ora_b_opcode : public ora_opcode
{
public:
    ora_b_opcode();

public:
    void handle_opcode(cpu&);
};

class ora_c_opcode : public ora_opcode
{
public:
    ora_c_opcode();

public:
    void handle_opcode(cpu&);
};

class ora_d_opcode : public ora_opcode
{
public:
    ora_d_opcode();

public:
    void handle_opcode(cpu&);
};

class ora_e_opcode : public ora_opcode
{
public:
    ora_e_opcode();

public:
    void handle_opcode(cpu&);
};

class ora_h_opcode : public ora_opcode
{
public:
    ora_h_opcode();

public:
    void handle_opcode(cpu&);
};

class ora_l_opcode : public ora_opcode
{
public:
    ora_l_opcode();

public:
    void handle_opcode(cpu&);
};

class ora_m_opcode : public ora_opcode
{
public:
    ora_m_opcode();

public:
    void handle_opcode(cpu&);
};

class ora_a_opcode : public ora_opcode
{
public:
    ora_a_opcode();

public:
    void handle_opcode(cpu&);
};


class cmp_opcode : public opcodes, public cmp_instr
{
protected:
    cmp_opcode(QString, int);
};

class cmp_b_opcode : public cmp_opcode
{
public:
    cmp_b_opcode();

public:
    void handle_opcode(cpu&);
};

class cmp_c_opcode : public cmp_opcode
{
public:
    cmp_c_opcode();

public:
    void handle_opcode(cpu&);
};

class cmp_d_opcode : public cmp_opcode
{
public:
    cmp_d_opcode();

public:
    void handle_opcode(cpu&);
};

class cmp_e_opcode : public cmp_opcode
{
public:
    cmp_e_opcode();

public:
    void handle_opcode(cpu&);
};

class cmp_h_opcode : public cmp_opcode
{
public:
    cmp_h_opcode();

public:
    void handle_opcode(cpu&);
};

class cmp_l_opcode : public cmp_opcode
{
public:
    cmp_l_opcode();

public:
    void handle_opcode(cpu&);
};

class cmp_m_opcode : public cmp_opcode
{
public:
    cmp_m_opcode();

public:
    void handle_opcode(cpu&);
};

class cmp_a_opcode : public cmp_opcode
{
public:
    cmp_a_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // REG_OR_MEM_TO_ACC_OPCODE_H
