/*
 * bsp_f2838x.h
 *
 *  Created on: 20 de jan de 2025
 *      Author: ramon.martins
*/

/**
 * @addtogroup CPU1
 * @{
 */

/**
 * @addtogroup microcontroler_support_cpu1
 * @{
 *
 *  @details Library to abstract the MCU, providing general functions
 *  to configure and manipulate peripherals
 */

#ifndef BSP_BSP_F2838X_BSP_F2838X_CPU1_H_
#define BSP_BSP_F2838X_BSP_F2838X_CPU1_H_

#include <bsp_f28379d_cpu1_basic.h>

// Include Peripheral BSPs

#include <bsp_f28379d_cpu1_board_init.h>

/**
 * @brief Insert a break point by firmware
 */

#define BSP_BKPT ESTOP0

/**
 * @brief The MCU and all peripherals as defined in the sysconfig file.
 * This function clears the GPIO configurations, Interrupts, configures the clock,
 * and performs all the configurations described in the sysconfig file of this project.
 */

void bsp_init(void);

/**
 * @brief Enable call of interrupts.
 */

void bsp_enable_interrupts(void);

/**
 * @brief Disable call of interrupts.
 */

void bsp_disable_interrupts(void);

/**
 * @}
 */

/**
 * @}
 */

#endif /* BSP_BSP_F2838X_BSP_F2838X_H_ */


