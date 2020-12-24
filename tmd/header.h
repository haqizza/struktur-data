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

void makeTree(char c[], int nBawaan, char bawaan[][50], tree *T); //Buat Tree
void addChild(char c[], int nBawaan, char bawaan[][50], simpul *root); // Tambah Child ke Root
void addBawaan(char bawaan[][50], simpul *node); // Tambahkan Bawaan
void delAll(simpul *root); // Hapus Node dengan Childnya
void delChild(char c[], simpul *root); // Hapus Node
simpul* findSimpul(char c[], simpul *root); // Cari Node dengan Kontainer
void pindahMandiri(simpul *child, tree *TMandiri); // Pindahkan child jadi Mandiri
void pindah(simpul *nodeChild, simpul *nodeParent);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyBawaan(simpul **nodeTujuan, simpul *nodeAsal);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul **root2);