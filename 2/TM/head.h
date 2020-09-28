#include <stdio.h>
#include <malloc.h>
#include <string.h>

//TM 2

typedef struct {
  char nama[100];
  char rumus[100];
  char konsentrasi[100];
}senyawa;

typedef struct elmt* alamatelmt;

typedef struct {
  senyawa kontainer;
  alamatelmt next;
}elemen;

typedef struct {
  elemen* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], char rumus[], char konsentrasi[], list *L);
void addAfter(elemen* prev, char nama[], char rumus[], char konsentrasi[], list *L);
void addLast(char nama[], char rumus[], char konsentrasi[], list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);