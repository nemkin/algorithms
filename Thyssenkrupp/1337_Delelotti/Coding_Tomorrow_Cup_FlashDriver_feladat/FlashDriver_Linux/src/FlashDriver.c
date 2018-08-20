/*
 * FlashDriver.c
 *
 *  Created on: 2018. 04. 17.
 *  Author: thyssenkrupp Components Technology Hungary Ltd.
 */
#include <FlashDriver.h>
#include <ModuleTest.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * API function to write one byte data into flash memory.
 *
 * This is the only one API function you have to implement and it to be tested by the module test.
 * The API function will be called by the module test with different parameters to test functionality of the implemented
 * algorithm. The implementation shall consider that ModuleTest_WritePhysicalFlashAddress(), which is declared in
 * ModuleTest.h, shall be called.
 *
 * @param aVirtualAddress Virtual address.
 * @param aData One byte data to be written.
 */

void FlashDriver_Write(uint32_t aVirtualAddress, uint8_t aData)
{
     
    /* Put your algorithm implementation here. Don't forget to call ModuleTest_WritePhysicalFlashAddress() */

    int n = global_parameters.n;
    uint64_t* section_begins = (uint64_t*)malloc(n*sizeof(uint64_t));
    uint64_t* section_sizes = (uint64_t*)malloc(n*sizeof(uint64_t));

    for(int i=0; i<global_parameters.n; ++i) {

        uint64_t place = global_parameters.section_ids[i]-1;

        section_begins[place] = global_parameters.section_begins[i];
        section_sizes[place] = global_parameters.section_sizes[i];
        printf("%lud %lud %lud\n", place, section_begins[place], section_sizes[place]);
    }

    uint64_t virtual_size = 0;

    for(int i=0; i<n; ++i) {

        if(virtual_size + section_sizes[i] > aVirtualAddress) {

            ModuleTest_WritePhysicalFlashAddress(section_begins[i] + (aVirtualAddress - virtual_size), aData);
            break;
        }

        virtual_size += section_sizes[i];
    }

    free(section_begins);
    free(section_sizes);
}

