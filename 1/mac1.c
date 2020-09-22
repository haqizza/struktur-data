#include "head1.h"

void createList(list *L) {
  (*L).first = -1;
  int i;

  for(i=0;i<10;i++){
    // Inisialisasi isi array
    (*L).data[i].next = -2;
  }
}

int countElement(list L){
  int hasil = 0;
  if (L.first != -1){
    // List tak kosong
    int hitung;

    //Init
    hitung = L.first;

    while (hitung != -1){
      // Proses
      hasil = hasil + 1;

      // Iterasi
      hitung = L.data[hitung].next; //= element.next
    }
  }

  return hasil;
}

int emptyElement(list L){
  int hasil = -1;

  if (countElement(L) < 10){
    int ketemu = 0;

    int i = 0;

    while((ketemu == 0) && (i < 10)){
      if (L.data[i].next == -2){
        hasil = i;
        ketemu = 1;
      }
      else{
        i = i + 1;
      }
    }
  }

  return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L){
  if(countElement(*L) < 10){
    int baru = emptyElement(*L);

    strcpy((*L).data[baru].kontainer.nim, nim);
    strcpy((*L).data[baru].kontainer.nama, nama);
    strcpy((*L).data[baru].kontainer.nilai, nilai);
    // printf("add first\n");

    if((*L).first == -1){
      //jika kosong
      (*L).data[baru].next = -1;
    }
    else{
      //Jika isi
      (*L).data[baru].next = (*L).first;
    }
    (*L).first = baru;
  }
  else{
    //Jika array penuh
    printf("sudah tidak dapat ditambah\n");   
  }
}

void addAfter(int prev, char nim[], char nama[], char nilai[], list *L){
  if(countElement(*L) < 10){
    int baru = emptyElement(*L);
    strcpy((*L).data[baru].kontainer.nim, nim);
    strcpy((*L).data[baru].kontainer.nama, nama);
    strcpy((*L).data[baru].kontainer.nilai, nilai);
    // printf("add after\n");
    if((*L).data[prev].next == -1){
      //jika kosong
      (*L).data[baru].next = -1;
    }
    else{
      //Jika isi
      (*L).data[baru].next = (*L).data[prev].next;
    }
    (*L).data[prev].next = baru;
  }
  else{
    //Jika array penuh
    printf("sudah tidak dapat ditambah\n");   
  }
}

void addLast(char nim[], char nama[], char nilai[], list *L){
  if((*L).first == -1){
    //jika list kosong
    addFirst(nim, nama, nilai, L);
  }
  else{
    //Jika list terisi
    if(countElement(*L) < 10){
      //Jika array belum penuh
      //Mencari element terakhir

      //Init
      int prev = (*L).first;

      while((*L).data[prev].next != -1){
        //iterasi
        prev = (*L).data[prev].next;
      }

      addAfter(prev, nim, nama, nilai, L);
      // printf("add last\n");
    }
    else{
      //Jika array penuh
    printf("sudah tidak dapat ditambah\n");
    }
  }
}

void delFirst(list *L){
  if((*L).first != -1){
    int hapus = (*L).first;
    
    if(countElement(*L) == 1){
      (*L).first = -1;
    }
    else{
      (*L).first = (*L).data[hapus].next;
    }
    //elemen awal sebelumnya dikosongkan
    (*L).data[hapus].next = -2;
    // printf("delFirst\n");
  }
  else{
    //Jika list masih kosong
    printf("list kosong\n");
  }
}

void delAfter(int prev, list *L){
  int hapus = (*L).data[prev].next;

  if(hapus != -1){
    if((*L).data[hapus].next == -1){
      (*L).data[prev].next = -1;
    }
    else{
      (*L).data[prev].next = (*L).data[hapus].next;
    }
    //pengosongan elemen
    (*L).data[hapus].next = -2;
    // printf("delAfter\n");
  }
}

void delLast(list *L){
  if((*L).first != -1){
    if(countElement(*L) == 1){
      //Jika ist isi 1 elemen
      delFirst(L);
    }
    else{
      int hapus = (*L).first;
      int prev;

      while((*L).data[hapus].next != -1){
        //iterasi
        prev = hapus;
        hapus = (*L).data[hapus].next;
      }
      //elemen sebelum terakhir diganti jadi terakhir
      delAfter(prev, L);
    }
    // printf("delLast\n");
  }
  else{
      //Jika list kosong
      printf("list kosong\n");
  }
}

void printElement(list L){
  if(L.first != -1){
    //init
    int tunjuk = L.first;
    int i = 1;
    // printf("%d print El\n", L.first);
    while(tunjuk != -1){
      //proses
      // printf("%d print El.data\n", tunjuk);
      // printf("%d print El.data\n", L.data[tunjuk].next);

      printf("elemen ke: %d\n", i);
      printf("nim: %s\n", L.data[tunjuk].kontainer.nim);
      printf("nama: %s\n", L.data[tunjuk].kontainer.nama);
      printf("nilai: %s\n", L.data[tunjuk].kontainer.nilai);
      printf("next: %d\n", L.data[tunjuk].next);
      printf("===========\n");
      //Iterasi
      tunjuk = L.data[tunjuk].next;
      i = i + 1;
    }
  }
  else{
    //Jika list kosong
    printf("list kosong\n");
  }
  
}

void delAll(list *L){
  int i;

  for(i = countElement(*L);i>=1;i--){
    //menghapius elemen
    delLast(L);
  }
}
