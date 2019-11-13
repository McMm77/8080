#ifndef NOP_OPCODE_H
#define NOP_OPCODE_H

#include "opcodes.h"

class nop_opcode : public opcodes
{
public:
    nop_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // NOP_OPCODE_H
