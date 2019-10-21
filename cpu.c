#include "cpu.h"
#include "deassembler.h"

typedef unsigned long uint32_t;

#define OPCODE_INSTR		(0xFF)
#define OPCODE_FUNC(a)		static void a

#define INCR_PC_CNT(cpu_ptr)        (cpu_ptr->core.pc++)
#define INCR_PC_X_CNT(cpu_ptr, x)   (cpu_ptr->core.pc += x)
#define SET_PC_CNT(cpu_ptr, x)      (cpu_ptr->core.pc = x)

static void mov_instr(memory_t*, memory_t*, cpu_model_t*);
static void ora_instr(memory_t*, memory_t*, cpu_model_t*);
static void rz_instr(memory_t*, memory_t*, cpu_model_t*);
static void ldax_instr(memory_t*, memory_t*, cpu_model_t*);
static void inx_instr(memory_t*, memory_t*, cpu_model_t*);
static void dcx_instr(memory_t*, memory_t*, cpu_model_t*);
static void jnz_instr(memory_t*, memory_t*, cpu_model_t*);
static void ret_instr(memory_t*, memory_t*, cpu_model_t*);
static void nop_instr(memory_t*, memory_t*, cpu_model_t*);
static void stax_instr(memory_t*, memory_t*, cpu_model_t*);
static void inr_instr(memory_t*, memory_t*, cpu_model_t*);
static void dcr_instr(memory_t*, memory_t*, cpu_model_t*);
static void mvi_instr(memory_t*, memory_t*, cpu_model_t*);
static void rlc_instr(memory_t*, memory_t*, cpu_model_t*);
static void lxi_instr(memory_t*, memory_t*, cpu_model_t*);
static void dcr_instr(memory_t*, memory_t*, cpu_model_t*);
static void dad_instr(memory_t*, memory_t*, cpu_model_t*);
static void rrc_instr(memory_t*, memory_t*, cpu_model_t*);
static void ral_instr(memory_t*, memory_t*, cpu_model_t*);
static void rar_instr(memory_t*, memory_t*, cpu_model_t*);
static void shld_instr(memory_t*, memory_t*, cpu_model_t*);
static void daa_instr(memory_t*, memory_t*, cpu_model_t*);
static void lhld_instr(memory_t*, memory_t*, cpu_model_t*);
static void cma_instr(memory_t*, memory_t*, cpu_model_t*);
static void sta_instr(memory_t*, memory_t*, cpu_model_t*);
static void stc_instr(memory_t*, memory_t*, cpu_model_t*);
static void lda_instr(memory_t*, memory_t*, cpu_model_t*);
static void cmc_instr(memory_t*, memory_t*, cpu_model_t*);
static void hlt_instr(memory_t*, memory_t*, cpu_model_t*);
static void add_instr(memory_t*, memory_t*, cpu_model_t*);
static void adc_instr(memory_t*, memory_t*, cpu_model_t*);
static void sub_instr(memory_t*, memory_t*, cpu_model_t*);
static void sbb_instr(memory_t*, memory_t*, cpu_model_t*);
static void ana_instr(memory_t*, memory_t*, cpu_model_t*);
static void xra_instr(memory_t*, memory_t*, cpu_model_t*);
static void cmp_instr(memory_t*, memory_t*, cpu_model_t*);
static void rnz_instr(memory_t*, memory_t*, cpu_model_t*);
static void pop_instr(memory_t*, memory_t*, cpu_model_t*);
static void jmp_instr(memory_t*, memory_t*, cpu_model_t*);
static void cnz_instr(memory_t*, memory_t*, cpu_model_t*);
static void push_instr(memory_t*, memory_t*, cpu_model_t*);
static void adi_instr(memory_t*, memory_t*, cpu_model_t*);
static void rst_instr(memory_t*, memory_t*, cpu_model_t*);
static void jz_instr(memory_t*, memory_t*, cpu_model_t*);
static void cz_instr(memory_t*, memory_t*, cpu_model_t*);
static void call_instr(memory_t*, memory_t*, cpu_model_t*);
static void aci_instr(memory_t*, memory_t*, cpu_model_t*);
static void rnc_instr(memory_t*, memory_t*, cpu_model_t*);
static void jnc_instr(memory_t*, memory_t*, cpu_model_t*);
static void out_instr(memory_t*, memory_t*, cpu_model_t*);
static void cnc_instr(memory_t*, memory_t*, cpu_model_t*);
static void sui_instr(memory_t*, memory_t*, cpu_model_t*);
static void rc_instr(memory_t*, memory_t*, cpu_model_t*);
static void jc_instr(memory_t*, memory_t*, cpu_model_t*);
static void in_instr(memory_t*, memory_t*, cpu_model_t*);
static void cc_instr(memory_t*, memory_t*, cpu_model_t*);
static void sbi_instr(memory_t*, memory_t*, cpu_model_t*);
static void rpo_instr(memory_t*, memory_t*, cpu_model_t*);
static void jpo_instr(memory_t*, memory_t*, cpu_model_t*);
static void xthl_instr(memory_t*, memory_t*, cpu_model_t*);
static void cpo_instr(memory_t*, memory_t*, cpu_model_t*);
static void ani_instr(memory_t*, memory_t*, cpu_model_t*);
static void rpe_instr(memory_t*, memory_t*, cpu_model_t*);
static void pchl_instr(memory_t*, memory_t*, cpu_model_t*);
static void jpe_instr(memory_t*, memory_t*, cpu_model_t*);
static void xchg_instr(memory_t*, memory_t*, cpu_model_t*);
static void cpe_instr(memory_t*, memory_t*, cpu_model_t*);
static void xri_instr(memory_t*, memory_t*, cpu_model_t*);
static void rp_instr(memory_t*, memory_t*, cpu_model_t*);
static void jp_instr(memory_t*, memory_t*, cpu_model_t*);
static void di_instr(memory_t*, memory_t*, cpu_model_t*);
static void cp_instr(memory_t*, memory_t*, cpu_model_t*);
static void ori_instr(memory_t*, memory_t*, cpu_model_t*);
static void rm_instr(memory_t*, memory_t*, cpu_model_t*);
static void sphl_instr(memory_t*, memory_t*, cpu_model_t*);
static void jm_instr(memory_t*, memory_t*, cpu_model_t*);
static void ei_instr(memory_t*, memory_t*, cpu_model_t*);
static void cm_instr(memory_t*, memory_t*, cpu_model_t*);
static void cpi_instr(memory_t*, memory_t*, cpu_model_t*);

static void empty_instr(memory_t*, memory_t*, cpu_model_t*);

/* Table taken from http://pastraiser.com/cpu/i8080/i8080_opcodes.html */
static void (*assembly_instr[]) (memory_t*, memory_t*, cpu_model_t*) = 
{
	nop_instr,  inx_instr,  stax_instr,  inx_instr,   inr_instr,  dcr_instr,   mvi_instr,  rlc_instr,
	nop_instr,  dad_instr,  ldax_instr,  dcx_instr,   inr_instr,  dcr_instr,   mvi_instr,  rrc_instr,	/* \n */
	nop_instr,  lxi_instr,  stax_instr,  inx_instr,   inr_instr,  dcr_instr,   mvi_instr,  ral_instr,
	nop_instr,  dad_instr,  ldax_instr,  dcx_instr,   inr_instr,  dcr_instr,   mvi_instr,  rar_instr,	/* \n */
	nop_instr,  lxi_instr,  shld_instr,  inx_instr,   inr_instr,  dcr_instr,   mvi_instr,  daa_instr,
	nop_instr,  dad_instr,  lhld_instr,  dcx_instr,   inr_instr,  dcr_instr,   mvi_instr,  cma_instr,	/* \n */
	nop_instr,  lxi_instr,  sta_instr,   inx_instr,   inr_instr,  dcr_instr,   mvi_instr,  stc_instr,
	nop_instr,  dad_instr,  lda_instr,   dcx_instr,   inr_instr,  dcr_instr,   mvi_instr,  cmc_instr,
	mov_instr,  mov_instr,  mov_instr,   mov_instr,   mov_instr,  mov_instr,   mov_instr,  mov_instr,
	mov_instr,  mov_instr,  mov_instr,   mov_instr,   mov_instr,  mov_instr,   mov_instr,  mov_instr,
	mov_instr,  mov_instr,  mov_instr,   mov_instr,   mov_instr,  mov_instr,   mov_instr,  mov_instr,
	mov_instr,  mov_instr,  mov_instr,   mov_instr,   mov_instr,  mov_instr,   mov_instr,  mov_instr,
	mov_instr,  mov_instr,  mov_instr,   mov_instr,   mov_instr,  mov_instr,   mov_instr,  mov_instr,
	mov_instr,  mov_instr,  mov_instr,   mov_instr,   mov_instr,  mov_instr,   mov_instr,  mov_instr,
	mov_instr,  mov_instr,  mov_instr,   mov_instr,   mov_instr,  mov_instr,   hlt_instr,  mov_instr,
	mov_instr,  mov_instr,  mov_instr,   mov_instr,   mov_instr,  mov_instr,   mov_instr,  mov_instr,
	add_instr,  add_instr,  add_instr,   add_instr,   add_instr,  add_instr,   add_instr,  add_instr,
	adc_instr,  adc_instr,  adc_instr,   adc_instr,   adc_instr,  adc_instr,   adc_instr,  adc_instr,
	sub_instr,  sub_instr,  sub_instr,   sub_instr,   sub_instr,  sub_instr,   sub_instr,  sub_instr,
	sbb_instr,  sbb_instr,  sbb_instr,   sbb_instr,   sbb_instr,  sbb_instr,   sbb_instr,  sbb_instr,
	ana_instr,  ana_instr,  ana_instr,   ana_instr,   ana_instr,  ana_instr,   ana_instr,  ana_instr,
	xra_instr,  xra_instr,  xra_instr,   xra_instr,   xra_instr,  xra_instr,   xra_instr,  xra_instr,
	ora_instr,  ora_instr,  ora_instr,   ora_instr,   ora_instr,  ora_instr,   ora_instr,  ora_instr,
	cmp_instr,  cmp_instr,  cmp_instr,   cmp_instr,   cmp_instr,  cmp_instr,   cmp_instr,  cmp_instr,
	rnz_instr,  pop_instr,  jnz_instr,   jmp_instr,   cnz_instr,  push_instr,  adi_instr,  rst_instr,
	rz_instr,   ret_instr,  jz_instr,    jmp_instr,   cz_instr,   call_instr,  aci_instr,  rst_instr,
	rnc_instr,  pop_instr,  jnc_instr,   out_instr,   cnc_instr,  push_instr,  sui_instr,  rst_instr,
	rc_instr,   ret_instr,  jc_instr,    in_instr,    cc_instr,   call_instr,  sbi_instr,  rst_instr,
	rpo_instr,  pop_instr,  jpo_instr,   xthl_instr,  cpo_instr,  push_instr,  ani_instr,  rst_instr,
	rpe_instr,  pchl_instr, jpe_instr,   xchg_instr,  cpe_instr,  call_instr,  xri_instr,  rst_instr,
	rp_instr,   pop_instr,  jp_instr,    di_instr,    cp_instr,   push_instr,  ori_instr,  rst_instr,
	rm_instr,   sphl_instr, jm_instr,    ei_instr,    cm_instr,   call_instr,  cpi_instr,  rst_instr};


// ---------------------------------------------------------------
static void display_curr_cpu_status(cpu_core_t* core)
{
	printf("\n--------------------------");
	printf("------ CPU STATUS --------\n");
	printf("Stack: %d\n", core->stack);
	printf("PC: %d\n", core->pc);
	printf("Accumulator: %d\n", core->accumulator);
	printf("Reg A: 0x%02x\t\tReg B 0x%02x\n", core->a, core->b);
	printf("Reg C: 0x%02x\t\tReg D 0x%02x\n", core->c, core->d);
	printf("Reg E: 0x%02x\t\tReg H 0x%02x\n", core->e, core->h);
	printf("Reg L: 0x%02x\t\tReg M 0x%02x\n", core->l, core->m);
	printf("Status: C: %d P: %d AC: %d z: %d s: %d\n", core->status.c, core->status.p, core->status.ac, core->status.z, core->status.s);
        printf("----------------------------\n");	
}

// ---------------------------------------------------------------
void display_cpu_status(cpu_model_t *cpu)
{
	display_curr_cpu_status(&cpu->core);
}

// ---------------------------------------------------------------
//                 CARRY BIT INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(cmc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	cpu->core.status.c = (cpu->core.status.c == 0) ? 1 : 0;
	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(stc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	cpu->core.status.c = 1;
	INCR_PC_CNT(cpu);
}

// ---------------------------------------------------------------
//                 SINGLE REGISTER INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(inr_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];
	uint8_t *reg = common_func_get_reg(cpu, opcode);

	if (reg == &cpu->core.m) {
		uint16_t addr = (cpu->core.h << 8) | cpu->core.l;
		uint16_t val = ram->memory[addr]++;

		common_func_mem_zero_status_bit(cpu, val);
		common_func_mem_parity_status_bit(cpu, val);
		common_func_mem_sign_status_bit(cpu, val);

	}

	else {
		(*reg)++;
		common_func_reg_zero_status_bit(cpu, *reg);
		common_func_reg_parity_status_bit(cpu, *reg);
		common_func_reg_sign_status_bit(cpu, *reg);
	}

	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(dcr_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];
	uint8_t *reg = common_func_get_reg(cpu, opcode);

	if (reg == &cpu->core.m) {
		uint16_t addr = (cpu->core.h << 8) | cpu->core.l;
		uint16_t val = ram->memory[addr]--;

		common_func_mem_zero_status_bit(cpu, val);
		common_func_mem_parity_status_bit(cpu, val);
		common_func_mem_sign_status_bit(cpu, val);

	}

	else {
		*reg--;
		common_func_reg_zero_status_bit(cpu, *reg);
		common_func_reg_parity_status_bit(cpu, *reg);
		common_func_reg_sign_status_bit(cpu, *reg);
	}

	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(cma_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	cpu->core.accumulator = ~(cpu->core.accumulator);

	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(daa_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t lb_acc = cpu->core.accumulator & 0x0F;
	uint8_t hb_acc = cpu->core.accumulator & 0xF0;

	if (lb_acc > 9 || cpu->core.status.ac == 1) {
		cpu->core.accumulator += 6;

		if (hb_acc != cpu->core.accumulator & 0xF0)
			cpu->core.status.ac = 1;
	}

	hb_acc = (cpu->core.accumulator >> 4) & 0x0F;

	if (hb_acc > 9 || cpu->core.status.c == 1) {
		hb_acc += 9;
		cpu->core.accumulator = ((hb_acc << 4) & 0xF0) | cpu->core.accumulator & 0x0F;
	}

	INCR_PC_CNT(cpu);
}

// ---------------------------------------------------------------
//                 NOP INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(nop_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	INCR_PC_CNT(cpu);
}

// ---------------------------------------------------------------
//                 DATA TRANSFER INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(mov_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];
	uint16_t addr = 0x00;

	switch(opcode) {
		case 0x40:
			break;
		case 0x41:
			cpu->core.b = cpu->core.c;
			break;
		case 0x42:
			cpu->core.b = cpu->core.d;
			break;
		case 0x43:
			cpu->core.b = cpu->core.e;
			break;
		case 0x44:
			cpu->core.b = cpu->core.h;
			break;
		case 0x45:
			cpu->core.b = cpu->core.l;
			break;
		case 0x46:
			addr = (cpu->core.h << 8) | cpu->core.l;
			cpu->core.b = ram->memory[addr];
			break;
		case 0x47:
			cpu->core.b = cpu->core.a;
			break;
		case 0x48:
			cpu->core.c = cpu->core.b;
			break;
		case 0x49:
			break;
		case 0x4A:
			cpu->core.c = cpu->core.d;
			break;
		case 0x4B:
			cpu->core.c = cpu->core.e;
			break;
		case 0x4C:
			cpu->core.c = cpu->core.h;
			break;
		case 0x4D:
			cpu->core.c = cpu->core.l;
			break;
		case 0x4E:
			addr = (cpu->core.h << 8) | cpu->core.l;
			cpu->core.c = ram->memory[addr];
			break;
		case 0x4F:
			cpu->core.c = cpu->core.a;
			break;
		case 0x50:
			cpu->core.d = cpu->core.b;
			break;
		case 0x51:
			cpu->core.d = cpu->core.c;
			break;
		case 0x52:
			cpu->core.d = cpu->core.d;
			break;
		case 0x53:
			cpu->core.d = cpu->core.e;
			break;
		case 0x54:
			cpu->core.d = cpu->core.h;
			break;
		case 0x55:
			cpu->core.d = cpu->core.l;
			break;
		case 0x56:
			addr = (cpu->core.h << 8) | cpu->core.l;
			cpu->core.d = ram->memory[addr];
			break;
		case 0x57:
			cpu->core.d = cpu->core.a;
			break;
		case 0x58:
			cpu->core.e = cpu->core.b;
			break;
		case 0x59:
			cpu->core.e = cpu->core.c;
			break;
		case 0x5A:
			cpu->core.e = cpu->core.d;
			break;
		case 0x5B:
			cpu->core.e = cpu->core.e;
			break;
		case 0x5C:
			cpu->core.e = cpu->core.h;
			break;
		case 0x5D:
			cpu->core.e = cpu->core.l;
			break;
		case 0x5E:
			addr = (cpu->core.h << 8) | cpu->core.l;
			cpu->core.e = ram->memory[addr];
			break;
		case 0x5F:
			cpu->core.e = cpu->core.a;
			break;
		case 0x60:
			cpu->core.h = cpu->core.b;
			break;
		case 0x61:
			cpu->core.h = cpu->core.c;
			break;
		case 0x62:
			cpu->core.h = cpu->core.d;
			break;
		case 0x63:
			cpu->core.h = cpu->core.e;
			break;
		case 0x64:
			cpu->core.h = cpu->core.h;
			break;
		case 0x65:
			cpu->core.h = cpu->core.l;
			break;
		case 0x66:
			addr = (cpu->core.h << 8) | cpu->core.l;
			cpu->core.h = ram->memory[addr];
			break;
		case 0x67:
			cpu->core.h = cpu->core.a;
			break;
		case 0x68:
			cpu->core.l = cpu->core.b;
			break;
		case 0x69:
			cpu->core.l = cpu->core.c;
			break;
		case 0x6A:
			cpu->core.l = cpu->core.d;
			break;
		case 0x6B:
			cpu->core.l = cpu->core.e;
			break;
		case 0x6C:
			cpu->core.l = cpu->core.h;
			break;
		case 0x6D:
			cpu->core.l = cpu->core.l;
			break;
		case 0x6E:
			addr = (cpu->core.h << 8) | cpu->core.l;
			cpu->core.l = ram->memory[addr];
			break;
		case 0x6F:
			cpu->core.l = cpu->core.a;
			break;
		case 0x70:
			addr = (cpu->core.h << 8) | cpu->core.l;
			ram->memory[addr] = cpu->core.b;
			break;
		case 0x71:
			addr = (cpu->core.h << 8) | cpu->core.l;
			ram->memory[addr] = cpu->core.c;
			break;
		case 0x72:
			addr = (cpu->core.h << 8) | cpu->core.l;
			ram->memory[addr] = cpu->core.d;
			break;
		case 0x73:
			addr = (cpu->core.h << 8) | cpu->core.l;
			ram->memory[addr] = cpu->core.e;
			break;
		case 0x74:
			addr = (cpu->core.h << 8) | cpu->core.l;
			ram->memory[addr] = cpu->core.h;
			break;
		case 0x75:
			addr = (cpu->core.h << 8) | cpu->core.l;
			ram->memory[addr] = cpu->core.l;
			break;
		case 0x77:
			addr = (cpu->core.h << 8) | cpu->core.l;
			ram->memory[addr] = cpu->core.a;
			break;
		case 0x78:
			cpu->core.a = cpu->core.b;
			break;
		case 0x79:
			cpu->core.a = cpu->core.c;
			break;
		case 0x7A:
			cpu->core.a = cpu->core.d;
			break;
		case 0x7B:
			cpu->core.a = cpu->core.e;
			break;
		case 0x7C:
			cpu->core.a = cpu->core.h;
			break;
		case 0x7D:
			cpu->core.a = cpu->core.l;
			break;
		case 0x7E:
			addr = (cpu->core.h << 8) | cpu->core.l;
			cpu->core.a = ram->memory[addr];
			break;
		case 0x7F:
			cpu->core.a = cpu->core.a;
			break;
	
	}

	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(stax_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];
	uint16_t address = 0x00;

	if (opcode == 0x02) {
		address = cpu->core.b << 8 | cpu->core.c;
	} else {
		address = cpu->core.d << 8 | cpu->core.e;
	}

	ram->memory[address] = cpu->core.accumulator;

	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(ldax_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];
	uint16_t address = 0x00;

	if (opcode == 0x0A) {
		address = cpu->core.b << 8 | cpu->core.c;
	} else {
		address = cpu->core.d << 8 | cpu->core.e;
	}

	cpu->core.accumulator = ram->memory[address];
	
	INCR_PC_CNT(cpu);
}

// ---------------------------------------------------------------
//        REGISTER OR MEMORY TO ACCUMULATOR INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(ora_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(add_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(adc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(sub_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(sbb_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(ana_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(xra_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cmp_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
//              ROTATE ACCUMULATOR INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(rlc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rrc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(ral_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rar_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
//              REGISTER PAIR INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(push_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(pop_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(dad_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(inx_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(dcx_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(xchg_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(xthl_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(sphl_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
//              IMMEDIATE INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(mvi_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(adi_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(aci_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(sui_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(sbi_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(ani_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(xri_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(ori_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cpi_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(lxi_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
// 		DIRECT ADDRESSING INSTRUCTIONS
// ---------------------------------------------------------------
static uint16_t get_direct_address_from_mem(memory_t *mem, cpu_model_t *cpu)
{
	uint8_t laddr = mem->memory[cpu->core.pc+1];
	uint8_t haddr = mem->memory[cpu->core.pc+2];

	return ((haddr << 8) | laddr);
}

OPCODE_FUNC(sta_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint16_t addr = get_direct_address_from_mem(rom, cpu); 

	ram->memory[addr] = cpu->core.accumulator;

	INCR_PC_X_CNT(cpu, 3);
}

OPCODE_FUNC(lda_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint16_t addr = get_direct_address_from_mem(rom, cpu); 

	cpu->core.accumulator = ram->memory[addr];

	INCR_PC_X_CNT(cpu, 3);
}

OPCODE_FUNC(shld_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint16_t addr = get_direct_address_from_mem(rom, cpu); 

	ram->memory[addr] = cpu->core.l;
	ram->memory[addr +1] = cpu->core.h;

	INCR_PC_X_CNT(cpu, 3);
}

OPCODE_FUNC(lhld_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint16_t addr = get_direct_address_from_mem(rom, cpu); 

	cpu->core.l = ram->memory[addr];
	cpu->core.h = ram->memory[addr+1];

	INCR_PC_X_CNT(cpu, 3);
}

// ---------------------------------------------------------------
// 		JUMP INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(pchl_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jmp_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jnc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jz_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jnz_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jm_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jp_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jpe_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(jpo_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
// 		CALL SUBROUTINE INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(call_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cnc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cz_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cnz_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cm_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cp_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cpe_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cpo_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
// 		RETURN FROM SUBROUTINE INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(return_instr)(uint8_t flag, uint8_t arbiter, cpu_model_t* cpu)
{}

OPCODE_FUNC(ret_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rz_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rnz_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rnc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rm_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rp_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rpe_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rpo_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(rst_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
// 		INTERRUPT FLIP-FLOP INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(di_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(ei_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
// 		INPUT/OUTPUT INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(out_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(in_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

// ---------------------------------------------------------------
// 		HALT INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(hlt_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	INCR_PC_CNT(cpu);

	cpu->is_running = 0;
}

// -----------------------------------------------------------------------------------
void reset_cpu(cpu_model_t *cpu_8080)
{
	cpu_8080->is_running = 0;
	memset(&cpu_8080->core, 0, sizeof(cpu_core_t));
}

void cpu_set_accumulator_value(cpu_model_t *cpu_8080, uint8_t val)
{
	cpu_8080->core.accumulator = val;
}

uint8_t cpu_get_reg_value(cpu_model_t *cpu_8080, char reg)
{
	switch (reg) {
		case 'a':
			reg = cpu_8080->core.a;
			break;
		case 'b':
			reg = cpu_8080->core.b;
			break;
		case 'c':
			reg = cpu_8080->core.c;
			break;
		case 'd':
			reg = cpu_8080->core.d;
			break;
		case 'e':
			reg = cpu_8080->core.e;
			break;
		case 'h':
			reg = cpu_8080->core.h;
			break;
		case 'l':
			reg = cpu_8080->core.l;
			break;
		case 'm':
			reg = cpu_8080->core.m;
			break;
	}

	return reg;
}

// -----------------------------------------------------------------------------------
void cpu_set_reg_value(cpu_model_t *cpu_8080, char reg, uint8_t val)
{
	switch (reg) {
		case 'a':
			cpu_8080->core.a = val;
			break;
		case 'b':
			cpu_8080->core.b = val;
			break;
		case 'c':
			cpu_8080->core.c = val;
			break;
		case 'd':
			cpu_8080->core.d = val;
			break;
		case 'e':
			cpu_8080->core.e = val;
			break;
		case 'h':
			cpu_8080->core.h = val;
			break;
		case 'l':
			cpu_8080->core.l = val;
			break;
		case 'm':
			cpu_8080->core.m = val;
			break;
	}
}


// -----------------------------------------------------------------------------------
void execute_single_cpu_cycle(memory_t* ram, memory_t* rom, cpu_model_t* cpu_8080)
{
	uint16_t opcode = rom->memory[0];

	(*assembly_instr[opcode])(ram, rom, cpu_8080);

	display_curr_cpu_status(&cpu_8080->core);
}

// -----------------------------------------------------------------------------------
void execute_cpu(memory_t* ram, memory_t* rom, cpu_model_t* cpu_8080)   {

	while(rom->memory_size > cpu_8080->core.pc)   {

		if(cpu_8080->is_running == 1)
		{
			dissamble_curr_instr(rom, cpu_8080->core.pc);

			uint16_t opcode  = rom->memory[cpu_8080->core.pc];

			(*assembly_instr[opcode])(ram, rom, cpu_8080);
		}

		display_curr_cpu_status(&cpu_8080->core);	
	}
}
