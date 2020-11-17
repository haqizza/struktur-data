#include "header.h"
/*Saya Muhammad Izzatul Haq mengerjakan Kuis 2 dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main(){	
    queue Q;
    createEmpty(&Q);
    char nama[100];
    char ktp[100];
    int anggota, i, n, m, mAr[50];

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s %s %d", nama, ktp, &anggota);
        addPriority(nama, ktp, anggota, &Q);
    }
    scanf("%d",&m);
    for(i = 0; i < m; i++){
        scanf("%d", &mAr[i]);
    }

    printQueue(Q, m, mAr);

return 0;
}