/*
 * bsp_f2838x_board_init.h
 *
 *  Created on: 22 de fev de 2025
 *      Author: ramon.martins
 */

#ifndef BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_BOARD_INIT_H_
#define BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_BOARD_INIT_H_

#include <bsp_f28379d_cpu1_basic.h>

/**
 * @brief alternative board init
 *
 * Board init used because the initialization of CAN PUBLIC
 * will cause a fail, because the can belongs to Cortex M
 *
 */

void bsp_board_init(void);

#endif /* BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F28379D_CPU1_BOARD_INIT_H_ */
