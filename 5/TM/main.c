#include "head.h"

int main(){
    list L;
    createList(&L);
    
    char huruf, kata[50];
    int i, j, n;

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf(" %c", &huruf);
        addLastB(huruf, &L);

        //Karena huruf diinput Add Last, harus dicari ujungnya karena tidak menggunakan tail
        eBaris *last = L.first;

        while(last->next != NULL){
            last = last->next;
        }

        scanf("%s", kata);
        addLastK(kata, last);
        scanf("%s", kata);
        addFirstK(kata, last);
        scanf("%s", kata);
        addAfterK(last->col, kata);
        scanf("%s", kata);
        addFirstK(kata, last);
    };
    
    printElement(L);

    return 0;
}