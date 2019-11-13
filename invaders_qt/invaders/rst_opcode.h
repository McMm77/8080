#ifndef RST_OPCODE_H
#define RST_OPCODE_H

#include "opcodes.h"

class rst_opcode : public opcodes
{
protected:
    rst_opcode(QString);
};

class rst0_opcode : public rst_opcode
{
public:
    rst0_opcode();

public:
    void handle_opcode(cpu&);
};

class rst1_opcode : public rst_opcode
{
public:
    rst1_opcode();

public:
    void handle_opcode(cpu&);
};

class rst2_opcode : public rst_opcode
{
public:
    rst2_opcode();

public:
    void handle_opcode(cpu&);
};

class rst3_opcode : public rst_opcode
{
public:
    rst3_opcode();

public:
    void handle_opcode(cpu&);
};

class rst4_opcode : public rst_opcode
{
public:
    rst4_opcode();

public:
    void handle_opcode(cpu&);
};

class rst5_opcode : public rst_opcode
{
public:
    rst5_opcode();

public:
    void handle_opcode(cpu&);
};

class rst6_opcode : public rst_opcode
{
public:
    rst6_opcode();

public:
    void handle_opcode(cpu&);
};

class rst7_opcode : public rst_opcode
{
public:
    rst7_opcode();

public:
    void handle_opcode(cpu&);
};

#endif // RST_OPCODE_H
