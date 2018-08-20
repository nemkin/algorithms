/*
 * ModuleTest.h
 *
 *  Created on: 2018. 04. 17.
 *  Author: thyssenkrupp Components Technology Hungary Ltd.
 */

#ifndef MODULETEST_H_
#define MODULETEST_H_

#include "types.h"

/**
 * Enumeration for module test types. These literals are input parameters for module tests according to the
 * instruction can be found in the task description.
 */
typedef enum
{
    MODULE_TEST1 = 0U,
    MODULE_TEST2 = 1U

} ModuleTestType;

typedef void (*FlashDriver_WriteType)(uint32_t aVirtualAddress, uint8_t aData);

/**
 * Starts the module test of your implementation.
 *
 * @param aType Type of the module test.
 * @param aFlashDriverWriteFunction Points to your implementation API function.
 */
void ModuleTest_Start(ModuleTestType aType, FlashDriver_WriteType aFlashDriverWriteFunction);

/**
 * Virtually writes the given data into the given physical address.
 *
 * This function is used in module test to check your physical address is correct according to the virtual address
 * given in FlashDriver_Write's 'aAddress' parameter.
 *
 * @param aPhysicalAddress Physical address.
 * @param aData One byte data.
 */
void ModuleTest_WritePhysicalFlashAddress(uint32_t aPhysicalAddress, uint8_t aData);

#endif /* MODULETEST_H_ */
