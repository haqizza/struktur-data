#include "head.h"

int main() {
  list L;
  createList(&L);

  char name[6][100];
  char rumus[6][100];
  char konsentrasi[6][100];
  int i;
  for (i=0;i<6;i++){
    scanf("%s %s %s", name[i], rumus[i], konsentrasi[i]);
  };
  
  printf("=====\n");

  addFirst(name[0], rumus[0], konsentrasi[0], &L);
  addLast(name[1], rumus[1], konsentrasi[1], &L);
  addFirst(name[2], rumus[2], konsentrasi[2], &L);

  printElement(L);

  addAfter((elemen *)L.first->next, name[3], rumus[3], konsentrasi[3], &L);
  
  printElement(L);

  delAfter((elemen *)L.first->next, &L);
  addLast(name[4], rumus[4], konsentrasi[4], &L);

  printElement(L);

  delFirst(&L);
  delLast(&L);

  printElement(L);

  delAll(&L);

  printElement(L);

  addLast(name[5], rumus[5], konsentrasi[5], &L);

  printElement(L);
  
  return 0;
}