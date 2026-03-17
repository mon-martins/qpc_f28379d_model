#include <bsp_f28379d_cpu1_timer.h>
/*
 * bsp_f2838x_cpu1_timer.c
 *
 *  Created on: 30 de out de 2025
 *      Author: ramon.martins
 */


uint32_t bsp_rtos_timer_get_tick(void){
    return CPUTimer_getTimerCount(CPUTIMER2_BASE);
}


