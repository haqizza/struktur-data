#include <stdio.h>
#include <string.h>
#include <malloc.h>
// Saya Muhammad Izzatul Haq mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

typedef struct smp *alamatsimpul;

typedef struct smp{
    char kontainer[50];
    char bawaan[50][50];
    int bawaanNumber;
    int level;
    int space;
    alamatsimpul sibling;
    alamatsimpul child;
}simpul;

typedef struct{
    simpul *root;
}tree;

// Buat Tree
void makeTree(char c[], int nBawaan, char bawaan[][100], tree *T);

// Tambahkan Child ke Root
void addChild(char c[], int nBawaan, char bawaan[][100], simpul *root);

// Tambahkan Bawaan
void addBawaan(char bawaan[][100], simpul *node); 

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

// Hitung string terpanjang dalam satu level
int countLongest(int level, simpul *root);

// Cek level Node dan menandainya
void checkLevel(int level, simpul **root);

// Print whitespace
void printSpaces(int length);

// Print Tree sesuai format
void printTree(int levelSpace[], simpul *root);