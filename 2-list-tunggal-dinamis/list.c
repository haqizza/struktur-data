#include "head.h"

int main() {
  list L;
  createList(&L);
  printElement(L);
  
  printf("================\n");

  addFirst("1", "Orang_1", "A", &L);
  addAfter(L.first, "2", "Orang_2", "A", &L);
  addLast("3", "Orang_3", "A", &L);
  printElement(L);

  printf("================\n");

  delFirst(&L);
  delAfter(L.first,&L);
  delLast(&L);
  printElement(L);

  printf("================\n");

  // system("pause");
  return 0;
};