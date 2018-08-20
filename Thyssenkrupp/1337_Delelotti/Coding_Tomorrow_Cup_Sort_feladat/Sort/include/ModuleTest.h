/*
 * ModuleTest.h
 *
 *  Created on: 2018. 04. 17.
 *  Author: thyssenkrupp Components Technology Hungary Ltd.
 */

#ifndef MODULETEST_H_
#define MODULETEST_H_

#include "types.h"

/* Type definition of tested functions. */
typedef void (*SortType)(void);

/**
 * Starts the module test of your implementation.
 *
 * @param aSortFunction Points to your sort implementation API function.
 */
void ModuleTest_Start(SortType aSortFunction);

/**
 * Compares two items of the list selected by its indexes.
 *
 * If at least one of the given indexes is invalid this function simply skips the operation and the test will fail.
 *
 * @param aIndex1 Index of the first item to be compared with the item given by the second index.
 * @param aIndex2 Index of the second item to be compared with the item given by the first index.
 * @return 0 in case of the two items are equal, 1 in case of the item[aIndex1] > item[aIndex2], otherwise -1.
 */
int ModuleTest_CompareListItems(uint32_t aIndex1, uint32_t aIndex2);

/**
 * Swaps two items of the list selected by its indexes.
 *
 * If at least one of the given indexes is invalid this function simply skips the operation and the test will fail.
 *
 * @param aIndex1 Index of the item which will be swapped by aIndex2.
 * @param aIndex2 Index of the item which will be swapped by aIndex1.
 */
void ModuleTest_SwapListItems(uint32_t aIndex1, uint32_t aIndex2);

/**
 * Gets size of the list.
 *
 * @return Size of the list.
 */
uint32_t ModuleTest_GetListSize(void);

#endif /* MODULETEST_H_ */
