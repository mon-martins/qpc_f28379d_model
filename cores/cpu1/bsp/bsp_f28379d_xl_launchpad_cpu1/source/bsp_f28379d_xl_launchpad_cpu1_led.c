#include <bsp_f28379d_xl_launchpad_cpu1_led.h>
/*
 * bsp_led.c
 *
 *  Created on: 6 de fev de 2025
 *      Author: ramon.martins
 */


//S_DEFINE_THIS_MODULE("bsp_led_cpu1");
//
//enum{
//    FUNCTION_TURN_LED1_ON_NOT_IMPLMENTED  = 1U,
//    FUNCTION_TURN_LED1_OFF_NOT_IMPLMENTED = 2U,
//    TURN_ON_LED2_ONLY_AVAILIBLE_TO_CPU2  = 3U,
//    TURN_OFF_LED2_ONLY_AVAILIBLE_TO_CPU2 = 4U,
//};

void bsp_turn_on_led_1(void){
    // REQUIRE AND ASURE not applicable

    bsp_gpio_write(GPIO_LED1, false);
}

void bsp_turn_off_led_1(void){
    // REQUIRE AND ASURE not applicable

    bsp_gpio_write(GPIO_LED1, true);
}

void bsp_turn_on_led_2(void){
    // REQUIRE AND ASURE not applicable

    bsp_gpio_write(GPIO_LED2, false);

}

void bsp_turn_off_led_2(void){
    // REQUIRE AND ASURE not applicable

    bsp_gpio_write(GPIO_LED2, true);
}

