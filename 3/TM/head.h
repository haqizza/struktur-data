#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char peran[50];
  char nama[50];
  int umur;
}aktor;

typedef struct {
  aktor kontainer;
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
void addFirst(char peran[], char nama[], int umur, list *L);
void addAfter(int before, char peran[], char nama[], int umur, list *L);
void addLast(char peran[], char nama[], int umur, list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElementToHead(list L);
void printElement(list L);
void delAll(list *L);