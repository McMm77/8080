#ifndef RET_OPCODE_H
#define RET_OPCODE_H

#include "opcodes.h"

class ret_opcode : public opcodes
{
public:
    ret_opcode();

protected:
    ret_opcode(QString);

public:
    void handle_opcode(cpu&);
};

class rz_opcode : public ret_opcode
{
public:
    rz_opcode();

public:
    void handle_opcode(cpu&);
};

class rnz_opcode : public ret_opcode
{
public:
    rnz_opcode();

public:
    void handle_opcode(cpu&);
};

class rp_opcode : public ret_opcode
{
public:
    rp_opcode();

public:
    void handle_opcode(cpu&);
};

class rm_opcode : public ret_opcode
{
public:
    rm_opcode();

public:
    void handle_opcode(cpu&);
};

class rpo_opcode : public ret_opcode
{
public:
    rpo_opcode();

public:
    void handle_opcode(cpu&);
};

class rpe_opcode : public ret_opcode
{
public:
    rpe_opcode();

public:
    void handle_opcode(cpu&);
};

class rnc_opcode : public ret_opcode
{
public:
    rnc_opcode();

public:
    void handle_opcode(cpu&);
};

class rc_opcode : public ret_opcode
{
public:
    rc_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // RET_OPCODE_H
