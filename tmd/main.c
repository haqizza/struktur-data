#include "header.h"
// Saya Muhammad Izzatul Haq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
int main(){
    tree T, T2, TMandiri[20];
    int i, j;
    int nSimpul, nPindah, nBawaan = 0, nMandiri = 0;
    char c, parent[50], value[50], bawaan[50][50];

    scanf("%d", &nSimpul);

    for(i = 0; i < nSimpul; i++){
        j = 0;
        
        do{
            scanf(" %c", &c);
            parent[j] = c;
            // printf("%c", c);
            j++;
        }while(c != '#');

        j--;
        parent[j] = '\0';
        // printf("%s\n", parent);
        j = 0;

        do{
            scanf("%c", &c);
            value[j] = c;
            // printf("%c",c);
            j++;
        }while(c != '#');

        j--;
        value[j] = '\0';
        // printf("%s\n", value);
        scanf("%d", &nBawaan);
        // printf("n: %d", nBawaan);

        for(j = 0; j < nBawaan; j++){
            scanf("%s", bawaan[j]);
        }
        // printf("--%s %s\n", parent, value);
        
        simpul *node;

        // printf("%d\n",strcmp(parent, "null"));
        if(strcmp(parent, "null") == 0){
            // jika ini tak punya parent, berarti root, maka dibuat Tree
            makeTree(value, nBawaan, bawaan, &T);
            // printf("in oke\n");
            node = T.root;
            // printf("out oke\n");
        }
        else{
            // Jika punya parent
            // Cari simpul
            node = findSimpul(parent, T.root);
            // printf("find node %s\n", node->kontainer);
            // Tambah Child
            addChild(value, nBawaan, bawaan, node);
        }
    }
    // printTreePreOrder(T.root);
    // scanf("%d", &nPindah);
    // simpul *nodeParent, *nodeChild;

    // for(i = 0; i < nPindah; i++){
    //     scanf("%s %s", value, parent);

    //     if(strcmp(parent, "mandiri") == 0){
    //         nodeChild = findSimpul(value, T.root);
    //         // Tree pindah mandiri masing masing dijadikan pohon
    //         printf("node %s\n", nodeChild->kontainer);

    //         pindahMandiri(nodeChild, &TMandiri[j]);
            
    //         nMandiri++; // Ganti pohon bila terisi
    //         j++; // Tambah Tree
    //     }
    //     else{
    //         nodeChild = findSimpul(value, T.root);
    //         nodeParent = findSimpul(parent, T.root);
    //         printf("child %s\n", nodeChild->kontainer);
    //         printf("parent %s\n", nodeParent->kontainer);

    //         // Pindahkan nodeChild menjadi child nodeParent
    //         pindah(nodeChild, nodeParent);
    //         printf("pindah\n");
    //     }
    // }

    copyTree(T.root, &T2.root);
    printTreePreOrder(T.root);
    printf("%d\n", isEqual(T.root, &T2.root));
    printTreePreOrder(T2.root);
    // printTreePreOrder(TMandiri[0].root);

    return 0; 
}