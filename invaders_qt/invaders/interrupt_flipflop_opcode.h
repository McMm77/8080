#ifndef INTERRUPT_FLIPFLOP_OPCODE_H
#define INTERRUPT_FLIPFLOP_OPCODE_H

#include "opcodes.h"

class ei_opcode : public opcodes
{
public:
    ei_opcode();

public:
    void handle_opcode(cpu&);
};

class di_opcode : public opcodes
{
public:
    di_opcode();

public:
    void handle_opcode(cpu&);
};


#endif // INTERRUPT_FLIPFLOP_OPCODE_H
