#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char nama[50]; 
    int prior; 
    int waktu;
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
void add(char nama[], int waktu, queue *Q);
void addPrior(char nama[], int prior, int waktu, queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void print(char search[], queue Q);