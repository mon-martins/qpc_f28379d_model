/*
 * freertos_calls.c
 *
 *  Created on: 31 de jan de 2025
 *      Author: ramon.martins
 */

#include "freertos_support.h"

S_DEFINE_THIS_MODULE("freertos_calls");

enum{
    STACK_OVERFLOW  = 1U,
    MALLOC_OVERFLOW = 2U,
};

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    // This is a critical erro in your FreeRTOS, this erros musca cause a stop
    // or a reset on your code

    S_ASSERT(STACK_OVERFLOW,0);

}


void vApplicationMallocFailedHook(){
    // This is a critical erro in your FreeRTOS, this erros musca cause a stop
    // or a reset on your code

    S_ASSERT(MALLOC_OVERFLOW,0);
}
