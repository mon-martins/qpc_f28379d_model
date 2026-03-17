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
 *  @brief cla task 1, finished to run (event)
 *
 *  When the task 1 is finished this function is called from the ISR,
 *  redeclare this function for your specific application.
 *
 */

void event_cla_1_finish(BaseType_t * pointer_x_higher_priority_task_woken);

/**
 *  @brief cla task 2, finished to run (event)
 *
 *  When the task 2 is finished this function is called from the ISR,
 *  redeclare this function for your specific application.
 *
 */

void event_cla_2_finish(BaseType_t * pointer_x_higher_priority_task_woken);

/**
 *  @brief cla task 3, finished to run (event)
 *
 *  When the task 3 is finished this function is called from the ISR,
 *  redeclare this function for your specific application.
 *
 */

void event_cla_3_finish(BaseType_t * pointer_x_higher_priority_task_woken);

/**
 *  @brief cla task 4, finished to run (event)
 *
 *  When the task 4 is finished this function is called from the ISR,
 *  redeclare this function for your specific application.
 *
 */

void event_cla_4_finish(BaseType_t * pointer_x_higher_priority_task_woken);

/**
 *  @brief cla task 5, finished to run (event)
 *
 *  When the task 5 is finished this function is called from the ISR,
 *  redeclare this function for your specific application.
 *
 */

void event_cla_5_finish(BaseType_t * pointer_x_higher_priority_task_woken);

/**
 *  @brief cla task 6, finished to run (event)
 *
 *  When the task 6 is finished this function is called from the ISR,
 *  redeclare this function for your specific application.
 *
 */

void event_cla_6_finish(BaseType_t * pointer_x_higher_priority_task_woken);

/**
 *  @brief cla task 7, finished to run (event)
 *
 *  When the task 7 is finished this function is called from the ISR,
 *  redeclare this function for your specific application.
 *
 */

void event_cla_7_finish(BaseType_t * pointer_x_higher_priority_task_woken);

/**
 *  @brief cla task 8, finished to run (event)
 *
 *  When the task 8 is finished this function is called from the ISR,
 *  redeclare this function for your specific application.
 *
 */

void event_cla_8_finish(BaseType_t * pointer_x_higher_priority_task_woken);

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

/**
 * @brief function to clear cla1isr1's interrupt flags and triggers specifics events.
 */

void bsp_cla1_isr1(void);

/**
 * @brief function to clear cla1isr2's interrupt flags and triggers specifics events.
 */

void bsp_cla1_isr2(void);

/**
 * @brief function to clear cla1isr3's interrupt flags and triggers specifics events.
 */

void bsp_cla1_isr3(void);

/**
 * @brief function to clear cla1isr4's interrupt flags and triggers specifics events.
 */

void bsp_cla1_isr4(void);


/**
 * @brief function to clear cla1isr5's interrupt flags and triggers specifics events.
 */

void bsp_cla1_isr5(void);

/**
 * @brief function to clear cla1isr6's interrupt flags and triggers specifics events.
 */

void bsp_cla1_isr6(void);

/**
 * @brief function to clear cla1isr7's interrupt flags and triggers specifics events.
 */

void bsp_cla1_isr7(void);

/**
 * @brief function to clear cla1isr8's interrupt flags and triggers specifics events.
 */

void bsp_cla1_isr8(void);

#endif /* BSP_BSP_INTERRUPTS_INCLUDE_BSP_INTERRUPTS_CPU1_CLA_H_ */
