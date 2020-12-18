#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct smp *alamatsimpul;

typedef struct smp{
    int kontainer;
    alamatsimpul right;
    alamatsimpul left;
}simpul;

typedef struct{
    simpul* root;
}tree;

void makeTree(int n, tree *T);
void addRight(int n, simpul *root);
void addLeft(int n, simpul *root);
simpul* findSimpul(int n, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
int sumRightTree(int type, simpul *root);
int sumTree(int type, simpul *root);