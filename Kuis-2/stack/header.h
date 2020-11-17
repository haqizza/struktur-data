#include <stdio.h>
#include <string.h>
/*Saya Muhammad Izzatul Haq mengerjakan Kuis 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct{
    int nomor;
    char simbol;
}nilaiMatKul;

typedef struct{
int top;
nilaiMatKul data[50];
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(int nomor, char simbol, stack *S);
void check(int n, stack *S);
void pop(stack *S);
void printStack(stack S);
void printStackReverse(stack S);