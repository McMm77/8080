#ifndef HLT_OPCODE_H
#define HLT_OPCODE_H

#include "opcodes.h"

class hlt_opcode : public opcodes
{
public:
    hlt_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // HLT_OPCODE_H
