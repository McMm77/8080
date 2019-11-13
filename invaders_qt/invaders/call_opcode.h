#ifndef CALL_OPCODE_H
#define CALL_OPCODE_H

#include "opcodes.h"

class call_opcode : public opcodes
{
public:
    call_opcode();

protected:
    call_opcode(QString);

public:
    void handle_opcode(cpu&);
};

class cz_opcode : public call_opcode
{
public:
    cz_opcode();

public:
    void handle_opcode(cpu&);
};

class cnz_opcode : public call_opcode
{
public:
    cnz_opcode();

public:
    void handle_opcode(cpu&);
};

class cnc_opcode : public call_opcode
{
public:
    cnc_opcode();

public:
    void handle_opcode(cpu&);
};

class cc_opcode : public call_opcode
{
public:
    cc_opcode();

public:
    void handle_opcode(cpu&);
};

class cm_opcode : public call_opcode
{
public:
    cm_opcode();

public:
    void handle_opcode(cpu&);
};

class cp_opcode : public call_opcode
{
public:
    cp_opcode();

public:
    void handle_opcode(cpu&);
};

class cpo_opcode : public call_opcode
{
public:
    cpo_opcode();

public:
    void handle_opcode(cpu&);
};

class cpe_opcode : public call_opcode
{
public:
    cpe_opcode();

public:
    void handle_opcode(cpu&);
};


#endif // CALL_OPCODE_H
