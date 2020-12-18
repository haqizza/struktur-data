#include "header.h"

int main(){
    graph G, G2;
    char node, value[51], start[51], stop[51];
    int type = 0, n, i, j;

    createEmpty(&G);
    createEmpty(&G2);

    //Graph 1
    //scan jumlah simpul
    scanf("%d", &n);

    //scan input simpul
    for(i = 0; i < n; i++){
        scanf("%s", value);
        addSimpul(value, &G);
    }

    //scan jumlah jalan
    scanf("%d", &n);

    //scan input jalan
    for(i = 0; i < n; i++){
        scanf("%s %s", start, stop);
        simpul *begin = findSimpul(start, G);
        simpul *end = findSimpul(stop, G);

        addJalur(begin, end);
    }

    //Graph 2
    //scan jumlah simpul
    scanf("%d", &n);

    //scan input simpul
    for(i = 0; i < n; i++){
        scanf("%s", value);
        addSimpul(value, &G2);
    }

    //scan jumlah jalan
    scanf("%d", &n);

    //scan input jalan
    for(i = 0; i < n; i++){
        scanf("%s %s", start, stop);
        simpul *begin = findSimpul(start, G2);
        simpul *end = findSimpul(stop, G2);

        addJalur(begin, end);
    }


    //Additional Jalur
    //scan jumlah jalur tambahan
    scanf("%d", &n);

    //scan input jalur tambahan
    for(i = 0; i < n; i++){
        scanf("%s %s", start, stop);
        // cari simpul
        simpul *begin = findSimpul(start, G);
        simpul *end = findSimpul(stop, G);
        
        //jika tidak ditemukan, cari di G2
        if((begin == NULL) || (end == NULL)){
            begin = findSimpul(start, G2);
            end = findSimpul(stop, G2);
        }

        //jika masih belum ditemukan, cek di G dan G2
        if((begin == NULL) || (end == NULL)){
            begin = findSimpul(start, G);
            end = findSimpul(stop, G2);
            //type 1 menandakan gabungan
            type = 1;
        }

        addJalur(begin, end);
    }

    // apakah gabungan
    if(type == 1){
        // gabungkan graf
        connect(&G, &G2);
        //print
        printf("Graf Gabungan:\n\n");
        printGraph(G);
    }else{
        //print terpisah
        printf("Graf Pertama:\n\n");
        printGraph(G);
        printf("\nGraf Kedua:\n\n");
        printGraph(G2);
    }

    return 0;
}