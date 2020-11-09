#include "header.h"

void createEmpty(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;}

int isEmpty(queue Q){
    int hasil = 0; 

    if(Q.first == -1){
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q){
    int hasil = 0;

    if(Q.last == 5){
        hasil = 1;
    }
    return hasil;
}

void add(char nama[], float nilai, queue *Q){

if(isEmpty(*Q) == 1){
    /* jika queue kosong */
    (*Q).first = 0;
    (*Q).last = 0;
    strcpy((*Q).data[0].nama, nama);
    (*Q).data[0].nilai = nilai;
}
else{
    /* jika queue tidak kosong */
    if(isFull(*Q) != 1){
        (*Q).last = (*Q).last + 1;
        strcpy((*Q).data[(*Q).last].nama, nama);
        (*Q).data[(*Q).last].nilai = nilai;
    }
    else{
        printf("queue penuh\n");
    }
    }
}
void addPriority(char nama[], float nilai, int prior, queue *Q){
    int i;
    if(prior < 6){
        for(i = Q->last; i >= prior-1; i--){
            strcpy((*Q).data[i + 1].nama, (*Q).data[i].nama);
            (*Q).data[i + 1].nilai = (*Q).data[i].nilai;
        }
        (*Q).last = (*Q).last + 1;
        strcpy((*Q).data[prior-1].nama, nama);
        (*Q).data[prior-1].nilai = nilai;
    }
    else{
        add(nama, nilai, Q);
    }
}
void del(queue *Q1, queue *Q2){

    if((*Q1).last == 0){
        (*Q1).first = -1;
        (*Q1).last = -1;
    }else{
        int i;
        //move
        add((*Q1).data[(Q1)->first].nama, (*Q1).data[(Q1)->first].nilai, Q2);

        //shift
        for(i = (*Q1).first + 1; i <= (*Q1).last; i++){
            strcpy((*Q1).data[i-1].nama, (*Q1).data[i].nama);
            (*Q1).data[i-1].nilai = (*Q1).data[i].nilai;
        }
        (*Q1).last = (*Q1).last - 1;
    }
}

void printQueue(queue Q, int number){

    
    printf("Queue %d\n", number);

    if(Q.first != -1){
        int i;

        for(i = Q.first; i <= Q.last; i++){
            printf("%s %.1f\n", Q.data[i].nama, Q.data[i].nilai);
        }
        printf("******************\n");
    }
    else{
        /* proses jika queue kosong */
        printf("Queue Kosong\n");
    }
}