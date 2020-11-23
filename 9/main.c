#include "header.h"

int main(){
    tree T;
    makeTree('A', &T);

    addLeft('B', T.root);
    addRight('C', T.root);
    addLeft('D', T.root->left);
    addRight('E', T.root->left);
    addRight('F', T.root->right);
    
    printf("=================\n");
    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    printf("inOrder\n");
    printTreeInOrder(T.root);
    printf("\n=================\n");
    printf("postOrder\n");
    printTreePostOrder(T.root);
    printf("\n=================\n");

    tree T2;
    copyTree(T.root, &T2.root);

    if(isEqual(T.root, T2.root) == 1){
        printf("pohon sama\n");
    }
    else{
        printf("pohon tidak sama\n");
    }

    delRight(T.root->left);
    delLeft(T.root->left);
    printf("=================\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");

    return 0;
}