#include "head.h"

void createList(list *L) {
  (*L).first = -1;
  (*L).tail = -1;
  int i;

  for(i=0;i<10;i++){
    // Inisialisasi isi array
    (*L).data[i].prev = -2;
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

void addFirst(char peran[], char nama[], int umur, list *L){
  if(countElement(*L) < 10){
    int baru = emptyElement(*L);

    strcpy((*L).data[baru].kontainer.peran, peran);
    strcpy((*L).data[baru].kontainer.nama, nama);
    (*L).data[baru].kontainer.umur = umur;
    // printf("add first\n");

    if((*L).first == -1){
      //jika kosong
      (*L).data[baru].prev = -1;
      (*L).data[baru].next = -1;
      (*L).tail = baru;
    }
    else{
      //Jika isi
      (*L).data[baru].prev = -1;
      (*L).data[baru].next = (*L).first;
      (*L).data[(*L).first].prev = baru;
    }
    (*L).first = baru;
  }
  else{
    //Jika array penuh
    printf("sudah tidak dapat ditambah\n");   
  }
}

void addAfter(int before, char peran[], char nama[], int umur, list *L){
  if(countElement(*L) < 10){
    int baru = emptyElement(*L);

    strcpy((*L).data[baru].kontainer.peran, peran);
    strcpy((*L).data[baru].kontainer.nama, nama);
    (*L).data[baru].kontainer.umur = umur;
    // printf("add after\n");
    if((*L).data[before].next != -1){
      //jika baru bukan jadi terakhir
      (*L).data[baru].prev = before;
      (*L).data[baru].next = (*L).data[before].next;
      (*L).data[before].next = baru;
      (*L).data[(*L).data[baru].next].prev = baru;
    }
    else{
      //Jika baru jadi terakhir
      (*L).data[baru].prev = before;
      (*L).data[before].next = baru;
      (*L).data[baru].next = -1;
      (*L).tail = baru;
    }
  }
  else{
    //Jika array penuh
    printf("sudah tidak dapat ditambah\n");   
  }
}

void addLast(char peran[], char nama[], int umur, list *L){
  if((*L).first == -1){
    //jika list kosong
    addFirst(peran, nama, umur, L);
  }
  else{
    //Jika list terisi
    addAfter((*L).tail, peran, nama, umur, L);
      // printf("add last\n");
  }
}

void delFirst(list *L){
  if((*L).first != -1){
    int hapus = (*L).first;
    
    if(countElement(*L) == 1){
      (*L).first = -1;
      (*L).tail = -1;
    }
    else{
      (*L).first = (*L).data[(*L).first].next;
      (*L).data[(*L).first].prev = -1;
    }
    //elemen awal sebelumnya dikosongkan
    (*L).data[hapus].prev = -2;
    (*L).data[hapus].next = -2;
    // printf("delFirst\n");
  }
  else{
    //Jika list masih kosong
    printf("list kosong\n");
  }
}

void delAfter(int before, list *L){
  int hapus = (*L).data[before].next;

  if(hapus != -1){
    if((*L).data[hapus].next == -1){
      (*L).tail = before;
      (*L).data[before].next = -1;
    }
    else{
      (*L).data[before].next = (*L).data[hapus].next;
      (*L).data[(*L).data[hapus].next].prev = before;
    }
    //pengosongan elemen
    (*L).data[hapus].prev = -2;
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
      //elemen sebelum terakhir diganti jadi terakhir
      delAfter((*L).data[(*L).tail].prev, L);
    }
    // printf("delLast\n");
  }
  else{
      //Jika list kosong
      printf("list kosong\n");
  }
}

void printElementToHead(list L){
  if(L.first != -1){
    //init
    int tunjuk = countElement(L) - 1;
    
    while(tunjuk != -1){
      //proses
      printf("%s %s %d\n", L.data[tunjuk].kontainer.peran, L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.umur);
      //Iterasi
      tunjuk = L.data[tunjuk].prev;
    }
    printf("==========\n");
  }
  else{
    //Jika list kosong
    printf("List Kosong!\n");
    printf("==========\n");
  }
}

void printElement(list L){
  if(L.first != -1){
    //init
    int tunjuk = L.first;
    
    while(tunjuk != -1){
      //proses

      printf("%s %s %d\n", L.data[tunjuk].kontainer.peran, L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.umur);
      
      //Iterasi
      tunjuk = L.data[tunjuk].next;
    }
    printf("==========\n");
  }
  else{
    //Jika list kosong
    printf("List Kosong!\n");
    printf("==========\n");
  }
  
}

void delAll(list *L){
  int i;

  for(i = countElement(*L);i>=1;i--){
    //menghapius elemen
    delLast(L);
  }
}
