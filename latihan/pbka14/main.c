#include "header.h"

int main(){
    tree T;
    int i, n, value, root, side, count = 0;
    char str[10];

    scanf("%d", &n);

    simpul *node;
    for(i = 0; i < n; i++){
        scanf("%d %d %s", &value, &root, str);

        if(root == 0){
            makeTree(value, &T);
        }
        else{
            if(strcmp(str,"kanan") == 0){
                side = 0;
            }
            else{
                side = 1;
            }

            node = findSimpul(root, T.root);
            
            if(side == 0){
                addRight(value, node);
            }
            else{
                addLeft(value, node);
            }
        }
    }
    count = sumRightTree(1, T.root);
    printf("%d\n", count);

    count = sumRightTree(0, T.root);
    printf("%d\n", count);

    return 0;
}