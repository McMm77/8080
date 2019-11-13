#ifndef CARRY_BIT_OPCODE_H
#define CARRY_BIT_OPCODE_H

#include "opcodes.h"

class stc_opcode : public opcodes
{
public:
    stc_opcode();

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

#endif // CARRY_BIT_OPCODE_H
