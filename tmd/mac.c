#include "header.h"
// Saya Muhammad Izzatul Haq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

void makeTree(char c[], int nBawaan, char bawaan[][50], tree *T){
    simpul *node;
    node = (simpul *) malloc (sizeof (simpul));
    strcpy(node->kontainer, c);
    
    // Masukkan bawaan
    node->bawaanNumber = nBawaan; // Assign jumlah bawaan
    addBawaan(bawaan, node);

    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(char c[], int nBawaan, char bawaan[][50], simpul *root){
    if(root != NULL){
        /* jika simpul root tidak kosong, berarti dapat ditambahkan simpul anak */
        simpul *baru;
        baru = (simpul *) malloc (sizeof (simpul));
        strcpy(baru->kontainer, c);
        
        //Masukkan bawaan
        baru->bawaanNumber = nBawaan;
        addBawaan(bawaan, baru);
        
        baru->child = NULL;
        if(root->child == NULL){
            /* jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama */
            baru->sibling = NULL;
            root->child = baru;
        }
        else{
            if(root->child->sibling == NULL){
                /* jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else{
                simpul *last = root->child;
                /* mencari simpul anak terakhir karena akan dikaitkan dengan simpul  baru sebagai simpul anak terakhir yang baru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul anak terakhir, penunjuk last akan berjalan ke simpul anak berikutnya */ 
                while(last->sibling != root->child){
                    last = last->sibling;
                } 
                baru->sibling = root->child;
                last->sibling = baru;
            }
        } 
    } 
}

void addBawaan(char bawaan[][50], simpul *node){
    int i;

    for(i = 0; i < node->bawaanNumber; i++){
        strcpy(node->bawaan[i], bawaan[i]);
    }
}

simpul* findSimpul(char c[], simpul *root){
    simpul *hasil = NULL;
    int ketemu = 0;

    if(root != NULL){ 
        if(strcmp(root->kontainer, c) == 0){
            hasil = root;
        }
        else{
            simpul *bantu = root->child;
            if(bantu != NULL){
                if(bantu->sibling == NULL){
                    /*jika memiliki satu simpul anak*/
                    if(strcmp(bantu->kontainer, c) == 0){
                        if(hasil == NULL){
                            hasil = bantu;
                        }
                    }
                    else{
                        if(hasil == NULL){
                            hasil = findSimpul(c, bantu);
                        }
                    }
                }
                else{
                    /*jika memiliki banyak simpul anak*/ 
                    
                    while((bantu->sibling != root->child) && (ketemu == 0)){
                        if(strcmp(bantu->kontainer, c) == 0){
                            if(hasil == NULL){
                                hasil = bantu;
                            }
                            ketemu = 1;
                        }
                        else{
                            if(hasil == NULL){
                                hasil = findSimpul(c, bantu);
                            }
                            bantu = bantu->sibling;
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                    if(ketemu == 0){
                        if(strcmp(bantu->kontainer, c) == 0){
                            if(hasil == NULL){
                                hasil = bantu;
                            }
                        }
                        else{
                            if(hasil == NULL){
                                hasil = findSimpul(c, bantu);
                            }
                        }
                    }
                }
            }
        }
    }
    return hasil; 
}

simpul* findParent(char c[], simpul *root){
    simpul *hasil = NULL;
    int ketemu = 0;

    if(root->child != NULL){
        simpul *bantu = root->child;
        // bantu = root2->child;
        if(bantu->sibling == NULL){
            /*jika memiliki satu simpul anak*/
            if(strcmp(bantu->kontainer, c) == 0){
                if(hasil == NULL){
                    hasil = root;
                }
            }
            else{
                if(hasil == NULL){
                    hasil = findParent(c, bantu);
                }
            }
        }
        else{
            /*jika memiliki banyak simpul anak*/ 
            while((bantu->sibling != root->child) && (ketemu == 0)){
                if(strcmp(bantu->kontainer, c) == 0){
                    if(hasil == NULL){
                        hasil = root;
                    }
                    ketemu = 1;
                }
                else{
                    if(hasil == NULL){
                        hasil = findParent(c, bantu);
                        if(hasil != NULL){
                            ketemu = 1;
                        }
                    }
                    bantu = bantu->sibling;
                }
            }
            /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
            if(ketemu == 0){
                if(strcmp(bantu->kontainer, c) == 0){
                    if(hasil == NULL){
                        hasil = root;
                    }
                }
                else{
                    if(hasil == NULL){
                        hasil = findParent(c, bantu);
                    }
                }
            }
        }
    }
    return hasil; 
}

void pindahMandiri(simpul *nodeChild, tree *T, tree *TMandiri){
    simpul *node;
    //Jadikan Node sebagai Tree Mandiri
    TMandiri->root = nodeChild;

    // Putus child dari parent sebelumnya
    node = findParent(nodeChild->kontainer, T->root);
    disconnectChild(nodeChild->kontainer, node);
}

void pindah(simpul *nodeChild, simpul *nodeParent, tree *T){
    simpul *node;
    // Hapus nodeChild yang dari Parent sebelumnya
    node = findParent(nodeChild->kontainer, T->root);
    disconnectChild(nodeChild->kontainer, node);
    
    // Jadikan nodeChild sebagai Child baru dari nodeParent
    connectChild(nodeChild, nodeParent);
}

void disconnectChild(char c[], simpul *root){
    simpul *hapus = root->child;
    if(hapus->sibling == NULL){
        /*jika hanya mempunyai satu anak*/
        if(strcmp(root->child->kontainer, c) == 0){
            root->child = NULL;
        }
    }
    else{
        /*jika memiliki lebih dari satu simpul anak*/
        simpul *prev = NULL;
        /*mencari simpul yang akan dihapus*/
        int ketemu = 0;
        while((hapus->sibling != root->child) && (ketemu == 0)){
            if(strcmp(hapus->kontainer, c) == 0){
                ketemu = 1;
            }
            else{
                prev = hapus;
                hapus = hapus->sibling;
            }
        }
        /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
        if((ketemu == 0) && (strcmp(hapus->kontainer, c) == 0)){
            ketemu = 1;
        }
        if(ketemu == 1){
            simpul *last = root->child;
            /* mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir */
            while(last->sibling != root->child){
                last = last->sibling;
            }
            if(prev == NULL){
                /*jika simpul yang dihapus anak pertama*/
                if((hapus->sibling == last) && (last->sibling == root->child)){
                    /*jika hanya ada dua anak*/
                    root->child = last;
                    last->sibling = NULL;
                }
                else{
                    /* jika memiliki simpul anak lebih dari dua simpul */
                    root->child = hapus->sibling;
                    last->sibling = root->child; 
                }
            }
            else{
                if((prev == root->child) && (last->sibling == root->child)){
                    /* jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua */
                    root->child->sibling = NULL;
                }
                else{
                    /* jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul */
                    prev->sibling = hapus->sibling;
                    hapus->sibling = NULL;
                }
            }
        }
    }
}

void connectChild(simpul *nodeChild, simpul *nodeParent){
    if(nodeParent->child == NULL){
        /* jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama */
        nodeChild->sibling = NULL;
        nodeParent->child = nodeChild;
        
    }
    else{
        if(nodeParent->child->sibling == NULL){
            /* jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua */
            nodeChild->sibling = nodeParent->child;
            nodeParent->child->sibling = nodeChild;
        }
        else{
            simpul *last = nodeParent->child;
            /* mencari simpul anak terakhir karena akan dikaitkan dengan simpul  baru sebagai simpul anak terakhir yang baru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul anak terakhir, penunjuk last akan berjalan ke simpul anak berikutnya */ 
            while(last->sibling != nodeParent->child){
                last = last->sibling;
            }
            nodeChild->sibling = nodeParent->child;
            last->sibling = nodeChild;
        }
    } 
}

void printSpaces(int length){
    int i;

    for(i = 0; i < length; i++){
        printf(" ");
    }
}

void printTree(int length, simpul *root){
    int i, len, tempLength;
    
    if(root != NULL){
        printSpaces(length);
        printf("|%s\n", root->kontainer);
        tempLength = strlen(root->kontainer);
        
        for(i = 0; i < root->bawaanNumber; i++){
            printSpaces(length);
            printf(" %s\n", root->bawaan[i]);

            len = strlen(root->bawaan[i]);
            if(len > tempLength){
                tempLength = len;
            }
        }
        printf("\n");
        length += (tempLength + 1);
        
        simpul *bantu = root->child;

        if(bantu != NULL){
            if(bantu->sibling == NULL){
                /*jika memiliki satu simpul anak*/
                printTree(length, bantu);
            }
            else{
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while(bantu->sibling != root->child){ 
                    printTree(length,bantu);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                printTree(length, bantu);
            }
        }
    } 
}
