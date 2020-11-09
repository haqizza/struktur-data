#include "header.h"

int main(){
    queue Q;
    createEmpty(&Q);
    printQueue(Q); 
    printf("=================\n");

    add("13507701", "Nana", 64.75, &Q);
    add("13507702", "Rudi", 75.11, &Q);
    add("13507703", "Dea", 84.63, &Q);
    printQueue(Q);
    printf("=================\n");
    del(&Q);
    del(&Q);
    printQueue(Q);
    printf("=================\n");


return 0;
}