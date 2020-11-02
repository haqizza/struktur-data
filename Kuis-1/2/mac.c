#include "head.h"
/*Saya Muhammad Izzatul Haq mengerjakan Kuis 1 Nomor 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
void createList(int n, list *L) {
  (*L).first = -1;
  (*L).tail = -1;
  int i;

  for(i=0;i<n;i++){
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
      hasil = hasil + 1;

      // Iterasi
      hitung = L.data[hitung].next; //= element.next
    }
  }

  return hasil;
}

int emptyElement(list L){
  int hasil = -1;

  if (countElement(L) < 100){
    int ketemu = 0;

    int i = 0;

    while((ketemu == 0) && (i < 100)){
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

void addFirst(char nama[], list *L){
  if(countElement(*L) < 100){
    int baru = emptyElement(*L);

    //Assign data ke list
    strcpy((*L).data[baru].kontainer.nama, nama);

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

void addAfter(int before, char nama[], list *L){
  if(countElement(*L) < 100){
    int baru = emptyElement(*L);
    //Assign data ke list
    strcpy((*L).data[baru].kontainer.nama, nama);
    
    if((*L).data[before].next != -1){
      //jika baru, bukan jadi terakhir
      (*L).data[baru].prev = before;
      (*L).data[baru].next = (*L).data[before].next;
      (*L).data[before].next = baru;
      (*L).data[(*L).data[baru].next].prev = baru;
    }
    else{
      //Jika baru, jadi terakhir
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

void addLast(char nama[], list *L){
  if((*L).first == -1){
    //jika list kosong
    addFirst(nama, L);
  }
  else{
    //Jika list terisi
    addAfter((*L).tail, nama, L);
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
    // (*L).data[hapus].prev = -2;
    // (*L).data[hapus].next = -2;
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

int check(int n, list L){
  int tunjukF = L.first;//nilai awal dari first
  int tunjukT = L.tail;//nilai awal dari tail
  int i, compared, hasil = 0, nomor = 1;

  for(i = 0; i < (n/2); i++){
    compared = strcmp(L.data[tunjukF].kontainer.nama, L.data[tunjukT].kontainer.nama);

    if(compared != 0){
      hasil = nomor;
      break;
    }

    tunjukF = L.data[tunjukF].next;
    tunjukT = L.data[tunjukT].prev;
    nomor++;
  }

  return hasil;
}

void printHasil(int hasil){
  if(hasil == 0){
    printf("urutan sama\n");
  }
  else{
    printf("urutan tidak sama mulai urutan ke %d\n", hasil);
  }
}

//Print dari tail
// void printElementToHead(list L){
//   if(L.first != -1){
//     //init
//     int tunjuk = L.tail;//nilai awal dari tail
//     int i = 1;//Nomor
    
//     printf("=== Daftar Bu Tejo ===\n");

//     while(tunjuk != -1){
//       printf("%d. %s %d\n", i, L.data[tunjuk].kontainer.nama);
//       i++;
      
//       //Iterasi
//       tunjuk = L.data[tunjuk].prev;
//     }
//   }
// }

// void printElement(list L){
//   if(L.first != -1){
//     //init
//     int tunjuk = L.first;//nilai awal dari first
//     int i = 1;
    
//     printf("=== Pengumuman ===\n");

//     while(tunjuk != -1){
//       printf("%d. %s %d\n", i, L.data[tunjuk].kontainer.nama);
//       i++;

//       //Iterasi
//       tunjuk = L.data[tunjuk].next;
//     }
//   }
//   else{
//     //Jika list kosong
//     printf("List kosong.\n");
//   }
  
// }

void delAll(list *L){
  int i;

  for(i = countElement(*L);i>=1;i--){
    //menghapius elemen
    delLast(L);
  }
}