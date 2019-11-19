/* File : graph.c */
/* Body ADT Graph */
/* Menggunakan representai multilist */

#include <stdlib.h>
#include "graph.h"

/****************** PEMBUATAN GRAPH ******************/
void CreateGraph(int X, Graph* G)
/* I.S. G sembarang */
/* F.S. Terbentuk graph G */
{
    /* Kamus Lokal */
    adrNode temp;
    /* Algoritma */
    First(*G) = NodeUndef;
    InsertNode(G, X, &temp);
}

/****************** Manajemen Memori ******************/
adrNode AlokNodeGraph(int X)
/* Mengirimkan address hasil alokasi sebuah node */
/* Jika alokasi berhasil, maka address tidak nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /* Kamus Lokal */
    adrNode P = (adrNode) malloc (sizeof(NodeGraph));
    /* Algoritma */
    if (P != NodeUndef) {
        NoBangunan(P) = X;
        Trail(P) = NodeUndef;
        Next(P) = NodeUndef;
	}
    return P;
}
void DealokNodeGraph(adrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
adrSuccNode AlokSuccNode(adrNode Pn)
/* Mengirimkan address hasil alokasi sebuah SuccNode */
/* Jika alokasi berhasil, maka address tidak nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    adrSuccNode P = (adrSuccNode) malloc (sizeof(SuccNode));
    if(P != NodeUndef) {
        Succ(P) = Pn;
        Next(P) = NodeUndef;
    }
    return P;
}
void DealokSuccNode(adrSuccNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/*** PENCARIAN ELEMEN ***/
adrNode SearchNode(Graph G, int X)
/* Mengembalikan adrNode dari graph G dengan NoBangunan bernilai X */
{
    adrNode P = First(G);
    while(P != NodeUndef){
		if (NoBangunan(P) == X) {
            return P;
        } else {
            P = Next(P);
        }
	}
    return P;
}

adrSuccNode SearchEdge(Graph G, int prec, int succ)
/* Mengembalikan adrSuccNode dari NoBangunan prec dengan NoBangunan bernilai succ */
{
    /* Kamus Lokal */
    adrNode Pn;
    /* Algoritma */
    Pn = SearchNode(G, prec);
    if (Pn == NodeUndef) {
        return NodeUndef;
    } else {
        adrSuccNode PSucc = Trail(Pn);
        while (PSucc != NodeUndef) {
            if (NoBangunan(Succ(PSucc)) == succ) {
                return PSucc;
            } else {
                PSucc = Next(PSucc);
            }
        }
        return PSucc;
    }
}


/*** PENAMBAHAN ELEMEN ***/
void InsertNode(Graph* G, int X, adrNode* Pn)
/* I.S. G terdefinisi */
/* F.S. adrNode Pn terdapat pada Graph G dengan infotype X */
{
    /* Kamus Lokal */
    adrNode P;
    /* Algoritma */
    P = First(*G);
    *Pn = AlokNodeGraph(X);
    if (P == NodeUndef) {
        First(*G) = *Pn;
    } else {
        while (Next(P) != NodeUndef) {
            P = Next(P);
        }
        Next(P) = *Pn;
    }
       
}
void InsertEdge(Graph* G, int prec, int succ)
{
    /* Kamus Lokal */
    adrNode PPrec, PSucc;
    /* Algoritma */
    if(SearchNode(*G, prec) == NodeUndef) {
        InsertNode(G, prec, &PPrec);
    } else {
        PPrec = SearchNode(*G, prec);
    }

    if(SearchNode(*G,succ) == NodeUndef)
    {
        InsertNode(G, succ, &PSucc);
    } else {
        PSucc = SearchNode(*G, succ);
    }

    if (SearchEdge(*G, NoBangunan(PPrec), NoBangunan(PSucc)) == NodeUndef) {
        adrSuccNode Pn = Trail(PPrec);
        if (Pn == NodeUndef) {
            Trail(PPrec) = AlokSuccNode(PSucc);
        } else {
            while (Next(Pn) != NodeUndef) {
                Pn = Next(Pn);
            }
            Next(Pn) = AlokSuccNode(PSucc);
        }
    }
}

void GenerateHubunganBangunan(Graph *G, MATRIKSInt Hubungan)
/* I.S. G terdefinisi */
/* F.S. Graph berisi keterhubungan setiap NoBangunan terbentuk dari InfoKeterhubungan */
{
    /* Kamus Lokal */
    int i, j;
    /* Algoritma */
    for (i = GetFirstIdxBrs(Hubungan); i <= GetLastIdxBrs(Hubungan), i++) {
        for (j = GetFirstIdxBrs(Hubungan); j <= GetLastIdxKol(Hubungan); j++) {
            if (ElmtMat(Hubungan, i, j) == 1) {
                InsertEdge(G, i, j);
            }
        }
    }
}