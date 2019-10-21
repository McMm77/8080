#include <string.h>
#include <stdio.h>
#include "cli_parser.h"
#include "cpu.h"
#include "simple_assembler.h"

bool parse_opcode_cmd(memory_t *rom, char *cmd)
{
	bool is_valid_cmd = assemble(rom, cmd);

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
	char temp_cmd[80] = {0};
	strcpy(temp_cmd, cmd);
	char *tok = strtok(temp_cmd, " ");

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

	if (strcmp(tok, "read_acc") == 0) {
		return e_read_accumulator_cmd;
	}

	if (strcmp(tok, "write_acc") == 0) {
		return e_write_accumulator_cmd;
	}

	return e_opcode_cmd;
}


