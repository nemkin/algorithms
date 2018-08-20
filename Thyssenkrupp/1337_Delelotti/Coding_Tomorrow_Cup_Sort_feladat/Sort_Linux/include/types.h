/*
 * types.h
 *
 *  Created on: 2018. 04. 17.
 *  Author: thyssenkrupp Components Technology Hungary Ltd.
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>

#ifndef NULL_PTR
   /* Null pointer. */
   #define NULL_PTR  ((void *)0)
#endif

#ifndef TRUE
    /** Boolean true value */
    #define TRUE (1U)
#endif

#ifndef FALSE
    /** Boolean false value */
    #define FALSE (0U)
#endif

/* Boolean type definition. */
typedef unsigned char boolean;

#endif /* TYPES_H_ */
