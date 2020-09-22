#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nama[30];
  int skala;
}pasien;

typedef struct {
  pasien kontainer;
  int next;
}elemen;

typedef struct {
  int first;
  elemen data[100];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addLast(char nama[],int skala, list *L);
void sortAndPrintElement(int param, list L);
void delAll(list *L);