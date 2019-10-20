#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"
#include "cli_parser.h"

#define EMULATOR_VERSION_MAJOR		0
#define EMULATOR_VERSION_MINOR		1

#define RAM_SIZE			(16*1024)

memory_t ram_memory = {0, NULL};
memory_t rom_memory = {0, NULL};

static inline size_t get_file_size(FILE* pFile)
{
   fseek(pFile, 0, SEEK_END);
   size_t size = ftell(pFile);
   
   rewind(pFile);

   return size;
}

static int load_rom_memory_from_file(const char* rom_file, memory_t* rom_mem)
{
	FILE* pInputFile = fopen(rom_file, "rb");
	
	if(pInputFile == NULL) {
		printf("ERROR: Rom file not found\n");
		return -1;
	}
	
	size_t file_size = get_file_size(pInputFile);
   
	rom_mem->memory = (uint8_t*) malloc(file_size);
	
	if(rom_mem->memory == NULL) {
		printf("ERROR: Failed to allocate ROM memory\n");
		return -1;
	}
	
	rom_mem->memory_size = file_size;
	
	fread(rom_mem->memory, 1, file_size, pInputFile);
	
	return 0;
}

static void create_ram_memory()
{
	ram_memory.memory = (uint8_t*) malloc(RAM_SIZE);
	ram_memory.memory_size = RAM_SIZE;

	if(ram_memory.memory == NULL) {
		printf("ERROR: Failed to allocate RAM memory\n");
		exit(0);
	}
}

static int create_test_rom_image(memory_t* rom_mem)
{
	uint8_t memcpy_opcode[] = { 0x78, 0xB1, 0xC8, 0x1A, 0x77, 0x13, 0x23, 0x0B, 0x78, 0xB1, 0xC2, 0x03, 0x00, 0xC9 };

	rom_mem->memory = malloc(sizeof(memcpy_opcode));
	rom_mem->memory_size = sizeof(memcpy_opcode);

	memcpy(rom_mem->memory, memcpy_opcode, sizeof(memcpy_opcode));
}


static bool get_opcode(memory_t* mem, char* ass_code)
{
	memset(mem->memory, 0, 4);

	mem->memory[0] = 0x04;
	mem->memory_size = 1;

	return 1;
}

static void write_to_reg(char *str, cpu_model_t *cpu)
{
	char *reg = strtok(NULL, " ");
	char *val = strtok(NULL, " ");

	uint8_t reg_val = (uint8_t) atoi(val);

	cpu_set_reg_value(cpu, *reg, reg_val);
}

static void write_to_ram(char *str, cpu_model_t *cpu)
{
}

static void opcode_cmd(char *str, cpu_model_t *cpu, memory_t *rom)
{
	if (parse_opcode_cmd(rom, str) == true) {
		execute_single_cpu_cycle(&ram_memory, rom, cpu);
	}

	else {
		printf("Unrecognizable assembly command\n");
	}
}

static void show_cpu_state(cpu_model_t *cpu)
{
	display_cpu_status(cpu);
}

static void execute_cmd(cmd_type_t cmd, char *str, cpu_model_t *cpu, memory_t* rom)
{
	switch(cmd) {
		case e_write_reg_cmd:
			write_to_reg(str, cpu);
			break;
		case e_write_ram_cmd:
			write_to_ram(str, cpu);
			break;
		case e_show_cpu_state_cmd:
			show_cpu_state(cpu);
			break;
		case e_opcode_cmd:
			opcode_cmd(str, cpu, rom);
			break;
	}
}

static void enter_cli()
{
	uint8_t bLoop = 0;

	cpu_model_t cpu = {0};
	rom_memory.memory = malloc(4);
	rom_memory.memory_size = 0;

	while(bLoop == 0) {
		char str[80] = {0};

		printf("Assembly Code << ");
		int ret = scanf(" %[^\n]s", str);

		execute_cmd(get_cmd(str), str, &cpu, &rom_memory);
	}
}

static void enter_bin(char* rom_file)
{
	cpu_model_t cpu = {0};
	
	if(load_rom_memory_from_file(rom_file, &rom_memory) != 0)   {
		exit(0);
	}

	execute_cpu(&ram_memory, &rom_memory, &cpu);
}

static void enter_test_image() {

	cpu_model_t cpu = {0};

	create_test_rom_image(&rom_memory);

	execute_cpu(&ram_memory, &rom_memory, &cpu);
}

static void execute_code(char exec, int argc, char* argv[])
{
	if (exec == 'c') {
		printf("8080 Emulator Cli Mode\n");
		enter_cli();
	}

	else if(exec == 'b' && argc >= 3) {
		printf("8080 Emulator Normal Mode\n");
		enter_bin(argv[2]);
	}

	else if(exec == 't' ) {
		printf("8080 Emulator Test Image Mode\n");
		enter_test_image();
	}

	else {
		printf("Invalid arguments provided\n");
		exit(0);
	}
}

int main(int argc, char* argv[])
{
	printf("8080 Emulator - Version %d.%02d\n", EMULATOR_VERSION_MAJOR, EMULATOR_VERSION_MINOR);

	if(argc >= 2)   {
	
		if(argv[1][0] != '-') {
			printf("Error No arguments provided\n");
			exit(0);
		}

		create_ram_memory();
		execute_code(argv[1][1], argc, argv);
	}


	return 0;
}
