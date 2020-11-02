#include "head.h"
/*Saya Muhammad Izzatul Haq mengerjakan UTS dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
    list L;
    createList(&L);
    
    char nama[50], jenis[10];
    int i, n, m, tahun, temp;
    
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        temp = 0;
        scanf("%s %d %s", jenis, &tahun, nama);
        
        assignBnK(jenis, tahun, nama, &L);
    };

    scanf("%d",&m);
    for (i = 0; i < m; i++){
        scanf("%s %d", nama, &tahun);
        change(nama, tahun, &L);
    };

    sort(&L);
    printElement(L);
    
    // addFirstB("1", "Orang_1", &L);
    // addFirstK("IF40K1", "A", L.first);
    // addAfterK(L.first->col, "IF40Z1","A");
    // addLastK("IF40Z2", "A", L.first);
    // addAfterB(L.first, "2", "Orang_2");
    // addFirstK("TI5141", "A", L.first->next);
    // addLastK("IF5021", "A", L.first->next);
    // addLastB("3", "Orang_3", &L);
    // addFirstK("IF5321", "A", L.first->next->next);
    // printElement(L);

    // printf("=================\n");
    
    // delAllB(&L);
    // printElement(L);

    // printf("=================\n");

    return 0;
}