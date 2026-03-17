/*
 * bsp_f2838x_isr_stack_cpu1.h
 *
 *  Created on: 11 de mar de 2025
 *      Author: ramon.martins
 */

#ifndef BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_ISR_STACK_H_
#define BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_ISR_STACK_H_

#include <bsp_f28379d_cpu1_basic.h>

#if BSP_USE_ISR_STACK

extern volatile uint16_t savedSP;
extern uint16_t isrStack[BSP_ISR_STACK_SIZE_CPU1];
extern volatile uint16_t intNesting;

#define BSP_CHANGE_SP_TO_ISR_STACK \
    S_ASSERT(INTERRUPT_NESTING_NOT_SUPPORTED , !(intNesting) );\
    asm(" .ref    savedSP");\
    asm(" .ref    isrStack");\
    asm(" MOVL    XAR4, #savedSP"); \
    asm(" MOVL    XAR6, #0"); \
    asm(" MOV     AR6, SP"); \
    asm(" MOVL    *XAR4, XAR6"); \
    asm(" MOVL    XAR4, #isrStack"); \
    asm(" MOV     @SP, AR4"); \
    intNesting += 1



#define BSP_RESTORE_SP_FROM_ISR_STACK \
    asm(" MOVL    XAR0, #savedSP"); \
    asm(" MOVL    XAR0, *XAR0"); \
    asm(" MOV     @SP, AR0"); \
    intNesting -= 1

#endif

#endif /* BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_ISR_STACK_H_ */
