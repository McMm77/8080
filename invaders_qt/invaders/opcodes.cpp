#include <QString>
#include "opcodes.h"
#include "cpu_core.h"

opcodes::opcodes(uint8_t instr_size)
    : size(instr_size)
{}

opcodes::opcodes(uint8_t _opcode_size, uint8_t _cycle_steps, uint8_t _max_cycle_steps, QString _cmd_string)
    : size(_opcode_size),
      cycle_steps(cycle_steps),
      max_cycle_steps(_max_cycle_steps),
      assembly_command(_cmd_string)
{}

QString opcodes::convert_opcode_to_assembly(cpu& cpu_8080, uint16_t temp_pc)
{
    QString par_str;
    QString cmd;
    cmd.sprintf("0x%04x", temp_pc);
    cmd.append(": ");
    cmd.append(assembly_command);

    if (size == 2) {
        uint8_t par = cpu_8080.rom().get_u8(temp_pc+ 1);
        par_str.sprintf("%02xH", par);
        cmd.append(" $");
        cmd.append(par_str);
    }
    else if (size == 3) {
        uint16_t par = cpu_8080.rom().get_u16(temp_pc + 1);
        par_str.sprintf("%04xH", par);
        cmd.append(" $");
        cmd.append(par_str);
    }

    return cmd;
}

void opcodes::store_pre_debug_data(cpu& cpu_8080, cpu_debug& debug) {
    debug.curr_opcode_cmd = convert_opcode_to_assembly(cpu_8080, cpu_8080.core_p().get_pc());
    debug.curr_core_flags = cpu_8080.core_flag();
    debug.curr_core = cpu_8080.core_p();
}

void opcodes::store_post_debug_data(cpu& cpu_8080, cpu_debug& debug) {
    debug.post_opcode_cmd = convert_opcode_to_assembly(cpu_8080, cpu_8080.core_p().get_pc());
    debug.post_core_flags = cpu_8080.core_flag();
    debug.post_core = cpu_8080.core_p();
}

void opcodes::handle_opcode(cpu&)
{}
































