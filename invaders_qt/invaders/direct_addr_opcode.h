#ifndef DIRECT_ADDR_OPCODE_H
#define DIRECT_ADDR_OPCODE_H

#include "opcodes.h"

class sta_opcode : public opcodes
{
public:
    sta_opcode();

public:
    void handle_opcode(cpu&);
};

class lda_opcode : public opcodes
{
public:
    lda_opcode();

public:
    void handle_opcode(cpu&);
};

class shld_opcode : public opcodes
{
public:
    shld_opcode();

public:
    void handle_opcode(cpu&);
};

class lhld_opcode : public opcodes
{
public:
    lhld_opcode();

public:
    void handle_opcode(cpu&);
};


#endif // DIRECT_ADDR_OPCODE_H
