#include <cla1_shared_memory.h>
/*
 * cla1_shared_memory.c
 *
 *  Created on: 26 de jul de 2023
 *      Author: ramon.martins
 */


//
// Ensure that all data is placed in the data rams
//


//#define WAITSTEP     asm(" RPT #255 || NOP")

#ifdef __cplusplus
    #pragma DATA_SECTION("cpuToCla1MsgRAM")
    CPU_CLA_Message CPU2CLA_Message;
    #pragma DATA_SECTION("cla1ToCpuMsgRAM")
    CLA_CPU_Message CLA2CPU_Message;
    #pragma DATA_SECTION("CLA_Memory_CPU_Init")
    CLA_Memory_CPU_Init CLA_Memory;
#else
    #pragma DATA_SECTION(CPU2CLA_Message,"cpuToCla1MsgRAM")
    volatile CPU_CLA_Message CPU2CLA_Message;
    #pragma DATA_SECTION(CLA2CPU_Message,"cla1ToCpuMsgRAM")
    volatile CLA_CPU_Message CLA2CPU_Message;
    #pragma DATA_SECTION(CLA_Memory,"CLA_Memory_CPU_Init")
    volatile CLA_Memory_CPU_Init CLA_Memory;

#endif
