/*
 * bsp.h
 *
 *  Created on: 20 de jan de 2025
 *      Author: ramon.martins
 */

/**
 * @addtogroup CPU1
 * @{
 */

/**
 * @addtogroup board_support_cpu1
 * @{
 *
 *  @brief Library to abstract the board named VPU Ver. 100.
 *  @details Provides the necessary functions to interact with the board.
 *
 */

#ifndef BSP_BSP_VPU_V100_BSP_VPU_V100_CPU1_H_
#define BSP_BSP_VPU_V100_BSP_VPU_V100_CPU1_H_

#include <bsp_f28379d_cpu1.h>

//include specific components BSPs
#include <bsp_f28379d_xl_launchpad_cpu1_led.h>

/**
 * @brief Function to halt the code in case of an unforeseen condition,
 *
 * @details Function that safely halts the code for later debugging.
 * This function should be simple; in the release version,
 * it should reset the code after logging the error ID in some way.
 *
 * @param module (string)   Name of the module where the assert is called.
 * @param id     (uint16_t) Error number that triggered the assert, it must be unique for each assert in the module.
 *
 * @pre  None
 * @post None
 *
 */

void bsp_global_assert(char const * const module, uint16_t id);

/**
 * @}
 */

/**
 * @}
 */

#endif /* BSP_BSP_VPU_V100_BSP_VPU_V100_H_ */
