#include <bsp_interrupts_cpu1_cla.h>
/*
 * bsp_f2838x_interrupts_cpu1_cla.c
 *
 *  Created on: 11 de mar de 2025
 *      Author: ramon.martins
 */


S_DEFINE_THIS_MODULE("bsp_f2838x_cla_interrupts_cpu1");

enum{
    INTERRUPT_NESTING_NOT_SUPPORTED    = 1U,
    CLA_1_INTERRUPT_SHOULDNT_BE_CALLED = 2U,
    CLA_2_INTERRUPT_SHOULDNT_BE_CALLED = 3U,
    CLA_3_INTERRUPT_SHOULDNT_BE_CALLED = 4U,
    CLA_4_INTERRUPT_SHOULDNT_BE_CALLED = 5U,
    CLA_5_INTERRUPT_SHOULDNT_BE_CALLED = 6U,
    CLA_6_INTERRUPT_SHOULDNT_BE_CALLED = 7U,
    CLA_7_INTERRUPT_SHOULDNT_BE_CALLED = 8U,
    CLA_8_INTERRUPT_SHOULDNT_BE_CALLED = 9U,
};

//===============================================
// ISR primary functions / Change SP
//===============================================

__interrupt void cla1Isr1(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_cla1_isr1();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}

__interrupt void cla1Isr2(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_cla1_isr2();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}
__interrupt void cla1Isr3(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_cla1_isr3();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}
__interrupt void cla1Isr4(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_cla1_isr4();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}

__interrupt void cla1Isr5(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_cla1_isr5();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}

__interrupt void cla1Isr6(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_cla1_isr6();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}

__interrupt void cla1Isr7(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_cla1_isr7();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}

__interrupt void cla1Isr8(void){
    BSP_CHANGE_SP_TO_ISR_STACK;

    bsp_cla1_isr8();

    BSP_RESTORE_SP_FROM_ISR_STACK;
}

//===============================================
// ISR Treatment
//===============================================

void bsp_cla1_isr1(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;

    S_ASSERT(CLA_1_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_CLA_TASK_1);

    event_cla_1_finish(&x_higher_priority_task_woken);

    Interrupt_clearACKGroup(INT_myCLA01_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

void bsp_cla1_isr2(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;

    S_ASSERT(CLA_2_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_CLA_TASK_2);

    event_cla_2_finish(&x_higher_priority_task_woken);

    Interrupt_clearACKGroup(INT_myCLA02_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

void bsp_cla1_isr3(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;

    S_ASSERT(CLA_3_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_CLA_TASK_3);

    event_cla_3_finish(&x_higher_priority_task_woken);

    Interrupt_clearACKGroup(INT_myCLA03_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

void bsp_cla1_isr4(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;

    S_ASSERT(CLA_4_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_CLA_TASK_4);

    event_cla_4_finish(&x_higher_priority_task_woken);

    Interrupt_clearACKGroup(INT_myCLA04_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

void bsp_cla1_isr5(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;

    S_ASSERT(CLA_5_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_CLA_TASK_5);

    event_cla_5_finish(&x_higher_priority_task_woken);

    Interrupt_clearACKGroup(INT_myCLA05_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

void bsp_cla1_isr6(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;

    S_ASSERT(CLA_6_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_CLA_TASK_6);

    event_cla_6_finish(&x_higher_priority_task_woken);

    Interrupt_clearACKGroup(INT_myCLA06_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

void bsp_cla1_isr7(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;

    S_ASSERT(CLA_7_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_CLA_TASK_7);

    event_cla_7_finish(&x_higher_priority_task_woken);

    Interrupt_clearACKGroup(INT_myCLA07_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

void bsp_cla1_isr8(void){
    BaseType_t x_higher_priority_task_woken = pdFALSE;

    S_ASSERT(CLA_8_INTERRUPT_SHOULDNT_BE_CALLED , BSP_USE_CLA_TASK_8);

    event_cla_8_finish(&x_higher_priority_task_woken);

    Interrupt_clearACKGroup(INT_myCLA08_INTERRUPT_ACK_GROUP);

    portYIELD_FROM_ISR(x_higher_priority_task_woken);
}

//===============================================
// Event Weak Declaration
//===============================================

#pragma WEAK( event_cla_1_finish )
void event_cla_1_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}

#pragma WEAK( event_cla_2_finish )
void event_cla_2_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}

#pragma WEAK( event_cla_3_finish )
void event_cla_3_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}

#pragma WEAK( event_cla_4_finish )
void event_cla_4_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}

#pragma WEAK( event_cla_5_finish )
void event_cla_5_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}

#pragma WEAK( event_cla_6_finish )
void event_cla_6_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}

#pragma WEAK( event_cla_7_finish )
void event_cla_7_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}

#pragma WEAK( event_cla_8_finish )
void event_cla_8_finish(BaseType_t * pointer_x_higher_priority_task_woken){
    // Intentionally left empty
}

