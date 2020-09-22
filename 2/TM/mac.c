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

  }

  return hasil;
}

void addFirst(char nama[], char rumus[], char konsentrasi[], list *L){
  elemen* baru;
  baru = (elemen *) malloc (sizeof(elemen));
  strcpy(baru->kontainer.nama, nama);
  strcpy(baru->kontainer.rumus, rumus);
  strcpy(baru->kontainer.konsentrasi, konsentrasi);

  if((*L).first == NULL){
    baru->next = NULL;
  }
  else{
    baru->next = (alamatelmt) (*L).first;
  }

  (*L).first = baru;
  baru = NULL;
}

void addAfter(elemen* prev, char nama[], char rumus[], char konsentrasi[], list *L){
  elemen *baru;
  baru = (elemen*) malloc(sizeof(elemen));
  strcpy(baru->kontainer.nama, nama);
  strcpy(baru->kontainer.rumus, rumus);
  strcpy(baru->kontainer.konsentrasi, konsentrasi);

  if(prev->next == NULL){
    baru->next = NULL;
  }
  else{
    baru->next = prev->next;
  }
  prev->next = (alamatelmt) baru;
  baru = NULL;
}

void addLast(char nama[], char rumus[], char konsentrasi[], list *L){
  if((*L).first == NULL){
    //Jika kosong
    addFirst(nama, rumus, konsentrasi, L);
  }
  else{
    //Jika tak kosong
    //mencari elemen akhir list
    elemen* prev = (*L).first;

    while(prev->next != NULL){
      // Iterasi
      prev = (elemen *) prev->next;
    }
    addAfter(prev, nama, rumus, konsentrasi, L);
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
  // printf("Del After: %s %s %s\n", hapus->kontainer.nama, hapus->kontainer.rumus, hapus->kontainer.konsentrasi);
  if(hapus == NULL){
    // printf("prev NULL: %s %s %s\n", prev->kontainer.nama, prev->kontainer.rumus, prev->kontainer.konsentrasi);
    prev->next = NULL;
  }
  else{
    // printf("prev 1: %s %s %s\n", prev->kontainer.nama, prev->kontainer.rumus, prev->kontainer.konsentrasi);
    prev->next = hapus->next;
    // printf("prev 2: %s %s %s\n", prev->kontainer.nama, prev->kontainer.rumus, prev->kontainer.konsentrasi);

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
    }
  }
}

void printElement(list L){
  if(L.first != NULL){
    //Jika list tak kosong
    //init
    elemen* tunjuk = L.first;
    int i = 1;
    
    while(tunjuk != NULL){
      //proses
      printf("%s %s %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.rumus, tunjuk->kontainer.konsentrasi);

      // printf("elemen ke: %d\n", i);
      // printf("nama: %s\n", tunjuk->kontainer.nama);
      // printf("rumus: %s\n", tunjuk->kontainer.rumus);
      // printf("konsentrasi: %s\n", tunjuk->kontainer.konsentrasi);
      // printf("next: %d\n", tunjuk->next);
      
      //Iterasi
      tunjuk = (elemen *) tunjuk->next;
      i = i + 1;
    }
    printf("=====\n");
    free(tunjuk);
  }
  else{
    //Jika list kosong
    printf("List kosong\n");
    printf("=====\n");
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