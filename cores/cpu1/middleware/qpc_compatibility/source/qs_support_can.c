/*
 * qs_support.c
 *
 *  Created on: 9 de out de 2025
 *      Author: ramon.martins
 */

#ifdef Q_SPY

#include "qpc.h"
#include "bsp_vpu_v100_cpu1.h"

//S_DEFINE_THIS_MODULE("qs_support");

enum{
    TRANSMIT_QUEUE_FULL = 1U,
};

// Variables

QSTimeCtr QS_tickTime_;
QSTimeCtr QS_tickPeriod_;

// QF Support to QS Build

void QF_onStartup(void){
    // Not impplmented to CAN yet
}

void vApplicationTickHook(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* process time events for rate 0 */
    QTIMEEVT_TICK_FROM_ISR(0U, &xHigherPriorityTaskWoken, (void *)0);

    /* notify FreeRTOS to perform context switch from ISR, if needed */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

    QS_tickTime_ += QS_tickPeriod_;
}

Q_NORETURN Q_onError(
    char const * const module,
    int_t const id){
    bsp_global_assert(module, id);
}

// QS Support

//@ brief Prescale to timestamp value using bitwise, a value of X is an actual 2^-x prescaler
#define USER_QS_TICK_TIME_BIT_PRESCALE 0

void vApplicationIdleHook(void){

    QS_rxParse();  // parse all the received bytes

    if(
            bsp_can_is_message_available(BSP_CAN_QSPY_ID, 1234)
    ) { // TXE empty?

        uint16_t num_of_bytes = 8;

        QF_INT_DISABLE();
        const uint8_t * b = QS_getBlock(&num_of_bytes);
        QF_INT_ENABLE();

        uint64_t data = {0};
        for(uint16_t i=0;i<num_of_bytes;i++){
            data += ( ((uint64_t) (*(b++)) & 0xFF) << (i*8));
        }

        if(num_of_bytes > 0){
            QF_INT_DISABLE();
            bsp_can_send_message( BSP_CAN_QSPY_ID , 1234 , num_of_bytes, &data);
            QF_INT_ENABLE();
        }
    }



}

uint8_t QS_onStartup(void const *arg) {

    Q_UNUSED_PAR(arg);

    static uint8_t qsTxBuf[2048]; // buffer for QS-TX channel
    QS_initBuf(qsTxBuf, sizeof(qsTxBuf));

    static uint8_t qsRxBuf[100];    // buffer for QS-RX channel
    QS_rxInitBuf(qsRxBuf, sizeof(qsRxBuf));

//  todo start can if necessary

    // Review timing
    QS_tickTime_ = 0;
    QS_tickPeriod_ = BSP_RTOS_TIMER_PERIOD_IN_CPU_CLK >> USER_QS_TICK_TIME_BIT_PRESCALE;

    return 1;

}

void QS_onCleanup(void){
    // Intentionally left empty
}

#define CAN_ATTEMPTS_MAXIMUM_OF_ATTEMPTS 100000

// This is a blocking function supposed used just during initialization and ASSERTs
void QS_onFlush(void){
    while(true) {
        uint16_t num_of_bytes = 8;
        uint64_t data = 0;

        const uint8_t * b = QS_getBlock(&num_of_bytes);

        if (num_of_bytes > 0) { // NOT end-of-data

            // todo change to pattern

            for(uint16_t i=0;i<num_of_bytes;i++){
                data += ( ((uint64_t) (*(b++)) & 0xFF) << (i*8));
            }

            uint16_t num_of_attempts = 0;
            while(
                !bsp_can_is_message_available(BSP_CAN_QSPY_ID, 1234)
            ){
                num_of_attempts++;
                if(num_of_attempts > CAN_ATTEMPTS_MAXIMUM_OF_ATTEMPTS){
                    // This would be a ASSERT but this function may be called by one
                    break;
                }
            }

            bsp_can_send_message( BSP_CAN_QSPY_ID , 1234 , num_of_bytes, &data);

        }
        else {
            break; // break out of the loop
        }
    }
}

void QS_onReset(void){
    // todo reset system
}

QSTimeCtr QS_onGetTime(void){
    return QS_tickTime_ + (bsp_rtos_timer_get_tick() >> USER_QS_TICK_TIME_BIT_PRESCALE);
}

void QS_onCommand(uint8_t cmdId,
                  uint32_t param1, uint32_t param2, uint32_t param3)
{
    QS_BEGIN_ID(QS_USER + 1U, 0U)
        QS_U8(2, cmdId);
        QS_U32(8, param1);
        QS_U32(8, param2);
        QS_U32(8, param3);
    QS_END()
}

// RX Not impplmented to CAN yet
//{
//    for(uint16_t i= 0; i<number_of_words ; i++){
//        QS_RX_PUT( (uint8_t) data[i]);
//    }
//
//}

#endif
