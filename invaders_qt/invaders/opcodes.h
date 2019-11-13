#ifndef OPCODES_H
#define OPCODES_H

#include <QByteArray>
#include <QString>
// #include "cpu_core.h"

class cpu;
class cpu_debug;
class cpu_core;
class cpu_memory;
class cpu_core_status_flags;

class opcodes
{
protected:
    opcodes(uint8_t instr_size);
    opcodes(uint8_t _opcode_size, uint8_t _cycle_steps, uint8_t _max_cycle_steps, QString _cmd_string);

public:
    virtual void handle_opcode(cpu&);

public:
    void store_pre_debug_data(cpu&, cpu_debug&);
    void store_post_debug_data(cpu&, cpu_debug&);

private:
    QString convert_opcode_to_assembly(cpu&, uint16_t);

protected:
    uint8_t instr_size() const {
        return size;
    }

private:
    uint8_t size;
    uint8_t cycle_steps;
    uint8_t max_cycle_steps;
    QString assembly_command;

};



// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------





















#endif // OPCODES_H
