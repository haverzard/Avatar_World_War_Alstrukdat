/* File : graph.c */
/* Body ADT Graph */
/* Menggunakan representai multilist */

#include <stdlib.h>
#include "graph.h"
#include "listlinier.h"

/****************** PEMBUATAN GRAPH KOSONG ******************/
void CreateGraph(Graph *G)
/* I.S. G sembarang */
/* F.S. Terbentuk graph kosong */
{
    FirstG(*G) = Nil;
}

/****************** TEST GRAPH KOSONG ******************/
boolean IsEmptyGraph(Graph G)
/* mengeluarkan true jika graph G kosong */
{
    return FirstG(*G) == Nil;
}

/****************** Manajemen Memori ******************/
addressG AlokasiGraph (infotypeG X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /* KAMUS LOKAL */
    addressG P;
    /* ALGORITMA */
    P = (addressG *) malloc(sizeof(ElmtGraph));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    } 
    return P;
}
void DealokasiGraph (addressG *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/*** PENAMBAHAN ELEMEN ***/
void InsVFirstGraph (Graph *G, infotypeG X)
/* I.S. G mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan list X jika alokasi berhasil */
{
    /* KAMUS LOKAL */
    addressG P;
    /* ALGORITMA */
    P = AlokasiGraph(X);
    if (P != Nil) {
        Next(X) = FirstG(*G);
        FirstG(*G) = X;
    }
}
void InsVLastGraph(Graph *G, infotypeG X)
/* I.S. G mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen graph di akhir: elemen terakhir yang baru */
/* merupakan list X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS LOKAL */
    addressG P, temp;
    /* ALGORITMA */
    P = AlokasiGraph(X);
    if (IsEmptyGraph(*G)) {
        InsVFirstGraph(G, X);
    } else {
        temp = FirstG(*G);
        while (Next(temp) != Nil) {
            temp = Next(temp);
        }
        Next(temp) = P;
        Next(P) = Nil;
    }
}

void ResetGraph(Graph *G, int n)
/* I.S. Graph G sembarang */
/* F.S. Terbentuk Graph dengan n node dengan belum ada edge */
{
    
}

/*** JUMLAH ELEMEN ***/
int NbElmtGraph(Graph G)
/* mengeluarkan jumlah node pada graph G */
{
    /* KAMUS LOKAL */
    addressG P;
    int count;
    /* ALGORITMA */
    count = 0;
    P = FirstG(G);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

/*** PENCARIAN ELEMEN ***/
infotypeG SearchGraph(Graph G, int n)
/* NbElmtGraph(G) lebih besar dari n, mengeluarkan list yang merupakan info dari elemen ke n graph G */
{
    /* KAMUS LOKAL */
    addressG P;
    int NbElmt, count;
    /* ALGORITMA */
    NbElmt = NbElmtGraph(G);
    P = FirstG(G);
    count = 1;
    while (count < n && count < NbElmt) {
        count++;
        P = Next(P);
    }
    return Info(P);
}
int SearchInfoGraph(infotypeG L, infotypeL i)
/* mengeluarkan posisi dimana list L bernilai i, mengeluarkan 0 jika tidak ada */
{
    /* KAMUS LOKAL */
    addressG P;
    int count, NbElmt;
    /* ALGORITMA */
    if (IsEmptyGraph(L)) {
        return 0;
    } else {
        P = FirstG(L);
        count = 1; NbElmt = NbElmtGraph(L);
        while (Info(P) != i && count <= NbElmt) {
            count++;
            P = Next(P);
        }
        if (count > NbElmt) {
            return 0;
        } else {
            return count;
        }
    }
}

void GenerateRandomGraph(Graph *G,int n)
/* I.S. G sembarang */
/* F.S. G adalah connected graph dengan n node */
/* G didapat melalui hasil generate secara random */
{

}