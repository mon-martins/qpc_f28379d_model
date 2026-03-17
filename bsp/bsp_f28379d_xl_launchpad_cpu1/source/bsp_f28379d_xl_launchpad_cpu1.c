#include <bsp/bsp_f28379d_xl_launchpad_cpu1/include/bsp_f28379d_xl_launchpad_cpu1.h>
/*
 * bsp_vpu_v100.c
 *
 *  Created on: 20 de jan de 2025
 *      Author: ramon.martins
 */


#pragma WEAK( bsp_global_assert )
void _Noreturn bsp_global_assert (char const * const module, uint16_t id){

    //
    // REQUIRE
    //

    // Not applicable: if the require fails, there isn't any assert to be called
    // Just verify to log instead.

    bsp_disable_interrupts();

//    taskENTER_CRITICAL();

    BSP_BKPT;
    while(1);

    //
    // ENSURE
    //

    // Not applicable: void function, and the program doesn't reach this statement
}
