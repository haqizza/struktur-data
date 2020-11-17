#include "header.h"

int main(){	
    queue Q;
    createEmpty(&Q);
    char nama[50], tiket[10], search[50];
    int prior, waktu, i = 0;

    while(i = 0){
        scanf("%s %s %d", nama, tiket, &waktu);
    }
    scanf("%s", search);

    printf("******************\n");
    
    add(nama[0], nilai[0], &Q1);
    
    add(nama[1], nilai[1], &Q1);

    addPriority(nama[2], nilai[2], 2, &Q1);
    printQueue(Q1, 1);

    del(&Q1, &Q2);
    printQueue(Q1, 1);
    printQueue(Q2, 2);

    addPriority(nama[3], nilai[3], 1, &Q1);
    addPriority(nama[4], nilai[4], 99, &Q1);

    printQueue(Q1, 1);
    del(&Q1, &Q2);
    del(&Q1, &Q2);

    add(nama[5], nilai[5], &Q1);

    printQueue(Q1,1);
    printQueue(Q2,2);

return 0;
}