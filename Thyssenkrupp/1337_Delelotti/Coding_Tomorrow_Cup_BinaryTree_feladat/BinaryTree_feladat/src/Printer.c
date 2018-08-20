/*
 * Printer.c
 *
 *  Created on: May 2, 2018
 */

#include <stdio.h>

#include "../include/BinaryTree.h"

#define MAX_LNG 256

char array[MAX_LNG] = {};
int pos = 0;

/* Initializes the printer API for a new tree */
void PrintInit()
{
    int i;
    for(i=0; i<MAX_LNG; ++i) { array[i] = 0; }
    pos = 0;
}

/* Print a single character. Needs to be used from the Process code */
void PrintChar(char c)
{
    if( pos+1<MAX_LNG ) { array[pos++] = c; }
}

/* Evaluate results and compare with .solve file */
void PrintAssert(char *fileName)
{
    FILE *file;
    int idx = 0;
    int c;
    bool error = FALSE;

    printf("Evaluating the result of the algorithm.\n");
    printf("Result  : %s\n",array);
    printf("Expected: ");

    file = fopen(fileName, "r");

    c = fgetc(file);
    while(c != EOF)
    {
        if(idx<pos) { if(c != array[idx++]) error = TRUE; }
        else { error = TRUE; }
        putchar(c);
        c = fgetc(file);
    }

    if(error) { printf("\nERROR they do not match!\n\n"); }
    else { printf("\nCORRECT they do match!\n\n"); }

    fclose(file);

}
