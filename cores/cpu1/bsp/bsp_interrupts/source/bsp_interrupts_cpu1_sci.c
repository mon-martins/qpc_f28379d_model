/*
 * bsp_interrupts_cpu1_sci.c
 *
 *  Created on: 30 de out de 2025
 *      Author: ramon.martins
 */

#include <bsp_interrupts_cpu1_sci.h>

S_DEFINE_THIS_MODULE("bsp_interrupts_cpu1_sci");

enum{
    INTERRUPT_NESTING_NOT_SUPPORTED    = 1U,
    SCI_1_RX_INTERRUPT_SHOULDNT_BE_CALLED = 2U,
    SCI_1_TX_INTERRUPT_SHOULDNT_BE_CALLED = 3U,
};

__interrupt void INT_SCI_1_RX_ISR(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_sci_1_rx_isr();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}

__interrupt void INT_SCI_1_TX_ISR(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_sci_1_tx_isr();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}

void bsp_sci_1_rx_isr(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;
    S_ASSERT(SCI_1_RX_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_SCI_1_RX_INT);

    uint16_t data[16];
    uint16_t number_of_words_received;

    number_of_words_received = bsp_sci_receive_data(BSP_SCI_QSPY, data);

    event_sci_1_data_received( &x_higher_priority_task_woken , data , number_of_words_received );

    SCI_clearInterruptStatus(SCI_1_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INT_SCI_1_TX_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

void bsp_sci_1_tx_isr(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;
    S_ASSERT(SCI_1_TX_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_SCI_1_TX_INT);

    event_sci_1_tx_fifo_empty(&x_higher_priority_task_woken);

    // I think that clear this interrupt on spot is a bad idea, infinity trigger;
    // consider to clear when you send your message or better use rx interrupt insted;
    SCI_clearInterruptStatus(SCI_1_BASE, SCI_INT_TXFF);
    Interrupt_clearACKGroup(INT_SCI_1_TX_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

#pragma WEAK( event_sci_1_data_received )
void event_sci_1_data_received(BaseType_t *pointer_x_higher_priority_task_woken, uint16_t data[] , uint16_t number_of_words){
    // Intentionally left empty
}

#pragma WEAK( event_sci_1_tx_fifo_empty )
void event_sci_1_tx_fifo_empty(BaseType_t *pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}
