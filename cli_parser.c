#include <string.h>
#include <stdio.h>
#include "cli_parser.h"
#include "cpu.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)	(sizeof(x)/(sizeof(x[0])))
#endif /* ARRAY_SIZE */

typedef struct ass_opcode {
	uint8_t opcode;
	char* ass_cmd;
} ass_opcode_t;

static const char* single_instr_tab[] = { "NOP" , "STAX", "INX", "INR", "DCR", "RLC", "RAL", "DAA",
       				          "STC", "DAD", "LDAX", "DCX", "RRC", "RAR", "CMA", "CMC",
					  "MOV", "HLT", "ADD", "ADC", "SUB", "SBB", "ANA", "XRA",
					  "ORA", "CMP", "RNZ", "RNC", "RPO", "RP", "POP", "XTHL",
					  "DI",  "PUSH", "RST", "RZ", "RC", "RPE", "RM", "RET",
					  "PCHL", "SPHL", "XCHG", "EI", NULL };
static const char* single_param_instr_tab[] = {"MVI", "OUT", "ADI", "SUI", "ANI", "ORI", "IN", "ACI", "SBI", "XRI", "CPI", NULL };
static const char* dual_param_instr_tab[] = {"LXI", "SHLD", "STA", "LHLD", "LDA", "JNZ", "JNC", "JPO", "JP" "JMP", "CNZ", "CNC", "CPO",
	                                     "CP", "JZ", "JC", "JPE", "JM", "CZ", "CC", "CPE", "CM", "CALL", NULL};
static const ass_opcode_t opcode_table[] = 
	{{0x00, "NOP"}, {0x01, "LXIB"}, {0x02, "STAXB"}, {0x03, "INXB"}, {0x04, "INRB"}, {0x05, "DCRB"}, {0x06, "MVIB"}, {0x07, "RLC"},
	 {0x08, "NOP"}, {0x09, "DADB"}, {0x0A, "LDAXB"}, {0x0B, "DCXB"}, {0x0C, "INRC"}, {0X0D, "DCRC"}, {0x0E, "MVIC"}, {0x0F, "RRC"},
	 {0x10, "NOP"}, {0x11, "LXID"}, {0x12, "STAXD"}, {0x13, "INXD"}, {0x14, "INRH"}, {0x15, "DCRH"}, {0x16, "MVIH"}, {0x17, "RAL"},
	 {0x18, "NOP"}, {0x19, "DADB"}, {0x1A, "LDAXB"}, {0x1B, "DCXB"}, {0x1C, "INRC"}, {0X1D, "DCRC"}, {0x1E, "MVIC"}, {0x1F, "RRC"},
	 {0x20, "NOP"}, {0x21, "LXID"}, {0x22, "STAXD"}, {0x23, "INXD"}, {0x24, "INRH"}, {0x25, "DCRH"}, {0x22, "MVIH"}, {0x27, "RAL"},
	 {0x28, "NOP"}, {0x29, "DADB"}, {0x2A, "LDAXB"}, {0x2B, "DCXB"}, {0x2C, "INRC"}, {0X2D, "DCRC"}, {0x2E, "MVIC"}, {0x2F, "RRC"},
	 {0x30, "NOP"}, {0x31, "LXID"}, {0x32, "STAXD"}, {0x33, "INXD"}, {0x34, "INRH"}, {0x35, "DCRH"}, {0x36, "MVIH"}, {0x37, "RAL"},
	 {0x38, "NOP"}, {0x39, "DADD"}, {0x3A, "LDAXD"}, {0x3B, "DCXD"}, {0x3C, "INRD"}, {0x3D, "DCRD"}, {0x3E, "MVID"}, {0x3F, "CMA"}};

static int search_for_assembly_table_entry(char *full_assembly)
{
	int count = 0;
	int array_size = ARRAY_SIZE(opcode_table);

	printf("ARRAY SIZE: %d\n", array_size);
	for (count = 0 ; count < array_size ;  count++) {
		if( strcmp(full_assembly, opcode_table[count].ass_cmd) == 0)
			return count;
	}

	return -1;
}

static bool extract_single_instr(char* ass_cmd, char *str, memory_t* rom)
{
	char *s = NULL;
	char temp_str[10] = {0};
	char *p = strcat(temp_str, ass_cmd);

	do {
		s = strtok(NULL, " ,");

		if (s != NULL)
			p = strcat(p, s);

	} while (s!=NULL);

	int index = search_for_assembly_table_entry(temp_str);

	if (index != -1) {
		rom->memory[0] = opcode_table[index].opcode;
		rom->memory_size = 1;
	}

	return (index != -1);
}

static bool extract_single_param(char* ass_cmd, memory_t* rom)
{
	return false;
}

static bool extract_dual_param(char *ass_cmd, memory_t *rom)
{
	return false;
}

bool is_valid_instr(char *ass_cmd, const char* instr_table[])
{
	int count = 0;

	while (instr_table[count] != NULL) {
		if (strcmp(instr_table[count], ass_cmd) == 0)
			return true;

		count++;
	}

	return false;
}

bool parse_opcode_cmd(memory_t *rom, char *cmd)
{
	bool is_valid_cmd = false;

	char *ass_cmd = strtok(cmd, " ");

	if (is_valid_instr(ass_cmd, single_instr_tab)) {
		is_valid_cmd = extract_single_instr(ass_cmd, cmd, rom);
	}

	else if (is_valid_instr(ass_cmd, single_param_instr_tab)) {
		is_valid_cmd = extract_single_param(cmd, rom);
	}

	else if (is_valid_instr(ass_cmd, dual_param_instr_tab)) {
		is_valid_cmd = extract_dual_param(cmd, rom);
	}

	else
	{}

	return is_valid_cmd;
}

void parse_get_reg_cmd(char *cmd)
{
}

void parse_get_ram_cmd(char *cmd)
{
}

cmd_type_t get_cmd(char *cmd)
{
	char kut[80] = {0};
	strcpy(kut, cmd);
	char *tok = strtok(kut, " ");

	if (strcmp(tok, "wreg") == 0) {
		return e_write_reg_cmd;
	}

	if (strcmp(tok, "rreg") == 0) {
		return e_read_reg_cmd;
	}

	if (strcmp(tok, "rram") == 0) {
		return e_read_ram_cmd;
	}

	if (strcmp(tok, "wram") == 0) {
		return e_write_ram_cmd;
	}

	if (strcmp(tok, "show") == 0) {
		return e_show_cpu_state_cmd;
	}

	if (strcmp(tok, "cram") == 0) {
		return e_clear_ram_cmd;
	}

	return e_opcode_cmd;
}


