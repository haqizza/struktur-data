#include "header.h"

int main(){
    tree T;
    tree T2;
    int i, j, n, result, side;
    char parent[51], child[51], str[10];

    for(i = 0; i < 2; i++){
        //scan jumlah
        scanf("%d", &n);

        simpul *node;
        for(j = 0; j < n; j++){
            // scan baris input
            scanf("%s %s %s", parent, child, str);

            if(strcmp(parent, "null") == 0){
                // jika ini tak punya parent, berarti root, maka dibuat Tree
                if(i == 0){
                    // jika ini putaran pertama, buat Tree T
                    makeTree(child, &T);
                }
                else{
                    // jika ini putaran kedua, buat Tree T2
                    makeTree(child, &T2);
                }
            }
            else{
                //cek ditambahkan di sisi mana
                if(strcmp(str, "kanan") == 0){
                    //Jika sisi kanan
                    side = 0;
                }
                else{
                    //Jika sisi kiri
                    side = 1;
                }

                if(i == 0){
                    // jika ini putaran pertama, cari di Tree T
                    node = findSimpul(parent, T.root);
                }
                else{
                    // jika ini putaran kedua, cari di Tree T2
                    node = findSimpul(parent, T2.root);
                }
                
                // tambahkan sesuai sisi
                if(side == 0){
                    // jika kanan
                    addRight(child, node);
                }
                else{
                    // jika kiri
                    addLeft(child, node);
                }
            }
        }
    }
    
    // printTreePostOrder(T.root);
    // printf("\n");
    // printTreePostOrder(T2.root);
    // printf("\n");
    //cek apakah cerminan
    result = isMirror(T.root, T2.root);

    if (result == 1){
        // jika cerminan
        printf("pohon pertama cerminan pohon kedua\n");
    }else{
        // jika bukan cerminan
        printf("pohon pertama bukan cerminan pohon kedua\n");
    }
    

    return 0;
}