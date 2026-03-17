#include <bsp_f28379d_cpu1_sci.h>
/*
 * bsp_f2838x_cpu1_sci.c
 *
 *  Created on: 29 de out de 2025
 *      Author: ramon.martins
 */


S_DEFINE_THIS_MODULE("bsp_f2838x_cpu1_sci");

enum{
    INVALID_SCI_ID_1                   =  1U,
    INVALID_SCI_ID_2                   =  2U,
    INVALID_SCI_ID_3                   =  3U,
    INVALID_NUMBER_OF_WORDS_TO_SEND    =  4U,
    INVALID_NUMBER_OF_WORDS_TO_RECEIVE =  5U,
    INVALID_RETURN_TYPE_1              =  6U,
    INVALID_RETURN_TYPE_2              =  7U,
    INVALID_POINTER_VALUE_1            =  8U,
    INVALID_POINTER_VALUE_2            =  9U,
};

#define QUEUE_MAX_SIZE 16

static uint32_t bsp_sci_base[BSP_SCI_ID_NUMBER_OF_VALUES] = {
    [BSP_SCI_QSPY] = SCI_1_BASE,
};

bool bsp_sci_send_data(bsp_sci_ids_t sci_id, uint16_t data[], uint16_t number_of_words){
    S_REQUIRE(INVALID_SCI_ID_1 , sci_id < BSP_SCI_ID_NUMBER_OF_VALUES);
    S_REQUIRE(INVALID_NUMBER_OF_WORDS_TO_SEND , number_of_words <= QUEUE_MAX_SIZE);
    S_REQUIRE(INVALID_POINTER_VALUE_1 , data != NULL);

    bool successfull_operation = false;

    uint16_t number_of_words_left = QUEUE_MAX_SIZE - SCI_getTxFIFOStatus(bsp_sci_base[sci_id]);

    if(number_of_words_left >= number_of_words){
        successfull_operation = true;

        SCI_writeCharArray(bsp_sci_base[sci_id], data, number_of_words);
    }

    S_ENSURE(INVALID_RETURN_TYPE_1 ,  (successfull_operation == 0) || (successfull_operation == 1));

    return successfull_operation;
}

uint16_t bsp_sci_receive_data(bsp_sci_ids_t sci_id, uint16_t data[]){

    S_REQUIRE(INVALID_SCI_ID_2 , sci_id < BSP_SCI_ID_NUMBER_OF_VALUES);
    S_REQUIRE(INVALID_POINTER_VALUE_2 , data != NULL);

    uint16_t number_of_words_received = (uint16_t) SCI_getRxFIFOStatus(bsp_sci_base[sci_id]);

    S_ENSURE(INVALID_RETURN_TYPE_2 ,  number_of_words_received <= QUEUE_MAX_SIZE);

    for(uint16_t i = 0 ; i < number_of_words_received ; i++){
        data[i] = SCI_readCharNonBlocking(bsp_sci_base[sci_id]);
    }

    return number_of_words_received;
}

void bsp_sci_init(void){
    SCI_init();
}

void bsp_sci_enable_interrupt(){
    Interrupt_enable(bsp_sci_base[BSP_SCI_QSPY]);
}

bool bsp_sci_is_transmit_fifo_full(bsp_sci_ids_t sci_id){
    S_REQUIRE(INVALID_SCI_ID_3 , sci_id < BSP_SCI_ID_NUMBER_OF_VALUES);
    return (SCI_getTxFIFOStatus(bsp_sci_base[sci_id]) >= QUEUE_MAX_SIZE);
}








