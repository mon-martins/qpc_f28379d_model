#include <application_cpu1.h>
/*
 * main.c
 */

//S_DEFINE_THIS_MODULE("main");

enum{
    PASSED_THROUGH_SCHEDULER =1U,
};

/**
 *  @brief main function
 *
 *  Function called for the microcontroller automatically.
 *
 */


void main(void)
{

    //
    // REQUIRE
    //

    // Not applicable: main function, no parameters

    bsp_init();

    application_init();

    // Can be moved inside application_start
    bsp_enable_interrupts();

    application_start();

    //
    // ENSURE
    //

    // Not applicable: main function, no return.

//    S_ASSERT(PASSED_THROUGH_SCHEDULER,0);
}



