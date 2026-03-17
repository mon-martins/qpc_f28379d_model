/*
 * qs_config.c
 *
 *  Created on: 13 de nov de 2025
 *      Author: ramon.martins
 */

#ifdef Q_SPY

#include "qs_config.h"

// include your active objects
#include "active_objects/blinky/blinky.h"

#include "auto_dict.h"

void application_qs_filter_config(void) {
    //QS_GLB_FILTER(QS_ALL_RECORDS);
    //QS_GLB_FILTER(-QS_QF_RECORDS);

    QS_GLB_FILTER(QS_SM_RECORDS);


}

void application_dictionary_init(void) {

    void * ao_blinky = &inst_ao_blinky;
    QS_OBJ_DICTIONARY(ao_blinky);

    auto_dict_init_all();

}

#endif
