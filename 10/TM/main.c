#include "header.h"

int main(){
    tree T;
    char input[20], check[3];
    int i;

    for(i = 0; i < 10; i++){
        scanf(" %c", &input[i]);
    }

    printf("Langkah 1\n");
    printf("================\n");

    makeTree(input[0], &T);
	addChild(input[1], T.root);
	addChild(input[2], T.root);
	addChild(input[3], T.root);
	addChild(input[4], T.root->child->sibling);
	addChild(input[5], T.root->child);
	addChild(input[6], T.root->child->child);
	addChild(input[7], T.root);
	printTreePreOrder(T.root, 1);
    printf("\n");
	delChild(input[7],  T.root);
	printTreePreOrder(T.root, 1);
    printf("\n");
	addChild(input[8], T.root->child->sibling->child);
	addChild(input[9], T.root->child->child);
	printTreePreOrder(T.root, 1);

    printf("\nLangkah 2\n");
    printf("================\n");

    tree T2;

    copyTree(T.root, &T2.root);

    if(isEqual(T.root, T2.root) == 1){
        printf("Sama\n");
    }
    else{
        printf("tidak Sama\n");
    }

    printf("Langkah 3\n");
    printf("================\n");

    simpul *node[3];
    node[0] = findSimpul('J', T.root->child->child);
    node[1] = findSimpul('J', T.root->child->sibling->child);
    node[2] = findSimpul('J', T.root);

    for(i = 0; i < 3; i++){
        if(node[i] != NULL){
            printf("J ditemukan\n");
        }else{
            printf("J tidak ditemukan\n");
        }
    }
    
    return 0; 
}