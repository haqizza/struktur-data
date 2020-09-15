#include "head.h"

void createList(list *L){
  (*L).first = NULL;
}

int countElement(list L){
  int hasil = 0;

  if(L.first != NULL){
    // List tidak kosong
    elemen* tunjuk;

    //Init
    tunjuk = L.first;

    while (tunjuk != NULL){
      // proses
      hasil = hasil + 1;

      // iterasi
      tunjuk = (elemen *) tunjuk->next;
    }

    free(tunjuk);
  }

  return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L){
  elemen* baru;
  baru = (elemen *) malloc (sizeof(elemen));
  strcpy(baru->kontainer.nim, nim);
  strcpy(baru->kontainer.nama, nama);
  strcpy(baru->kontainer.nilai, nilai);

  if((*L).first == NULL){
    baru->next = NULL;
  }
  else{
    baru->next = (alamatelmt) (*L).first;
  }

  (*L).first = baru;
  baru = NULL;
}

void addAfter(elemen* prev, char nim[], char nama[], char nilai[], list *L){
  elemen *baru;
  baru = (elemen*) malloc(sizeof(elemen));
  strcpy(baru->kontainer.nim, nim);
  strcpy(baru->kontainer.nama, nama);
  strcpy(baru->kontainer.nilai, nilai);

  if(prev->next == NULL){
    baru->next = NULL;
  }
  else{
    baru->next = prev->next;
  }
  prev->next = (alamatelmt) baru;
  baru = NULL;
}

void addLast(char nim[], char nama[], char nilai[], list *L){
  if((*L).first == NULL){
    //Jika kosong
    addFirst(nim, nama, nilai, L);
  }
  else{
    //Jika tak kosong
    //mencari elemen akhir list
    elemen* prev = (*L).first;

    while(prev->next != NULL){
      // Iterasi
      prev = (elemen *) prev->next;
    }
    addAfter(prev, nim, nama, nilai, L);
    free(prev);
  }
  
}

void delFirst(list *L){
  if((*L).first != NULL){
   //Jika bukan list kosong
   elemen* hapus = (*L).first;
   
   if(countElement(*L) == 1){
     (*L).first = NULL;
   }
   else{
     (*L).first = (elemen *) (*L).first->next;
     hapus->next = NULL;
   }

   free(hapus);
  }
}

void delAfter(elemen* prev,list *L){
  elemen* hapus = (elemen*) prev->next;

  if(hapus != NULL){
    prev->next = NULL;
  }
  else{
    prev->next = hapus->next;
    hapus->next = NULL;
  }
  free(hapus);
}

void delLast(list *L){
  if((*L).first != NULL){
    //Jika tak kosong
    if(countElement(*L) == 1){
      //Hanya 1 elemen
      delFirst(L);
    }
    else{
      //mencari elemen akhir
      elemen* last = (*L).first;
      elemen* prev;

      while(last->next != NULL){
        //Iterasi
        prev = last;
        last = (elemen *) last->next;
      }

      delAfter(prev, L);

      free(last);
      free(prev);
    }
  }
}

void printElement(list L){
  if(L.first != NULL){
    //Jika list tak kosong
    //init
    elemen* tunjuk = L.first;
    int i = 1;
    // printf("%d print El\n", L.first);
    while(tunjuk != NULL){
      //proses
      // printf("%d print El.data\n", tunjuk);
      // printf("%d print El.data\n", L.data[tunjuk].next);

      printf("elemen ke: %d\n", i);
      printf("nim: %s\n", tunjuk->kontainer.nim);
      printf("nama: %s\n", tunjuk->kontainer.nama);
      printf("nilai: %s\n", tunjuk->kontainer.nilai);
      printf("next: %d\n", tunjuk->next);
      printf("===========\n");
      //Iterasi
      tunjuk = (elemen *) tunjuk->next;
      i = i + 1;
    }

    free(tunjuk);
  }
  else{
    //Jika list kosong
    printf("list kosong\n");
  }
  
}

void delAll(list *L){
  if(countElement(*L) != 0){
    int i;

    for (i = countElement(*L); i >= 1; i--){
      delLast(L);
    }
  }
}