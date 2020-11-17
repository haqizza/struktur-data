#include "header.h"
/*Saya Muhammad Izzatul Haq mengerjakan Kuis 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
void createEmpty(stack *S){
    (*S).top = -1;
}

int isEmpty(stack S){
    int hasil = 0;

    if(S.top == -1){
        hasil = 1;
    }
    return hasil;
}

int isFull(stack S){
    int hasil = 0;

    if(S.top == 50){
        hasil = 1;
    }
    return hasil;
}

void push(int nomor, char simbol, stack *S){

    if(isFull(*S) == 1){
        /*jika stack penuh*/
        printf("stack penuh\n");
    }
    else{
        if(isEmpty(*S) == 1){
            /* jika stack kosong */
            (*S).top = 0;
            (*S).data[0].nomor = nomor;
            (*S).data[0].simbol = simbol;
        }
        else{
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            (*S).data[(*S).top].nomor = nomor;
            (*S).data[(*S).top].simbol = simbol;
        }
    }
}

void pop(stack *S){
    if((*S).top == 0){
        /*jika stack berisi satu elemen*/
        (*S).top = -1;
    }
    else{
        if((*S).top != -1){
            /*jika stack tidak kosong*/
            (*S).top = (*S).top - 1;
        }
    }
}
void check(int n, stack *S){
    int i,j;
    printf("top %d\n", (*S).top);
    for(i = 0; i <= (*S).top; i++){
        switch ((*S).data[i].simbol){
            case '(':
                break;
            case ')':
                break;
            case '{':
                break;
            case '}':
                break;
            default:
                for(j = i; j < (*S).top; j++){
                    (*S).data[j].nomor = (*S).data[j+1].nomor;
                    (*S).data[j].simbol = (*S).data[j+1].simbol;
                }
                (*S).top = (*S).top - 1;
                printf("top %d\n", (*S).top);
                break;
        }
    }
    i=0;
    j=0;
    for(i = 0; i < (*S).top; i++){
        if(((*S).data[i].simbol == '(') && ((*S).data[i+1].simbol == ')')){ 
            printf("1 i: %d j: %d\n", i, j);
            for(j = i; j <= (*S).top -2; j++){
                (*S).data[j].nomor = (*S).data[j+2].nomor;
                (*S).data[j].simbol = (*S).data[j+2].simbol;
                printf("1 i: %d j: %d\n", i, j);
            }
            printf("1 i: %d j: %d\n", i, j);
        }
        else if(((*S).data[i].simbol == '{') && ((*S).data[i+1].simbol == '}')){
            printf("2 i: %d j: %d\n", i, j);
            for(j = i; j <= (*S).top -2; j++){
                (*S).data[j].nomor = (*S).data[j+2].nomor;
                (*S).data[j].simbol = (*S).data[j+2].simbol;
                printf("2 i: %d j: %d\n", i, j);
            }
            printf("2 i: %d j: %d\n", i, j);
        }
        printf("3 i: %d j: %d\n", i, (*S).data[j].simbol);
        (*S).top = (*S).top - 2;
        printStack(*S);
    }
}
void printStack(stack S){
    int i;
    if(S.top != -1){
        
        for(i = 0; i <= S.top; i++){
            printf("%d %c\n", S.data[i].nomor, S.data[i].simbol);
        }
    }
    else{
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}
void printStackReverse(stack S){
    int i;
    if(S.top != -1){
        for(i = S.top; i >= 0; i--){
            printf("%d %c\n", S.data[i].nomor, S.data[i].simbol);
        }
    }
    else{
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}