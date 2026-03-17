#include <bsp_f28379d_cpu1_cla.h>
/*
 * bsp_f2838x_cpu1_cla.c
 *
 *  Created on: 11 de fev de 2025
 *      Author: ramon.martins
 */


/**
 * @brief trigger the cal task 8 manually
 */
void bsp_force_task_8(void){
    // Require: no applicable
    CLA_forceTasks(myCLA0_BASE, CLA_TASKFLAG_8);
    // Asure: no applicable
}
