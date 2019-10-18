#include <string.h>
#include <stdio.h>
#include "cli_parser.h"
#include "cpu.h"

typedef struct ass_opcode {
	uint8_t opcode;
	char ass_cmd[];
} ass_opcode_t;


static ass_opcode_t opcode_table[] = 
	{{0x00, "NOP"}, {2, "LXIB"}, {3, "STAXB"}, {4, "INXB"}, {5, "INRB"}, {6, "DCRB"}, {7, "MVIB"}, {8, "RLC"}};

void parse_opcode_cmd(memory_t *rom, char *cmd)
{
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


