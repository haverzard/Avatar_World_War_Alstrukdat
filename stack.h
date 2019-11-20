/* File : stack.h */
/* Deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* ADT Stack untuk mekanisme command UNDO */

#ifndef STACK_H
#define STACK_H

#include "boolean.h"

/* KAMUS UMUM */
#define Nil 0
/* Nil adalah Konstanta untuk mendefinisikan keadaan kosong. */
#define MaxElStack 100
/* Nilai maksimum jumlah elemen pada Stack */

typedef int infotype; /* elemen */
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	infotype T[MaxElStack+1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] */

/* Jika S adalah Stack maka akses elemen : */
/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP	/* S.T[(S.TOP)] untuk mengakses elemen TOP */
#define InfoTop(S) (S).T[(S).TOP]	/* S.TOP adalah alamat elemen TOP */

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator Pembentuk Stack *** */
void CreateEmpty (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif