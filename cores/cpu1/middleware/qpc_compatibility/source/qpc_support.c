#include <bsp/bsp_f28379d_xl_launchpad_cpu1/include/bsp_f28379d_xl_launchpad_cpu1.h>
#include "qpc.h"


#ifndef Q_SPY
void QF_onStartup(void){
}

void vApplicationTickHook(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* process time events for rate 0 */
    QTIMEEVT_TICK_FROM_ISR(0U, &xHigherPriorityTaskWoken, (void *)0);

    /* notify FreeRTOS to perform context switch from ISR, if needed */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void vApplicationIdleHook(void){}

Q_NORETURN Q_onError(
    char const * const module,
    int_t const id){
    bsp_global_assert(module, id);
}

void QF_onCleanup(void){
    // Intentionally left empty
}

#endif
