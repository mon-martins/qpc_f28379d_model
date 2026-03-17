#include <bsp_f28379d_cpu1_interrupts_stack.h>

// See:
// "https://e2e.ti.com/support/microcontrollers/c2000-microcontrollers-group/c2000/f/c2000-microcontrollers-forum/1478782/tms320f28388d-assigning-isr-stack-to-the-main-stack-and-restore-it-later"
#if BSP_USE_ISR_STACK

volatile uint16_t savedSP;
uint16_t isrStack[BSP_ISR_STACK_SIZE_CPU1];
volatile uint16_t intNesting = 0;

#endif
