/*
 * Process.c
 *
 *  Created on: Apr 20, 2018
 */
#include "../include/BinaryTree.h"

void pre_1337(tNode *root, int current) {

    PrintChar(root[current].data);
    if(root[current].left != -1) pre_1337(root,root[current].left);
    if(root[current].right != -1) pre_1337(root,root[current].right);
}

void in_1337(tNode *root, int current) {

    if(root[current].left != -1) in_1337(root, root[current].left);
    PrintChar(root[current].data);
    if(root[current].right != -1) in_1337(root, root[current].right);
}

void post_1337(tNode *root, int current) {

    if(root[current].left != -1) post_1337(root, root[current].left);
    if(root[current].right != -1) post_1337(root, root[current].right);
    PrintChar(root[current].data);
}

void ProcessTree_1337(tNode *root, tAlg alg)
{

    if(alg==ALG_PRE_ORDER) pre_1337(root, 0);
    if(alg==ALG_IN_ORDER) in_1337(root, 0);
    if(alg==ALG_POST_ORDER) post_1337(root, 0);
}

