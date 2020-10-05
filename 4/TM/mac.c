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

void addFirst(char kata1[], char kata2[], list *L){

  elemen* baru;
  baru = (elemen *) malloc (sizeof(elemen));

  strcpy(baru->kontainer.kata1, kata1);
  strcpy(baru->kontainer.kata2, kata2);
  
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

void addBefore(elemen* after, char kata1[], char kata2[], list *L){
  if(after != NULL){
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));

    strcpy(baru->kontainer.kata1, kata1);
    strcpy(baru->kontainer.kata2, kata2);
    

    if(after->prev == NULL){
      baru->prev = NULL;
      (*L).first = baru;
    }
    else{
      baru->prev = after->prev;
      baru->prev->next = baru;
    }

    baru->next = after;
    after->prev = baru;
    baru = NULL;
  }
}

void addAfter(elemen* before, char kata1[], char kata2[], list *L){
  if(before != NULL){
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));

    strcpy(baru->kontainer.kata1, kata1);
    strcpy(baru->kontainer.kata2, kata2);
    

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

void addLast(char kata1[], char kata2[], list *L){
  if((*L).first == NULL){
    //jika list kosong
    addFirst(kata1, kata2, L);
  }
  else{
    //Jika list terisi
    addAfter((*L).tail, kata1, kata2, L);
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
        (*L).tail = before;
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
  }
}

void printElementToHead(list L){
  char strip[10];
  strcpy(strip, "-----");

  if(L.first != NULL){
    //init
    elemen* tunjuk = L.tail;
    while(tunjuk != NULL){
      //proses
      printf("%s %s\n", tunjuk->kontainer.kata1, tunjuk->kontainer.kata2);
      // printf("Asdos %s %s\n",kata1[4],kata2[4]);
      //Iterasi
      tunjuk = tunjuk->prev;
    }
    printf("%s\n", strip);
  }
  else{
    //Jika list kosong
    printf("LGD Kosong\n");
    printf("%s\n", strip);
  }
}

void printElement(list L){
  char strip[10];
  strcpy(strip, "-----");

  if(L.first != NULL){
    //init
    elemen* tunjuk = L.first;
    
    while(tunjuk != NULL){
      //proses

      printf("%s %s\n", tunjuk->kontainer.kata1, tunjuk->kontainer.kata2);
      //Iterasi
      tunjuk = tunjuk->next;
    }

    printf("%s\n", strip);
  }
  else{
    //Jika list kosong
    printf("LGD Kosong\n");
    printf("%s\n", strip);
  }
  
}

void delAll(list *L){
  if(countElement(*L) != 0){
    int i;

    for(i = countElement(*L);i>=1;i--){
      //menghapus elemen
      delLast(L);
    }
  }
}
