/*
 * cla1_shared_memory.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_
#define APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_

#include "CLAmath.h"

//
// Defines
//

//
// Globals
//

// ==============================
// CLA1 to CPU1 Named Values
//===============================



// ==============================
// CPU1 to CLA1 Named Values
//===============================

// Example
enum{
    BSP_CLA_CONTROL_1_ENABLED,
    BSP_CLA_CONTROL_1_DISABLED,
    BSP_CLA_CONTROL_1_TEST_CONTROL_ACTION,
};

// Caution use only variables with n*16bits size
// enums typedefs are 8bit variables
// - (this is strange to a c28x processor that uses only 16bit space on memory, but yes)

// CLA to CPU Message RAM area
typedef struct{

//Task 1 (C) Variables
    uint16_t example_1;
    float32_t example_2;

//Task 2 (C) Variables

//Task 3 (C) Variables

//Task 4 (C) Variables

//Task 5 (C) Variables

//Task 6 (C) Variables

//Task 7 (C) Variables

//Task 8 (C) Variables

//Common (C) Variables

}CLA_CPU_Message;

// Caution use only variables with n*16bits size
// CPU to CLA Message RAM area
typedef struct{

//Task 1 (C) Variables

    uint16_t example_1;
    float32_t example_2;

//Task 2 (C) Variables

//Task 3 (C) Variables

//Task 4 (C) Variables

//Task 5 (C) Variables

//Task 6 (C) Variables

//Task 7 (C) Variables

//Task 8 (C) Variables

//Common (C) Variables

}CPU_CLA_Message;

//Cla_CPU Memory, Be careful this memory can be initialized by CPU, but in real time it is only for CLA

typedef struct{
// Put your Cla_Data which is initialized by CPU here, go to "cla1_shared_memory.c" file and initiate this data globally.

}CLA_Memory_CPU_Init;


#endif /* APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_ */
