#include <string.h>
#include <stdio.h>
#include "cli_parser.h"
#include "cpu.h"
<<<<<<< HEAD
=======
#include "simple_assembler.h"
#include <string.h>
#include <ctype.h>
>>>>>>> e9475a4... fixup! emulator_8080: add cli parser

void parse_opcode_cmd(memory_t *rom, char *cmd)
{
}

void parse_get_reg_cmd(char *cmd)
{
}

void parse_get_ram_cmd(char *cmd)
{
}

static void make_string_uppercase(char *cmd)
{
	uint8_t cnt = 0;
	while(cmd[cnt]) {
		cmd[cnt] = toupper(cmd[cnt]);
		cnt++;
	}
}

cmd_type_t get_cmd(char *cmd)
{
	char temp_cmd[80] = {0};
	make_string_uppercase(cmd);

	strcpy(temp_cmd, cmd);
	char *tok = strtok(temp_cmd, " ");

	if (strcmp(tok, "WREG") == 0) {
		return e_write_reg_cmd;
	}

	if (strcmp(tok, "RREG") == 0) {
		return e_read_reg_cmd;
	}

	if (strcmp(tok, "RRAM") == 0) {
		return e_read_ram_cmd;
	}

	if (strcmp(tok, "WRAM") == 0) {
		return e_write_ram_cmd;
	}

	if (strcmp(tok, "SHOW") == 0) {
		return e_show_cpu_state_cmd;
	}

	if (strcmp(tok, "CRAM") == 0) {
		return e_clear_ram_cmd;
	}

	return e_opcode_cmd;
}


