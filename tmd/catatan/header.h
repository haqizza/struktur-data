#include <stdio.h>
#include <string.h>
#include <malloc.h>
// Saya Muhammad Izzatul Haq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

typedef struct smp *alamatsimpul;

typedef struct smp{
    char kontainer[50];
    char bawaan[50][50];
    int bawaanNumber;
    alamatsimpul sibling;
    alamatsimpul child;
}simpul;

typedef struct{
    simpul *root;
}tree;

// Buat Tree
void makeTree(char c[], int nBawaan, char bawaan[][50], tree *T);

// Tambahkan Child ke Root
void addChild(char c[], int nBawaan, char bawaan[][50], simpul *root);

// Tambahkan Bawaan
void addBawaan(char bawaan[][50], simpul *node); 

// Hapus Node dengan Childnya
void delAll(simpul *root);

// Hapus Child dari Node
void delChild(char c[], simpul *root);

// Cari Node
simpul* findSimpul(char c[], simpul *root); 

// Cari Parent dari Node
simpul* findParent(char c[], simpul *root);

// Pindahkan Child jadi Mandiri
void pindahMandiri(simpul *nodeChild, tree *T, tree *TMandiri);

// Pindahkan Child ke Parent barunya
void pindah(simpul *nodeChild, simpul *nodeParent, tree *T);

// Putus Child dari Parent/Siblingnya
void disconnectChild(char c[], simpul *root);

// Sambungkan Child ke Parent barunya
void connectChild(simpul *nodeChild, simpul *nodeParent);


void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyBawaan(simpul **nodeTujuan, simpul *nodeAsal);
void copyTree(simpul *root1, simpul **root2);