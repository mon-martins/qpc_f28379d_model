/*
 * bsp_f2838x_cpu1_timer.h
 *
 *  Created on: 30 de out de 2025
 *      Author: ramon.martins
 */

#ifndef BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_TIMER_H_
#define BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_TIMER_H_

#include <bsp_f28379d_cpu1_basic.h>

#define BSP_RTOS_TIMER_PERIOD_IN_CPU_CLK ((uint32_t) (configCPU_CLOCK_HZ/configTICK_RATE_HZ))

uint32_t bsp_rtos_timer_get_tick(void);

#endif /* BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F28379D_CPU1_TIMER_H_ */
