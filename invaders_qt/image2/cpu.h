#ifndef CPU_H
#define CPU_H

typedef signed char         int8_t;
typedef unsigned char		uint8_t;

typedef signed short		int16_t;
typedef unsigned short		uint16_t;

typedef struct memory {
    unsigned short memory_size;
    unsigned char* memory;
} memory_t;

typedef union status_reg {

    struct {
        uint8_t c       : 1;
        uint8_t pad_1   : 1;
        uint8_t p       : 1;
        uint8_t pad_2   : 1;
        uint8_t ac      : 1;
        uint8_t pad_3   : 1;
        uint8_t z       : 1;
        uint8_t s       : 1;
    } bits;

    uint8_t reg;

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

    uint16_t stack;
    uint16_t pc;
    status_reg_t status;

} cpu_core_t;

typedef struct cpu_model {
    uint8_t		is_running;
    bool		interrupt_enable;
    cpu_core_t	core;
} cpu_model_t;

void execute_cpu(memory_t* mem, cpu_model_t* cpu_8080);
void execute_interrupt_opcode_cmd(memory_t *mem, cpu_model_t* cpu_8080);


#endif // CPU_H
