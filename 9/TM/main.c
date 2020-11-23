#include "header.h"

int main(){
    tree T;
    int i;
    char harf[14];
    
    for(i = 0; i < 14; i++){
        scanf(" %c", &harf[i]);
    }

    makeTree(harf[0], &T);
    
    addLeft(harf[1],T.root);
    addRight(harf[2],T.root);
    addLeft(harf[3],T.root->right);
    addRight(harf[4],T.root->left);
    addRight(harf[5],T.root->right);
    addLeft(harf[6],T.root->left->right);
    addRight(harf[7],T.root->right->left);
    addRight(harf[8],T.root->left->right);
    addRight(harf[9],T.root->right->right);
    addLeft(harf[10],T.root->right->right);
    addLeft(harf[11],T.root->left->right->left);
    addLeft(harf[12],T.root->right->left->right);
    addRight(harf[13],T.root->right->left->right);
    
    printf("Pre Order:\n");
    printTreePreOrder(T.root);
    
    delLeft(T.root->left->right->left);

    printf("\nIn Order:\n");
    printTreeInOrder(T.root);

    delRight(T.root->right->right);

    printf("\nPost Order:\n");
    printTreePostOrder(T.root);
    printf("\n");
    
    return 0;
}