#include "header.h"


void makeTree(char str[], tree *T){
    simpul *baru;
    baru = (simpul *) malloc (sizeof (simpul));

    strcpy(baru->kontainer, str);
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}
void addRight(char str[], simpul *root){
    if(root->right == NULL){
        /*jika sub pohon kanan kosong*/
        simpul *baru;
        baru = (simpul *) malloc (sizeof (simpul));

        strcpy(baru->kontainer, str);
        baru->right = NULL;
        baru->left = NULL;
        root->right = baru;
    }
    else{
        printf("sub pohon kanan telah terisi \n");
    } 
}
void addLeft(char str[], simpul *root){
    if(root->left == NULL){
        /*jika sub pohon kiri kosong*/
        simpul *baru;
        baru = (simpul *) malloc (sizeof (simpul));

        strcpy(baru->kontainer, str);
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    }
    else{
        printf("sub pohon kiri telah terisi \n");
    } 
}
simpul* findSimpul(char str[], simpul *root){
    simpul *hasil = NULL;// untuk hasil
    simpul *node = NULL;// untuk menandai

    if(root != NULL){
        // apakah isi simpul sama dengan yang dicari
        if(strcmp(root->kontainer, str) == 0){
            //jika ya
            hasil = root;
        }
        else{
            // jika tidak
            // cari simpul dikiri
            node = findSimpul(str, root->left);
            
            // apakah ditemukan
            if(node != NULL){
                // jika ya, hasil node diassign ke hasil
                hasil = node;
            }

            //cari simpul di kanan
            hasil = findSimpul(str, root->right);
            
            // apakah ditemukan
            if(node != NULL){
                // jika ya, hasil node diassign ke hasil
                hasil = node;
            }
        }
    }
    return hasil;
}
void delAll(simpul *root){
    if(root != NULL){ 
        delAll(root->left); 
        delAll(root->right);
        free(root);
    }
}
void delRight(simpul *root){
    if(root != NULL){
        if(root->right != NULL){
            delAll(root->right);
            root->right = NULL;
        }
    }
}
void delLeft(simpul *root){ 
    if(root != NULL){
        if(root->left != NULL){
            delAll(root->left);
            root->left = NULL;
        }
    }
}
void printTreePreOrder(simpul *root){
    if(root != NULL){
        printf(" %s ", root->kontainer);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}
void printTreeInOrder(simpul *root){
    if(root != NULL){
        printTreeInOrder(root->left); 
        printf(" %s ", root->kontainer);
        printTreeInOrder(root->right);
    }
}
void printTreePostOrder(simpul *root){
    if(root != NULL){
        printTreePostOrder(root->left); 
        printTreePostOrder(root->right); 
        printf(" %s ", root->kontainer);
    }
}
void copyTree(simpul *root1, simpul **root2){
    if(root1 != NULL){
        (*root2) = (simpul *) malloc (sizeof (simpul));
        strcpy((*root2)->kontainer, root1->kontainer);

        if(root1->left != NULL){
            copyTree(root1->left, &(*root2)->left);
        }
        if(root1->right != NULL){
            copyTree(root1->right, &(*root2)->right);
        }
    }
}
int isEqual(simpul *root1, simpul *root2){
    int hasil = 1;

    if((root1 != NULL) && (root2 != NULL)){
        /* jika simpul pohon 1 dan pohon 2 sama sama tidak NULL */
        if(root1->kontainer != root2->kontainer){
            /* jika isi kontainer simpul pohon 1 dan pohon 2 tidak sama */
            hasil = 0;
        }
        else{
            /* jika isi kontainer simpul pohon 1 dan simpul pohon 2 sama, maka telusuri simpul selanjutnya */
            isEqual(root1->left, root2->left);
            isEqual(root1->right, root2->right);
        }
    }
    else{
        if((root1 != NULL)|| (root2 != NULL)){
            /* jika salah satu simpul ada yang NULL */
            hasil = 0;
        }
    }
    return hasil;
}
int isMirror(simpul *root1, simpul *root2){
    int hasil = 1, n;

    // printf("%d %s = %d %s\n", root1, root1->kontainer, root2, root2->kontainer);
    //cek kedua simpul apakah tidak null
    if((root1 != NULL) && (root2 != NULL)){
        // cek isi kedua simpul apakah sama
        if(strcmp(root1->kontainer, root2->kontainer) != 0){
            //jika tidak sama
            hasil = 0;
        }
        else{
            // jika sama
            // cek sisi kanan 
            n = isMirror(root1->left, root2->right);
            
            if(n != 1){
                // jika tidak sama, assign ke hasil
                hasil = n;
            }
            // cek sisi kiri
            n = isMirror(root1->right, root2->left);

            if(n != 1){
                // jika tidak sama, assign ke hasil
                hasil = n;
            }
        }
    }
    else{
        //jika masuk else, cek jika salah satunya null sedangkan yang lainnya tidak
        if((root1 != NULL) || (root2 != NULL)){
            hasil = 0;
        }
    }
    return hasil;
}