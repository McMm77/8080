#include "cpu.h"

typedef unsigned long uint32_t;

#define OPCODE_INSTR		(0xFF)
#define OPCODE_FUNC(a)		static void a
#define INCR_PC_CNT(cpu_ptr)	(cpu_ptr->core.pc++)

typedef struct status_reg {

	int c       : 1;
	int pad_1   : 1;
	int p       : 1;
	int pad_2   : 1;
	int ac      : 1;
	int pad_3   : 1;
	int z       : 1;
	int s       : 1;

} status_reg_t;

typedef struct cpu_core {
	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t d;
	uint8_t e;
	uint8_t h;
	uint8_t l;
	uint8_t m;
	
	uint16_t stack;
	uint16_t pc;
	status_reg_t status;
	
} cpu_core_t;

typedef struct cpu_model {
	uint8_t		is_running;
	cpu_core_t	core;
} cpu_model_t;	

static void display_curr_cpu_status(cpu_core_t* core)
{
	printf("\n--------------------------");
	printf("------ CPU STATUS --------\n");
	printf("Stack: %d\n", core->stack);
	printf("PC: %d\n", core->pc);
	printf("Reg A: 0x%02x\t\tReg B 0x%02x\n", core->a, core->b);
	printf("Reg C: 0x%02x\t\tReg D 0x%02x\n", core->c, core->d);
	printf("Reg E: 0x%02x\t\tReg H 0x%02x\n", core->e, core->h);
	printf("Reg L: 0x%02x\t\tReg M 0x%02x\n", core->l, core->m);
	printf("Status: C: %d P: %d AC: %d z: %d s: %d\n", core->status.c, core->status.p, core->status.ac, core->status.z, core->status.s);
        printf("----------------------------\n");	

}

extern void dissamble_curr_instr(memory_t*, int);

static cpu_model_t	cpu = {0};

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


/* -------------------------------------------------------------- */

static void push_to_stack(cpu_model_t* cpu, uint8_t val)
{
}

static uint8_t pull_from_stack(cpu_model_t* cpu)
{
	return 0;
}

static void push_to_memory(memory_t* ram, cpu_model_t* cpu, uint16_t addr, uint8_t val)
{
}

static uint8_t pull_from_memory(memory_t* ram, cpu_model_t* cpu, uint16_t addr)
{
	return 0;
}

// ---------------------------------------------------------------
//                 CARRY BIT INSTRUCTIONS
// ---------------------------------------------------------------
OPCODE_FUNC(cmc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	cpu->core.status.c ^= cpu->core.status.c;
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
{}


OPCODE_FUNC(dcr_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(cma_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(daa_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

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
static inline void move_regval_from_to(uint8_t* reg_src, uint8_t* reg_dest)   {
	*reg_dest = *reg_src;
}

OPCODE_FUNC(mov_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];

	switch(opcode)   {
	   case 0x77:
		move_regval_from_to( &(cpu->core.b), &(cpu->core.a));
		break;

	   case 0x78:
		move_regval_from_to( &(cpu->core.a), &(cpu->core.m));
		break;
	}

	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(stax_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(ldax_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint16_t offset = 0;
	uint8_t opcode = rom->memory[cpu->core.pc];

	switch(opcode)
	{
	    case 0x0A:
		offset = (cpu->core.b << 8) | (cpu->core.c);
		cpu->core.a = *(ram->memory + offset);
		break;

	    case 0x1A:
		offset = (cpu->core.d << 8) | (cpu->core.e);
		cpu->core.a = *(ram->memory + offset);
		break;
	}
	
	INCR_PC_CNT(cpu);
}

// ---------------------------------------------------------------
//        REGISTER OR MEMORY TO ACCUMULATOR INSTRUCTIONS
// ---------------------------------------------------------------
static void ora_val(uint8_t* reg, cpu_model_t* cpu)
{
	uint8_t alu = cpu->core.a | *reg;

	cpu->core.status.z = (alu != 0x00) ? 0 : 1;
	cpu->core.status.s = (alu &= 0x80) ? 1 : 0;
	cpu->core.status.p = (alu &= 0x01) ? 0 : 1;

	cpu->core.a = alu;
}

OPCODE_FUNC(ora_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];

	switch(opcode)	{
	    case 0xB0:
		ora_val(&(cpu->core.b), cpu);
		break;
	    case 0xB1:
		ora_val(&(cpu->core.c), cpu);
		break;
	    case 0xB2:
		ora_val(&(cpu->core.d), cpu);
		break;
	    case 0xB3:
		ora_val(&(cpu->core.e), cpu);
		break;
	    case 0xB4:
		ora_val(&(cpu->core.h), cpu);
		break;
	    case 0xB5:
		ora_val(&(cpu->core.l), cpu);
		break;
	    case 0xB6:
		ora_val(&(cpu->core.m), cpu);
	        break;
	    case 0xB7:
		ora_val(&(cpu->core.a), cpu);
                break;
	}

	INCR_PC_CNT(cpu);
}

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
static void inx(uint8_t* left, uint8_t* right)
{
	uint32_t reg_val = (*left << 8) | *right;

	reg_val++;
	reg_val &= 0x0000FFFF;
	
	*left  = (reg_val >> 8) && 0xFF;
	*right = (reg_val >> 0) && 0xFF;
	
}

static void dcx(uint8_t* left, uint8_t* right)
{
	uint16_t reg_val = (*left << 8) | *right;

	reg_val = (reg_val != 0x00) ? reg_val-- : 0xFFFF;

	*left = (reg_val >> 8) & 0xFF;
	*right = (reg_val >> 0) & 0xfF;	
}

OPCODE_FUNC(push_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(pop_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];

	switch(opcode)
	{
	}

}

void dad_common_instr(uint16_t* hl, uint16_t* ot, cpu_model_t* cpu)
{
	uint32_t res = *hl + *ot;

	cpu->core.status.c = (res & 0x00010000) ? 1 : 0;

	*hl = (uint16_t) res & 0x0000FFFF;
}

OPCODE_FUNC(dad_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];
	uint16_t hl_reg = cpu->core.h << 8 | cpu->core.l;
	uint16_t ot_reg = 0;

	switch(opcode)
	{
		case 0x09:
			ot_reg = cpu->core.b << 8 | cpu->core.c;
			break;

		case 0x19:
			ot_reg = cpu->core.d << 8 | cpu->core.e;
			break;

		case 0x29:
			ot_reg = hl_reg;
			break;

		case 0x39:
			ot_reg = cpu->core.stack;
			break;
	}

	dad_common_instr(&hl_reg, &ot_reg, cpu);

	cpu->core.h = (hl_reg >> 8) & 0x00FF;
	cpu->core.l = (hl_reg >> 0) & 0x00FF;
}

OPCODE_FUNC(inx_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];

	switch(opcode)
	{
		case 0x03:
			inx(&cpu->core.b, &cpu->core.c);
			break;

		case 0x13:
			inx(&cpu->core.d, &cpu->core.e);
			break;

		case 0x23:
			inx(&cpu->core.h, &cpu->core.l);
			break;

		case 0x33:
			cpu->core.stack = (cpu->core.stack <= 0xFFFE) ? cpu->core.stack++ : 0x0000;
			break;
	}

	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(dcx_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t opcode = rom->memory[cpu->core.pc];
	
	switch(opcode)
	{
		case 0x0B:
			dcx(&cpu->core.b, &cpu->core.c);
			break;
		case 0x1B:
			dcx(&cpu->core.d, &cpu->core.e);
			break;
		case 0x2B:
			dcx(&cpu->core.h, &cpu->core.l);
			break;
		case 0x3B:
			cpu->core.stack = (cpu->core.stack != 0x00) ? cpu->core.stack-- : 0xFFFF;
			break;
	}

	INCR_PC_CNT(cpu);
}

static void exchange_registers(uint8_t* left, uint8_t* right)
{
	uint8_t temp_reg = *left;
	*left = temp_reg;
	*right = *left;
}

OPCODE_FUNC(xchg_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	exchange_registers(&cpu->core.h, &cpu->core.d);
	exchange_registers(&cpu->core.l, &cpu->core.e);

	INCR_PC_CNT(cpu);
}

OPCODE_FUNC(xthl_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	uint8_t msb = pull_from_memory(ram, cpu, cpu->core.stack);
        uint8_t lsb = pull_from_memory(ram, cpu, cpu->core.stack+1);

	exchange_registers(&msb, &cpu->core.h);
	exchange_registers(&lsb, &cpu->core.l);

	push_to_memory(ram, cpu, cpu->core.stack, msb);
	push_to_memory(ram, cpu, cpu->core.stack+1, lsb);

	INCR_PC_CNT(cpu);	
}

OPCODE_FUNC(sphl_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	cpu->core.stack = cpu->core.h << 8 & cpu->core.l;

	INCR_PC_CNT(cpu);
}
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
OPCODE_FUNC(sta_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(lda_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(shld_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

OPCODE_FUNC(lhld_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{}

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
{
	uint8_t opcode = ram->memory[cpu->core.pc];
	uint16_t parameter = (ram->memory[cpu->core.pc+2] << 8) | ram->memory[cpu->core.pc+1];

	if(cpu->core.status.s == 0)   {
		cpu->core.pc = parameter;
	}

	else   {
		cpu->core.pc += 3;
	}
}

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
{
	if(flag == arbiter) {
		cpu->core.pc = pull_from_stack(cpu) << 8 | pull_from_stack(cpu);
	}

	else {
		INCR_PC_CNT(cpu);
	}
}

OPCODE_FUNC(ret_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	return_instr(0,0, cpu);
}

OPCODE_FUNC(rz_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	return_instr(cpu->core.status.z, 1, cpu);
}

OPCODE_FUNC(rnz_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	return_instr(cpu->core.status.z, 0, cpu);
}

OPCODE_FUNC(rc_instr)(memory_t* ram, memory_t* rois_runningm, cpu_model_t* cpu)
{
	return_instr(cpu->core.status.c, 0, cpu);
}


OPCODE_FUNC(rnc_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	return_instr(cpu->core.status.c, 0, cpu);
}

OPCODE_FUNC(rm_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	return_instr(cpu->core.status.s, 0, cpu);
}

OPCODE_FUNC(rp_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	return_instr(cpu->core.status.s, 1, cpu);
}

OPCODE_FUNC(rpe_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	return_instr(cpu->core.status.p, 1, cpu);
}

OPCODE_FUNC(rpo_instr)(memory_t* ram, memory_t* rom, cpu_model_t* cpu)
{
	return_instr(cpu->core.status.p, 0, cpu);
}

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

static void cpu_latch_time(cpu_model_t* cpu)
{}

static void cpu_check_for_interrupts(cpu_model_t* cpu)
{}


void execute_cpu(memory_t* ram, memory_t* rom)   {

	while(rom->memory_size > cpu.core.pc)   {

		if(cpu.is_running == 1)
		{
			dissamble_curr_instr(rom, cpu.core.pc);

			uint16_t opcode  = rom->memory[cpu.core.pc];

			(*assembly_instr[opcode])(ram, rom, &cpu);
				
			cpu_latch_time(&cpu);	
		}

		cpu_check_for_interrupts(&cpu);

		display_curr_cpu_status(&cpu.core);	
	}

	printf("End of program\n");
}
