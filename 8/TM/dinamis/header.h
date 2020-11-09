#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char nama[50]; 
    float nilai;
}nilaiMatKul;

typedef struct elm *alamatelmt;

typedef struct elm{
    nilaiMatKul kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen *first;
    elemen *last;
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], float nilai, queue *Q);
void addPriority(char nama[], float nilai, int prior, queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, int number);