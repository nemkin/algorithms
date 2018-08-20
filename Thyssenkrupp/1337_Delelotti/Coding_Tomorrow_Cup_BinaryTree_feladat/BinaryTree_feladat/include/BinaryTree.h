
#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#define NULL_IDX    (-1)

#define FALSE       (0U)
#define TRUE        (!FALSE)

typedef unsigned char bool;

typedef struct
{
     char data;     /* Character stored as data */
     int left;      /* Index in the array of the left child */
     int right;     /* Index in the array of the right child */
}tNode;

typedef enum
{
    ALG_PRE_ORDER,
    ALG_IN_ORDER,
    ALG_POST_ORDER
}tAlg;

extern void ProcessTree_CsapatNev(tNode *root, tAlg alg);
extern void LoadTree(char *fileName, tNode** array, int* size);
extern void PrintInit();
extern void PrintChar(char c);
extern void PrintAssert(char *fileName);

#endif /* BINARY_TREE_H_ */
