#ifndef IO_OPCODE_H
#define IO_OPCODE_H

#include "opcodes.h"

class in_opcode : public opcodes
{
public:
    in_opcode();

public:
    void handle_opcode(cpu&);
};

class out_opcode : public opcodes
{
public:
    out_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // IO_OPCODE_H
