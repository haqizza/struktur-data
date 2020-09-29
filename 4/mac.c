#include "head.h"

void createList(list *L) {
  (*L).first = NULL;
  (*L).tail = NULL;
}

int countElement(list L){
  int hasil = 0;

  if (L.first != NULL){
    // List tak kosong
    elemen* hitung;

    //Init
    hitung = L.first;

    while (hitung != NULL){
      // Proses
      hasil = hasil + 1;

      // Iterasi
      hitung = hitung->next; //= element.next
    }
  }

  return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L){

  elemen* baru;
  baru = (elemen *) malloc (sizeof(elemen));

  strcpy(baru->kontainer.nim, nim);
  strcpy(baru->kontainer.nama, nama);
  strcpy(baru->kontainer.nilai, nilai);
  // printf("add first\n");

  if((*L).first == NULL){
    //jika kosong
    baru->prev = NULL;
    baru->next = NULL;
    (*L).tail = baru;
  }
  else{
    //Jika isi
    baru->prev = NULL;
    baru->next = (*L).first;
    (*L).first->prev = baru;
  }
  (*L).first = baru;
  baru = NULL;
}

void addAfter(elemen* before, char nim[], char nama[], char nilai[], list *L){
  if(before != NULL){
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));

    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

    if(before->next == NULL){
      baru->next = NULL;
      (*L).tail = baru;
    }
    else{
      baru->next = before->next;
      baru->next->prev = baru;
    }

    baru->prev = before;
    before->next = baru;
    baru = NULL;
  }
}

void addLast(char nim[], char nama[], char nilai[], list *L){
  if((*L).first == NULL){
    //jika list kosong
    addFirst(nim, nama, nilai, L);
  }
  else{
    //Jika list terisi
    addAfter((*L).tail, nim, nama, nilai, L);
  }
}

void delFirst(list *L){
  if((*L).first != NULL){
    elemen* hapus = (*L).first;
    
    if(countElement(*L) == 1){
      (*L).first = NULL;
      (*L).tail = NULL;
    }
    else{
      (*L).first = (*L).first->next;
      (*L).first->prev = NULL;
      hapus->next = NULL;
    }

    free(hapus);
  }
}

void delAfter(elemen* before, list *L){
  if(before != NULL){
    elemen* hapus = before->next;

    if(hapus != NULL){
      if(hapus->next == NULL){
        before->next= NULL;
      }
      else{
        before->next = hapus->next;
        hapus->next->prev = before;
        hapus->next = NULL;
      }
      //pengosongan memori
      hapus->prev = NULL;
      free(hapus);
    }  
  }
}

void delLast(list *L){
  if((*L).first != NULL){

    if(countElement(*L) == 1){
      //Jika ist isi 1 elemen
      delFirst(L);
    }
    else{
      //elemen sebelum terakhir diganti jadi terakhir
      delAfter((*L).tail->prev, L);
    }
    // printf("delLast\n");
  }
}

void printElement(list L){
  if(L.first != NULL){
    //init
    elemen* tunjuk = L.first;
    int i = 1;
    // printf("%d print El\n", L.first);
    while(tunjuk != NULL){
      //proses
      // printf("%d print El.data\n", tunjuk);
      // printf("%d print El.data\n", L.data[tunjuk].next);

      printf("elemen ke: %d\n", i);
      printf("prev: %d\n", tunjuk->prev);
      printf("nim: %s\n", tunjuk->kontainer.nim);
      printf("nama: %s\n", tunjuk->kontainer.nama);
      printf("nilai: %s\n", tunjuk->kontainer.nilai);
      printf("next: %d\n", tunjuk->next);
      printf("===========\n");
      //Iterasi
      tunjuk = tunjuk->next;
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
