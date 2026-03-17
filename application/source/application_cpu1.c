#include <application_cpu1.h>
/*
 * application.c
 *
 *  Created on: 23 de jan de 2025
 *      Author: ramon.martins
 */


void application_init(void){

}

void application_start(void){

    for(;;)
    {
        //
        // Turn on LED
        //
        GPIO_writePin(GPIO_LED1, 0);
        CLA_forceTasks(myCLA0_BASE, CLA_TASKFLAG_8);

        //
        // Delay for a bit.
        //
        DEVICE_DELAY_US(500000);

        //
        // Turn off LED
        //
        GPIO_writePin(GPIO_LED1, 1);
        CLA_forceTasks(myCLA0_BASE, CLA_TASKFLAG_8);

        //
        // Delay for a bit.
        //
        DEVICE_DELAY_US(500000);
    }

}
