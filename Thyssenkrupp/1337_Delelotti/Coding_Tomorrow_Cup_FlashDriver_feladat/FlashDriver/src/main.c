/*
 * main.c
 *
 *  Created on: 2018. 04. 17.
 *  Author: thyssenkrupp Components Technology Hungary Ltd.
 */

#include <stdlib.h>
#include <FlashDriver.h>
#include <ModuleTest.h>

/**
 * Main function of the project. Please only modify the MODULE_TESTX parameter
 * according to the instructions of the current task.
 * Module test is a library which contains all you need to test your implementation.
 */
int main(void)
{
    /*
     * This function call will test your algorithm implementation.
     * - In case of failure of the test please check your implementation.
     * - In case of success of the test you have done with your task.
     * */
    ModuleTest_Start(MODULE_TEST1, FlashDriver_Write);

    return EXIT_SUCCESS;
}
