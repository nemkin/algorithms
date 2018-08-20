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

    global_parameters.n = 12;
    global_parameters.section_ids = (uint64_t*)malloc(global_parameters.n*sizeof(uint64_t));
    global_parameters.section_begins = (uint64_t*)malloc(global_parameters.n*sizeof(uint64_t));
    global_parameters.section_sizes = (uint64_t*)malloc(global_parameters.n*sizeof(uint64_t));

    global_parameters.section_ids[0] = 1;
    global_parameters.section_ids[1] = 3;
    global_parameters.section_ids[2] = 10;
    global_parameters.section_ids[3] = 11;
    global_parameters.section_ids[4] = 12;
    global_parameters.section_ids[5] = 4;
    global_parameters.section_ids[6] = 8;
    global_parameters.section_ids[7] = 9;
    global_parameters.section_ids[8] = 2;
    global_parameters.section_ids[9] = 5;
    global_parameters.section_ids[10] = 6;
    global_parameters.section_ids[11] = 7;
    global_parameters.section_begins[0] = 0xA0000000;
    global_parameters.section_begins[1] = 0xA0001000;
    global_parameters.section_begins[2] = 0xA0009000;
    global_parameters.section_begins[3] = 0xA000A000;
    global_parameters.section_begins[4] = 0xB0000000;
    global_parameters.section_begins[5] = 0xC0000000;
    global_parameters.section_begins[6] = 0xC0008000;
    global_parameters.section_begins[7] = 0xC0010000;
    global_parameters.section_begins[8] = 0xC0014000;
    global_parameters.section_begins[9] = 0xC0018000;
    global_parameters.section_begins[10] = 0xC0019000;
    global_parameters.section_begins[11] = 0xC001A000;
    global_parameters.section_sizes[0] = 0x1000;
    global_parameters.section_sizes[1] = 0x8000;
    global_parameters.section_sizes[2] = 0x1000;
    global_parameters.section_sizes[3] = 0x2000;
    global_parameters.section_sizes[4] = 0x8000;
    global_parameters.section_sizes[5] = 0x8000;
    global_parameters.section_sizes[6] = 0x8000;
    global_parameters.section_sizes[7] = 0x4000;
    global_parameters.section_sizes[8] = 0x4000;
    global_parameters.section_sizes[9] = 0x1000;
    global_parameters.section_sizes[10] = 0x1000;
    global_parameters.section_sizes[11] = 0x1000;

    ModuleTest_Start(MODULE_TEST2, FlashDriver_Write);

    return EXIT_SUCCESS;
}
