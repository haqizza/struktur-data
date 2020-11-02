#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Saya Muhammad Izzatul Haq mengerjakan Kuis 1 Nomor 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct {
  char nama[100];
}kartu;

typedef struct {
  kartu kontainer;
  int next;
  int prev;
}elemen;

typedef struct {
  int first;
  int tail;
  elemen data[100];
}list;

void createList(int n, list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], list *L);
void addAfter(int before, char nama[], list *L);
void addLast(char nama[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
int check(int n, list L);
void printHasil(int hasil);
void printElementToHead(list L);
void printElement(list L);