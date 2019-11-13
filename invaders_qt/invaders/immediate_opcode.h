#ifndef IMMEDIATE_OPCODE_H
#define IMMEDIATE_OPCODE_H

#include "opcodes.h"
#include "acc_instructions.h"

class mvi_opcode : public opcodes
{
protected:
    mvi_opcode(QString, int);
};

class mvi_b_opcode : public mvi_opcode
{
public:
    mvi_b_opcode();

public:
    void handle_opcode(cpu&);
};

class mvi_d_opcode : public mvi_opcode
{
public:
    mvi_d_opcode();

public:
    void handle_opcode(cpu&);
};

class mvi_h_opcode : public mvi_opcode
{
public:
    mvi_h_opcode();

public:
    void handle_opcode(cpu&);
};

class mvi_m_opcode : public mvi_opcode
{
public:
    mvi_m_opcode();

public:
    void handle_opcode(cpu&);
};

class mvi_c_opcode : public mvi_opcode
{
public:
    mvi_c_opcode();

public:
    void handle_opcode(cpu&);
};

class mvi_e_opcode : public mvi_opcode
{
public:
    mvi_e_opcode();

public:
    void handle_opcode(cpu&);
};

class mvi_l_opcode : public mvi_opcode
{
public:
    mvi_l_opcode();

public:
    void handle_opcode(cpu&);
};

class mvi_a_opcode : public mvi_opcode
{
public:
    mvi_a_opcode();

public:
    void handle_opcode(cpu&);
};

class lxi_opcode : public opcodes
{
protected:
    lxi_opcode(QString);
};

class lxi_b_opcode : public lxi_opcode
{
public:
    lxi_b_opcode();

public:
    void handle_opcode(cpu&);
};

class lxi_d_opcode : public lxi_opcode
{
public:
    lxi_d_opcode();

public:
    void handle_opcode(cpu&);
};

class lxi_h_opcode : public lxi_opcode
{
public:
    lxi_h_opcode();

public:
    void handle_opcode(cpu&);
};

class lxi_sp_opcode : public lxi_opcode
{
public:
    lxi_sp_opcode();

public:
    void handle_opcode(cpu&);
};


class adi_opcode : public opcodes, public add_instr
{
public:
    adi_opcode();

public:
    void handle_opcode(cpu&);
};

class sbi_opcode : public opcodes, public sbb_instr
{
public:
    sbi_opcode();

public:
    void handle_opcode(cpu&);
};

class sui_opcode : public opcodes, public sub_instr
{
public:
    sui_opcode();

public:
    void handle_opcode(cpu&);
};

class aci_opcode : public opcodes, public adc_instr
{
public:
    aci_opcode();

public:
    void handle_opcode(cpu&);
};

class ani_opcode : public opcodes, public ana_instr
{
public:
    ani_opcode();

public:
    void handle_opcode(cpu&);
};

class xri_opcode : public opcodes, public xra_instr
{
public:
    xri_opcode();

public:
    void handle_opcode(cpu&);
};

class ori_opcode : public opcodes, public ora_instr
{
public:
    ori_opcode();

public:
    void handle_opcode(cpu&);
};

class cpi_opcode : public opcodes, public cmp_instr
{
public:
    cpi_opcode();

public:
    void handle_opcode(cpu&);
};




#endif // IMMEDIATE_OPCODE_H
