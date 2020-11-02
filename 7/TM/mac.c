#include "header.h"

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

    if(S.top == 9){
        hasil = 1;
    }
    return hasil;
}

void push(char kata[], stack *S){

    if(isFull(*S) == 1){
        /*jika stack penuh*/
        printf("stack penuh\n");
    }
    else{
        if(isEmpty(*S) == 1){
            /* jika stack kosong */
            (*S).top = 0;
            strcpy((*S).data[0].kata, kata);
        }
        else{
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].kata,kata);
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

//Untuk pop dari SFrom ke STo
void popTo(stack *STo, stack *SFrom){
    if((*SFrom).top == 0){
        /*jika stack berisi satu elemen*/
        int n = (*SFrom).top;//agar mudah dibaca, assign ke n

        push((*SFrom).data[n].kata, STo);//Push dulu data top SFrom ke STo
        (*SFrom).top = -1;//Hapus top Sfrom
    }
    else{
        if((*SFrom).top != -1){
            /*jika stack tidak kosong*/
            int n = (*SFrom).top;

            push((*SFrom).data[n].kata, STo);//Push dulu data top SFrom ke STo
            (*SFrom).top = (*SFrom).top - 1;//Hapus top Sfrom
        }
    }
}

void printStack(stack S, int par){
    //If Untuk print prefix
    if (par == 1){
        printf("S1 - ");
    }else{
        printf("S2 - ");
    }
    //If cek keadaan stack
    if(S.top != -1){        
        int i;

        for(i=S.top;i>=0;i--){
            printf("%s", S.data[i].kata);

            if(i > 0){
                printf(" ");    
            }
        }
        
        printf("\n");
    }
    else{
        /* proses jika stack kosong */
        printf("Stack Kosong\n");
    }
}