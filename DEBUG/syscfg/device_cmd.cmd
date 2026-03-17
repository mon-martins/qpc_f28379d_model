
//
// Active linker CMD configuration selected by 
// the CMD Tool global settings
//
#define CMD_Config
#ifdef CMD_Config

MEMORY
{

    RAMM0                     : origin = 0x000123, length = 0x0002DD
    RAMM1                     : origin = 0x000400, length = 0x0003F8
    CLATOCPU_MSGRAM           : origin = 0x001480, length = 0x000080
    CPUTOCLA_MSGRAM           : origin = 0x001500, length = 0x000080
    RAMLS0                    : origin = 0x008000, length = 0x000800
    RAMLS1                    : origin = 0x008800, length = 0x000800
    RAMLS2                    : origin = 0x009000, length = 0x000800
    RAMLS3                    : origin = 0x009800, length = 0x000800
    RAMLS_4_5                 : origin = 0x00A000, length = 0x001000
    RAMD0                     : origin = 0x00B000, length = 0x000800
    RAMD1                     : origin = 0x00B800, length = 0x000800
    RAMGS_0_4                 : origin = 0x00C000, length = 0x005000
    RAMGS5                    : origin = 0x011000, length = 0x001000
    RAMGS6                    : origin = 0x012000, length = 0x001000
    RAMGS7                    : origin = 0x013000, length = 0x001000
    RAMGS8                    : origin = 0x014000, length = 0x001000
    RAMGS9                    : origin = 0x015000, length = 0x001000
    RAMGS10                   : origin = 0x016000, length = 0x001000
    RAMGS11                   : origin = 0x017000, length = 0x001000
    RAMGS12                   : origin = 0x018000, length = 0x001000
    RAMGS13                   : origin = 0x019000, length = 0x001000
    RAMGS14                   : origin = 0x01A000, length = 0x001000
    RAMGS15                   : origin = 0x01B000, length = 0x000FF8
    CPU2TOCPU1RAM             : origin = 0x03F800, length = 0x000400
    CPU1TOCPU2RAM             : origin = 0x03FC00, length = 0x000400
    FLASHA                    : origin = 0x080000, length = 0x002000
    FLASHB                    : origin = 0x082000, length = 0x002000
    FLASHC                    : origin = 0x084000, length = 0x002000
    FLASHD                    : origin = 0x086000, length = 0x002000
    FLASHE                    : origin = 0x088000, length = 0x008000
    FLASHF                    : origin = 0x090000, length = 0x008000
    FLASHG                    : origin = 0x098000, length = 0x008000
    FLASHH                    : origin = 0x0A0000, length = 0x008000
    FLASHI                    : origin = 0x0A8000, length = 0x008000
    FLASHJ                    : origin = 0x0B0000, length = 0x008000
    FLASHK                    : origin = 0x0B8000, length = 0x002000
    FLASHL                    : origin = 0x0BA000, length = 0x002000
    FLASHM                    : origin = 0x0BC000, length = 0x002000
    FLASHN                    : origin = 0x0BE000, length = 0x001FF0
    RESET                     : origin = 0x3FFFC0, length = 0x000002
}


SECTIONS
{
    //
    // C28x Sections
    //
    .reset               : >  RESET, TYPE = DSECT /* not used, */
    codestart            : >  0x080000
    .text                : >> FLASHA | FLASHB | FLASHC | FLASHD,
                              ALIGN(8)
/* 
       Flash build using the CLA need to include a memcpy from FLASH to RAM in the initialization. Example: 
       memcpy((uint32_t *)((uint32_t)&Clas1ProgRunStart), (uint32_t *)&Clas1ProgLoadStart, /
        (uint32_t)&Clas1ProgLoadSize); 
     */ 
    .TI.ramfunc          :    LOAD >  FLASHD,
                              RUN  >  RAMGS_0_4,
                              TABLE(copyTable_ramfunc),
                              ALIGN(8)
    .binit               : >  FLASHE,
                              ALIGN(8)
    .ovly                : >  FLASHE,
                              ALIGN(8)
    .cinit               : >  FLASHF,
                              ALIGN(8)
    .stack               : >  RAMM1,
                              ALIGN(8)
    .init_array          : >  FLASHE,
                              ALIGN(8)
    .bss                 : >  RAMGS_0_4
    .const               : >  FLASHE,
                              ALIGN(8)
    .data                : >  RAMGS_0_4
    .switch              : >  FLASHE,
                              ALIGN(8)
    .sysmem              : >  RAMGS_0_4

    //
    // CLA Sections
    //
/* 
       Flash build using the CLA need to include a memcpy from FLASH to RAM in the initialization. Example: 
       memcpy((uint32_t *)((uint32_t)&Clas1ProgRunStart), (uint32_t *)&Clas1ProgLoadStart, /
        (uint32_t)&Clas1ProgLoadSize); 
     */ 
    Cla1Prog             :    LOAD >  FLASHJ,
                              RUN  >  RAMLS_4_5,
                              TABLE(copyTable_cla1Prog),
                              ALIGN(8)
/* 
       Flash build using the CLA need to include a memcpy from FLASH to RAM in the initialization. Example: 
       memcpy((uint32_t *)((uint32_t)&Clas1ProgRunStart), (uint32_t *)&Clas1ProgLoadStart, /
        (uint32_t)&Clas1ProgLoadSize); 
     */ 
    .const_cla           :    LOAD >  FLASHN,
                              RUN  >  RAMLS3,
                              TABLE(BINIT),
                              ALIGN(8)
    .scratchpad          : >  RAMLS3
    .bss_cla             : >  RAMLS3
    cla1ToCpuMsgRAM      : >  CLATOCPU_MSGRAM
    cpuToCla1MsgRAM      : >  CPUTOCLA_MSGRAM

    //
    // User Sections
    //
    RTOS_static_stack { *(.freertosStaticStack) }    >  RAMGS_0_4,
                              ALIGN(8),
                              FILL(171)
    MSGRAM_CPU1_TO_CPU2 : > CPU1TOCPU2RAM, type=NOINIT
    MSGRAM_CPU2_TO_CPU1 : > CPU2TOCPU1RAM, type=NOINIT

}

#endif

/*
//===========================================================================
// End of file.
//===========================================================================
*/
