/*
 * Loader.c
 *
 *  Created on: Apr 20, 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/BinaryTree.h"

void LoadTree(char *fileName, tNode** array, int* size)
{
    FILE *ptr;

    ptr = fopen(fileName,"rb");
    fread(size,sizeof(int),1,ptr);
    (*array) = (tNode*)malloc((*size)*sizeof(tNode));
    fread((*array),sizeof(tNode),(*size),ptr);
    fclose(ptr);
}
