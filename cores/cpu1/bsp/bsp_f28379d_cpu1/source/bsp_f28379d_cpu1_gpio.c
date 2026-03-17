#include <bsp_f28379d_cpu1_gpio.h>
/*
 * bsp_f2838x_cpu1_gpio.c
 *
 *  Created on: 6 de fev de 2025
 *      Author: ramon.martins
 */


S_DEFINE_THIS_MODULE("bsp_f2838x_gpio_cpu1");

enum{
    GPIO_INVALID_1    = 1U,
    STATE_INVALID   = 2U,

    GPIO_INVALID_2 = 3U,
};

void bsp_gpio_write(uint16_t gpio , bool state){

    S_REQUIRE(STATE_INVALID , (state == 0) || (state == 1) );
    S_REQUIRE(GPIO_INVALID_1  , (gpio <=133) );

    GPIO_writePin(gpio, state);
}

bool bsp_gpio_read(uint16_t gpio){
    S_REQUIRE(GPIO_INVALID_2  , (gpio <=133) );

    return GPIO_readPin(gpio);
}
