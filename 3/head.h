#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nim[10];
  char nama[50];
  char nilai[2];
}nilaiMatkul;

typedef struct {
  nilaiMatkul kontainer;
  int next;
  int prev;
}elemen;

typedef struct {
  int first;
  int tail;
  elemen data[10];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(int before, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);