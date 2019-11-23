#include "../point.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    POINT P,Q;

    P = MakePOINT(1,1);
    printf("Koordinat titik P :");
    TulisPOINT(P);
    printf("\n");
    printf("Pergeseran titik P 2 satuan ke timur dan 2 satuan ke utara");
    SetAbsis(&P,3);
    SetOrdinat(&P,3);
    TulisPOINT(P);
    printf("\n");
    printf("Masukkin koordinat titik Q :");
    BacaPOINT(&Q);
    if (EQ_POINT(P,Q)){
        printf("Kedua titik tersebut berhimpit\n");
    } else if (NEQ_POINT(P,Q)){
        printf("Kedua titik berbeda\n");
    }

    if (IsOrigin(Q)){
        printf("Titik Q terletak pada origin\n");
    } else {
        if (IsOnSbX(Q)){
            printf("Titik Q terletak pada Sb X\n");
        } else if (IsOnSbY(Q)){
            printf("Titik Q terletak pada Sb Y\n");  
        } else{
            printf("Titik Q terletak pada Kuadran %d\n",Kuadran(Q));
        }
    }
    return 0;
}