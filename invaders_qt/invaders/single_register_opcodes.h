#ifndef SINGLE_REGISTER_OPCODES_H
#define SINGLE_REGISTER_OPCODES_H

#include "opcodes.h"

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

class daa_opcode : public opcodes
{
public:
    daa_opcode();

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


class cma_opcode : public opcodes
{
public:
    cma_opcode();

public:
    void handle_opcode(cpu&);
};


#endif // SINGLE_REGISTER_OPCODES_H
