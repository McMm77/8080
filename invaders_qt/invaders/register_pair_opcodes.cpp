#include "register_pair_opcodes.h"
#include "cpu_core.h"

inx_opcode::inx_opcode(QString ass_cmd)
    : opcodes(1, 5, 5, ass_cmd)
{}

void inx_opcode::inx(uint8_t &hbit, uint8_t &lbit)
{
    uint16_t inx_reg = (hbit << 8) | lbit;
    inx_reg++;

    hbit = (inx_reg >> 8) & 0xFF;
    lbit = inx_reg & 0xFF;
}

inx_b_opcode::inx_b_opcode()
    : inx_opcode("INX B")
{}

void inx_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_c();
    uint8_t hreg = cpu_8080.core_p().get_reg_b();

    inx(hreg, lreg);

    cpu_8080.core_p().set_reg_c(lreg);
    cpu_8080.core_p().set_reg_b(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

inx_d_opcode::inx_d_opcode()
    :inx_opcode("INDX D")
{}

void inx_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_e();
    uint8_t hreg = cpu_8080.core_p().get_reg_d();

    inx(hreg, lreg);

    cpu_8080.core_p().set_reg_e(lreg);
    cpu_8080.core_p().set_reg_d(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

inx_h_opcode::inx_h_opcode()
    :inx_opcode("INX H")
{}

void inx_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_l();
    uint8_t hreg = cpu_8080.core_p().get_reg_h();

    inx(hreg, lreg);

    cpu_8080.core_p().set_reg_l(lreg);
    cpu_8080.core_p().set_reg_h(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

inx_sp_opcode::inx_sp_opcode()
    : inx_opcode("INX SP")
{}
void inx_sp_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t sp = cpu_8080.core_p().get_sp();
    sp++;
    cpu_8080.core_p().set_sp(sp++);
    cpu_8080.core_p().increase_pc(instr_size());
}

dcx_opcode::dcx_opcode(QString ass_cmd)
    : opcodes(1, 5, 5, ass_cmd)
{}

void dcx_opcode::dcx(uint8_t& hbit, uint8_t& lbit)
{
    uint16_t dcx_reg = (hbit << 8) | lbit;
    dcx_reg--;

    hbit = (dcx_reg >> 8) & 0xFF;
    lbit = dcx_reg & 0xFF;
}

dcx_b_opcode::dcx_b_opcode()
    : dcx_opcode("DCX B")
{}

void dcx_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_c();
    uint8_t hreg = cpu_8080.core_p().get_reg_b();

    dcx(hreg, lreg);

    cpu_8080.core_p().set_reg_c(lreg);
    cpu_8080.core_p().set_reg_b(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcx_d_opcode::dcx_d_opcode()
    : dcx_opcode("DCX D")
{}

void dcx_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_e();
    uint8_t hreg = cpu_8080.core_p().get_reg_d();

    dcx(hreg, lreg);

    cpu_8080.core_p().set_reg_e(lreg);
    cpu_8080.core_p().set_reg_d(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcx_h_opcode::dcx_h_opcode()
    : dcx_opcode("DCX H")
{}

void dcx_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t lreg = cpu_8080.core_p().get_reg_l();
    uint8_t hreg = cpu_8080.core_p().get_reg_h();

    dcx(hreg, lreg);

    cpu_8080.core_p().set_reg_l(lreg);
    cpu_8080.core_p().set_reg_h(hreg);

    cpu_8080.core_p().increase_pc(instr_size());
}

dcx_sp_opcode::dcx_sp_opcode()
    : dcx_opcode("DCX SP")
{}

void dcx_sp_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t sp = cpu_8080.core_p().get_sp();
    sp--;
    cpu_8080.core_p().set_sp(sp++);
    cpu_8080.core_p().increase_pc(instr_size());
}

// --------------------------------
pop_opcode::pop_opcode(QString ass_cmd)
    : opcodes(1, 10, 10, ass_cmd)
{}

pop_b_opcode::pop_b_opcode()
    : pop_opcode("POP B")
{}

void pop_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_c(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_b(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());
}

pop_d_opcode::pop_d_opcode()
    : pop_opcode("POP D")
{}

void pop_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_e(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_d(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());
}

pop_h_opcode::pop_h_opcode()
    : pop_opcode("POP H")
{}

void pop_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_p().set_reg_l(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_h(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());
}

pop_psw_opcode::pop_psw_opcode()
    : pop_opcode("POP PSW")
{}

void pop_psw_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.core_flag().set_psw(cpu_8080.pop_from_the_stack());
    cpu_8080.core_p().set_reg_h(cpu_8080.pop_from_the_stack());

    cpu_8080.core_p().increase_pc(instr_size());
}

// -----------------------------------------
push_opcode::push_opcode(QString ass_cmd)
    : opcodes(1, 10, 10, ass_cmd)
{}

push_b_opcode::push_b_opcode()
    : push_opcode("PUSH B")
{}

void push_b_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_b());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_b());

    cpu_8080.core_p().increase_pc(instr_size());
}

push_d_opcode::push_d_opcode()
    : push_opcode("PUSH D")
{}

void push_d_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_d());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_e());

    cpu_8080.core_p().increase_pc(instr_size());
}

push_h_opcode::push_h_opcode()
    : push_opcode("PUSH H")
{}

void push_h_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_h());
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_l());

    cpu_8080.core_p().increase_pc(instr_size());
}

push_psw_opcode::push_psw_opcode()
    : push_opcode("PUSH PSW")
{}

void push_psw_opcode::handle_opcode(cpu &cpu_8080)
{
    cpu_8080.push_on_the_stack(cpu_8080.core_p().get_reg_a());
    cpu_8080.push_on_the_stack(cpu_8080.core_flag().get_psw());

    cpu_8080.core_p().increase_pc(instr_size());
}

dad_opcode::dad_opcode(QString ass_cmd)
    : opcodes(1, 10, 10, ass_cmd)
{}

dad_b_opcode::dad_b_opcode()
    : dad_opcode("DAD B")
{}

void dad_b_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t bc_lval = cpu_8080.core_p().get_reg_c();
    uint8_t bc_hval = cpu_8080.core_p().get_reg_b();
    uint16_t bc_val = (bc_hval << 8) | bc_lval;

    uint8_t hl_lval = cpu_8080.core_p().get_reg_l();
    uint8_t hl_hval = cpu_8080.core_p().get_reg_h();
    uint16_t hl_val = (hl_hval << 8) | hl_lval;

    uint32_t prod = bc_val + hl_val;

    uint8_t c_flag = ((prod & 0x00010000) != 0);
    cpu_8080.core_flag().set_c_flag(c_flag);

    uint8_t h_bit = (prod >> 8) & 0xFF;
    uint8_t l_bit = prod & 0xFF;

    cpu_8080.core_p().set_reg_l(l_bit);
    cpu_8080.core_p().set_reg_h(h_bit);

    cpu_8080.core_p().increase_pc(instr_size());

}

dad_d_opcode::dad_d_opcode()
    : dad_opcode("DAD D")
{}

void dad_d_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t bc_lval = cpu_8080.core_p().get_reg_e();
    uint8_t bc_hval = cpu_8080.core_p().get_reg_d();
    uint16_t bc_val = (bc_hval << 8) | bc_lval;

    uint8_t hl_lval = cpu_8080.core_p().get_reg_l();
    uint8_t hl_hval = cpu_8080.core_p().get_reg_h();
    uint16_t hl_val = (hl_hval << 8) | hl_lval;

    uint32_t prod = bc_val + hl_val;

    uint8_t c_flag = ((prod & 0x00010000) != 0);
    cpu_8080.core_flag().set_c_flag(c_flag);

    uint8_t h_bit = (prod >> 8) & 0xFF;
    uint8_t l_bit = prod & 0xFF;

    cpu_8080.core_p().set_reg_l(l_bit);
    cpu_8080.core_p().set_reg_h(h_bit);

    cpu_8080.core_p().increase_pc(instr_size());
}

dad_h_opcode::dad_h_opcode()
    : dad_opcode("DAD H")
{

}

void dad_h_opcode::handle_opcode(cpu &cpu_8080)
{
    uint8_t bc_lval = cpu_8080.core_p().get_reg_l();
    uint8_t bc_hval = cpu_8080.core_p().get_reg_h();
    uint16_t bc_val = (bc_hval << 8) | bc_lval;

    uint8_t hl_lval = cpu_8080.core_p().get_reg_l();
    uint8_t hl_hval = cpu_8080.core_p().get_reg_h();
    uint16_t hl_val = (hl_hval << 8) | hl_lval;

    uint32_t prod = bc_val + hl_val;

    uint8_t c_flag = ((prod & 0x00010000) != 0);
    cpu_8080.core_flag().set_c_flag(c_flag);

    uint8_t h_bit = (prod >> 8) & 0xFF;
    uint8_t l_bit = prod & 0xFF;

    cpu_8080.core_p().set_reg_l(l_bit);
    cpu_8080.core_p().set_reg_h(h_bit);

    cpu_8080.core_p().increase_pc(instr_size());

}

dad_sp_opcode::dad_sp_opcode()
    : dad_opcode("DAD SP")
{}

void dad_sp_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t bc_val = cpu_8080.core_p().get_sp();

    uint8_t hl_lval = cpu_8080.core_p().get_reg_l();
    uint8_t hl_hval = cpu_8080.core_p().get_reg_h();
    uint16_t hl_val = (hl_hval << 8) | hl_lval;

    uint32_t prod = bc_val + hl_val;

    uint8_t c_flag = ((prod & 0x00010000) != 0);
    cpu_8080.core_flag().set_c_flag(c_flag);

    uint8_t h_bit = (prod >> 8) & 0xFF;
    uint8_t l_bit = prod & 0xFF;

    cpu_8080.core_p().set_reg_l(l_bit);
    cpu_8080.core_p().set_reg_h(h_bit);

    cpu_8080.core_p().increase_pc(instr_size());

}

sphl_opcode::sphl_opcode()
    : opcodes(1, 5, 5, "SPHL")
{}

void sphl_opcode::handle_opcode(cpu&)
{}

xchg_opcode::xchg_opcode()
    : opcodes(1, 5, 5, "XCHG")
{}

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

xthl_opcode::xthl_opcode()
    : opcodes(1, 5, 5, "XTHL")
{}

void xthl_opcode::handle_opcode(cpu &cpu_8080)
{
    uint16_t stack_addr = cpu_8080.core_p().get_sp();
    uint8_t l_bit = cpu_8080.core_p().get_reg_l();
    uint8_t h_bit = cpu_8080.core_p().get_reg_h();

    cpu_8080.rom().set_u8(stack_addr, l_bit);
    cpu_8080.rom().set_u8(stack_addr+1, h_bit);

    cpu_8080.core_p().increase_pc(instr_size());
}

