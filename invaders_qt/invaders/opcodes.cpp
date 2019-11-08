#include <QString>
#include "opcodes.h"
#include "cpu_core.h"

QString opcodes::get_assembly_code(cpu& cpu_8080)
{
        QString cmd = QString::number(cpu_8080.core_p().get_pc());
        cmd.append(": ");
        cmd.append("Unknown Cmd");

        return cmd;
}

QString cma_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("CMA");

    return cmd;
}

void cma_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    cpu_8080.core_p().set_reg_a(~reg_a);

    cpu_8080.core_p().increase_pc(instr_size());
}

QString cmc_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("CMC");

    return cmd;
}

void cmc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t c_bit = (cpu_8080.core_flag().get_c_flag() == 0) ? 1 : 0;

    cpu_8080.core_flag().set_c_flag(c_bit);

    cpu_8080.core_p().increase_pc(instr_size());
}

QString stc_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("STC");

    return cmd;
}

void stc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_flag().set_c_flag(1);

    cpu_8080.core_p().increase_pc(instr_size());
}

QString nop_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("NOP");

    return cmd;
}
void nop_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().increase_pc(instr_size());
}

QString jmp_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JMP $");
    cmd.append(qaddr);

    return cmd;
}

void jmp_opcode::handle_opcode(cpu& cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_pc_to(addr);
}

QString jpo_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JPO $");
    cmd.append(qaddr);

    return cmd;
}

void jpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString jpe_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JPE $");
    cmd.append(qaddr);

    return cmd;
}

void jpe_opcode::handle_opcode(cpu& cpu_8080)
{
    if(cpu_8080.core_flag().get_p_flag()) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString jc_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JC $");
    cmd.append(qaddr);

    return cmd;
}

void jc_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_c_flag()) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString jnc_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JNC $");
    cmd.append(qaddr);

    return cmd;
}

void jnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_c_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString jz_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JZ $");
    cmd.append(qaddr);

    return cmd;
}

void jz_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_z_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString jnz_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JNZ $");
    cmd.append(qaddr);

    return cmd;
}

void jnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_z_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString jm_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JM $");
    cmd.append(qaddr);

    return cmd;
}

void jm_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_s_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString jp_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("JP $");
    cmd.append(qaddr);

    return cmd;
}

void jp_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_s_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString call_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CALL $");
    cmd.append(qaddr);

    return cmd;
}

void call_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t req_addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.push_u16_on_the_stack(cpu_8080.core_p().get_pc());
    cpu_8080.core_p().set_pc_to(req_addr);
}

QString cpe_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CPE $");
    cmd.append(qaddr);

    return cmd;
}

void cpe_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString cpo_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CPO $");
    cmd.append(qaddr);

    return cmd;
}

void cpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString cz_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CNZ $");
    cmd.append(qaddr);

    return cmd;
}

void cz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString cnz_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CNZ $");
    cmd.append(qaddr);

    return cmd;
}

void cnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString cnc_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CNC $");
    cmd.append(qaddr);

    return cmd;
}

void cnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString cc_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CC $");
    cmd.append(qaddr);

    return cmd;
}

void cc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString cm_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CM $");
    cmd.append(qaddr);

    return cmd;
}

void cm_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString cp_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("CP $");
    cmd.append(qaddr);

    return cmd;
}

void cp_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString ret_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RET");

    return cmd;
}

void ret_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t pc_counter = cpu_8080.pop_u16_from_the_stack();
    cpu_8080.core_p().set_pc_to(pc_counter);
}

QString rnz_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RNZ");

    return cmd;
}

void rnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString rz_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RZ");

    return cmd;
}

void rz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString rnc_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RNC");

    return cmd;
}

void rnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString rc_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RC");

    return cmd;
}

void rc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString rpo_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RPO");

    return cmd;
}

void rpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString rpe_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RPE");

    return cmd;
}

void rpe_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString rp_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RP");

    return cmd;
}

void rp_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

QString rm_opcode::get_assembly_code(cpu &cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("RM");

    return cmd;
}

void rm_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void rrc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t lbit = ((reg_a & 0x01) != 0);

    reg_a <<= 1;
    reg_a |= (lbit << 7);

    cpu_8080.core_flag().set_c_flag(lbit);
}

void mvi_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_b(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mvi_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_d(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mvi_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_h(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mvi_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    uint8_t hreg = cpu_8080.core_p().get_reg_h();
    uint8_t lreg = cpu_8080.core_p().get_reg_l();
    uint16_t addr = (hreg << 8) | lreg;

    cpu_8080.rom().set_u8(addr, data);

    cpu_8080.core_p().increase_pc(instr_size());
}


void mvi_c_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_c(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mvi_e_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_e(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mvi_l_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_l(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mvi_a_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t data = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_a(data);

    cpu_8080.core_p().increase_pc(instr_size());
}

void lxi_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1));
    cpu_8080.core_p().set_reg_b(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+2));
    cpu_8080.core_p().increase_pc(instr_size());
}

void lxi_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1));
    cpu_8080.core_p().set_reg_d(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+2));
    cpu_8080.core_p().increase_pc(instr_size());
}

void lxi_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1));
    cpu_8080.core_p().set_reg_h(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+2));
    cpu_8080.core_p().increase_pc(instr_size());
}

void lxi_sp_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_sp(cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1));
    cpu_8080.core_p().increase_pc(instr_size());
}

QString sta_opcode::get_assembly_code(cpu& cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("STA $");
    cmd.append(qaddr);

    return cmd;
}

void sta_opcode::handle_opcode(cpu& cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_a(cpu_8080.rom()[addr]);
    cpu_8080.core_p().increase_pc(instr_size());
}

QString lda_opcode::get_assembly_code(cpu& cpu_8080)
{
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    QString qaddr = QString::number(addr);
    cmd.append(": ");
    cmd.append("LDA $");
    cmd.append(qaddr);

    return cmd;
}

void lda_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc()+1);

    cpu_8080.core_p().set_reg_a(cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void daa_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t lb_acc = reg_a & 0x0F;

    if (lb_acc > 9 || cpu_8080.core_flag().get_ac_flag()) {
        cpu_8080.core_flag().set_ac_flag(reg_a, 6);
        cpu_8080.core_p().set_reg_a(reg_a + 6);
    }

    reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t hb_acc = (reg_a >> 4) & 0x0F;

    if (hb_acc > 9 || cpu_8080.core_flag().get_c_flag()) {
        cpu_8080.core_flag().set_c_flag(hb_acc, 6);
    }

    cpu_8080.core_p().increase_pc(instr_size());
}

QString pop_b_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("POP B");

    return cmd;
}

void pop_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_b(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());
}

QString pop_d_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("POP D");

    return cmd;
}

void pop_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_d(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());

}

QString pop_h_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("POP H");

    return cmd;
}

void pop_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_h(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());

}

QString pop_psw_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("POP PSW");

    return cmd;
}

void pop_psw_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_flag().set_psw(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_h(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());
}

QString push_b_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("PUSH B");

    return cmd;
}


void push_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_b());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

QString push_d_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("PUSH D");

    return cmd;
}

void push_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_d());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

QString push_h_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("PUSH H");

    return cmd;
}

void push_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_h());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

QString push_psw_opcode::get_assembly_code(cpu &cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("PUSH PSW");

    return cmd;
}

void push_psw_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_a());
    cpu_8080.push_on_the_stack(cpu_8080.core_flag().get_psw());

    cpu_8080.core_p().increase_pc(instr_size());
}

void ei_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.enable_interrupt(true);
}

void di_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.enable_interrupt(false);
}

void shld_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc()+1);

    cpu_8080.core_p().set_reg_l(addr);
    cpu_8080.core_p().set_reg_h(addr+1);

    cpu_8080.core_p().increase_pc(instr_size());
}

void rlc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t hbit = (reg_a & 0x80) != 0;

    reg_a <<= 1;
    reg_a |= hbit;

    cpu_8080.core_flag().set_c_flag(hbit);
    cpu_8080.core_p().set_reg_a(reg_a);

    cpu_8080.core_p().increase_pc(instr_size());
}

void rar_opcode::handle_opcode(cpu& cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t c_status_flag = cpu_8080.core_flag().get_c_flag();
    uint8_t lbit = ((reg_a & 0x01) !=0 );

    reg_a >>= 1;
    reg_a |= (c_status_flag << 7);
    cpu_8080.core_flag().set_c_flag(lbit);

    cpu_8080.core_p().increase_pc(instr_size());
}

void xchg_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t hbit = cpu_8080.core_p().get_reg_d();
    uint8_t lbit = cpu_8080.core_p().get_reg_e();

    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().set_reg_h(hbit);
    cpu_8080.core_p().set_reg_l(lbit);

    cpu_8080.core_p().increase_pc(instr_size());
}

void lhld_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc()+1);

    cpu_8080.core_p().set_reg_l(cpu_8080.rom().get_u8(addr));
    cpu_8080.core_p().set_reg_l(cpu_8080.rom().get_u8(addr+1));

    cpu_8080.core_p().increase_pc(instr_size());
}

void xthl_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t stack_addr = cpu_8080.core_p().get_sp();
    uint8_t l_bit = cpu_8080.core_p().get_reg_l();
    uint8_t h_bit = cpu_8080.core_p().get_reg_h();

    cpu_8080.rom().set_u8(stack_addr, l_bit);
    cpu_8080.rom().set_u8(stack_addr+1, h_bit);

    cpu_8080.core_p().increase_pc(instr_size());
}

void pchl_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_h = cpu_8080.core_p().get_reg_h();
    uint8_t reg_l = cpu_8080.core_p().get_reg_l();
    uint16_t counter = (reg_h << 8) | reg_l;

    cpu_8080.core_p().set_pc_to(counter);
}

void stax_opcode::store_acc_to_mem(cpu &cpu_8080, uint8_t reg_h, uint8_t reg_l)
{
    uint16_t address = (reg_h << 8) | reg_l;
    cpu_8080.rom().set_u16(address, cpu_8080.core_p().get_reg_a());
}

void stax_b_opcode::handle_opcode(cpu &cpu_8080)
{
    store_acc_to_mem(cpu_8080, cpu_8080.core_p().get_reg_b(), cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void stax_d_opcode::handle_opcode(cpu &cpu_8080)
{
    store_acc_to_mem(cpu_8080, cpu_8080.core_p().get_reg_d(), cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void ldax_opcode::retrieve_acc_from_mem(cpu &cpu_8080, uint8_t reg_h, uint8_t reg_l)
{
    uint16_t address = (reg_h << 8) | reg_l;
    cpu_8080.core_p().set_reg_a(cpu_8080.rom().get_u16(address));
}

void ldax_b_opcode::handle_opcode(cpu &cpu_8080)
{
    retrieve_acc_from_mem(cpu_8080, cpu_8080.core_p().get_reg_d(), cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void ldax_d_opcode::handle_opcode(cpu &cpu_8080)
{
    retrieve_acc_from_mem(cpu_8080, cpu_8080.core_p().get_reg_d(), cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void hlt_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.cpu_running(false);
}

void inr_opcode::inr(cpu &cpu_8080, uint8_t& val)
{
    val++;

    cpu_8080.core_flag().set_p_flag(val);
    cpu_8080.core_flag().set_z_flag(val);
    cpu_8080.core_flag().set_s_flag(val);
}

void inr_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_b = cpu_8080.core_p().get_reg_b();
    inr(cpu_8080, reg_b);
    cpu_8080.core_p().set_reg_b(reg_b);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_c_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_c = cpu_8080.core_p().get_reg_c();
    inr(cpu_8080, reg_c);
    cpu_8080.core_p().set_reg_c(reg_c);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_d = cpu_8080.core_p().get_reg_d();
    inr(cpu_8080, reg_d);
    cpu_8080.core_p().set_reg_d(reg_d);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_e_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_e = cpu_8080.core_p().get_reg_e();
    inr(cpu_8080, reg_e);
    cpu_8080.core_p().set_reg_e(reg_e);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_h = cpu_8080.core_p().get_reg_h();
    inr(cpu_8080, reg_h);
    cpu_8080.core_p().set_reg_h(reg_h);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_l_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_l = cpu_8080.core_p().get_reg_l();
    inr(cpu_8080, reg_l);
    cpu_8080.core_p().set_reg_l(reg_l);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    inr(cpu_8080, val);

    cpu_8080.rom().set_u8(addr, val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_a_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    inr(cpu_8080, reg_a);
    cpu_8080.core_p().set_reg_h(reg_a);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_opcode::dcr(cpu &cpu_8080, uint8_t& val)
{
    val--;

    cpu_8080.core_flag().set_p_flag(val);
    cpu_8080.core_flag().set_z_flag(val);
    cpu_8080.core_flag().set_s_flag(val);
}

void dcr_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_b();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_b(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_c_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_c();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_c(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_d();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_d(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_e_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_e();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_e(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_h();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_h(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_l_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_l();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_l(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    dcr(cpu_8080, val);

    cpu_8080.rom().set_u8(addr, val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_a_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg = cpu_8080.core_p().get_reg_a();
    dcr(cpu_8080, reg);
    cpu_8080.core_p().set_reg_a(reg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void add_opcode::add(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();

    cpu_8080.core_flag().set_c_flag(reg_a, val);
    cpu_8080.core_flag().set_ac_flag(reg_a, val);

    reg_a += val;

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void adc_opcode::adc(cpu &cpu_8080, uint8_t val)
{
    uint8_t cbit = cpu_8080.core_flag().get_c_flag();
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();

    cpu_8080.core_flag().set_c_flag(reg_a, val + cbit);
    cpu_8080.core_flag().set_ac_flag(reg_a, val + cbit);

    reg_a += (val + cbit);

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void sub_opcode::sub(cpu &cpu_8080, uint8_t val)
{
    uint8_t two_qu = ~val + 1;
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();

    cpu_8080.core_flag().set_c_flag(reg_a, two_qu);
    cpu_8080.core_flag().set_ac_flag(reg_a, two_qu);

    reg_a += two_qu;

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void sbb_opcode::sbb(cpu &cpu_8080, uint8_t val)
{
    uint8_t cbit = cpu_8080.core_flag().get_c_flag();
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t two_qu = ~(val + cbit) + 1;

    cpu_8080.core_flag().set_c_flag(reg_a, two_qu);
    cpu_8080.core_flag().set_ac_flag(reg_a, two_qu);

    reg_a += two_qu;

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void ana_opcode::ana(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a() & val;

    cpu_8080.core_flag().set_c_flag(0);
    cpu_8080.core_flag().set_ac_flag(0);

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);
}

void xra_opcode::xra(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a() ^ val;

    cpu_8080.core_flag().set_c_flag(0);
    cpu_8080.core_flag().set_ac_flag(0);

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);

}

void ora_opcode::ora(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a() | val;

    cpu_8080.core_flag().set_c_flag(0);
    cpu_8080.core_flag().set_ac_flag(0);

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);

    cpu_8080.core_p().set_reg_a(reg_a);

}

void cmp_opcode::cmp(cpu &cpu_8080, uint8_t val)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();

    cpu_8080.core_flag().set_c_flag(reg_a, val);
    cpu_8080.core_flag().set_ac_flag(reg_a, val);

    reg_a += val;

    cpu_8080.core_flag().set_p_flag(reg_a);
    cpu_8080.core_flag().set_z_flag(reg_a);
    cpu_8080.core_flag().set_s_flag(reg_a);
}

void sub_b_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sub_c_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sub_d_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sub_e_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sub_h_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sub_l_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sub_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    sub(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void sub_a_opcode::handle_opcode(cpu &cpu_8080)
{
    sub(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sui_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    sub(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

void sbb_b_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sbb_c_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sbb_d_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sbb_e_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sbb_h_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sbb_l_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sbb_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    sbb(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void sbb_a_opcode::handle_opcode(cpu &cpu_8080)
{
    sbb(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

void sbi_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    sbb(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

void ana_b_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ana_c_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ana_d_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ana_e_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ana_h_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ana_l_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ana_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    ana(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void ana_a_opcode::handle_opcode(cpu &cpu_8080)
{
    ana(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ani_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    ana(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xra_b_opcode::get_assembly_code(cpu& cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("XRA B");

    return cmd;
}

void xra_b_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xra_c_opcode::get_assembly_code(cpu& cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("XRA C");

    return cmd;
}

void xra_c_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xra_d_opcode::get_assembly_code(cpu& cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("XRA D");

    return cmd;
}

void xra_d_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xra_e_opcode::get_assembly_code(cpu& cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("XRA E");

    return cmd;
}

void xra_e_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xra_h_opcode::get_assembly_code(cpu& cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("XRA H");

    return cmd;
}

void xra_h_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xra_l_opcode::get_assembly_code(cpu& cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("XRA L");

    return cmd;
}

void xra_l_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xra_m_opcode::get_assembly_code(cpu& cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("XRA M");

    return cmd;
}

void xra_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    xra(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xra_a_opcode::get_assembly_code(cpu& cpu_8080) {
    QString cmd = QString::number(cpu_8080.core_p().get_pc());
    cmd.append(": ");
    cmd.append("XRA A");

    return cmd;
}

void xra_a_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

QString  xri_opcode::get_assembly_code(cpu& cpu_8080) {
    uint8_t pc = cpu_8080.core_p().get_pc();
    QString cmd = QString::number(pc);
    QString val = QString::number(cpu_8080.rom().get_u8(pc+1));

    cmd.append(": ");
    cmd.append("XRI $");
    cmd.append(val);

    return cmd;
}

void xri_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    xra(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

void ora_b_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ora_c_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ora_d_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ora_e_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ora_h_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ora_l_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ora_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    ora(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void ora_a_opcode::handle_opcode(cpu &cpu_8080)
{
    ora(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

void ori_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    ora(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

void cmp_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

void cmp_c_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

void cmp_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

void cmp_e_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

void cmp_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

void cmp_l_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

void cmp_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cmp(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void cmp_a_opcode::handle_opcode(cpu &cpu_8080)
{
    cmp(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

void cpi_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    cmp(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());
}

// ---------- *
void adc_b_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

void adc_c_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

void adc_d_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

void adc_e_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

void adc_h_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

void adc_l_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

void adc_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    adc(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void adc_a_opcode::handle_opcode(cpu &cpu_8080)
{
    adc(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

void aci_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    adc(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());

}
// ---------- *
void add_b_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

void add_c_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

void add_d_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

void add_e_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

void add_h_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

void add_l_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

void add_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    add(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void add_a_opcode::handle_opcode(cpu &cpu_8080)
{
    add(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
}

void adi_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t val = cpu_8080.rom().get_u8(cpu_8080.core_p().get_pc()+1);
    add(cpu_8080, val);
    cpu_8080.core_p().increase_pc(instr_size());

}


void inx_opcode::inx(uint8_t &hbit, uint8_t &lbit)
{
    uint16_t inx_reg = (hbit << 8) | lbit;
    inx_reg++;

    hbit = (inx_reg >> 8) & 0xFF;
    lbit = inx_reg & 0xFF;
}

void inx_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_c();
    uint8_t hreg = cpu_8080.core_p().get_reg_b();

    inx(hreg, lreg);

    cpu_8080.core_p().set_reg_c(lreg);
    cpu_8080.core_p().set_reg_b(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inx_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_e();
    uint8_t hreg = cpu_8080.core_p().get_reg_d();

    inx(hreg, lreg);

    cpu_8080.core_p().set_reg_e(lreg);
    cpu_8080.core_p().set_reg_d(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inx_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_l();
    uint8_t hreg = cpu_8080.core_p().get_reg_h();

    inx(hreg, lreg);

    cpu_8080.core_p().set_reg_l(lreg);
    cpu_8080.core_p().set_reg_h(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void inx_sp_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t sp = cpu_8080.core_p().get_sp();
    sp++;
    cpu_8080.core_p().set_sp(sp++);
    cpu_8080.core_p().increase_pc(instr_size());
}

void dcx_opcode::dcx(uint8_t& hbit, uint8_t& lbit)
{
    uint16_t dcx_reg = (hbit << 8) | lbit;
    dcx_reg--;

    hbit = (dcx_reg >> 8) & 0xFF;
    lbit = dcx_reg & 0xFF;
}

void dcx_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_c();
    uint8_t hreg = cpu_8080.core_p().get_reg_b();

    dcx(hreg, lreg);

    cpu_8080.core_p().set_reg_c(lreg);
    cpu_8080.core_p().set_reg_b(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcx_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_e();
    uint8_t hreg = cpu_8080.core_p().get_reg_d();

    dcx(hreg, lreg);

    cpu_8080.core_p().set_reg_e(lreg);
    cpu_8080.core_p().set_reg_d(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcx_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_l();
    uint8_t hreg = cpu_8080.core_p().get_reg_h();

    dcx(hreg, lreg);

    cpu_8080.core_p().set_reg_l(lreg);
    cpu_8080.core_p().set_reg_h(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcx_sp_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t sp = cpu_8080.core_p().get_sp();
    sp--;
    cpu_8080.core_p().set_sp(sp++);
    cpu_8080.core_p().increase_pc(instr_size());
}

// ---------- MOV B
void mov_bb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_bc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_bd_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_be_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_bh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_bl_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_bm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);
    cpu_8080.core_p().set_reg_b(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ba_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_b(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}



// ------------ MOV C
void mov_cb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_cc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_cd_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ce_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ch_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_cl_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_cm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_c(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ca_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}


// --------------- MOV D
void mov_db_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_dc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_dd_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_de_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_dh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_dl_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_dm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_d(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_da_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_d(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}


// ------------- MOV E
void mov_eb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ec_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ed_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ee_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_eh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_el_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_em_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_e(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ea_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ------------- MOV H
void mov_hb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_hc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_hd_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_he_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_hh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_hl_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_hm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_h(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ha_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_h(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ------------- MOV L
void mov_lb_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_lc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ld_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_le_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_lh_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ll_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_lm_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_l(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_la_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ------------- MOV M
void mov_mb_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_mc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_md_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_me_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_mh_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ml_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ma_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    cpu_8080.rom().set_u8(addr, cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

// ------------- MOV A
void mov_ab_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ac_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ad_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ae_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_ah_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_al_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_am_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    uint8_t val = cpu_8080.rom().get_u8(addr);

    cpu_8080.core_p().set_reg_a(val);

    cpu_8080.core_p().increase_pc(instr_size());
}

void mov_aa_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_a(cpu_8080.core_p().get_reg_a());

    cpu_8080.core_p().increase_pc(instr_size());
}

void rst0_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(0*8);
}

void rst1_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.core_p().set_pc_to(0);
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(1*8);
}

void rst2_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(2*8);
}

void rst3_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(3*8);
}

void rst4_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(4*8);
}

void rst5_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(5*8);
}

void rst6_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(6*8);
}

void rst7_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = cpu_8080.core_p().get_pc() + 1;
    cpu_8080.push_u16_on_the_stack(addr);

    cpu_8080.core_p().set_pc_to(7*8);
}

void ral_opcode::handle_opcode(cpu&)
{}

void sphl_opcode::handle_opcode(cpu&)
{}

void dad_b_opcode::handle_opcode(cpu&)
{}

void dad_d_opcode::handle_opcode(cpu&)
{}

void dad_h_opcode::handle_opcode(cpu&)
{}

void dad_sp_opcode::handle_opcode(cpu&)
{}

void out_opcode::handle_opcode(cpu&)
{}

void in_opcode::handle_opcode(cpu&)
{}
