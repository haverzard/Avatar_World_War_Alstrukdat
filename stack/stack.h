/* File : stack.h MODIFIED */
/* Deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* ADT Stack untuk mekanisme command UNDO */

#ifndef STACK_H
#define STACK_H

#include "../boolean/boolean.h"
#include "../arraydinpos/arraydinpos.h"
#include "../player/player.h"

/* KAMUS UMUM */
#define NilStack 0
#define MaxElStack 100
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int addressStack;   /* indeks tabel */
typedef struct {
	Player InfoP1;
	Player InfoP2;
	TabBangunan InfoTabBangunan;
} infotypeStack;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	infotypeStack T[MaxElStack+1]; /* tabel penyimpan elemen */
	addressStack TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] */

/* Jika S adalah Stack maka akses elemen : */
/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP	/* S.T[(S.TOP)] untuk mengakses elemen TOP */
#define InfoTop(S) (S).T[(S).TOP]	/* S.TOP adalah alamat elemen TOP */
#define InfoP1(X) (X).InfoP1
#define InfoP2(X) (X).InfoP2
#define InfoTabBangunan(X) (X).InfoTabBangunan

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator Pembentuk Stack *** */
void CreateEmpty_Stack (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty_Stack (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull_Stack (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypeStack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypeStack* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void UpdateStatus_Stack(Stack *S, Player P1, Player P2, TabBangunan TB);
/* Mengisi Stack dengan ADT yang ada */
/* I.S. Stack mungkin kosong mungkin terisi */
/* F.S. Stack terisi dengan elemennya adalah keterangan pada pemain apa dan Bangunan*/

void UndoStatus_Stack(Stack *S, Player *P1, Player *P2, TabBangunan *TB);
/* Pop Stack untuk UNDO */
/* I.S. Stack tidak kosong */
/* F.S. Stack berkurang 1 elemen */

void ResetStatus(Stack *S);
/* Mengosokan Isi Stack Saat bergantian Pemain */
/* I.S. Stack Mungkin Kosong, mungkin berisi */
/* F.S. Stack menjadi kosong */


#endif