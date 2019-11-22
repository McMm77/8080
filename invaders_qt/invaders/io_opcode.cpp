#include "io_opcode.h"
#include "cpu_core.h"

uint8_t shift_offset = 0x00;
uint8_t shift0 = 0x00;
uint8_t shift1 = 0x00;

extern QFile shortFile;

out_opcode::out_opcode(invaders& hw)
    : opcodes(2, 10, 10, "OUT"),
      hardware(hw)
{}

void out_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t port = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    uint8_t reg = 0;
    switch(port) {
        case 2:
            shift_offset = cpu_8080.core_p().get_reg_a() & 0x7;
            break;
    case 4:
            shift0 = shift1;
            shift1 = cpu_8080.core_p().get_reg_a();
            break;
    }



    if(port == 2) {
        QString str("OUT Opcode:\n");
        str.append("shift_offset: ");
        str.append(QString::number(shift_offset));
        str.append('\n');
        shortFile.write(str.toUtf8());
    }

    if(port == 4) {
        QString str("OUT Opcode:\n");
        str.append("Shift0: ");
        str.append(QString::number(shift0));
        str.append("\nShift1: ");
        str.append(QString::number(shift1));
        str.append('\n');
        shortFile.write(str.toUtf8());
    }



    cpu_8080.core_p().increase_pc(instr_size());
}

in_opcode::in_opcode(invaders& hw)
    : opcodes(2, 10, 10, "IN"),
    hardware(hw)
{}

void in_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t port = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    uint8_t reg = 0;
    switch(port) {
        case 0:
            reg = hardware.input_1_handler();
            break;
        case 1:
            reg = hardware.input_2_handler();
            break;
        case 2:
            reg = hardware.input_3_handler();
            break;
        case 3:
            uint16_t v= (shift1 << 8) | shift0;
            reg = ((v >> (8-shift_offset)) & 0xFF);
//            cpu_8080.core_p().set_reg_a(a);
        break;
    }


    cpu_8080.core_p().set_reg_a(reg);
    cpu_8080.core_p().increase_pc(instr_size());

    if( port == 3 ) {
        QString str("IN Opcode:\n");
        str.append("shift_offset: ");
        str.append(QString::number(shift_offset));
        str.append("\nReg A: ");
        QString reg_a;
        reg_a.sprintf("%02xH", reg);
        reg_a.append('\n');
        str.append(reg_a);
        shortFile.write(str.toUtf8());
    }
}
