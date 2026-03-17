/*
 * bsp_f2838x_cla_cpu1.h
 *
 *  Created on: 11 de fev de 2025
 *      Author: ramon.martins
 */

#ifndef BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_CLA_H_
#define BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_CLA_H_

#include <bsp_f28379d_cpu1_basic.h>

// Shared Memory Access and basic configuration
#include "cla1_config.h"

/**
 *  @brief Force the task 8 on CLA to run (event)
 *
 *  Start paramters on CLA, calling the task 8, edit the task 8,
 *  manually.
 */

void bsp_force_task_8(void);

#endif /* BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F28379D_CPU1_CLA_H_ */
