#include "opcodes.h"
#include "cpu_core.h"

opcodes::opcodes()
{
}

void cma_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    cpu_8080.core_p().set_reg_a(~reg_a);

    cpu_8080.core_p().increase_pc(instr_size());
}

void cmc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t c_bit = (cpu_8080.core_flag().get_c_flag() == 0) ? 1 : 0;

    cpu_8080.core_flag().set_c_flag(c_bit);

    cpu_8080.core_p().increase_pc(instr_size());
}

void stc_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_flag().set_c_flag(1);

    cpu_8080.core_p().increase_pc(instr_size());
}

void node_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().increase_pc(instr_size());
}

void jmp_opcode::handle_opcode(cpu& cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_pc_to(addr);
}

void jpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void jpe_opcode::handle_opcode(cpu& cpu_8080)
{
    if(cpu_8080.core_flag().get_p_flag()) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void jc_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_c_flag()) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void jnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_c_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void jz_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_z_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void jnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_z_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void jm_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_s_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void jp_opcode::handle_opcode(cpu &cpu_8080)
{
    if(cpu_8080.core_flag().get_s_flag() == 0) {
        jmp_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void call_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t req_addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.push_u16_on_the_stack(cpu_8080.core_p().get_pc());
    cpu_8080.core_p().set_pc_to(req_addr);
}

void cpe_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void cpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void cz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void cnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void cnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void cc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void cm_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 1) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void cp_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 0) {
        call_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void ret_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t pc_counter = cpu_8080.pop_u16_from_the_stack();
    cpu_8080.core_p().set_pc_to(pc_counter);
}

void rnz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void rz_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_z_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void rnc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void rc_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_c_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void rpo_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void rpe_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_p_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void rp_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 0) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
}

void rm_opcode::handle_opcode(cpu &cpu_8080)
{
    if (cpu_8080.core_flag().get_s_flag() == 1) {
        ret_opcode::handle_opcode(cpu_8080);
    } else {
        cpu_8080.core_p().increase_pc(instr_size());
    }
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

void sta_opcode::handle_opcode(cpu& cpu_8080)
{
    uint16_t addr = cpu_8080.rom().get_u16(cpu_8080.core_p().get_pc() + 1);
    cpu_8080.core_p().set_reg_a(cpu_8080.rom()[addr]);
    cpu_8080.core_p().increase_pc(instr_size());
}

void rrc_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t reg_a = cpu_8080.core_p().get_reg_a();
    uint8_t lbit = ((reg_a & 0x01) != 0);

    reg_a <<= 1;
    reg_a |= (lbit << 7);

    cpu_8080.core_flag().set_c_flag(lbit);
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

void pop_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_b(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());
}

void pop_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_d(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());

}

void pop_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_h(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());

}

void pop_psw_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_flag().set_psw(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_h(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());
}

void push_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_b());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void push_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_d());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void push_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_h());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
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

void rst7_opcode::handle_opcode(cpu&)
{}


void mov_opcode::handle_opcode(cpu&)
{}

void inx_opcode::handle_opcode(cpu&)
{}

void dcx_opcode::handle_opcode(cpu&)
{}

void dad_opcode::handle_opcode(cpu&)
{}


void out_opcode::handle_opcode(cpu&)
{}

void in_opcode::handle_opcode(cpu&)
{}

void inr_opcode::inr(cpu &cpu_8080, uint8_t val)
{
    val++;

    cpu_8080.core_flag().set_p_flag(val);
    cpu_8080.core_flag().set_z_flag(val);
    cpu_8080.core_flag().set_s_flag(val);
}

void inr_b_opcode::handle_opcode(cpu &cpu_8080)
{
    inr(cpu_8080, cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_c_opcode::handle_opcode(cpu &cpu_8080)
{
    inr(cpu_8080, cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_d_opcode::handle_opcode(cpu &cpu_8080)
{
    inr(cpu_8080, cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_e_opcode::handle_opcode(cpu &cpu_8080)
{
    inr(cpu_8080, cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_h_opcode::handle_opcode(cpu &cpu_8080)
{
    inr(cpu_8080, cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_l_opcode::handle_opcode(cpu &cpu_8080)
{
    inr(cpu_8080, cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    inr(cpu_8080, cpu_8080.rom().get_u8(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void inr_a_opcode::handle_opcode(cpu &cpu_8080)
{
    inr(cpu_8080, cpu_8080.core_p().get_reg_a());

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
    dcr(cpu_8080, cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_c_opcode::handle_opcode(cpu &cpu_8080)
{
    dcr(cpu_8080, cpu_8080.core_p().get_reg_c());

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_d_opcode::handle_opcode(cpu &cpu_8080)
{
    dcr(cpu_8080, cpu_8080.core_p().get_reg_d());

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_e_opcode::handle_opcode(cpu &cpu_8080)
{
    dcr(cpu_8080, cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_h_opcode::handle_opcode(cpu &cpu_8080)
{
    dcr(cpu_8080, cpu_8080.core_p().get_reg_h());

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_l_opcode::handle_opcode(cpu &cpu_8080)
{
    dcr(cpu_8080, cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    dcr(cpu_8080, cpu_8080.rom().get_u8(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void dcr_a_opcode::handle_opcode(cpu &cpu_8080)
{
    dcr(cpu_8080, cpu_8080.core_p().get_reg_a());

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

void xra_b_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_b());
    cpu_8080.core_p().increase_pc(instr_size());
}

void xra_c_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_c());
    cpu_8080.core_p().increase_pc(instr_size());
}

void xra_d_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_d());
    cpu_8080.core_p().increase_pc(instr_size());
}

void xra_e_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_e());
    cpu_8080.core_p().increase_pc(instr_size());
}

void xra_h_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_h());
    cpu_8080.core_p().increase_pc(instr_size());
}

void xra_l_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_l());
    cpu_8080.core_p().increase_pc(instr_size());
}

void xra_m_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t addr = (cpu_8080.core_p().get_reg_h() << 8) | cpu_8080.core_p().get_reg_l();
    xra(cpu_8080, cpu_8080.rom().get_u16(addr));

    cpu_8080.core_p().increase_pc(instr_size());
}

void xra_a_opcode::handle_opcode(cpu &cpu_8080)
{
    xra(cpu_8080, cpu_8080.core_p().get_reg_a());
    cpu_8080.core_p().increase_pc(instr_size());
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
