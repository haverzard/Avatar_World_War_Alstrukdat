/* Driver List Linier */
#include <stdio.h>
#include <stdlib.h>
#include "../../listlinier/listlinier.h"

int main (){
    //Kamus
    List L;
    infotype a,b,c,d;
    int e;
    address P,Q,R,S,temp,del;

    a =1;b=2,c=3,d=4,e;

    CreateEmpty_LL(&L);
    P = Alokasi(a);
    Q = Alokasi(b);
    R = Alokasi(c);
    S = Alokasi(d);

    if (IsEmpty_LL(L)){
        printf("List L masih dalam keadaan kosong\n");
    } else {
        printf("List L sudah terisi\n");
    }
    printf("\n");
    printf("Penambahan elemen ke list\n");
    printf("%d ditambahkan di awal list\n",b);
    InsertFirst(&L,Q);
    printf("%d ditambah di akhir list\n",c);
    InsertLast(&L,R);
    printf("%d ditambahkan di akhir list\n",d);
    InsertLast(&L,S);
    printf("%d ditambahkan di awal list\n",a);
    InsertFirst(&L,P);

    printf("Isi list setelah pengisian\n");
    temp = First(L);
    while (temp != Nil){
        printf("%d ",Info(temp));
        temp = Next(temp);
    }
    printf("\n");
    printf("\n");

    printf("Mencari apakah elemen 5 berada di dalam list\n");
    if (SearchInfo(L,e) == Nil){
        printf("5 tidak ada di dalam list\n");
    }
    printf("\n");

    printf("Penghapus elemen\n");
    printf("%d dihapus di akhir list\n",d);
    DelLast(&L,&del);   
    printf("%d dihapus di akhir list\n",c);
    DelLast(&L,&del);
    printf("Setelah penghapusan List tersisi 2 elemen\n");
    temp = First(L);
    while (temp != Nil){
        printf("%d ",Info(temp));
        temp = Next(temp);
    }
    
    return 0;
}
