#include "head.h"

/*Saya Muhammad Izzatul Haq mengerjakan Kuis 1 Nomor 1 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

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

void addFirst(char nama[], int harga, list *L){
  elemen* baru;
  baru = (elemen *) malloc (sizeof(elemen));
  strcpy(baru->kontainer.nama, nama);
  baru->kontainer.harga =  harga;
  

  if((*L).first == NULL){
    baru->next = NULL;
  }
  else{
    baru->next = (alamatelmt) (*L).first;
  }

  (*L).first = baru;
  baru = NULL;
}

void addAfter(elemen* prev, char nama[], int harga, list *L){
  elemen *baru;
  baru = (elemen*) malloc(sizeof(elemen));
  strcpy(baru->kontainer.nama, nama);
  baru->kontainer.harga =  harga;
  

  if(prev->next == NULL){
    baru->next = NULL;
  }
  else{
    baru->next = prev->next;
  }
  prev->next = (alamatelmt) baru;
  baru = NULL;
}

void addLast(char nama[], int harga, list *L){
  if((*L).first == NULL){
    //Jika kosong
    addFirst(nama, harga,  L);
  }
  else{
    //Jika tak kosong
    //mencari elemen akhir list
    elemen* prev = (*L).first;

    while(prev->next != NULL){
      // Iterasi
      prev = (elemen *) prev->next;
    }
    addAfter(prev, nama, harga,  L);
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
  // printf("Del After: %s %s %s\n", hapus->kontainer.nama, hapus->kontainer.harga, hapus->kontainer.konsentrasi);
  if(hapus == NULL){
    // printf("prev NULL: %s %s %s\n", prev->kontainer.nama, prev->kontainer.harga, prev->kontainer.konsentrasi);
    prev->next = NULL;
  }
  else{
    // printf("prev 1: %s %s %s\n", prev->kontainer.nama, prev->kontainer.harga, prev->kontainer.konsentrasi);
    prev->next = hapus->next;
    // printf("prev 2: %s %s %s\n", prev->kontainer.nama, prev->kontainer.harga, prev->kontainer.konsentrasi);

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

char moveList(char nama[], list *L1, list *L2){
  elemen* prev = (*L1).first;// tunjuk bekerja di list 1
  elemen* tunjuk = prev;//prev bekerja di list 1
  
  while(tunjuk != NULL){
    // printf("1 L2.first %d\n",(*L2).first);
    int comp = strcmp(nama, tunjuk->kontainer.nama);

    if(comp == 0){
      // printf("1 tunjuk %d\n",tunjuk);
      elemen* tunjuk1 = (*L2).first;

      if(tunjuk1 == NULL){
        //Jika L2 kosong
        // printf("1 prev->next %d tunjuk->next %d\n",prev->next,tunjuk->next);
        prev->next = tunjuk->next;//Membuat elemen sebelum tunjuk mengarah ke elemen setelah tunjuk
        // printf("2 prev->next %d tunjuk->next %d\n",prev->next,tunjuk->next);
        // printf("1 tunjuk %d\n",tunjuk);
        (*L2).first = tunjuk;//Membuat elemen yang ditemukan menjadi first di list 2
        // printf("2 tunjuk %d asa %d\n",tunjuk->next,(*L2).first);
        tunjuk->next = NULL;//Membuat next dari first di list 2 NULL
        // printf("1 (*L2)next %d tunjuk->next %d\n",(*L2).first->next, tunjuk->next);
      }else{
        

        //ELSE INI GAK JALAN, GAK TAU KENAPA


        // printf("1 tunjuk %d\n",tunjuk);
        // Jika tak kosong
        //mencari elemen akhir list
        elemen* prev2 = (*L2).first;//prev2 bekerja di list 2
        
        while(prev2->next != NULL){
          prev2 = (elemen *) prev2->next;
        }
        // printf("1 prev2next %d tunjuk %d\n",prev2,tunjuk);
        prev2->next = (alamatelmt) tunjuk;//Membuat elemen yang ditemukan menjadi first di list 2
        // printf("2 prev2next %d tunjuk %d\n",prev2->next,tunjuk);

        if(tunjuk->next == NULL){
          //Jika nilai selanjutnya dari tunjuk di L1 sama dengan NULL
          prev->next = NULL;//Nilai sebelumnya diisi NULL
        }
        else{
          //Jika tidak NULL
          printf("1 prev next %d tunjuk next %d\n",prev->next,tunjuk->next);
          prev->next = tunjuk->next;//[L1] Elemen sebelum tunjuk diarahkan pada elemen setelah tunjuk
          printf("2 prev next %d tunjuk next %d\n",prev->next,tunjuk->next);
          printf("2 L2 First %d\n",(*L2).first->next);
        }
        
        tunjuk->next = NULL;//Membuat next dari elemen di list 2 NULL
      }
    }
    printf("1 L2.first.next %d\n",(*L2).first->next);
    prev = tunjuk;
    tunjuk = (elemen *) tunjuk->next;
  }
  // free(tunjuk);
  tunjuk = NULL;
}

void printElement(list L1, list L2){
  if(L1.first != NULL){
    //Jika list tak kosong
    //init
    elemen* tunjuk = L1.first;

    printf("Isi list pertama:\n");

    while(tunjuk != NULL){
      printf("%s %d\n", tunjuk->kontainer.nama, tunjuk->kontainer.harga, tunjuk->next);
      
      //Iterasi
      tunjuk = (elemen *) tunjuk->next;
    }

    tunjuk = L2.first;
    printf("Isi list kedua:\n");

    while(tunjuk != NULL){
      printf("%s %d\n", tunjuk->kontainer.nama, tunjuk->kontainer.harga);
      
      tunjuk = (elemen *) tunjuk->next;
    }
    free(tunjuk);
  }
  else{
    //Jika list kosong
    printf("List kosong\n");
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