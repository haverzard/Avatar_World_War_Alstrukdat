/* File : stack.c MODIFIED */
/* Deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* ADT Stack untuk mekanisme command UNDO */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "bangunan.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator Untuk Membuat Stack Kosong *** */
void CreateEmpty (Stack *S){
    Top(*S) = NilStack;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai NilStack */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S){
    return (Top(S) == NilStack);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S){
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
    Top(*S) --;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void UpdateStatus(Stack *S, Player P) {
    /* Kamus Lokal */
    infotypeStack X;
    Bangunan B;

    /* Algoritma */
    InfoPlayer(X) = P;
    InfoBangunan(X) = B;
    Push(S, X);
}
/* Mengisi Stack dengan ADT yang ada */
/* I.S. Stack mungkin kosong mungkin terisi */
/* F.S. Stack terisi dengan elemennya adalah keterangan pada pemain apa dan Bangunan*/

void LoadStatus(Stack *S, Player P);
/* Pop Stack untuk UNDO */
/* I.S. Stack tidak kosong */
/* F.S. Stack berkurang 1 elemen */

void ResetStatus(Stack *S) {
    CreateEmpty(S);
}
/* Mengosokan Isi Stack Saat bergantian Pemain */
/* I.S. Stack Mungkin Kosong, mungkin berisi */
/* F.S. Stack menjadi kosong */