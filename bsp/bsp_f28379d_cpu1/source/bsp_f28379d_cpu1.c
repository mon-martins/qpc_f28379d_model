#include <bsp_f28379d_cpu1.h>
/*
 * bsp_f2838x.c
 *
 *  Created on: 20 de jan de 2025
 *      Author: ramon.martins
 */


void bsp_init(void){

    //
    // REQUIRE
    //

    // Not applicable: no parameters

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Initialize GPIO and configure the GPIO pin as a push-pull output
    //
    Device_initGPIO();
    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();


    bsp_board_init();

    C2000Ware_libraries_init();

    //
    // ENSURE
    //

    // Not applicable
}

void bsp_enable_interrupts(void){

    //
    // REQUIRE
    //

    // Not applicable: no parameters

    EINT;
#ifdef DEBUG
    ERTM;
#endif

    //
    // ENSURE
    //

    // Not applicable
}

void bsp_disable_interrupts(void){

    //
    // REQUIRE
    //

    // Not applicable: no parameters

    Interrupt_disableGlobal();

    DINT;
#ifdef DEBUG
    DRTM;
#endif

    //
    // ENSURE
    //

    // Not applicable
}

