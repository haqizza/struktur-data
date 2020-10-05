#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char kata1[50];
  char kata2[50];
}kata;

typedef struct elmt *alamatelmt;

typedef struct elmt{
  kata kontainer;
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
void addFirst(char kata1[], char kata2[], list *L);
void addBefore(elemen* after, char kata1[], char kata2[], list *L);
void addAfter(elemen* before, char kata1[], char kata2[], list *L);
void addLast(char kata1[], char kata2[], list *L);
void delFirst(list *L);
void delAfter(elemen* before, list *L);
void delLast(list *L);
void printElementToHead(list L);
void printElement(list L);
void delAll(list *L);