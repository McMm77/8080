#include "cpu.h"

typedef enum opcode_index {
        eNOP1 = 0, eLXIB,   eSTAXB,  eINXB,   eINRB,  eDCRB,    eMVIB,  eRLC,   eNOP2,  eDADB,  eLDAXB,  eDCXB,  eINRC,  eDCRC,  eMVIC,  eRRC,
        eNOP3,     eLXID,   eSTAXD,  eINXD,   eINRD,  eDCRD,    eMVID,  eRAL,   eNOP4,  eDADD,  eLDAXD,  eDCXD,  eINRE,  eDCRE,  eMVIE,  eRAR,
	eNOP4,     eLXIH,   eSHLD,   eINXH,   eINRH,  eDCRH,    eMVIH,  eDAA,   eNOP5,  eDADH,  eLHLD,   eDCXH,  eINRL,  eDCRL,  eMVIL,  eCMA,
	eNOP6,     eLXISP,  eSTA,    eINXSP,  eINRM,  eDCRM,    eMVIM,  eSTC,   eNOP7,  eDADSP, eLDA,    eDCX,   eINRA,  eDCRA,  eMVIA,  eCMC,
	eMOVBB,    eMOVBC,  eMOVBD,  eMOBBE,  eMOVBH, eMOVBL,   eMOVBM, eMOVBA, eMOVCB, eMOVCC, eMOVCD,  eMOVCE, eMOVCH, eMOVCL, eMOVCM, eMOVCA,
	eMOVDB,    eMOVDC,  eMOVDD,  eMOVDE,  eMOVDH, eMOVDL,   eMOVDM, eMOVDA, eMOVEB, eMOVEC, eMOVED,  eMOVEE, eMOVEH, eMOVEL, eMOVEM, eMOVEA,
	eMOVHB,    eMOVHC,  eMOVHD,  eMOBHE,  eMOVHH, eMOVHL,   eMOVHM, eMOVHA, eMOVLB, eMOVLC, eMOVLD,  eMOVLE, eMOVLH, eMOVLL, eMOVLM, eMOVLA,
	eMOVMB,    eMOVMC,  eMOVMD,  eMOVME,  eMOVMH, eMOVML,   eHLT,   eMOVMA, eMOVAB, eMOVAC, eMOVAD,  eMOVAE, eMOVAH, eMOVAL, eMOVAM, eMOVAA,
        eADDB,     eADDC,   eADDD,   eADDE,   eADDH,  eADDL,    eADDM,  eADDA,  eADCB,  eADCC,  eADCD,   eADCE,  eADCH,  eADCL,  eADCM,  eADCA,
	eSUBB,     eSUBC,   eSUBD,   eSUBE,   eSUBH,  eSUBL,    eSUBM,  eSUBA,  eSBBB,  eSBBC,  eSBBD,   eSBBE,  eSBBH,  eSBBL,  eSBBM,  eSBBA,
	eANAB,     eANAC,   eANAD,   eANAE,   eANAH,  eANAL,    eANAM,  eANAA,  eXRAB,  eXRAC,  eXRAD,   eXRAE,  eXRAH,  eXRAL,  eXRAM,  eXRAA,
	eORAB,     eORAC,   eORAD,   eORAE,   eORAH,  eORAL,    eORAM,  eORAA,  eCMPB,  eCMPC,  eCMPD,   eCMPE,  eCMPH,  eCMPL,  eCMPM,  eCMPA,
	eRNZ,      ePOPB,   eJNZ,    eJMP,    eCNZ,   ePUSHB,   eADI,   eRST_0, eRZ,    eRET,   eJZ,     eJMP1,  eCZ,    eCALL,  eACI,   eRST_1,
	eRNC,      ePOPD,   eJNC,    eOUT,    eCNC,   ePUSHD,   eSUI,   eRST_2, eRC,    eRET1,  eJC,     eIN,    eCC,    eCALL1, eSBI,   eRST_3,
	eRPO,      ePOPH,   eJPO,    eXTHL,   eCPO,   ePUSHH,   eANI,   eRST_4, eRPE,   ePCHL,  eJPE,    eXCHG,  eCPE,   eCALL2, eXRI,   eRST_5,
	eRP,       ePOPPSW, eJP,     eDI,     eCP,    ePUSHPSW, eORI,   eRST_6, eRM,    eSPHL,  eJM,     eEI     eCM,    eCALL3, eCPI,   eRST_7
} opcode_index_t;

typedef struct opcode_instr opcode_instr_t;

typedef uint8_t (*opcode_handler) (opcode_instr_t*, memory_t*, cpu_model_t*);

struct opcode_instr {
        opcode_index_t index;           /* opcode index                           */
        char *ass_uniq_cmd;             /* unique readable command                */
        char *ass_cmd;                  /* readable command                       */
        uint8_t min_cycle_time;         /* minimal cycle time (in case of branch) */
        uint8_t max_cycle_time;         /* maximal cycle time (in case of branch) */
        uint8_t cycle_time;             /* current cycle time                     */
        uint8_t opcode_size;            /* opcode size (1,2 or 3)                 */
        opcode_handler func;            /* function pointer to handler            */
};

static inline void increase_program_counter(cpu_model_t*, opcode_instr_t*);
static inline void set_program_counter(cpu_model_t*, uint16_t);

static uint8_t opcode_handler_not_supported(opcode_instr_t*, memory_t*, cpu_model_t*);

static uint8_t opcode_handler_nop(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_lxib(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_staxb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_inxb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_inrb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_dcrb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mvib(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rlc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_dadb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_ldaxb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_dcxb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_inrc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_dcrc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mvic(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rrc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_lxid(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_staxd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_inxd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_inrd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_dcrd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mvid(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_ral(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_dadd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_ldaxd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_dcxd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_inre(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_dcre(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mvie(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rar(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_bb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_bc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_bd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_be(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_bh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_bl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_bm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ba(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_cb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_cc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_cd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ce(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ch(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_cl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_cm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ca(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_db(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_dc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_dd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_de(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_dh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_dl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_dm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_da(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_eb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ec(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ed(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ee(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_eh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_el(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_em(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ea(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_hb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_hc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_hd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_he(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_hh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_hl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_hm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ha(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_lb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_lc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ld(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_le(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_lh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ll(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_lm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_la(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_mb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_mc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_md(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_me(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_mh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ml(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_hlt(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ma(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ab(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ac(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ad(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ae(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_ah(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_al(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_am(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_mov_aa(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_addb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_addc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_addd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adde(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_addh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_addl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_addm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adda(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adcb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adcc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adcd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adce(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adch(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adcl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adcm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adca(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_subb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_subc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_subd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sube(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_subh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_subl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_subm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_suba(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbbb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbbc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbbd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbbe(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbbh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbbl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbbm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbba(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_anab(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_anac(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_anad(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_anae(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_anah(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_anal(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_anam(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_anaa(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xrab(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xrac(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xrad(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xrae(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xrah(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xral(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xram(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xraa(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_orab(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_orac(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_orad(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_orae(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_orah(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_oral(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_oram(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_oraa(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cmpb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cmpc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cmpd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cmpe(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cmph(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cmpl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cmpm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cmpa(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rnz(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_popb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jnz(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jmp(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cnz(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_pushb(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_adi(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rst_0(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rz(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_ret(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jz(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cz(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_call(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_aci(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rst_1(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rnc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_popd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jnc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_out(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cnc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_pushd(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sui(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rst_2(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_in(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cc(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sbi(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rst_3(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rpo(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_poph(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jpo(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xthl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cpo(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_pushh(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_ani(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rst_4(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rpe(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_pchl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jpe(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xchg(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cpe(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_xri(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rst_5(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rp(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_poppsw(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jp(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_di(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cp(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_pushpsw(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_ori(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rst_6(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_sphl(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_jm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_ei(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cm(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_cpi(opcode_instr_t*, memory_t*, cpu_model_t*);
static uint8_t opcode_handler_rst_7(opcode_instr_t*, memory_t*, cpu_model_t*);

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
                                        {eRAR, "RAR", "RAR", 4, 4, 4, 1, opcode_handler_rar},
					{eNOP5, "NOP5", "NOP", 4, 4, 4, 1, opcode_handler_not_supported},
					{eLXISP, "LXIH", "LXI H", 10, 10, 10, 3, opcode_handler_lxih},
					{eSHLD, "SHLD", "SHLD", 16, 16, 16, 3, opcode_handler_shld},
					{eINXH, "INXH", "INX H", 5, 5, 5, 1, opcode_handler_inxh},
					{eINRH, "INRH", "INR H", 5, 5, 5, 1, opcode_handler_inrh},
					{eDCRH, "DCRH", "DCR H", 5, 5, 5, 1, opcode_handler_dcrh},
					{eMVIH, "MVIH", "MVI H", 7, 7, 7, 2, opcode_handler_mvih},
					{eDAA, "DAA", "DAA", 4, 4, 4, 1, opcode_handler_daa},
					{eNOP6, "NOP6", "NOP", 4, 4, 4, 1, opcode_handler_not_supported},
					{eDADH, "DADH", "DAD H", 10, 10, 10, 1, opcode_handler_dadh},
					{eLHLD, "LHLD", "LHLD", 16, 16, 16, 3, opcode_handler_lhld},
					{eDCXH, "DCXH", "DCX H", 5, 5, 5, 1, opcode_handler_dcxh},
					{eINRL, "INRL", "INR L", 5, 5, 5, 1, opcode_handler_inrl},
					{eDCRL, "DCRL", "DCR L", 5, 5, 5, 1, opcode_handler_dcrl},
					{eMVIL, "MVIL", "MVI L", 7, 7, 7, 2, opcode_handler_mvil},
					{eCMA, "CMA", "CMA", 4, 4, 4, 1, opcode_handler_cma},
					{eNOP7, "NOP7", "NOP", 4, 4, 4, 1, opcode_handler_not_supported},
					{eLXISP, "LXISP" "LXI SP", 10, 10, 10, 3, opcode_handler_lxisp},
					{eSTA, "STA", "STA", 13, 13, 13, 3, opcode_handler_sta},
					{eINXSP, "INXSP", "INX SP", 5, 5, 5, 1, opcode_handler_inxsp},
					{eINRM, "INRM", "INR M", 10, 10, 10, 1, opcode_handler_inrm},
					{eDCRM, "DCRM", "DCR M", 10, 10, 10, 1, opcode_handler_dcrm},
					{eMVIM, "MVIM", "MVI M", 10, 10, 10, 2, opcode_handler_mvim},
					{eSTC, "STC", "STC", 4, 4, 4, 1, opcode_handler_stc},
					{eNOP8, "NOP8", "NOP", 4, 4, 4, 1, opcode_handler_not_supported},
					{eDADSP, "DADSP", "DAD SP", 10, 10, 10, 1, opcode_handler_dadsp},
					{eLDA, "LDA", "LDA", 13, 13, 13, 3, opcode_handler_lda},
					{eDCX, "DCXSP", "DCX SP", 5, 5, 5, 1, opcode_handler_dcxsp},
					{eINRA, "INRA", "INR A", 5, 5, 5, 1, opcode_handler_inra},
					{eDCRA, "DCRA", "DCR A", 5, 5, 5, 1, opcode_handler_dcra},
					{eMVIA, "MVIA", "MVI A", 7, 7, 7, 2, opcode_handler_mvia},
					{eCMC, "CMC", "CMC", 4, 4, 4, 1, opcode_handler_cmc}
};


