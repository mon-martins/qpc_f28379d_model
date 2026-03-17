/*
 * bsp_gpio_cpu1.h
 *
 *  Created on: 6 de fev de 2025
 *      Author: ramon.martins
 */

#ifndef BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_GPIO_H_
#define BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_GPIO_H_

#include <bsp_f28379d_cpu1_basic.h>

/**
 * @brief change the state of the specific  GPIO
 *
 * @pre gpio is a valid one, between 0 and 133. some unvalid values will not me checked.
 * @pre state equals to 0 or 1
 */

void bsp_gpio_write(uint16_t gpio , bool state);

/**
 *  @brief get the state of the specific GPIO
 *
 *  @pre gpio is a valid one, between 0 and 133. some unvalid values will not me checked.
 */

bool bsp_gpio_read(uint16_t gpio);

#endif /* BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F28379D_CPU1_GPIO_H_ */
