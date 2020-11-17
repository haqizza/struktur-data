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

void add(char nama[], int waktu, queue *Q ){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
 
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.waktu = waktu;
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

void addPrior(char nama[], int prior, int waktu, queue *Q){
    elemen* baru;
    elemen* bantu = (*Q).first;
    elemen* prevBantu = (*Q).first;
    baru = (elemen *) malloc (sizeof (elemen));
    int i = 0,counter = 0;

    if((prior < 4) && ((*Q).first != NULL)){
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.prior = prior;
        baru->kontainer.waktu = waktu;

        while(bantu != NULL){
            i++;
            if(baru->kontainer.prior == bantu->kontainer.prior){
                counter = i;
                break;
            }
            bantu = bantu->next;
        }

        i = 1;
        bantu = (*Q).first;
        // printf("%d\n",counter);
        if (counter == 0){
            while(i < prior - 1){
                bantu = bantu->next;
                i++;
            }
            // printf("%d\n",i);
            // printf("%s %d\n",bantu->kontainer.nama, bantu->next);
            // printf("%s %d\n",Q->first->kontainer.nama,Q->first->next);
        }else{
            for(i; i < counter; i++){
                if(i>1){
                    prevBantu = prevBantu->next;
                }
                bantu = bantu->next;
            }
        }

        if((bantu == (*Q).first) && (bantu->kontainer.prior != baru->kontainer.prior) && (baru->kontainer.prior == 1)){
            baru->next = (*Q).first;
            (*Q).first = baru;
        }else{
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
    else{
        add(nama, waktu, Q);
    }
}
void del(queue *Q){
    if((*Q).first != NULL){
        /* jika queue bukan queue kosong */
        elemen *hapus = (*Q).first; 

        if(countElement(*Q) == 1){
        (*Q).first = NULL;
        (*Q).last = NULL;
        }else{
        (*Q).first = (*Q).first->next;
        hapus->next = NULL;
        }

        free(hapus);
    }
}

void printQueue(queue Q){

    if(Q.first != NULL){

        elemen* bantu = Q.first;

        while(bantu != NULL){
            printf("nama : %s %d\n", bantu->kontainer.nama, bantu->kontainer.waktu);
            printf("next : %s\n", bantu->next->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
        }
        printf("\n");
    }
    else{
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}

void print(char search[], queue Q){
    elemen* bantu = Q.first;
    char names[50][50];
    int counter = 0, sum = 0, i, x;
    while(bantu != NULL){
        x = strcmp(bantu->kontainer.nama,search);
        sum += bantu->kontainer.waktu;
        strcpy(names[counter], bantu->kontainer.nama);
        if(x == 0){
            break;
        }
        bantu = bantu->next;
        counter++;
    }
    printf("%s mengantri selama %d\n", bantu->kontainer.nama, sum);
    printf("Daftar orang sebelumnya:\n");
    for(i = 0; i<counter; i++){
        printf("%s\n",names[i]);
    }
}