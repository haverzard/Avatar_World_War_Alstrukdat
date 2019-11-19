/* File : graph.h */
/* Definisi ADT Graph */
/* Menggunakan representai multilist */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"

#define NodeUndef NULL

typedef struct tNodeGraph* adrNode;
typedef struct tSuccNode* adrSuccNode;

typedef struct tNodeGraph {
    int NoBangunan;
    adrSuccNode Trail;
    adrNode Next;
} NodeGraph;

typedef struct tSuccNode {
    adrNode Succ;
    adrSuccNode Next;
} SuccNode;

typedef struct {
    adrNode First;
} Graph;

//Selektor
#define First(G) (G).First
#define NoBangunan(Pn) (Pn)->NoBangunan
#define Trail(Pn) (Pn)->Trail
#define Asal(Pn) (Pn)->asal
#define Tujuan(Pn) (Pn)->tujuan
#define Succ(Pn) (Pn)->Succ
#define NPred(Pn) (Pn)->NPred
#define Next(Pn) (Pn)->Next

/****************** PEMBUATAN GRAPH ******************/
void CreateGraph(int X, Graph* G);
/* I.S. G sembarang */
/* F.S. Terbentuk graph G */

/****************** Manajemen Memori ******************/
adrNode AlokNodeGraph(int X);
/* Mengirimkan address hasil alokasi sebuah node */
/* Jika alokasi berhasil, maka address tidak nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNodeGraph(adrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
adrSuccNode AlokSuccNode(adrNode Pn);
/* Mengirimkan address hasil alokasi sebuah SuccNode */
/* Jika alokasi berhasil, maka address tidak nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokSuccNode(adrSuccNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/*** PENCARIAN ELEMEN ***/
adrNode SearchNode(Graph G, int X);
/* Mengembalikan adrNode dari graph G dengan NoBangunan bernilai X */
adrSuccNode SearchEdge(Graph G, int prec, int succ);
/* Mengembalikan adrSuccNode dari NoBangunan prec dengan NoBangunan bernilai succ */

/*** PENAMBAHAN ELEMEN ***/
void InsertNode(Graph* G, int X, adrNode* Pn);
/* I.S. G terdefinisi */
/* F.S. adrNode Pn terdapat pada Graph G dengan infotype X */
void InsertEdge(Graph* G, int prec, int succ);
/* I.S. G terdefinisi */
/* F.S. adrNode Pn terdapat pada Graph G dengan infotype X */

void GenerateHubunganBangunan(Graph *G, MATRIKSInt Hubungan);
/* I.S. G terdefinisi */
/* F.S. Graph berisi keterhubungan setiap NoBangunan terbentuk dari InfoKeterhubungan */

#endif // GRAPH_H