#include "head.h"

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

void addFirst(char nama[], int tgl, int umur, list *L){
  if(countElement(*L) < 100){
    int baru = emptyElement(*L);

    //Assign data ke list
    strcpy((*L).data[baru].kontainer.nama, nama);
    (*L).data[baru].kontainer.tgl = tgl;
    (*L).data[baru].kontainer.umur = umur;

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

void addAfter(int before, char nama[], int tgl, int umur, list *L){
  if(countElement(*L) < 100){
    int baru = emptyElement(*L);
    //Assign data ke list
    strcpy((*L).data[baru].kontainer.nama, nama);
    (*L).data[baru].kontainer.tgl = tgl;
    (*L).data[baru].kontainer.umur = umur;
    
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

void addLast(char nama[], int tgl, int umur, list *L){
  if((*L).first == -1){
    //jika list kosong
    addFirst(nama, tgl, umur, L);
  }
  else{
    //Jika list terisi
    addAfter((*L).tail, nama, tgl, umur, L);
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

//Untuk mengurutkan list
void sort(list *L){
  if((*L).first != -1){
    //init
    peserta store;//Penyimpanan sementara
    int tunjuk;
    int patokan; //Patokan untuk loop, karena harus berhenti di sebelum akhir
    int move = 0; //Menghitung jika ada pergerakan

    // Sorting ascending
    do{
      move = 0;
      tunjuk = (*L).first;
      patokan = (*L).data[tunjuk].next;

      while(patokan != -1){    

        if((*L).data[tunjuk].kontainer.umur > (*L).data[tunjuk + 1].kontainer.umur){
          strcpy(store.nama, (*L).data[tunjuk].kontainer.nama);
          store.tgl = (*L).data[tunjuk].kontainer.tgl;
          store.umur = (*L).data[tunjuk].kontainer.umur;

          strcpy((*L).data[tunjuk].kontainer.nama, (*L).data[tunjuk +1].kontainer.nama);
          (*L).data[tunjuk].kontainer.tgl = (*L).data[tunjuk+1].kontainer.tgl;
          (*L).data[tunjuk].kontainer.umur = (*L).data[tunjuk+1].kontainer.umur;

          strcpy((*L).data[tunjuk +1].kontainer.nama, store.nama);
          (*L).data[tunjuk +1].kontainer.tgl = store.tgl;
          (*L).data[tunjuk +1].kontainer.umur = store.umur;

          move++;
        }

        //Next
        tunjuk = (*L).data[tunjuk].next;
        patokan = (*L).data[tunjuk].next;
      }
    }while(move != 0);//Loop tidak akan berhenti selama ada perpindahan
  }
}

//Menyaring data yang tidak menang
void filter(list *L){
  int tunjuk = (*L).first;

  do{
    // printf("filter %d %d\n", (*L).first,(*L).data[tunjuk].prev);
    if((*L).data[tunjuk].kontainer.menang == 0){
      
      if(tunjuk == -1){
        delFirst(L);
      }
      else{
        delAfter((*L).data[tunjuk].prev,L);
      }
    }

    tunjuk = (*L).data[tunjuk].next;
  }while(tunjuk != -1);
}

//Untuk mengecek satu pada deret biner ganjil atau genap
int istEineUngerade(int number){
  int hasil = 0;//Nilai awalnya 0, untuk genap
  int count = 0;//Untuk menghitung angka 1 yang ditemukan
  int temp;//Penyimpanan sementara

  //Algoritma konversi desimal ke biner
  while(number > 0){
    temp = number % 2;
    if (temp == 1){
      //jika ada angka 1, dihitung
      count++;
    }
    number = number / 2;
  }
  //1 yang ditemukan dicek, apakah genap atau ganjil
  temp = count % 2;

  if(temp == 1){
    //Jika ganjil
    hasil = 1;
  }

  return hasil;
}

// Untuk mengecek dapat vocher atau tidak
void checkWin(list *L){
  if((*L).first != -1){
    //init
    int tunjuk = (*L).first;
    int hasil;
    
    while(tunjuk != -1){
      hasil = istEineUngerade((*L).data[tunjuk].kontainer.tgl);//Mengecek jumlah '1'nya ganjil atau genap
      (*L).data[tunjuk].kontainer.menang = hasil;//Ditandai menang atau tidak
      
      //Iterasi
      tunjuk = (*L).data[tunjuk].next;
    }
  }
}

void printElement(list L){
  if(L.first != -1){
    //init
    int tunjuk = L.first;//nilai awal dari first
    int i = 1;
    
    printf("=== Pengumuman ===\n");

    while(tunjuk != -1){
      printf("%d. %s %d\n", i, L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.umur);
      i++;

      //Iterasi
      tunjuk = L.data[tunjuk].next;
    }
  }
  else{
    //Jika list kosong
    printf("Tidak ada pendaftar yang beruntung.\n");
  }
  
}

void delAll(list *L){
  int i;

  for(i = countElement(*L);i>=1;i--){
    //menghapius elemen
    delLast(L);
  }
}