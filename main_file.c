#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"

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

static int create_test_rom_image(memory_t* rom_mem)
{
	uint8_t memcpy_opcode[] = { 0x78, 0xB1, 0xC8, 0x1A, 0x77, 0x13, 0x23, 0x0B, 0x78, 0xB1, 0xC2, 0x03, 0x00, 0xC9 };
	// uint8_t memcpy_opcode[] = {0x00, 0x01, 0x00, 0x01};
	

	rom_mem->memory = malloc(sizeof(memcpy_opcode));
	rom_mem->memory_size = sizeof(memcpy_opcode);

	memcpy(rom_mem->memory, memcpy_opcode, sizeof(memcpy_opcode));
}

int main(int argc, char* argv[])
{
	printf("8080 Emulator - Version %d.%02d\n", EMULATOR_VERSION_MAJOR, EMULATOR_VERSION_MINOR);

	if(argc >= 2)   {
	
		if(load_rom_memory_from_file(argv[1], &rom_memory) != 0)   {
			exit(0);
		}
	}

	else {
		printf("ERROR: No ROM Image provided\n");

		create_test_rom_image(&rom_memory);
	}


	ram_memory.memory = (uint8_t*) malloc(RAM_SIZE);
	ram_memory.memory_size = RAM_SIZE;

	if(ram_memory.memory == NULL) {
		printf("ERROR: Failed to allocate RAM memory\n");
		exit(0);
	}

	execute_cpu(&ram_memory, &rom_memory);

	return 0;
}
