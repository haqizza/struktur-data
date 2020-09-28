#include "head.h"

int main() {
  list L;
  createList(&L);

  char peran[6][50], nama[6][50];
  int umur[6];
  int i;

  
  for (i=0;i<6;i++){
    scanf("%s %s %d", peran[i], nama[i], &umur[i]);
  };
  
  addFirst(peran[0], nama[0], umur[0], &L);
  addLast(peran[1], nama[1], umur[1], &L);
  addAfter(L.first, peran[2], nama[2], umur[2], &L);

  printElement(L);

  delAfter(L.data[L.first].next, &L);

  printElement(L);

  addFirst(peran[3], nama[3], umur[3], &L);
  delAfter(L.first, &L);

  printElement(L);

  addAfter(L.data[L.first].next, peran[4], nama[4], umur[4], &L);
  addLast(peran[5], nama[5], umur[5], &L);

  printElementToHead(L);

  delAll(&L);

  printElement(L);

  // system("pause");
  return 0;
}