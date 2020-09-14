#include "head1.h"

int main() {
  list L;
  createList(&L);

  char name[10], gender;
  int age;
  
  scanf("%s %c %d", name, &gender, &age);
  addFirst(name, gender, age, &L);
  scanf("%s %c %d", name, &gender, &age);
  addFirst(name, gender, age, &L);
  scanf("%s %c %d", name, &gender, &age);
  addAfter(L.data[L.first].next, name, gender, age, &L);
  
  printElement(L);

  delFirst(&L);
  scanf("%s %c %d", name, &gender, &age);
  addLast(name, gender, age, &L);
  delAfter(L.first, &L);
  
  printElement(L);
  scanf("%s %c %d", name, &gender, &age);
  addAfter(L.first, name, gender, age, &L);
  delLast(&L);
  printElement(L);

  delAll(&L);
  printElement(L);

  system("pause");
  return 0;
};