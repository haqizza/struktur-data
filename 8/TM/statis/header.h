#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50];
    float nilai;
}nilaiMatKul;

typedef struct{
    int first;
    int last;
    nilaiMatKul data[6];
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(char nama[], float nilai, queue *Q);
void addPriority(char nama[], float nilai, int prior, queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, int number);