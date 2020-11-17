#include "header.h"
/*Saya Muhammad Izzatul Haq mengerjakan Kuis 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
void createEmpty(queue *Q){ 
    (*Q).first = NULL; 
    (*Q).last = NULL;
}

int isEmpty(queue Q){ 
    int hasil = 0; 

    if(Q.first == NULL){
        hasil = 1;
    }
return hasil;
}

int countElement(queue Q){
    int hasil = 0;
    if(Q.first != NULL){
        /* queue tidak kosong */ 
        elemen* bantu;
        /* inisialisasi */ 
        bantu = Q.first;

        while(bantu != NULL){
            /* proses */
            hasil= hasil + 1;
            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(char nama[], char ktp[], int anggota, queue *Q){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.ktp, ktp);
    baru->kontainer.anggota = anggota;
    baru->next = NULL; 
    
    if((*Q).first == NULL){
    (*Q).first = baru;
    }
    else{
        (*Q).last->next = baru;
    }

    (*Q).last = baru;
    baru = NULL;
}

void addPriority(char nama[], char ktp[], int anggota, queue *Q){
    elemen* baru;
    elemen* bantu = (*Q).first;
    elemen* prevBantu = (*Q).first;
    baru = (elemen *) malloc (sizeof (elemen));
    int i = 0, par = 0;

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.ktp, ktp);
    baru->kontainer.anggota = anggota;

    if(isEmpty(*Q) == 0){
        if (anggota == 1){
            baru->next = (*Q).first;
            (*Q).first = baru;
        }
        else{
            while(bantu->kontainer.anggota < anggota){
                if(i>1){
                    prevBantu = prevBantu->next;
                }
                    bantu = bantu->next;
                    i++;
                }
                if(bantu == (*Q).first){
                    (*Q).first = baru;
                }
                baru->next = bantu;
                prevBantu->next = baru;
            }
    }
    else{
        add(nama, ktp, anggota, Q);
    }
}

void printQueue(queue Q, int m, int mAr[]){
    elemen* bantu = Q.first;
    int i = 0, j = 0, stat = 0;

    if(Q.first != NULL){
        elemen* bantu = Q.first;

        for(i = 0; i < m; m++){
            printf("gelombang %d:\n", i);
            for(j = 0; j < mAr[i]; j++){
                printf("%s %s %d\n", bantu->kontainer.nama, bantu->kontainer.ktp, bantu->kontainer.anggota);
                bantu = bantu->next; 
            }
        }
        printf("sisa antrian:");
        while(bantu != NULL){
            printf("%s %s %d\n", bantu->kontainer.nama, bantu->kontainer.ktp, bantu->kontainer.anggota);
            /* iterasi */
            bantu = bantu->next; 
        }
        
    }
    else{
        /* proses jika queue kosong */
        printf("Queue Kosong\n");
    }
}

