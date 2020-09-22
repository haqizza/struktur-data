#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nama[10];
  char jenisKelamin;
  int umur;
}dataMahasiswa;

typedef struct {
  dataMahasiswa kontainer;
  int next;
}elemen;

typedef struct {
  int first;
  elemen data[10];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char jenisKelamin, int umur, list *L);
void addAfter(int prev, char nama[], char jenisKelamin, int umur, list *L);
void addLast(char nama[], char jenisKelamin, int umur, list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);