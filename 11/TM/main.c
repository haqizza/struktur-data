#include "header.h"

int main(){
    graph G;
    char node;

    createEmpty(&G);
    addSimpul('A', &G);
    addSimpul('B', &G);
    addSimpul('C', &G);
    addSimpul('D', &G);
    addSimpul('E', &G);
    addSimpul('F', &G);

    scanf("%c", &node);

    simpul *begin = findSimpul('A', G);
    simpul *end = findSimpul('B', G);

    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 0);
    }

    begin = findSimpul('B', G);
    end = findSimpul('C', G);
    
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 0);
    }

    end = findSimpul('E', G);
    
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 0);
    }

    begin = findSimpul('C', G);
    end = findSimpul('D', G);
    
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 0);
    }

    begin = findSimpul('D', G);
    end = findSimpul('F', G);
    
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 0);
    }


    printGraph(G);

    printf("-----\n");

    delSimpul(node, &G);
    
    printGraph(G);

    return 0;
}