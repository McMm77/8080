#ifndef __COMMON_TYPES_H__
#define __COMMON_TYPES_H__

typedef signed char		int8_t;
typedef unsigned char		uint8_t;

typedef signed short		int16_t;
typedef unsigned short		uint16_t;

//typedef unsigned long		uint32_t;

typedef struct memory {
	size_t memory_size;
#ifdef dgconfig_DEASSEMBLER
	int index;
#endif
	uint8_t* memory;
} memory_t;

#endif
