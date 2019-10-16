#include "cpu.h"

#define REG_B_MASK	((uint8_t) (0b00000000))
#define REG_C_MASK	((uint8_t) (0b00001000))
#define REG_D_MASK	((uint8_t) (0b00010000))
#define REG_E_MASK	((uint8_t) (0b00011000))
#define REG_H_MASK	((uint8_t) (0b00100000))
#define REG_L_MASK	((uint8_t) (0b00101000))
#define REG_M_MASK	((uint8_t) (0b00110000))
#define REG_A_MASK	((uint8_t) (0b00111000))
#define REG_MASK	((uint8_t) (0b00111000))

uint8_t *common_func_get_reg(cpu_model_t *cpu, uint8_t opcode)
{
	uint8_t opcode_masked = opcode & REG_MASK;
	uint8_t *reg = NULL;
	
	switch (opcode_masked) {
		case REG_B_MASK:
			reg = &(cpu->core.b);
			break;
		case REG_C_MASK:
			reg = &(cpu->core.c);
			break;
		case REG_D_MASK:
			reg = &(cpu->core.d);
			break;
		case REG_E_MASK:
			reg = &(cpu->core.e);
			break;
		case REG_H_MASK:
			reg = &(cpu->core.h);
			break;
		case REG_L_MASK:
			reg = &(cpu->core.l);
			break;
		case REG_M_MASK:
			reg = &(cpu->core.m);
			break;
		case REG_A_MASK:
			reg = &(cpu->core.a);
			break;

	}

	return reg;
}

void common_func_reg_zero_status_bit(cpu_model_t* cpu, uint8_t reg)
{
	cpu->core.status.z = (reg==0) ? 1 : 0;
}

void common_func_reg_parity_status_bit(cpu_model_t* cpu, uint8_t reg)
{
	cpu->core.status.p = (reg&=0x01) ? 0 : 1;
}

void common_func_reg_sign_status_bit(cpu_model_t* cpu, uint8_t reg)
{
	cpu->core.status.s = (reg&=0x80) ? 1 : 0;
}

void common_func_mem_zero_status_bit(cpu_model_t* cpu, uint16_t reg)
{
	cpu->core.status.z = (reg==0) ? 1 : 0;
}

void common_func_mem_parity_status_bit(cpu_model_t* cpu, uint16_t reg)
{
	cpu->core.status.p = (reg&=0x01) ? 0 : 1;
}

void common_func_mem_sign_status_bit(cpu_model_t* cpu, uint16_t reg)
{
	cpu->core.status.s = (reg&=0x80) ? 1 : 0;
}
