#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct smp *alamatsimpul;

typedef struct smp{
    char kontainer[51];
    alamatsimpul right;
    alamatsimpul left;
}simpul;

typedef struct{
    simpul* root;
}tree;

void makeTree(char str[], tree *T);
void addRight(char str[], simpul *root);
void addLeft(char str[], simpul *root);
simpul* findSimpul(char str[], simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
int isMirror(simpul *root1, simpul *root2);