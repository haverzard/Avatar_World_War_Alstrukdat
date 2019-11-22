/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
// Queue with elemen of Skill

#ifndef queue_H
#define queue_H

#include "boolean.h"

#define NilQ 0
/* Konstanta untuk mendefinisikan addressQ tak terdefinisi */

//Nama Skill
//Instant Upgrade       U atau u
//Shield                S atau s
//Extra Turn            E atau e
//Attack Up             A atau a
//Critical Hit          H atau h
//Instant Reinforcement R atau r
//Barrage               B atau b

/* Definisi elemen dan addressQ */
typedef char skilltype;
typedef int addressQ;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { skilltype * S;   /* tabel penyimpan elemen */
                 addressQ HEAD;  /* alamat penghapusan */
                 addressQ TAIL;  /* alamat penambahan */
                 int MaxElQ;     /* Max elemen queue */
               } Queue;
/* Definisi Queue kosong: HEAD=NilQ; TAIL=NilQ. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).S[(Q).HEAD]
#define InfoTail(Q) (Q).S[(Q).TAIL]
#define MaxElQ(Q) (Q).MaxElQ

/* ********* Prototype ********* */
boolean IsEmpty_Queue (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull_Queue (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */
int NBElmt (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty_Queue (Queue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, skilltype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, skilltype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilQai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */

void CopyQueue (Queue Qin, Queue *Qout);
/* I.S. Qin terdefinisi, Qout sembarang */
/* F.S. Qout berisi salinan dari Qin */
/* Proses : Menyalin isi Qin ke Qout */

#endif