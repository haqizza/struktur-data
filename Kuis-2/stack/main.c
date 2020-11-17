#include "header.h"
/*Saya Muhammad Izzatul Haq mengerjakan Kuis 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main(){
    stack S, S1;
    createEmpty(&S);
    createEmpty(&S1);
    int n,i,nomor;
    char simbol;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %c", &nomor, &simbol);
        // push(nomor,simbol, &S);
        
        switch (simbol){
            case '(':
                //Masukkan stack
                push(nomor, simbol, &S);
                break;
            case '{':
                //Masukkan stack
                push(nomor, simbol, &S);
                break;
            case ')':
                if(S.data[S.top].simbol == '('){
                    // tarik dari stack jika berpasangan dengan top
                    pop(&S);
                }
                else{
                    //Jika tidak sepasang, masukkan ke stack dump
                    push(nomor,simbol, &S1);
                }
                break;
            case '}':
                if(S.data[S.top].simbol == '{'){
                    // tarik dari stack jika berpasangan dengan top
                    pop(&S);
                }
                else{
                    //Jika tidak sepasang, masukkan ke stack dump
                    push(nomor,simbol, &S1);
                }
                break;
            default:
                break;
        }
    }
    printStack(S);
    printStackReverse(S1);
    
    return 0;
}