#include "header.h"

void createEmpty(stack *S){
    (*S).top = NULL;
}

int isEmpty(stack S){
    int hasil = 0;
    if(S.top == NULL){
        hasil = 1;
        }
    return hasil;
}

int countElement(stack S){

    int hasil = 0;

    if(S.top != NULL){
        /* stack tidak kosong */
        elemen* bantu;

        /* inisialisasi */
        bantu = S.top;

        while(bantu != NULL){
            /* proses */
            hasil= hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(char nim[], char nama[], float nilai, stack *S ){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nilai = nilai;

    if((*S).top == NULL){
        //jika stack kosong
        baru->next = NULL;
    }
    else{
        //jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S){
    if((*S).top != NULL){
    /*jika stack bukan list kosong*/
    elemen *hapus = (*S).top;

    if(countElement(*S) == 1){
        (*S).top = NULL;
        }
    else{
        (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else{
        printf("stack kosong");
    }
}

void printStack(stack S){
    if(S.top != NULL){
        printf("------isi stack------\n");

        elemen* bantu = S.top;

        int i = 1;

        while(bantu != NULL){
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n",bantu->kontainer.nim);
            printf("nama : %s\n",bantu->kontainer.nama);
            printf("nilai : %f\n",bantu->kontainer.nilai);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
        printf("---------------------\n");
    }
    else{
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}

