//* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
// Queue with elemen of Skill

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmpty_Queue (Queue Q){
    return (Head(Q)==NilQ && Tail(Q)==NilQ);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsFull_Queue (Queue Q){
    return (NBElmt(Q) == MaxElQ(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */

int NBElmt (Queue Q){
    // return (((Tail(Q)-Head(Q))%MaxElQ(Q)) +1);
    if (IsEmpty_Queue(Q)) {
        return 0;
    } else if (Tail(Q) >= Head(Q)) {
        return Tail(Q)-Head(Q)+1;
    } else {
        return Tail(Q)+(MaxElQ(Q)-Head(Q)+1);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty_Queue (Queue * Q, int Max){
    (*Q).S = (skilltype*) malloc ((Max+1)*sizeof(skilltype));
    if ((*Q).S != NULL){
        MaxElQ(*Q)= Max;
        Head(*Q)=0;
        Tail(*Q)=0;
    } else {
        MaxElQ(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
    free((*Q).S);
    MaxElQ(*Q) = 0;
}
/* Proses: Mengembali   kan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, skilltype X){
    if (IsEmpty_Queue(*Q)){
        Head(*Q)     = 1;
        Tail(*Q)     = 1;
        InfoTail(*Q) = X;
        printf("aaaa");
    } else { //Not Empty
        printf("Masuk ke Add\n");
        Tail(*Q) = (Tail(*Q) % MaxElQ(*Q)) +1;
        InfoTail(*Q) = X;
        printf("berhasil ditambah ke ADD");
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

void Del (Queue * Q, skilltype * X){
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1) { //Tail(*Q)=1 karena prekondisi tidak mungkin kosong
        Head(*Q) = NilQ;
        Tail(*Q) = NilQ;
    } else {
        Head(*Q) = (Head(*Q) % MaxElQ(*Q) +1);
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilQai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */

void CopyQueue (Queue Qin, Queue *Qout) {
    /* Kamus Lokal */
    Queue Qtemp;
    int NbEl;
    /* Algoritma */
    CreateEmpty_Queue(Qout, MaxElQ(Qin));
    NbEl = NBElmt(Qin);
    if (NbEl > 0) {
        for (int i = 1; i <= NbEl; i++) {
            Add(Qout, (Qin.S[i]));
        }
    }
}
/* I.S. Qin terdefinisi, Qout sembarang */
/* F.S. Qout berisi salinan dari Qin */
/* Proses : Menyalin isi Qin ke Qout */