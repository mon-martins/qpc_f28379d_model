#include <bsp_interrupts_cpu1_cla.h>
#include <bsp_f28379d_cpu1.h>
/*
 * bsp_f2838x_interrupts_cpu1_cla.c
 *
 *  Created on: 11 de mar de 2025
 *      Author: ramon.martins
 */

__interrupt void cla1Isr1(void){
    Interrupt_clearACKGroup(INT_myCLA01_INTERRUPT_ACK_GROUP);
}

__interrupt void cla1Isr2(void){
    Interrupt_clearACKGroup(INT_myCLA02_INTERRUPT_ACK_GROUP);
}
__interrupt void cla1Isr3(void){
    Interrupt_clearACKGroup(INT_myCLA03_INTERRUPT_ACK_GROUP);
}
__interrupt void cla1Isr4(void){
    Interrupt_clearACKGroup(INT_myCLA04_INTERRUPT_ACK_GROUP);
}

__interrupt void cla1Isr5(void){
    Interrupt_clearACKGroup(INT_myCLA05_INTERRUPT_ACK_GROUP);
}

__interrupt void cla1Isr6(void){
    Interrupt_clearACKGroup(INT_myCLA06_INTERRUPT_ACK_GROUP);
}

__interrupt void cla1Isr7(void){
    Interrupt_clearACKGroup(INT_myCLA07_INTERRUPT_ACK_GROUP);
}

__interrupt void cla1Isr8(void){
    GPIO_togglePin(GPIO_LED2);
    Interrupt_clearACKGroup(INT_myCLA08_INTERRUPT_ACK_GROUP);
}
