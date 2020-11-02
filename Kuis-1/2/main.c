#include "head.h"

int main() {
  /*Saya Muhammad Izzatul Haq mengerjakan Kuis 1 Nomor 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
  char nama[100];
  int n, i, hasil;

  scanf("%d", &n);
  list L;
  createList(n, &L);

  for(i = 0; i < n; i++){
    scanf("%s",nama);
    addLast(nama, &L);
  }
  
  hasil = check(n, L);

  printHasil(hasil);

  // system("pause");
  return 0;
}