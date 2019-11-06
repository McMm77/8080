#include "cpu.h"

typedef enum opcode_index {
        eNOP1 = 0, eLXIB, eSTAXB, eINXB, eINRB, eDCRB, eMVIB, eRLC, eNOP2, eDADB, eLDAXB, eDCXB, eINRC, eDCRC, eMVIC, eRRC,
        eNOP3,     eLXID, eSTAXD, eINXD, eINRD, eDCRD, eMVID, eRAL, eNOP4, eDADD, eLDAXD, eDCXD, eINRE, eDCRE, eMVIE, eRAR
} opcode_index_t;

typedef struct opcode_instr opcode_instr_t;

typedef void (*opcode_handler) (opcode_instr_t*, memory_t*, cpu_model_t*);

struct opcode_instr {
        opcode_index_t index;           /* opcode index */
        char *ass_uniq_cmd;             /* unique readable command */
        char *ass_cmd;                  /* readable command */
        uint8_t min_cycle_time;         /* minimal cycle time (in case of branch) */
        uint8_t max_cycle_time;         /* maximal cycle time (in case of branch) */
        uint8_t cycle_time;             /* current cycle time */
        uint8_t opcode_size;            /* opcode size (1,2 or 3) */
        opcode_handler func;            /* function pointer to handler */
};

static inline void increase_program_counter(cpu_model_t*, opcode_instr_t*);
static inline void set_program_counter(cpu_model_t*, uint16_t);

static void opcode_handler_not_supported(opcode_instr_t*, memory_t*, cpu_model_t*);

static void opcode_handler_nop(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_lxib(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_staxb(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_inxb(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_inrb(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_dcrb(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_mvib(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_rlc(opcode_instr_t*, memory_t*, cpu_model_t*);

static void opcode_handler_dadb(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_ldaxb(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_dcxb(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_inrc(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_dcrc(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_mvic(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_rrc(opcode_instr_t*, memory_t*, cpu_model_t*);

static void opcode_handler_lxid(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_staxd(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_inxd(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_inrd(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_dcrd(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_mvid(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_ral(opcode_instr_t*, memory_t*, cpu_model_t*);

static void opcode_handler_dadd(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_ldaxd(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_dcxd(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_inre(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_dcre(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_mvie(opcode_instr_t*, memory_t*, cpu_model_t*);
static void opcode_handler_rar(opcode_instr_t*, memory_t*, cpu_model_t*);


static opcode_instr_t opcode_table[] = {{eNOP1, "NOP1", "NOP", 4, 4, 4, 1, opcode_handler_nop},
                                        {eLXIB, "LXIB", "LXI B", 10, 10, 10, 3, opcode_handler_lxib},
                                        {eSTAXB, "STAXB", "STAX B", 7, 7, 7, 1, opcode_handler_staxb},
                                        {eINXB, "INXB", "INX B", 5, 5, 5, 1, opcode_handler_inxb},
                                        {eINRB, "INRB", "INR B", 5, 5, 5, 1, opcode_handler_inrb},
                                        {eDCRB, "DCRB", "DCR B", 5, 5, 5, 1, opcode_handler_dcrb},
                                        {eMVIB, "MVIB", "MVI B", 7, 7, 7, 2, opcode_handler_mvib},
                                        {eRLC, "RLC", "RLC", 4, 4, 4, 1, opcode_handler_rlc},
                                        {eNOP2, "NOP2", "NOP", 4, 4, 4, 1, opcode_handler_not_supported},
                                        {eDADB, "DADB", "DAD B", 10, 10, 10, 1, opcode_handler_dadb},
                                        {eLDAXB, "LDAXB", "LDAX B", 7, 7, 7, 1, opcode_handler_ldaxb},
                                        {eDCXB, "DCXB", "DCX B", 5, 5, 5, 1, opcode_handler_dcxb},
                                        {eINRC, "INRC", "INR C", 5, 5, 5, 1, opcode_handler_inrc},
                                        {eDCRC, "DCRC", "DCR C", 5, 5, 5, 1, opcode_handler_dcrc},
                                        {eMVIC, "MVIC", "MVI C", 7, 7, 7, 2, opcode_handler_mvic},
                                        {eNOP3, "NOP3", "NOP", 4, 4, 4, 1, opcode_handler_not_supported},
                                        {eRRC, "RRC", "RR C", 4, 4, 4, 1, opcode_handler_rrc},
                                        {eLXID, "LXID", "LXI D", 10, 10, 10, 3, opcode_handler_lxid},
                                        {eSTAXD, "STAXD", "STAX D", 7, 7, 7, 1, opcode_handler_staxd},
                                        {eINXD, "INXD", "INX D", 5, 5, 5, 1, opcode_handler_inxd},
                                        {eINRD, "INRD", "INR D", 5, 5, 5, 1, opcode_handler_inrd},
                                        {eDCRD, "DCRD", "DCR D", 5, 5, 5, 1, opcode_handler_dcrd},
                                        {eMVID, "MVID", "MVI D", 7, 7, 7, 2, opcode_handler_mvid},
                                        {eRAL, "RAL", "RAL", 4, 4, 4, 1, opcode_handler_ral},
                                        {eNOP4, "NOP4", "NOP", 4, 4, 4, 1, opcode_handler_not_supported},
                                        {eDADD, "DADD", "DAD D", 10, 10, 10, 1, opcode_handler_dadd},
                                        {eLDAXD, "LDAXD", "LDAX D", 7, 7, 7, 1, opcode_handler_ldaxd},
                                        {eDCXD, "DCXD", "DCX D", 5, 5, 5, 1, opcode_handler_dcxd},
                                        {eINRE, "INRE", "INR E", 5, 5, 5, 1, opcode_handler_inre},
                                        {eDCRE, "DCRE", "DCR E", 5, 5, 5, 1, opcode_handler_dcre},
                                        {eMVIE, "MVIE", "MVI E", 7, 7, 7, 2, opcode_handler_mvie},
                                        {eRAR, "RAR", "RAR", 4, 4, 4, 1, opcode_handler_rar}
};

static void opcode_handler_not_supported(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_nop(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_lxib(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_staxb(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_inxb(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_inrb(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_dcrb(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_mvib(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_rlc(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_dadb(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_ldaxb(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_dcxb(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_inrc(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_dcrc(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_mvic(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_rrc(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_lxid(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_staxd(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_inxd(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_inrd(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_dcrd(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_mvid(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_ral(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_dadd(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_ldaxd(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_dcxd(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_inre(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_dcre(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_mvie(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

static void opcode_handler_rar(opcode_instr_t *opcode, memory_t *mem, cpu_model_t *cpu)
{}

