#include "header.h"

int main(){
    stack S;
    createEmpty(&S);
    
    printStack(S);

    printf("=================\n");
    push("13507701", "Nana", 64.75, &S);
    push("13507702", "Rudi", 75.11, &S);
    push("13507703", "Dea", 84.63, &S);
    printStack(S);
    printf("=================\n");
    pop(&S);
    pop(&S);
    printStack(S);
    printf("=================\n");

    return 0;
}