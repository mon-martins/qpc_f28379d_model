/*
 * external_triggers.c
 *
 *  Created on: 4 de jul de 2025
 *      Author: ramon.martins
 */

/*
 * Warning: Triggers are called from interrupts
 */

#include <application_cpu1.h>

S_DEFINE_THIS_MODULE("extern_trigger");

enum{
    BUTTON_PRESSED = 1U,
};

void event_button_2_pressed(BaseType_t * pointer_x_higher_priority_task_woken){

    S_ASSERT(BUTTON_PRESSED,0);
    BSP_BKPT;

}
