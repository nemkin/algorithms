/*
 * FlashDriver.h
 *
 *  Created on: 2018. 04. 17.
 *  Author: thyssenkrupp Components Technology Hungary Ltd.
 */

#ifndef FLASHDRIVER_H_
#define FLASHDRIVER_H_

#include <types.h>

typedef struct PARAMETERS {

    int n;
    uint64_t* section_ids;
    uint64_t* section_begins;
    uint64_t* section_sizes;
    
} PARAMETERS;

PARAMETERS global_parameters;

void FlashDriver_Write(uint32_t aVirtualAddress, uint8_t aData);

#endif /* FLASHDRIVER_H_ */
