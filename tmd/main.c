#include "header.h"
// Saya Muhammad Izzatul Haq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
int main(){
    tree T, T2, TMandiri[20];
    int i, j;
    int nSimpul, nPindah, nBawaan = 0, nMandiri = 0;
    int levelLength[50];
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
    
    printf("pohon awal:\n\n");
    printTree(0, T.root);
    printf("\n");

    scanf("%d", &nPindah);
    simpul *nodeParent, *nodeChild;
    j = 0;
    
    for(i = 0; i < nPindah; i++){
        scanf("%s %s", value, parent);

        if(strcmp(parent, "mandiri") == 0){
            nodeChild = findSimpul(value, T.root);
            // Tree pindah mandiri masing masing dijadikan pohon
            pindahMandiri(nodeChild, &T, &TMandiri[j]);
            
            nMandiri++; // Ganti pohon bila terisi
            j++; // Tambah Tree
        }
        else{
            nodeChild = findSimpul(value, T.root);
            nodeParent = findSimpul(parent, T.root);

            // Pindahkan nodeChild menjadi child nodeParent
            pindah(nodeChild, nodeParent, &T);
        }
    }

    printf("pohon pindah naungan:\n\n");
    printTree(0, T.root);

    printf("pohon mandiri:\n\n");
    for(i = 0; i < nMandiri; i++){
        printTree(0, TMandiri[0].root);
    }

    return 0; 
}