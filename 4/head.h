#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char nim[10];
  char nama[50];
  char nilai[2];
}nilaiMatKul;

typedef struct elmt *alamatelmt;

typedef struct elmt{
  nilaiMatKul kontainer;
  alamatelmt prev;
  alamatelmt next;
} elemen;

typedef struct{
elemen *first;
elemen *tail;
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(elemen* before, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(elemen* before, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);