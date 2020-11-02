#include "head.h"

int main(){
    list L;
    createList(&L);
    printElement(L);
    printf("=================\n");

    addFirstB("1", "Orang_1", &L);
    addFirstK("IF40K1", "A", L.first);
    addAfterK(L.first->col, "IF40Z1","A");
    addLastK("IF40Z2", "A", L.first);
    addAfterB(L.first, "2", "Orang_2");
    addFirstK("TI5141", "A", L.first->next);
    addLastK("IF5021", "A", L.first->next);
    addLastB("3", "Orang_3", &L);
    addFirstK("IF5321", "A", L.first->next->next);
    printElement(L);

    printf("=================\n");
    
    delAllB(&L);
    printElement(L);

    printf("=================\n");

    return 0;
}