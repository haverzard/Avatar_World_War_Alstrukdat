//* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
// Queue with elemen of Skill

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// #define Nil 0
// /* Konstanta untuk mendefinisikan address tak terdefinisi */

// /* Definisi elemen dan address */
// typedef int infotype;
// typedef int address;   /* indeks tabel */
// /* Contoh deklarasi variabel bertype Queue : */
// /* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
// typedef struct { skilltype * T;   /* tabel penyimpan elemen */
//                  address HEAD;  /* alamat penghapusan */
//                  address TAIL;  /* alamat penambahan */
//                  int MaxEl;     /* Max elemen queue */
//                } Queue;
// /* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
// /* Catatan implementasi: T[0] tidak pernah dipakai */

// /* ********* AKSES (Selektor) ********* */
// /* Jika Q adalah Queue, maka akses elemen : */
// #define Head(Q) (Q).HEAD
// #define Tail(Q) (Q).TAIL
// #define InfoHead(Q) (Q).T[(Q).HEAD]
// #define InfoTail(Q) (Q).T[(Q).TAIL]
// #define MaxEl(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return (Head(Q)==Nil && Tail(Q)==Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsFull (Queue Q){
    return (NBElmt(Q) == MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (Queue Q){
    // return (((Tail(Q)-Head(Q))%MaxEl(Q)) +1);
    int x = Tail(Q)-Head(Q);
    if (x>0){
        return (x+1);
    } else {
        if (x==0){
            return 0;
        } else {
            return (x+MaxEl(Q)+1);
        }
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
    (*Q).T = (infotype*) malloc ((Max+1)*sizeof(infotype));
    if ((*Q).T != NULL){
        MaxEl(*Q)= Max;
        Head(*Q)=0;
        Tail(*Q)=0;
    } else {
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
    free((*Q).T);
    MaxEl(*Q) = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, skilltype X){
    if (IsEmpty(*Q)){
        Head(*Q)     = 1;
        Tail(*Q)     = 1;
        InfoTail(*Q) = X;
    } else { //Not Empty
        Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) +1;
        InfoTail(*Q) = X;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

void Del (Queue * Q, skilltype * X){
    *X = InfoHead(*Q);
    if (Tail(*Q)==Head(*Q)) { //Tail(*Q)=1 karena prekondisi tidak mungkin kosong
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) =(Head(*Q)%MaxEl(*Q)+1);
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */