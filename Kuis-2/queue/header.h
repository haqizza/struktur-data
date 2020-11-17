#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*Saya Muhammad Izzatul Haq mengerjakan Kuis 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct{
    char nama[100]; 
    char ktp[100];
    int anggota;
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
void add(char nama[], char ktp[], int anggota, queue *Q);
void addPriority(char nama[], char ktp[], int anggota, queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, int m, int mAr[]);