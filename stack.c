/* File : stack.c MODIFIED */
/* Deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* ADT Stack untuk mekanisme command UNDO */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator Untuk Membuat Stack Kosong *** */
void CreateEmpty_Stack (Stack *S){
    Top(*S) = NilStack;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai NilStack */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty_Stack (Stack S){
    return (Top(S) == NilStack);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull_Stack (Stack S){
    return (Top(S) == MaxElStack);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypeStack X){   
    Top(*S) += 1;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypeStack* X){
    (*X) = InfoTop(*S);
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void UpdateStatus_Stack(Stack *S, Player P1, Player P2, TabBangunan TB) {
/* Mengisi Stack dengan ADT yang ada */
/* I.S. Stack mungkin kosong mungkin terisi */
/* F.S. Stack terisi dengan elemennya adalah keterangan pada pemain apa dan Bangunan*/
    /* Kamus Lokal */
    infotypeStack X;
    Player temp1, temp2;
    List L1, L2;
    TabBangunan TB2;
    /* Algoritma */
    temp1 = P1; temp2 = P2;
    CopyList(ListBangunan(P1), &ListBangunan(temp1));
    CopyList(ListBangunan(P2), &ListBangunan(temp2));
    CopyTab(TB, &TB2);
    InfoP1(X) = temp1;
    InfoP2(X) = temp2;
    InfoTabBangunan(X) = TB2;
    Push(S, X);
    // printf("0000000000000000000000000\n"); PrintListBangunan(1, InfoP1(X), InfoP2(X)); printf("0000000000000000000000000\n"); 
}

void UndoStatus_Stack(Stack *S, Player *P1, Player *P2, TabBangunan *TB)
/* Pop Stack untuk UNDO */
/* I.S. Stack tidak kosong */
/* F.S. Stack berkurang 1 elemen */
{
    infotypeStack X;
    if (!IsEmpty_Stack(*S)) {
        Pop(S, &X);
        *P1 = InfoP1(X);
        *P2 = InfoP2(X);
        *TB = InfoTabBangunan(X);
        // printf("111111111111111111111111\n"); PrintListBangunan(1, *P1, *P2); printf("111111111111111111111111\n"); 
    } else {
        printf("Tidak bisa UNDO lagi!\n");
    }
}

void ResetStatus(Stack *S) {
/* Mengosokan Isi Stack Saat bergantian Pemain */
/* I.S. Stack Mungkin Kosong, mungkin berisi */
/* F.S. Stack menjadi kosong */
    CreateEmpty_Stack(S);
}
