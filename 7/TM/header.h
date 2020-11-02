#include <stdio.h>
#include <string.h>

typedef struct{
char kata[50];
}katas;

typedef struct{
int top;
katas data[10];
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char kata[], stack *S);
void pop(stack *S);
void popTo(stack *STo, stack *SFrom);//Untuk Pop daro SFrom ke STo, posisi seperti posisi assign agar universal
void printStack(stack S,int par);