#include "header.h"

int main(){
    stack S1, S2;
    createEmpty(&S1);
    createEmpty(&S2);
    
    char kata[50];

    printStack(S1,1);
    printStack(S2,2);

    scanf("%s",kata);
    push(kata, &S1);
    scanf("%s",kata);
    push(kata, &S2);

    printStack(S1,1);
    printStack(S2,2);

    pop(&S1);
    popTo(&S1,&S2);
    scanf("%s",kata);
    push(kata, &S1);
    scanf("%s",kata);
    push(kata, &S1);
    scanf("%s",kata);
    push(kata, &S2);
    popTo(&S2,&S1);

    printStack(S1,1);
    printStack(S2,2);

    return 0;
}