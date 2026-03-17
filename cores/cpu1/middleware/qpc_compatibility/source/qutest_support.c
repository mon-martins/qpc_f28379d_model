/*
 * qutest_support.c
 *
 *  Created on: 9 de out de 2025
 *      Author: ramon.martins
 */

#ifdef Q_UTEST

// todo

void QS_onTestLoop(void){
}

void QS_onTestEvt(QEvt * e){
}

void QS_onTestPost(
    void const * sender,
    QActive * recipient,
    QEvt const * e,
    bool status
){
}

void QS_onTestSetup(void){
}

void QS_onTestTeardown(void){
}

#endif
