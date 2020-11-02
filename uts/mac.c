#include "head.h"
/*Saya Muhammad Izzatul Haq mengerjakan UTS dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void createList(list *L){
    (*L).first = NULL;
}

int countElementB(list L){
    int hasil = 0;

    if(L.first !=NULL){
        /*list tidak kosong*/
        eBaris* bantu;
        /*inisialisasi*/
        bantu = L.first;

        while(bantu != NULL){
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

int countElementK(eBaris L){
    int hasil = 0;
    if(L.col !=NULL){
        /*list tidak kosong*/
        eKolom* bantu;
        /*inisialisasi*/
        bantu = L.col;

        while(bantu != NULL){
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(char jenis[], int tahun, list *L){
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    strcpy(baru->kontainer.jenis, jenis);
    baru->kontainer.tahun = tahun;
    baru->col = NULL;

    if((*L).first == NULL){
        baru->next = NULL;
    }else{
        baru->next = (*L).first;
    }

    (*L).first = baru;
    baru = NULL;
}

void addFirstK(char nama[], eBaris *L){
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    strcpy(baru->kontainer_kol.nama, nama);
    

    if((*L).col == NULL){
        baru->next_kol = NULL; 
    }else{
        baru->next_kol = (*L).col;
    }

    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris* prev, char jenis[], int tahun){
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    strcpy(baru->kontainer.jenis, jenis);
    baru->kontainer.tahun = tahun;
    baru->col = NULL;
    
    if(prev->next == NULL){
        baru->next = NULL;
    }else{
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom* prev, char nama[]){
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    strcpy(baru->kontainer_kol.nama, nama);
    

    if(prev->next_kol == NULL){
        baru->next_kol = NULL;
    }else{
        baru->next_kol = prev->next_kol;
    }

    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(char jenis[], int tahun, list *L){
    if((*L).first == NULL){
    /*jika list adalah list kosong*/
        addFirstB(jenis, tahun, L);
    }
    else{
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eBaris *last = (*L).first;

        while(last->next != NULL){
            /*iterasi*/
            last = last->next;
        }

        addAfterB(last,jenis, tahun);
    }
}

void addLastK(char nama[], eBaris *L){
    if((*L).col == NULL){
        /*jika list adalah list kosong*/
        addFirstK(nama, L);
    }
    else{
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eKolom *last = (*L).col;

        while(last->next_kol != NULL){
            /*iterasi*/
            last = last->next_kol;
        }

        addAfterK(last, nama);
    }
}

void delFirstK(eBaris *L){
    if((*L).col != NULL){
        /*jika list bukan list kosong*/
        eKolom* hapus = (*L).col;

        if(countElementK(*L) == 1){
            (*L).col = NULL;
        }else{
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }

        free(hapus);
    }
}

void delAfterK(eKolom* prev){
    eKolom* hapus = prev->next_kol;

    if(hapus != NULL){
        if(hapus->next_kol == NULL){
            prev->next_kol = NULL;

        }else{
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }

        free(hapus);
    }
}

void delLastK(eBaris *L){
    if((*L).col != NULL){
        /*jika list tidak kosong*/
        if(countElementK(*L) == 1){
            /*list terdiri dari satu
            elemen*/
            delFirstK(L);
        }
        else{
            /*mencari elemen terakhir list*/
            eKolom *last = (*L).col;
            eKolom *before_last;

            while(last->next_kol != NULL){
                /*iterasi*/
                before_last = last;
                last = last->next_kol;
            }

            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L){
    if(countElementK(*L) != 0){
        int i;

        for(i=countElementK(*L);i>=1;i--){
            /*proses menghapus elemen list*/
            delLastK(L);
        }
    }
}

void delFirstB(list *L){
    if((*L).first != NULL){
        /*jika list bukan list kosong*/
        eBaris *hapus = (*L).first;

        if(hapus->col != NULL){
            //menghapus semua elemen kolom jika ada
            delAllK(hapus);
        }

        if(countElementB(*L) == 1){
            (*L).first = NULL;
        }
        else{
            (*L).first = (*L).first->next;
        }

        hapus->next = NULL;
        free(hapus);
    }
    else{
        printf("list kosong");
    }
}

void delAfterB(eBaris* prev){
    if(prev != NULL){
        eBaris *hapus = prev->next;

        if(hapus != NULL){
            if(hapus->col != NULL){
                //menghapus semua elemen kolom jika ada
                delAllK(hapus);
            }

            if(hapus->next == NULL){
                prev->next = NULL;
            }
            else{
                prev->next = hapus->next;
            }

            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L){
    if((*L).first != NULL){
        /*jika list tidak kosong*/
        if(countElementB(*L) == 1){
                /*list terdiri dari satu
                elemen*/
                delFirstB(L);
        }
        else{
            /*mencari elemen terakhir list*/
            eBaris *last = (*L).first;
            eBaris *before_last;

            while(last->next != NULL){
                /*iterasi*/
                before_last = last;
                last = last->next;
            }

            delAfterB(before_last);
        }
    }
}

void delAllB(list *L){
    if(countElementB(*L) != 0){
        int i;

        for(i=countElementB(*L);i>=1;i--){
            /*proses menghapus elemen list*/
            delLastB(L);
        }
    }
}

void printElement(list L){
    if(L.first != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        eBaris* bantu = L.first;
        printf("- obat keras\n");

        while(bantu != NULL){
            if(strcmp(bantu->kontainer.jenis,"keras") == 0){
                eKolom* eCol = bantu->col;

                while(eCol != NULL){
                    printf("%d %s\n",
                    bantu->kontainer.tahun,
                    eCol->kontainer_kol.nama);
                    eCol = eCol->next_kol;
                }
            }
            bantu = bantu->next;
        }
        
        printf("- obat ringan\n");
        bantu = L.first;

        while(bantu != NULL){
            if(strcmp(bantu->kontainer.jenis,"ringan") == 0){
                eKolom* eCol = bantu->col;

                while(eCol != NULL){
                    printf("%d %s\n",
                    bantu->kontainer.tahun,
                    eCol->kontainer_kol.nama);
                    eCol = eCol->next_kol;
                }
            }
            bantu = bantu->next;
        }
    }
    else{
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

void sort(list *L){
    int move = 0,i = 0;
    eBaris *last = (*L).first;
    eBaris *lastPrev = last;

    do{
        if((strcmp(last->kontainer.jenis, "ringan") == 0) && (strcmp(last->next->kontainer.jenis,"keras") == 0)){
            if(i == 0){
                (*L).first = last->next;
                last->next = last->next->next;
                (*L).first->next = last;
            }else{
                lastPrev = last->next;
                last->next = last->next->next;
                lastPrev->next = last;
            }
        }else if(strcmp(last->kontainer.jenis, last->next->kontainer.jenis) == 0){
            if(last->kontainer.tahun > last->next->kontainer.tahun){
                if(i == 0){
                (*L).first = last->next;
                last->next = last->next->next;
                (*L).first->next = last;
            }else{
                lastPrev = last->next;
                last->next = last->next->next;
                lastPrev->next = last;
            }
            }
        }
        i++;
        eBaris *lastPrev = last;
        last = last->next;
    }while((last->next != NULL) && (move == 0));
}

void assignBnK(char jenis[],int tahun,char nama[],list *L){
    int temp = 0;

    if((*L).first == NULL){
        addFirstB(jenis, tahun, L);
        addLastK(nama, (*L).first);
    }else{
        eBaris *last = (*L).first;

        while(last->next != NULL){
            if((strcmp(last->kontainer.jenis,jenis) == 0) && (last->kontainer.tahun == tahun)){
                temp = 1;
                // printf("%s : %d\n",last->kontainer.jenis, last->kontainer.tahun);
                addLastK(nama, last);
                break;
            }
            last = last->next;
            // printf("%d\n",temp);
        }
        if (temp == 0){
            addAfterB(last, jenis, tahun);
            addLastK(nama, last->next);
        }
    }
}

void move(eBaris *thisB, eKolom *thisC, int tahun,list *L){
    int temp = 0;
    char jenis[10];
    eBaris *last = (*L).first;
    eKolom *thisPrev = thisC;

    while(last->next != NULL){
        if((strcmp(last->kontainer.jenis,thisB->kontainer.jenis) != 0) && (last->kontainer.tahun == tahun)){
            temp = 1;

            if(thisC != NULL){
                if(thisC->next_kol == NULL){
                    thisPrev->next_kol = NULL;
                }else{
                    thisPrev->next_kol = thisC->next_kol;
                    thisC->next_kol = NULL;
                }
            }
            break;
        }
        last = last->next;
    }

    if (temp == 0){
        if(strcmp(last->kontainer.jenis,"keras") == 0){
            strcpy(jenis,"ringan");
        }else{
            strcpy(jenis,"keras");
        }
        addAfterB(last, jenis, tahun);
    }

    eKolom *lastC = last->next->col;

    while(lastC->next_kol != NULL){
        /*iterasi*/
        lastC = lastC->next_kol;
    }

    lastC->next_kol = thisC;

}

void change(char nama[], int tahun,list *L){
    char jenis[10];
    int temp1;
    eKolom *temp;
    eBaris *last = (*L).first;

    while(last->next != NULL){
        eKolom *lastC = last->col;
        
        while(lastC->next_kol != NULL){
            if(strcmp(lastC->kontainer_kol.nama, nama) == 0){
                printf("%d",strcmp(lastC->kontainer_kol.nama, nama));
                move(last, lastC, tahun, L);
                

            }
            lastC = lastC->next_kol;
        }
        last = last->next;
    }
    if (temp1 == 0){
        addLastK(nama, last->next);
    }
}