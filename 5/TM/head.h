#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char huruf;
}mahasiswa;

typedef struct{
    char kata[50];
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
void addFirstB(char huruf, list *L);
void addFirstK(char kata[], eBaris *L);
void addAfterB(eBaris* prev, char huruf);
void addAfterK(eKolom* prev, char kata[]);
void addLastB(char huruf, list *L);
void addLastK(char kata[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);