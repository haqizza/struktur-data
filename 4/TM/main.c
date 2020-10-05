#include "head.h"

int main() {
  list L;
  createList(&L);
  
  char kata1[10][50], kata2[10][50];
  int i;


  for (i=0;i<6;i++){
    scanf("%s %s", kata1[i], kata2[i]);
  };
  
  addFirst(kata1[0], kata2[0], &L);
  addAfter(L.first, kata1[1], kata2[1], &L);
  addBefore(L.first->next, kata1[2], kata2[2], &L);
  printElement(L);

  delAfter(L.first->next->prev, &L);
  addLast(kata1[3], kata2[3], &L);
  printElement(L);

  delFirst(&L);
  addLast(kata1[4], kata2[4], &L);
  addAfter(L.first->next, kata1[5], kata2[5], &L);
  delLast(&L);
  printElementToHead(L);

  delAll(&L);
  printElement(L);

  // system("pause");
  return 0;
}