/*
 * bsp_interrupts_cpu1_sci.h
 *
 *  Created on: 30 de out de 2025
 *      Author: ramon.martins
 */

#ifndef BSP_BSP_INTERRUPTS_INCLUDE_BSP_INTERRUPTS_CPU1_SCI_H_
#define BSP_BSP_INTERRUPTS_INCLUDE_BSP_INTERRUPTS_CPU1_SCI_H_

#include <bsp_interrupts_cpu1.h>

/**
 * @brief ScI RX interrupt service routine.
 *
 * @note This function should not be called directly by the user; it is
 * automatically invoked when an interrupt occurs.
 */
__interrupt void INT_SCI_1_RX_ISR(void);


/**
 * @brief SCI TX interrupt service routine.
 *
 * @note This function should not be called directly by the user; it is
 * automatically invoked when an interrupt occurs.
 */
__interrupt void INT_SCI_1_TX_ISR(void);


/**
 * @brief Handles SCI RX interrupt, cleaning the required flags.
 *
 * @note This function is called within the ISR and should not be invoked manually.
 */
void bsp_sci_1_rx_isr(void);


/**
 * @brief Handles SCI TX interrupt, cleaning the required flags.
 *
 * @note This function is called within the ISR and should not be invoked manually.
 */
void bsp_sci_1_tx_isr(void);


/**
 * @brief Event handler for data reception on SCI 1.
 */
void event_sci_1_data_received(BaseType_t *pointer_x_higher_priority_task_woken, uint16_t data[] , uint16_t number_of_words);


/**
 * @brief Event handler for SCI TX FIFO empty event.
 */
void event_sci_1_tx_fifo_empty(BaseType_t *pointer_x_higher_priority_task_woken);

#endif /* BSP_BSP_INTERRUPTS_INCLUDE_BSP_INTERRUPTS_CPU1_SCI_H_ */
