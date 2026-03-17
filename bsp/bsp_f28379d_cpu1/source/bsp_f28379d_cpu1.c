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
//    Board_init();

    //Enable interrupts  to CM
    Interrupt_enable(IPC_INT0);
    Interrupt_enable(IPC_INT1);
    Interrupt_enable(IPC_INT2);
    Interrupt_enable(IPC_INT3);
    Interrupt_enable(IPC_INT4);
    Interrupt_enable(IPC_INT5);
    Interrupt_enable(IPC_INT6);
    Interrupt_enable(IPC_INT7);

    C2000Ware_libraries_init();

    //
    // Boot CPU2 core
    //

#if BSP_USE_CPU2
    Device_bootCPU2(BOOT_MODE_CPU2);
#endif

#if BSP_SYNC_CPU2 && BSP_USE_CPU2
    IPC_clearFlagLtoR(IPC_CPU1_L_CPU2_R, IPC_FLAG_ALL);
    IPC_sync(IPC_CPU1_L_CPU2_R, BSP_IPC_CPU1_CPU2_SYNC_FLAG);
#endif

//    bsp_ipc_init_message_queue(IPC_CPU1_L_CPU2_R, &bsp_ipc_message_queue_cpu1_cpu2[0] , 1 , 1 );

//    bsp_ipc_memory_shared_init();

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

