/*
 * FlashDriver.c
 *
 *  Created on: 2018. 04. 17.
 *  Author: thyssenkrupp Components Technology Hungary Ltd.
 */
#include <FlashDriver.h>
#include <ModuleTest.h>

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
}
