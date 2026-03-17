/*
 * cla1_config.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_CLA_CLA1_CONFIG_H_
#define APPLICATION_INCLUDE_CLA_CLA1_CONFIG_H_

#include <cla1_shared_memory.h>

extern volatile CPU_CLA_Message CPU2CLA_Message;

extern volatile CLA_CPU_Message CLA2CPU_Message;

extern volatile CLA_Memory_CPU_Init CLA_Memory;


//
// Function Prototypes
//
// The following are symbols defined in the CLA assembly code
// Including them in the shared header file makes them
// .global and the main CPU can make use of them.
//

/**
 * Task 1 specific to the application
 */
__interrupt void Cla1Task1(void);

/**
 * Task 2 specific to the application
 */

__interrupt void Cla1Task2(void);

/**
 * Task 3 specific to the application
 */

__interrupt void Cla1Task3(void);

/**
 * Task 4 specific to the application
 */

__interrupt void Cla1Task4(void);

/**
 * Task 5 specific to the application
 */

__interrupt void Cla1Task5(void);

/**
 * Task 6 specific to the application
 */

__interrupt void Cla1Task6(void);

/**
 * Task 7 specific to the application
 */

__interrupt void Cla1Task7(void);

/**
 * Task 8 specific to the application
 *
 * Generally used to initiate the variables.
 * Because the CLA will not initiate it's memory automatically.
 *
 */

__interrupt void Cla1Task8(void);

#endif /* APPLICATION_INCLUDE_CLA_CLA1_CONFIG_H_ */
