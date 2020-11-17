#include "header.h"

int main(){	
    queue Q;
    createEmpty(&Q);
    char nama[50], tiket[10], search[50];
    int waktu, i = 0;

    while(i == 0){
        scanf("%s", nama);

        if(strcmp(nama,".") == 0){
            break;
        }else{
            scanf("%s %d", tiket, &waktu);

            if(strcmp(tiket, "Golden") == 0){
                addPrior(nama, 1, waktu, &Q);
            }else if(strcmp(tiket, "Silver") == 0){
                addPrior(nama, 2, waktu, &Q);
            }else if(strcmp(tiket, "Bronze") == 0){
                addPrior(nama, 3, waktu, &Q);
            }else{
                addPrior(nama, 5, waktu, &Q);
            }
            // printf("Cek %s %d %d\n",nama, prior, waktu);
        }
    }
    scanf("%s", search);
    // printQueue(Q);
    print(search, Q);

    return 0;
}