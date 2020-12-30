#include "header.h"
// Saya Muhammad Izzatul Haq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

void makeTree(char c[], int nBawaan, char bawaan[][100], tree *T){
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

void addChild(char c[], int nBawaan, char bawaan[][100], simpul *root){
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
                // Mencari simpul anak terakhir karena akan dikaitkan dengan simpul  baru sebagai simpul anak terakhir yang baru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul anak terakhir, penunjuk last akan berjalan ke simpul anak berikutnya
                while(last->sibling != root->child){
                    last = last->sibling;
                } 
                baru->sibling = root->child;
                last->sibling = baru;
            }
        } 
    } 
}

void addBawaan(char bawaan[][100], simpul *node){
    int i;
    // Assign setiap value dari array
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
        
        if(bantu->sibling == NULL){
            // jika memiliki satu simpul anak
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
            // Jika memiliki banyak simpul anak
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
            //  Memproses simpul anak terakhir karena belum terproses dalam pengulangan
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
        // Jika hanya mempunyai satu anak
        if(strcmp(root->child->kontainer, c) == 0){
            root->child = NULL;
        }
    }
    else{
        // Jika memiliki lebih dari satu simpul anak
        simpul *prev = NULL;
        // Mencari simpul yang akan dihapus
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

        // Memproses simpul anak terakhir karena belum terproses dalam pengulangan
        if((ketemu == 0) && (strcmp(hapus->kontainer, c) == 0)){
            ketemu = 1;
        }

        if(ketemu == 1){
            simpul *last = root->child;
            // Mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir
            while(last->sibling != root->child){
                last = last->sibling;
            }
            if(prev == NULL){
                // Jika simpul yang dihapus anak pertama
                if((hapus->sibling == last) && (last->sibling == root->child)){
                    // jika hanya ada dua anak
                    root->child = last;
                    last->sibling = NULL;
                }
                else{
                    //  jika memiliki simpul anak lebih dari dua simpul
                    root->child = hapus->sibling;
                    last->sibling = root->child; 
                }
            }
            else{
                if((prev == root->child) && (hapus->sibling == root->child)){
                    // Jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua
                    root->child->sibling = NULL;
                }
                else{
                    // Jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul
                    prev->sibling = hapus->sibling;
                    hapus->sibling = NULL;
                }
            }
        }
    }
}

void connectChild(simpul *nodeChild, simpul *nodeParent){
    if(nodeParent->child == NULL){    
        // Jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama
        nodeChild->sibling = NULL;
        nodeParent->child = nodeChild;
        // if(strcmp(nodeChild->kontainer, "tricolor") == 0){
        //     printf("----------%s %s\n", nodeParent->kontainer, nodeParent->child->kontainer);
        // }
    }
    else{
        if(nodeParent->child->sibling == NULL){
            // Jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua
            nodeChild->sibling = nodeParent->child;
            nodeParent->child->sibling = nodeChild;
        }
        else{
            simpul *last = nodeParent->child;
            // Mencari simpul anak terakhir karena akan dikaitkan dengan simpul  baru sebagai simpul anak terakhir yang baru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul anak terakhir, penunjuk last akan berjalan ke simpul anak berikutnya
            while(last->sibling != nodeParent->child){
                last = last->sibling;
            }
            nodeChild->sibling = nodeParent->child;
            last->sibling = nodeChild;
        }
    } 
}

int countLongest(int level, simpul *root){
    int i, len, tempLength, tempHasil, hasil = 0;

    if(root != NULL){
        tempLength = strlen(root->kontainer);

        for(i = 0; i < root->bawaanNumber; i++){
            // Bandingkan panjang string, paling banyak dipilih
            len = strlen(root->bawaan[i]);
            if(len > tempLength){
                tempLength = len;
            }
        }

        if(root->level == level){
            hasil = tempLength;
        }

        simpul *bantu = root->child;

        if(bantu != NULL){
            if(bantu->sibling == NULL){
                /*jika memiliki satu simpul anak*/
                tempHasil =  countLongest(level, bantu);
                if(tempHasil > hasil){
                    hasil = tempHasil;
                }
            }
            else{
                /*jika memiliki banyak simpul anak*/
                while(bantu->sibling != root->child){
                    tempHasil = countLongest(level, bantu);
                    if(tempHasil > hasil){
                        hasil = tempHasil;
                    }
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                tempHasil =  countLongest(level, bantu);
                if(tempHasil > hasil){
                    hasil = tempHasil;
                }
            }
        }
    }
    return hasil;
}

void checkLevel(int level, simpul **root){
    if((*root) != NULL){
        // Tandai Level
        (*root)->level = level;

        simpul *bantu = (*root)->child;

        level += 1;
        if(bantu != NULL){
            if(bantu->sibling == NULL){
                /*jika memiliki satu simpul anak*/
                checkLevel(level, &bantu);
            }
            else{
                /*jika memiliki banyak simpul anak*/
                while(bantu->sibling != (*root)->child){
                    checkLevel(level, &bantu);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                checkLevel(level, &bantu);
            }
        }
    } 
}

void printSpaces(int length){
    int i;
    // Print
    for(i = 0; i < length; i++){
        printf(" ");
    }
}

void printTree(int levelSpace[], simpul *root){
    int i, len, tempLength;
    
    if(root != NULL){
        // Print Node
        printf("\n");
        printSpaces(levelSpace[root->level]);
        printf("|%s\n", root->kontainer, root->level);
        tempLength = strlen(root->kontainer); // Cek panjang string


        // Print Bawaan
        for(i = 0; i < root->bawaanNumber; i++){
            printSpaces(levelSpace[root->level]);
            printf(" %s\n", root->bawaan[i]);
            
            // // Bandingkan panjang string, paling banyak dipilih
            // len = strlen(root->bawaan[i]);
            // if(len > tempLength){
            //     tempLength = len;
            // }
        }
        
        // Tambahkan panjang string terpilih ke total dengan panjang sebelumnya, menjadi panjang spasi
        // length += (tempLength + 1);
        
        simpul *bantu = root->child;

        if(bantu != NULL){
            if(bantu->sibling == NULL){
                /*jika memiliki satu simpul anak*/
                printTree(levelSpace, bantu);
            }
            else{
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while(bantu->sibling != root->child){ 
                    printTree(levelSpace,bantu);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                printTree(levelSpace, bantu);
            }
        }
    }
}