#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char nama[50];
  int tgl;
  int umur;
  int menang;
}peserta;

typedef struct {
  peserta kontainer;
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
void addFirst(char nama[], int tgl, int umur, list *L);
void addAfter(int before, char nama[], int tgl, int umur, list *L);
void addLast(char nama[], int tgl, int umur, list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void sort(list *L);
void filter(list *L);
int istEinerUngerade(int number);
void checkWin(list *L);
void printElementToHead(list L);
void printElement(list L);