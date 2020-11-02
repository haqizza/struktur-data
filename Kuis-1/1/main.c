#include "head.h"

int main() {
  /*Saya Muhammad Izzatul Haq mengerjakan Kuis 1 Nomor 1 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
  list L1,L2;
  createList(&L1);
  createList(&L2);

  char nama[105];
  int harga;
  int i,n1,n2;

  scanf("%d",&n1);
  for (i = 0; i < n1; i++){
    scanf("%s %d", nama, &harga);
    addLast(nama, harga, &L1);
  };

  scanf("%d",&n2);
  for (i = 0; i < n2; i++){
    scanf("%s", nama);
    moveList(nama, &L1, &L2);
  };
  
  printElement(L1,L2);

  
  
  return 0;
}