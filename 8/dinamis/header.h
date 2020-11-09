#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char nim[10]; 
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