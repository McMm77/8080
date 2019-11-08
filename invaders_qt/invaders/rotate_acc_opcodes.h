#ifndef ROTATE_ACC_OPCODES_H
#define ROTATE_ACC_OPCODES_H

#include "opcodes.h"

class ral_opcode : public opcodes
{
public:
    ral_opcode();

public:
    void handle_opcode(cpu&);
};

class rrc_opcode : public opcodes
{
public:
    rrc_opcode();

public:
    void handle_opcode(cpu&);
};


class rlc_opcode : public opcodes
{
public:
    rlc_opcode();

public:
    void handle_opcode(cpu&);
};

class rar_opcode : public opcodes
{
public:
    rar_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // ROTATE_ACC_OPCODES_H
