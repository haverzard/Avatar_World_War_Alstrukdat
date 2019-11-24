#include "../../arraydinpos/arraydinpos.h"
#include "../../bangunan/bangunan.h"
#include "../../point/point.h"

#include <stdio.h>
#include <stdlib.h>

int main (){
    //Kamus
    int max1;
    TabBangunan T1,T2;
    Bangunan B1,B2,B3,tempB;
    POINT temp1,temp2,temp3;

    temp1 = MakePOINT(5,5);
    temp2 = MakePOINT(6,6);
    temp3 = MakePOINT(7,7);
    MakeEmpty(&T1,3);
    InitBangunan(&B1,'C');
	InitBangunan(&B2,'F');
	InitBangunan(&B3,'T');
    Koordinat(B1) = temp1;
	Koordinat(B2) = temp2;
	Koordinat(B3) = temp3;
    AddAsLastEl(&T1,B1);
    AddAsLastEl(&T1,B2);
    AddAsLastEl(&T1,B3);
    
    printf("indeks pertama  array : %d\n",GetFirstIdx(T1));
    if (IsIdxValid_Array(T1,2)){
        printf("2 adalah index yang valid\n");
    } else {
        printf("2 adalah index yang valid\n");
    }
    printf("indeks terakhir array : %d\n",GetLastIdx(T1));
    
    if (IsFull_Array(T1)){
        printf("Array penuh\n");
    } else {
        printf("Array tidak penuh\n");
    }

    CopyTab(T1,&T2); 
    if (IsEQ(T1,T2)){
        printf("Array T1 dan T2 sama\n");
    } else {
        printf("Array T1 dan T2 tidak sama\n");
    }
    DelLastEl(&T1,&tempB);
    DelLastEl(&T1,&tempB);
    DelLastEl(&T1,&tempB);
    if (IsEmpty_Array(T1)){
        printf("Setelah didelete 3 elemen Array T1 kosong\n");
    }

    return 0;
}