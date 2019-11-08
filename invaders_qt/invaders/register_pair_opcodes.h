#ifndef REGISTER_PAIR_OPCODES_H
#define REGISTER_PAIR_OPCODES_H

#include "opcodes.h"

class inx_opcode : public opcodes
{
protected:
    inx_opcode(QString);

protected:
    void inx(uint8_t&, uint8_t&);
};
\
class inx_b_opcode : public inx_opcode
{
public:
    inx_b_opcode();

public:
    void handle_opcode(cpu&);
};

class inx_d_opcode : public inx_opcode
{
public:
    inx_d_opcode();

public:
    void handle_opcode(cpu&);
};

class inx_h_opcode : public inx_opcode
{
public:
    inx_h_opcode();

public:
    void handle_opcode(cpu&);
};

class inx_sp_opcode : public inx_opcode
{
public:
    inx_sp_opcode();

public:
    void handle_opcode(cpu&);
};


class dcx_opcode : public opcodes
{
public:
    dcx_opcode(QString);

public:
    void dcx(uint8_t&, uint8_t&);
};

class dcx_b_opcode : public dcx_opcode
{
public:
    dcx_b_opcode();

public:
    void handle_opcode(cpu&);
};

class dcx_d_opcode : public dcx_opcode
{
public:
    dcx_d_opcode();

public:
    void handle_opcode(cpu&);
};

class dcx_h_opcode : public dcx_opcode
{
public:
    dcx_h_opcode();

public:
    void handle_opcode(cpu&);
};

class dcx_sp_opcode : public dcx_opcode
{
public:
    dcx_sp_opcode();

public:
    void handle_opcode(cpu&);
};

class pop_opcode : public opcodes
{
protected:
    pop_opcode(QString);
};

class pop_b_opcode : public pop_opcode
{
public:
    pop_b_opcode();

public:
    void handle_opcode(cpu&);
};

class pop_d_opcode : public pop_opcode
{
public:
    pop_d_opcode();

public:
    void handle_opcode(cpu&);
};

class pop_h_opcode : public pop_opcode
{
public:
    pop_h_opcode();

public:
    void handle_opcode(cpu&);
};

class pop_psw_opcode : public pop_opcode
{
public:
    pop_psw_opcode();

public:
    void handle_opcode(cpu&);
};

class push_opcode : public opcodes
{
protected:
    push_opcode(QString);

};

class push_b_opcode : public push_opcode
{
public:
    push_b_opcode();

public:
    void handle_opcode(cpu&);
};

class push_d_opcode : public push_opcode
{
public:
    push_d_opcode();

public:
    void handle_opcode(cpu&);
};

class push_h_opcode : public push_opcode
{
public:
    push_h_opcode();

public:
    void handle_opcode(cpu&);
};

class push_psw_opcode : public push_opcode
{
public:
    push_psw_opcode();

public:
    void handle_opcode(cpu&);
};

class dad_opcode : public opcodes
{
protected:
    dad_opcode(QString);
};

class dad_b_opcode : public dad_opcode
{
public:
    dad_b_opcode();

public:
    void handle_opcode(cpu&);
};

class dad_d_opcode : public dad_opcode
{
public:
    dad_d_opcode();

public:
    void handle_opcode(cpu&);
};

class dad_h_opcode : public dad_opcode
{
public:
    dad_h_opcode();

public:
    void handle_opcode(cpu&);
};

class dad_sp_opcode : public dad_opcode
{
public:
    dad_sp_opcode();

public:
    void handle_opcode(cpu&);
};

class xchg_opcode : public opcodes
{
public:
    xchg_opcode();

public:
    void handle_opcode(cpu&);
};

class xthl_opcode : public opcodes
{
public:
    xthl_opcode();

public:
    void handle_opcode(cpu&);
};

class sphl_opcode : public opcodes
{
public:
    sphl_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // REGISTER_PAIR_OPCODES_H
