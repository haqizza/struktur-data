#include "header.h"
// Saya Muhammad Izzatul Haq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
int main(){
    tree T, T2, TMandiri[20];
    int i, j;
    int nSimpul, nPindah, nBawaan = 0, nMandiri = 0;
    int levelSpace[20], temp;
    char c, parent[100], value[100], bawaan[100][100];
    
    // Scan jumlah Node
    scanf("%d", &nSimpul);

    //Inisialisasi Tree
    for(i = 0; i < nSimpul; i++){
        j = 0;
        
        //Scan Parent dari Node
        do{
            scanf(" %c", &c);
            parent[j] = c;
            j++;
        }while(c != '#');

        j--;
        parent[j] = '\0';
        j = 0;

        //Scan value Node
        do{
            scanf("%c", &c);
            value[j] = c;
            j++;
        }while(c != '#');

        j--;
        value[j] = '\0';

        //Scan jumlah bawaan
        scanf("%d", &nBawaan);

        // Scan bawaan
        for(j = 0; j < nBawaan; j++){
            scanf("%s", bawaan[j]);
        }
        
        simpul *node;

        // Buat Node
        if(strcmp(parent, "null") == 0){
            // Jika ini tak punya parent, berarti root, maka dibuat Tree
            makeTree(value, nBawaan, bawaan, &T);
            node = T.root;
        }
        else{
            // Jika punya parent
            // Cari simpul
            node = findSimpul(parent, T.root);

            // Tambah Child
            addChild(value, nBawaan, bawaan, node);
        }
    }
    
    // Scan jumlah pindah
    scanf("%d", &nPindah);

    char valueP[100][100], parentP[100][100];

    for(i = 0; i < nPindah; i++){
        // Scan value dan Parent
        scanf("%s %s", valueP[i], parentP[i]);
    }

    //Cek level dan tandai
    checkLevel(0, &T.root);

    //Hitung space untuk setiap level
    levelSpace[0] = 0;
    temp = 0;
    
    for(i = 1; i < 20; i++){
        levelSpace[i] = countLongest(i - 1, T.root) + temp + 1;
        temp = levelSpace[i];
    }

    // Print pohon awal
    printf("pohon awal:\n");
    printTree(levelSpace, T.root);
    
    simpul *nodeParent, *nodeChild;    
    j = 0;
    
    //Perpindahan
    for(i = 0; i < nPindah; i++){
        if(strcmp(parentP[i], "mandiri") == 0){
            // Jika dijadikan mandiri
            // Cari simpul yang akan dilepas
            nodeChild = findSimpul(valueP[i], T.root);
            
            // Tree pindah mandiri masing masing dijadikan pohon
            pindahMandiri(nodeChild, &T, &TMandiri[j]);
            
            nMandiri++; // Ganti Tree bila terisi
            j++; // Tambah Tree
        }
        else{
            //Jika dipindahkan
            // Cari masing-masing Node
            nodeChild = findSimpul(valueP[i], T.root);
            nodeParent = findSimpul(parentP[i], T.root);

            // Pindahkan nodeChild menjadi child dari nodeParent
            pindah(nodeChild, nodeParent, &T);
        }
    }
    
    //Cek level dan tandai
    checkLevel(0, &T.root);
    
    //Hitung space untuk setiap level
    levelSpace[0] = 0;
    temp = 0;
    
    for(i = 1; i < 20; i++){
        levelSpace[i] = countLongest(i - 1, T.root) + temp + 1;
        temp = levelSpace[i];
    }
    
    // Print 
    printf("\npohon pindah naungan:\n");
    printTree(levelSpace, T.root);
    
    //  Print
    if(nMandiri > 0){
        printf("\npohon mandiri:\n");
    }
    for(i = 0; i < nMandiri; i++){
        // Cek level dan tandai
        checkLevel(0, &TMandiri[i].root);

        //Hitung space untuk setiap level
        levelSpace[0] = 0;
        temp = 0;
        
        for(j = 1; j < 20; j++){
            levelSpace[j] = countLongest(j - 1, TMandiri[i].root) + temp + 1;
            temp = levelSpace[j];
        }

        // Print
        printTree(levelSpace, TMandiri[i].root);
    }

    return 0;
}