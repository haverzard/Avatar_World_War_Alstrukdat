/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen char ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"
#include "player.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 20
#define KolMin 1
#define KolMax 30

typedef int indeks; /* indeks baris, kolom */
typedef char ElType_Matriks;
typedef struct {
    ElType_Matriks Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

extern MATRIKS Peta;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define ElmtMat(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid_Matriks (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff_Matriks (MATRIKS M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKSPETA (MATRIKS M, Player P1, Player P2);
/* I.S. M, P1, P2 terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 10x15 (ingat di akhir tiap baris, tidak ada spasi)
=================
=  PETA ARENA   =
=================
*****************
*        V   T C*
*  C            *
*T      V     C *
*    F          *
*           F   *
*  T            *
*         T     *
* C   V        T*
*            C  *
*C T            *
*****************
*/

#endif