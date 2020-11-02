#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Muhammad Izzatul Haq mengerjakan UTS dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct{
    char jenis[10];
    int tahun;
}dataObat;

typedef struct{
    char nama[50];
}nama;

typedef struct eklm *alamatekolom;

typedef struct eklm{
    nama kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
    dataObat kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

typedef struct{
    eBaris *first;
}list;


void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char jenis[], int tahun, list *L);
void addFirstK(char nama[], eBaris *L);
void addAfterB(eBaris* prev, char jenis[], int tahun);
void addAfterK(eKolom* prev, char nama[]);
void addLastB(char jenis[], int tahun, list *L);
void addLastK(char nama[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);

void sort(list *L);
void assignBnK(char jenis[], int tahun, char nama[], list *L);
void change(char nama[], int tahun,list *L);
void move(eBaris *thisB, eKolom *thisC, int tahun,list *L);