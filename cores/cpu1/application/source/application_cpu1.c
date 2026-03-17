#include <application_cpu1.h>
/*
 * application.c
 *
 *  Created on: 23 de jan de 2025
 *      Author: ramon.martins
 */


static QEvt const * blinky_queue[16]; /* event queue buffer */
static StackType_t  blinky_stack[AO_BLINKY_MINIMAL_STACK_SIZE]; /* stack for AO */

#pragma DATA_SECTION(blinky_stack, ".freertosStaticStack")
#pragma DATA_ALIGN ( blinky_stack , portBYTE_ALIGNMENT )

static QSubscrList subscr_sto[MAX_PUB_SIG];

static EvtPool1_t EvtPool1_inst[EVT_POOL_1_SIZE];
static EvtPool2_t EvtPool2_inst[EVT_POOL_2_SIZE];
static EvtPool3_t EvtPool3_inst[EVT_POOL_3_SIZE];
static EvtPool4_t EvtPool4_inst[EVT_POOL_4_SIZE];

void application_init(void){

    bsp_force_task_8();

    QF_init();

#ifdef Q_SPY

    if (!QS_INIT( (void*) 0 )) {         // Initialize QS target component
        //todo set error
//        Q_ERROR();                // unable to initialize QSpy
    }

    application_qs_filter_config();

    application_dictionary_init();

#endif

    // Init your Event Pool
    QF_poolInit( EvtPool1_inst , sizeof(EvtPool1_inst)  , sizeof(EvtPool1_inst[0]) );
    QF_poolInit( EvtPool2_inst , sizeof(EvtPool2_inst)  , sizeof(EvtPool2_inst[0]) );
    QF_poolInit( EvtPool3_inst , sizeof(EvtPool3_inst)  , sizeof(EvtPool3_inst[0]) );
    QF_poolInit( EvtPool4_inst , sizeof(EvtPool4_inst)  , sizeof(EvtPool4_inst[0]) );

    // Init your PS List
    QF_psInit(subscr_sto, Q_DIM(subscr_sto));

    ao_blinky_ctor(pointer_ao_blinky);

    QACTIVE_START(
        pointer_ao_blinky,
        AO_BLINKY_PRIO,
        blinky_queue,
        Q_DIM(blinky_queue),
        blinky_stack,
        sizeof(blinky_stack),
        (QEvt *)0
    );

}

void application_start(void){

    QF_run();
//    for(;;){
//    }
}
