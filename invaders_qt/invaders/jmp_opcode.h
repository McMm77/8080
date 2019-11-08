#ifndef JMP_OPCODE_H
#define JMP_OPCODE_H

#include "opcodes.h"

class jmp_opcode : public opcodes
{
public:
    jmp_opcode();

protected:
    jmp_opcode(QString);

public:
    void handle_opcode(cpu&);
};

class jpo_opcode : public jmp_opcode
{
public:
    jpo_opcode();

public:
    void handle_opcode(cpu&);
};

class jpe_opcode : public jmp_opcode
{
public:
    jpe_opcode();

public:
    void handle_opcode(cpu&);
};

class jz_opcode : public jmp_opcode
{
public:
    jz_opcode();

public:
    void handle_opcode(cpu&);
};

class jnz_opcode : public jmp_opcode
{
public:
    jnz_opcode();

public:
    void handle_opcode(cpu&);
};

class jc_opcode : public jmp_opcode
{
public:
    jc_opcode();

public:
    void handle_opcode(cpu&);
};

class jnc_opcode : public jmp_opcode
{
public:
    jnc_opcode();

public:
    void handle_opcode(cpu&);
};

class jp_opcode : public jmp_opcode
{
public:
    jp_opcode();

public:
    void handle_opcode(cpu&);
};

class jm_opcode : public jmp_opcode
{
public:
    jm_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // JMP_OPCODE_H
