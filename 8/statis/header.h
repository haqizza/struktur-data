#include <stdio.h>
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50];
    float nilai;
}nilaiMatKul;

typedef struct{
    int first;
    int last;
    nilaiMatKul data[10];
}queue;