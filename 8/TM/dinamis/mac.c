#include "header.h"

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

void add(char nama[], float nilai, queue *Q){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));

    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nilai = nilai;
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

void addPriority(char nama[], float nilai, int prior, queue *Q){
    elemen* baru;
    elemen* bantu = (*Q).first;
    elemen* prevBantu = (*Q).first;
    baru = (elemen *) malloc (sizeof (elemen));
    int i = 1;

    if(prior < 6){
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.nilai = nilai;

        if (prior == 1){
            baru->next = (*Q).first;
            (*Q).first = baru;
        }
        else{            
            while(i < prior){
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
        add(nama, nilai, Q);
    }
}

void del(queue *Q1, queue *Q2){
    if((*Q1).first != NULL){
        elemen *hapus = (*Q1).first; 

        add((*Q1).first->kontainer.nama, (*Q1).first->kontainer.nilai, Q2);

        if(countElement(*Q1) == 1){
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }else{
            (*Q1).first = (*Q1).first->next;
            hapus->next = NULL;
        }

        free(hapus);
    }
}

void printQueue(queue Q, int number){
    
    printf("Queue %d\n", number);

    if(Q.first != NULL){

        elemen* bantu = Q.first;

        while(bantu != NULL){
            printf("%s %.1f\n", bantu->kontainer.nama, bantu->kontainer.nilai);
            /* iterasi */
            bantu = bantu->next; 
        }
        printf("******************\n");
    }
    else{
        /* proses jika queue kosong */
        printf("Queue Kosong\n");
    }
}

