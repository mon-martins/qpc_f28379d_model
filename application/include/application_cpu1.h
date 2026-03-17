/*
 * application.h
 *
 *  Created on: 23 de jan de 2025
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_APPLICATION_H_
#define APPLICATION_INCLUDE_APPLICATION_H_

#include <bsp_f28379d_cpu1.h>
//#include <main_qm.h>



/**
 * @addtogroup CPU1
 * @{
 */

/**
 *  @addtogroup Application_cpu1
 *  @{
 */


/**
 *  @brief Inialize the user application
 *
 *  Initialize Conditions of the application, constructors included.
 */

void application_init(void);

/**
 *  @brief Starts the user application.
 *
 *  Starts the application, call the supper loop or RTOS scheduler.
 *
 */

void application_start(void);

#endif /* APPLICATION_INCLUDE_APPLICATION_CM_H_ */

/**
 * @}
 */

/**
 * @}
 */
