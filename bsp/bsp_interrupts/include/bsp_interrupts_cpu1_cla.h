/*
 * bsp_interrupts_cpu1_cla.h
 *
 *  Created on: 12 de mar de 2025
 *      Author: ramon.martins
 */

#ifndef BSP_BSP_INTERRUPTS_INCLUDE_BSP_CLA_INTERRUPTS_CPU1_H_
#define BSP_BSP_INTERRUPTS_INCLUDE_BSP_CLA_INTERRUPTS_CPU1_H_

#include <bsp_interrupts_cpu1.h>


/**
 *
 * @brief Native C28x Interrupt called when CLA task 1 has finished
 *
 * Mostly here to change the SP(Stack Pointer)
 *
 */

__interrupt void cla1Isr1(void);

/**
 *
 * @brief Native C28x Interrupt called when CLA task 2 has finished
 *
 * Mostly here to change the SP(Stack Pointer)
 *
 */

__interrupt void cla1Isr2(void);

/**
 *
 * @brief Native C28x Interrupt called when CLA task 3 has finished
 *
 * Mostly here to change the SP(Stack Pointer)
 *
 */

__interrupt void cla1Isr3(void);

/**
 *
 * @brief Native C28x Interrupt called when CLA task 4 has finished
 *
 * Mostly here to change the SP(Stack Pointer)
 *
 */

__interrupt void cla1Isr4(void);

/**
 *
 * @brief Native C28x Interrupt called when CLA task 5 has finished
 *
 * Mostly here to change the SP(Stack Pointer)
 *
 */

__interrupt void cla1Isr5(void);

/**
 *
 * @brief Native C28x Interrupt called when CLA task 6 has finished
 *
 * Mostly here to change the SP(Stack Pointer)
 *
 */

__interrupt void cla1Isr6(void);

/**
 *
 * @brief Native C28x Interrupt called when CLA task 7 has finished
 *
 * Mostly here to change the SP(Stack Pointer)
 *
 */

__interrupt void cla1Isr7(void);

/**
 *
 * @brief Native C28x Interrupt called when CLA task 8 has finished
 *
 * Mostly here to change the SP(Stack Pointer)
 *
 */

__interrupt void cla1Isr8(void);


#endif /* BSP_BSP_INTERRUPTS_INCLUDE_BSP_INTERRUPTS_CPU1_CLA_H_ */
