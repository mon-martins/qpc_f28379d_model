#include <application_cpu1.h>
/*
 * application.c
 *
 *  Created on: 23 de jan de 2025
 *      Author: ramon.martins
 */

#include "c2000_freertos.h"

void application_init(void){

}

void application_start(void){

    FreeRTOS_init();

}

void blinky_led_1_func( void * pvParameters ){
    for(;;)
    {
        //
        // Turn on LED
        //
        bsp_turn_on_led_1();
        bsp_force_task_8();

        //
        // Delay for a bit.
        //
        vTaskDelay(pdMS_TO_TICKS(500));

        //
        // Turn off LED
        //
        bsp_turn_off_led_1();
        bsp_force_task_8();

        //
        // Delay for a bit.
        //
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}


void event_cla_8_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    static uint16_t is_led_2_on = false;

    if(is_led_2_on){
        is_led_2_on = false;
        bsp_turn_off_led_2();
    }else{
        is_led_2_on = true;
        bsp_turn_on_led_2();
    }

}
