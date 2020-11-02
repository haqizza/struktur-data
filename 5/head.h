#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nim[10];
    char nama[50];
}mahasiswa;

typedef struct{
    char kode[10];
    char nilai[2];
}matKul;

typedef struct eklm *alamatekolom;

typedef struct eklm{
    matKul kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
    mahasiswa kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

typedef struct{
    eBaris *first;
}list;


void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char nim[], char nama[], list *L);
void addFirstK(char kode[], char nilai[], eBaris *L);
void addAfterB(eBaris* prev, char nim[], char nama[]);
void addAfterK(eKolom* prev, char kode[], char nilai[]);
void addLastB(char nim[], char nama[], list *L);
void addLastK(char kode[], char nilai[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);