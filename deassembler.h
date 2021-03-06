#ifndef __DEASSEMBLER_H__
#define __DEASSEMBLER_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common_types.h"

#define DISAMMBLER_VERSION_MAJOR		0
#define DISAMMBLER_VERSION_MINOR		1

typedef unsigned char 	uint8_t;
typedef unsigned short 	uint16_t;
typedef unsigned long 	uint32_t;

const char* dissamble_single_cmd(uint8_t* mem);
void dissamble(memory_t* rom);

#endif /* __DEASSEMBLER_H__ */
