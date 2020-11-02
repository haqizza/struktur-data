#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*Saya Muhammad Izzatul Haq mengerjakan Kuis 1 Nomor 1 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct {
  char nama[105];
  int harga;
}menu;

typedef struct elmt* alamatelmt;

typedef struct {
  menu kontainer;
  alamatelmt next;
}elemen;

typedef struct {
  elemen* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], int harga, list *L);
void addAfter(elemen* prev, char nama[], int harga, list *L);
void addLast(char nama[], int harga, list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
char moveList(char nama[], list *L1, list *L2);
void printElement(list L1, list L2);
void delAll(list *L);