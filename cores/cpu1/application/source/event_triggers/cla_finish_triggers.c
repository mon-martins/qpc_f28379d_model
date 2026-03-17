/*
 * cla_finish_triggers.c
 *
 *  Created on: 18 de jun de 2025
 *      Author: ramon.martins
 */

/*
 * Warning: Triggers are called from interrupts
 */

#include <application_cpu1.h>

void event_cla_1_finish(BaseType_t * pointer_x_higher_priority_task_woken){

}

void event_cla_2_finish(BaseType_t * pointer_x_higher_priority_task_woken){

}

void event_cla_8_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    static uint16_t is_led_2_on = false;
    if(is_led_2_on){
        bsp_turn_off_led_2();
        is_led_2_on = false;
    }else{
        bsp_turn_on_led_2();
        is_led_2_on = true;
    }
}
