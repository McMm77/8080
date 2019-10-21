#ifndef __CPU_H__
#define __CPU_H__

#include <stdio.h>
#include <stdlib.h>
#include "common_types.h"

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

	uint8_t accumulator;	
	uint16_t stack;
	uint16_t pc;
	status_reg_t status;
	
} cpu_core_t;

typedef struct cpu_model {
	uint8_t		is_running;
	cpu_core_t	core;
} cpu_model_t;	


/* ---------------------------------------
 * Set the accumulator value
 */
void cpu_set_accumulator_value(cpu_model_t*, uint8_t);

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
void execute_single_cpu_cycle(memory_t*, memory_t*, cpu_model_t*);

/* ---------------------------------------
 * executes a program 
 */
void execute_cpu(memory_t*, memory_t*, cpu_model_t*);

/* ---------------------------------------
 * Returns pointer to the register
 */
uint8_t *common_func_get_reg(cpu_model_t*, uint8_t);

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

