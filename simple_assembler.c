#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_assembler.h"

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
	{{0x00, "NOP"}, {0x01, "LXIB"},  {0x02, "STAXB"}, {0x03, "INXB"},  {0x04, "INRB"}, {0x05, "DCRB"}, {0x06, "MVIB"}, {0x07, "RLC"},
	 {0x08, "NOP"}, {0x09, "DADB"},  {0x0A, "LDAXB"}, {0x0B, "DCXB"},  {0x0C, "INRC"}, {0X0D, "DCRC"}, {0x0E, "MVIC"}, {0x0F, "RRC"},

	 {0x10, "NOP"}, {0x11, "LXID"},  {0x12, "STAXD"}, {0x13, "INXD"},  {0x14, "INRD"}, {0x15, "DCRD"}, {0x16, "MVID"}, {0x17, "RAL"},
	 {0x18, "NOP"}, {0x19, "DADD"},  {0x1A, "LDAXD"}, {0x1B, "DCXD"},  {0x1C, "INRE"}, {0X1D, "DCRE"}, {0x1E, "MVIE"}, {0x1F, "RAR"},

	 {0x20, "NOP"}, {0x21, "LXIH"},  {0x22, "SHLD"},  {0x23, "INXH"},  {0x24, "INRH"}, {0x25, "DCRH"}, {0x22, "MVIH"}, {0x27, "DAA"},
	 {0x28, "NOP"}, {0x29, "DADH"},  {0x2A, "LHLD"},  {0x2B, "DCXH"},  {0x2C, "INRL"}, {0X2D, "DCRL"}, {0x2E, "MVIL"}, {0x2F, "CMA"},

	 {0x30, "NOP"}, {0x31, "LXISP"}, {0x32, "STA"},   {0x33, "INXSP"}, {0x34, "INRM"}, {0x35, "DCRM"}, {0x36, "MVIM"}, {0x37, "STC"},
	 {0x38, "NOP"}, {0x39, "DADSP"}, {0x3A, "LDA"},   {0x3B, "DCXSP"}, {0x3C, "INRA"}, {0x3D, "DCRA"}, {0x3E, "MVIA"}, {0x3F, "CMC"},
	 
	 {0x40, "MOVBB"}, {0x41, "MOVBC"},  {0x42, "MOVBD"}, {0x43, "MOVBE"},  {0x44, "MOVBH"}, {0x45, "MOVBL"}, {0x46, "MOVBM"}, {0x47, "MOVBA"},
	 {0x48, "MOVCB"}, {0x49, "MOVCC"},  {0x4A, "MOVCD"}, {0x4B, "MOVCE"},  {0x4C, "MOVCH"}, {0X4D, "MOVCL"}, {0x4E, "MOVCM"}, {0x4F, "MOVCA"},

	 {0x50, "MOVDB"}, {0x51, "MOVDC"},  {0x52, "MOVDD"},  {0x53, "MOVDE"},  {0x54, "MOVDH"}, {0x55, "MOVDL"}, {0x52, "MOVDM"}, {0x57, "MOVDA"},
	 {0x58, "MOVEB"}, {0x59, "MOVEC"},  {0x5A, "MOVED"},  {0x5B, "MOVEE"},  {0x5C, "MOVEH"}, {0X5D, "MOVEL"}, {0x5E, "MOVEM"}, {0x5F, "MOVEA"},
	 
	 {0x60, "MOVHB"}, {0x61, "MOVHC"},  {0x62, "MOVHD"}, {0x63, "MOVHE"},  {0x64, "MOVHH"}, {0x65, "MOVHL"}, {0x66, "MOVHM"}, {0x67, "MOVHA"},
	 {0x68, "MOVLB"}, {0x69, "MOVLC"},  {0x6A, "MOVLD"}, {0x6B, "MOVLE"},  {0x6C, "MOVLH"}, {0X6D, "MOVLL"}, {0x6E, "MOVLM"}, {0x6F, "MOVLA"},

	 {0x70, "MOVMB"}, {0x71, "MOVMC"},  {0x72, "MOVMD"},  {0x73, "MOVME"},  {0x74, "MOVMH"}, {0x75, "MOVML"}, {0x72, "HLT"}, {0x77, "MOVMA"},
	 {0x78, "MOVAB"}, {0x79, "MOVAC"},  {0x7A, "MOVAD"},  {0x7B, "MOVAE"},  {0x7C, "MOVAH"}, {0X7D, "MOVAL"}, {0x7E, "MOVAM"}, {0x7F, "MOVAA"},
	
	};

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

static bool is_valid_instr(char *ass_cmd, const char* instr_table[])
{
	int count = 0;

	while (instr_table[count] != NULL) {
		if (strcmp(instr_table[count], ass_cmd) == 0)
			return true;

		count++;
	}

	return false;
}

bool assemble(memory_t *rom, char *cmd)
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

