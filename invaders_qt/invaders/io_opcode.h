#ifndef IO_OPCODE_H
#define IO_OPCODE_H

#include "opcodes.h"

class invaders;

class in_opcode : public opcodes
{
public:
    in_opcode(invaders&);

public:
    void handle_opcode(cpu&);

private:
    invaders& hardware;
};

class out_opcode : public opcodes
{
public:
    out_opcode(invaders&);

public:
    void handle_opcode(cpu&);

private:
    invaders& hardware;
};

#endif // IO_OPCODE_H
