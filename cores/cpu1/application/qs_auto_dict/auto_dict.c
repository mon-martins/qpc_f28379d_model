/************************************************************/
// Automatically generated C source file
/************************************************************/

#include "auto_dict.h"
#include "../../generated_files/qm_files/main_qm.h"
#include "../../generated_files/qm_files/active_objects/blinky/blinky.h"
#include "../../generated_files/qm_files/qs_config.h"
#include "../../generated_files/qm_files/qp_config.h"

void auto_dict_init_signals(void){
    QS_SIG_DICTIONARY(FIRST_PUBLISH_SIG, (void *)0);
    QS_SIG_DICTIONARY(HALF_CYCLE_SIG, (void *)0);
    QS_SIG_DICTIONARY(KERNEL_START_SIG, (void *)0);
    QS_SIG_DICTIONARY(MAX_PUB_SIG, (void *)0);
    QS_SIG_DICTIONARY(Q_USER_SIG, (void *)0);
}

void auto_dict_init_states(void){
    QS_FUN_DICTIONARY(Blinky_OPERATION);
    QS_FUN_DICTIONARY(Blinky_LED_OFF);
    QS_FUN_DICTIONARY(Blinky_LED_ON);
    QS_FUN_DICTIONARY(Blinky_INITIALIZATION);
    QS_FUN_DICTIONARY(Blinky_PRE_KERNEL);
    QS_FUN_DICTIONARY(Blinky_POST_KERNEL);
}
void auto_dict_init_all(void){
    auto_dict_init_signals();
    auto_dict_init_states();
}
