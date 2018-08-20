/*
 * Main.c
 *
 *  Created on: Apr 20, 2018
 */
#include <stdio.h>

#include "../include/BinaryTree.h"

int main(void)
{
    tNode *root;
    int size = 0;

    LoadTree("Tree_1_PostOrder.data",&root,&size);
    PrintInit();
    ProcessTree_1337(root,ALG_POST_ORDER);
    PrintAssert("Tree_1_PostOrder.solve");

    LoadTree("Tree_2_InOrder.data",&root,&size);
    PrintInit();
    ProcessTree_1337(root,ALG_IN_ORDER);
    PrintAssert("Tree_2_InOrder.solve");

    LoadTree("Tree_3_PreOrder.data",&root,&size);
    PrintInit();
    ProcessTree_1337(root,ALG_PRE_ORDER);
    PrintAssert("Tree_3_PreOrder.solve");

    return 0;
}
