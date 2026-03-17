/*
 * bsp_f2838x_config.h
 *
 *  Created on: 20 de jan de 2025
 *      Author: ramon.martins
 *  This is a file to configure the bsp, configure this file at the very first time you are
 *  running your project, define your system operation and then avoid to change this afterward.
 *
 */


/**
 * @brief Configuration documment to bsp.
 */

#ifndef BSP_BSP_F2838X_BSP_F28379D_CONFIG_H_
#define BSP_BSP_F2838X_BSP_F28379D_CONFIG_H_

// Start CPU2?
#define BSP_USE_CPU2               0

// Syncronizate?
#define BSP_SYNC_CPU2              0
#define BSP_IPC_CPU1_CPU2_SYNC_FLAG  IPC_FLAG31

// To configure the CPU2 Boot mode you must to change on sysconfig->IPC

// ISRs

// Stack for ISR (just for CPU1 and CPU2)

#define BSP_USE_ISR_STACK 1

#define BSP_ISR_STACK_SIZE_CPU1 512

#define BSP_ISR_STACK_SIZE_CPU2 512

// CAUTION: Interrupt nesting, currently not supported.

#define BSP_USE_IPC_CPU1_TO_CPU2_MEMORY_SHARED  1
#define BSP_USE_IPC_CPU2_TO_CPU1_MEMORY_SHARED  1

#define BSP_IPC_INIT_MEMORY_SHARED_FLAG    IPC_FLAG31
#define BSP_IPC_INIT_MEMORY_SHARED_COMMAND 0xFFFFFF01

// IPC MESSAGE QUEUE

#define BSP_USE_IPC_CPU1_CPU2_MESSAGE_QUEUE 1

// Configure the library
#define BSP_IPC_MESSAGE_QUEUE_BUFFER_SIZE         30
#define BSP_IPC_MESSAGE_QUEUE_MAX_PAYLOAD_SIZE    3   /* times 16bits */

#define BSP_IPC_CPU1_CM_MESSAGE_QUEUE_INTERRUPTS_USED     1   /* Only to Message Queue*/
#define BSP_IPC_CPU2_CM_MESSAGE_QUEUE_INTERRUPTS_USED     1   /* Only to Message Queue*/
#define BSP_IPC_CPU1_CPU2_MESSAGE_QUEUE_INTERRUPTS_USED   1   /* Only to Message Queue*/

#define BSP_IPC_INIT_MESSAGE_QUEUE_FLAG    IPC_FLAG31
#define BSP_IPC_INIT_MESSAGE_QUEUE_COMMAND 0xFFFFFF02

// Interrupts ALLOWED TO RUN

// EXTERNAL

#define BSP_USE_EXTERNAL_BUTTON_INT 1

// IPC

#define BSP_USE_CPU1_IPC_FROM_CPU2_ISR0 0
#define BSP_USE_CPU1_IPC_FROM_CPU2_ISR1 0
#define BSP_USE_CPU1_IPC_FROM_CPU2_ISR2 0
#define BSP_USE_CPU1_IPC_FROM_CPU2_ISR3 0

#define BSP_USE_CPU2_IPC_FROM_CPU1_ISR0 0
#define BSP_USE_CPU2_IPC_FROM_CPU1_ISR1 0
#define BSP_USE_CPU2_IPC_FROM_CPU1_ISR2 0
#define BSP_USE_CPU2_IPC_FROM_CPU1_ISR3 0

// CLA Config

//CPU1

#define BSP_USE_CLA_TASK_1 0
#define BSP_USE_CLA_TASK_2 0
#define BSP_USE_CLA_TASK_3 0
#define BSP_USE_CLA_TASK_4 0
#define BSP_USE_CLA_TASK_5 0
#define BSP_USE_CLA_TASK_6 0
#define BSP_USE_CLA_TASK_7 0
#define BSP_USE_CLA_TASK_8 1

//SCI

#define BSP_USE_SCI_1_RX_INT 1
#define BSP_USE_SCI_1_TX_INT 0


#endif /* BSP_BSP_F2838X_BSP_F2838X_CONFIG_H_ */
