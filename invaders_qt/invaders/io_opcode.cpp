#include "io_opcode.h"
#include "cpu_core.h"

uint8_t shift_offset = 0x00;
uint8_t shift0 = 0x00;
uint8_t shift1 = 0x00;


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
            reg = 0x08; //hardware.input_1_handler();
            break;
        case 1:
            reg = hardware.input_2_handler();
            break;
        case 2:
            reg = 2; //hardware .input_3_handler();
            break;
        case 3:
            uint16_t v= (shift1 << 8) | shift0;
            uint8_t a = ((v >> (8-shift_offset)) & 0xFF);
            cpu_8080.core_p().set_reg_a(a);
        break;
    }

    cpu_8080.core_p().set_reg_a(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}
