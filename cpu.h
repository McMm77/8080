#ifndef __CPU_H__
#define __CPU_H__

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"

typedef union status_reg {

	struct {
		uint8_t c       : 1;
		uint8_t pad_1   : 1;
		uint8_t p       : 1;
		uint8_t pad_2   : 1;
		uint8_t ac      : 1;
		uint8_t pad_3   : 1;
		uint8_t z       : 1;
		uint8_t s       : 1;
	} bits;

	uint8_t reg;	

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
	bool		interrupt_enable;	
	cpu_core_t	core;
} cpu_model_t;	

void execute_interrupt_opcode_cmd(memory_t *ram, memory_t* cmd, cpu_model_t* cpu_8080);

/* ---------------------------------------
 * Sets a reg value
 */
void cpu_set_reg_value(cpu_model_t*, char, uint8_t);

/* ---------------------------------------
 * Display Current CPU Status
 */
void display_cpu_status(cpu_model_t*);

/* ---------------------------------------
 * Reset the CPU
 */
void reset_cpu(cpu_model_t*);

/* ---------------------------------------
 * Executes a single instruction
 */
bool execute_single_cpu_cycle(memory_t*, memory_t*, cpu_model_t*);

/* ---------------------------------------
 * executes a program 
 */
void execute_cpu(memory_t*, memory_t*, cpu_model_t*);

/* ---------------------------------------
 * Returns pointer to the register
 */
uint8_t *common_func_get_reg(cpu_model_t*, uint8_t);

void display_curr_cpu_status(cpu_core_t* core);

/* ---------------------------------------
 * Will (re)set the zero status but depending of the 
 * reg value
 */
void common_func_reg_zero_status_bit(cpu_model_t*, uint8_t);

/* Will (re)set the parity status bit depending of the 
 * reg value
 */
void common_func_reg_parity_status_bit(cpu_model_t*, uint8_t);

/* Will (re) set the sign status bit depending of the
 * reg value
 */
void common_func_reg_sign_status_bit(cpu_model_t*, uint8_t);

/* ---------------------------------------
 * Will (re)set the zero status but depending of the 
 * mem value
 */
void common_func_mem_zero_status_bit(cpu_model_t*, uint16_t);

/* Will (re)set the parity status bit depending of the 
 * mem value
 */
void common_func_mem_parity_status_bit(cpu_model_t*, uint16_t);

/* Will (re) set the sign status bit depending of the
 * mem value
 */
void common_func_mem_sign_status_bit(cpu_model_t*, uint16_t);

#endif /* __CPU_H__ */

