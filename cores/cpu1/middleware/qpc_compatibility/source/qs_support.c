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

// Variables

QSTimeCtr QS_tickTime_;
QSTimeCtr QS_tickPeriod_;

// QF Support to QS Build

void QF_onStartup(void){
    // todo enable qs related interrupts, flush(Non-blocking) received data if needed
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

    // todo get peripheral status
    bool peripheral_available = true; // true = peripheral available

    if(peripheral_available){

        // todo choose between two methods getbyte or getblock

        /* Get Byte Model

        QF_INT_DISABLE();
        uint16_t byte_to_send = QS_getByte();
        QF_INT_ENABLE();

        if (byte_to_send != QS_EOD) {  // not End-Of-Data?
            // Send byte_to_send
        }

        // */

        /* Get Block Model

        uint16_t num_of_bytes = 8; //get number of bytes your peripheral can handle at the moment

        QF_INT_DISABLE();
        const uint8_t * buffer = QS_getBlock(&num_of_bytes);
        QF_INT_ENABLE();

        // Send buffer with num_of_bytes bytes using peripheral of your choice

        // */
    }

}

uint8_t QS_onStartup(void const *arg) {

    Q_UNUSED_PAR(arg);

    static uint8_t qsTxBuf[2048]; // buffer for QS-TX channel
    QS_initBuf(qsTxBuf, sizeof(qsTxBuf));

    static uint8_t qsRxBuf[100];    // buffer for QS-RX channel
    QS_rxInitBuf(qsRxBuf, sizeof(qsRxBuf));

    //todo Initial Peripheral configuration

    QS_tickTime_ = 0;
    QS_tickPeriod_ = BSP_RTOS_TIMER_PERIOD_IN_CPU_CLK >> USER_QS_TICK_TIME_BIT_PRESCALE;

    return 1;

}

void QS_onCleanup(void){
    // Intentionally left empty
}

void QS_onFlush(void){
    while(true) {

        // todo choose between two methods getbyte or getblock

        /*{ Get-Byte Model

        uint16_t byte_to_send = QS_getByte();

        if (byte_to_send != QS_EOD) {  // not End-Of-Data?

            bool successfull_operation = true;
            uint16_t num_of_attempts = 0;

            bool peripheral_available = true; // true = peripheral available
            while( !peripheral_available ){
                // Set a time condition in fraction like 100 times 1 millisecond
                num_of_attempts++;

                if(num_of_attempts > 100 ){
                    // QS failed to flush
                    successfull_operation = false;
                    break;
                }
            }

            if(!successfull_operation) continue;

            // Send byte_to_send using peripheral of your choice

        }else {
            break; // break out of the loop
        }


        // }*/

        /*{ Get-Block Model

        uint16_t num_of_bytes = 8; // block size of your choice

        QF_INT_DISABLE();
        const uint8_t * buffer = QS_getBlock(&num_of_bytes);
        QF_INT_ENABLE();

        if (num_of_bytes > 0) {
            bool successfull_operation = true;
            uint16_t num_of_attempts = 0;

            bool peripheral_available = true; // true = peripheral available
            while( !peripheral_available ){
                num_of_attempts++;

                if(num_of_attempts > 100 ){
                    // QS failed to flush
                    successfull_operation = false;
                    break;
                }
            }

            if(!successfull_operation) continue;

            // Send buffer with num_of_bytes bytes using peripheral of your choice

        }else{
            break;
        }

        // }*/
    }

}

void QS_onReset(void){
    // todo reset your board
}

QSTimeCtr QS_onGetTime(void){
    return QS_tickTime_ + (bsp_rtos_timer_get_tick() >> USER_QS_TICK_TIME_BIT_PRESCALE);
}

void QS_onCommand(uint8_t cmdId,
                  uint32_t param1, uint32_t param2, uint32_t param3)
{
    //todo custom your commands from QSPY Host
    QS_BEGIN_ID(QS_USER + 1U, 0U)
        QS_U8(2, cmdId);
        QS_U32(8, param1);
        QS_U32(8, param2);
        QS_U32(8, param3);
    QS_END()
}

//todo received qs command interrupt from the peripheral
/* todo
{
    //receive your data and send using QS_RX_PUT
    QS_RX_PUT( (uint8_t) data);
}
*/
#endif
