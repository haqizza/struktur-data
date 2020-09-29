#include "head.h"

int main() {
  char nama[50];
  int data, i, tgl, umur;

  scanf("%d", &data);
  list L;
  createList(data, &L);

  for(i = 0; i < data; i++){
    scanf("%s %d %d",nama, &tgl, &umur);
    addLast(nama, tgl, umur, &L);
  }
  
  sort(&L);
  checkWin(&L);
  filter(&L);

  printElementToHead(L);
  printElement(L);

  // system("pause");
  return 0;
}