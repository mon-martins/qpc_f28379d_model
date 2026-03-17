/*
 * bsp_f2838x_cpu1_sci.h
 *
 *  Created on: 29 de out de 2025
 *      Author: ramon.martins
 */

#ifndef BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_SCI_H_
#define BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F2838X_CPU1_SCI_H_

#include <bsp_f28379d_cpu1_basic.h>

typedef enum{
    BSP_SCI_QSPY = 1U,
    BSP_SCI_ID_NUMBER_OF_VALUES
}bsp_sci_ids_t;

bool bsp_sci_send_data(bsp_sci_ids_t sci_id, uint16_t data[], uint16_t number_of_words);

uint16_t bsp_sci_receive_data(bsp_sci_ids_t sci_id, uint16_t data[]);

void bsp_sci_init(void);

void bsp_sci_enable_interrupt();

bool bsp_sci_is_transmit_fifo_full(bsp_sci_ids_t sci_id);

#endif /* BSP_BSP_F2838X_CPU1_INCLUDE_BSP_F28379D_CPU1_SCI_H_ */
