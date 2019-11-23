/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_INT_H
#define MATRIKS_INT_H

#include "../boolean/boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMinMatInt 1
#define BrsMaxMatInt 20
#define KolMinMatInt 1
#define KolMaxMatInt 30

typedef int indeksMatInt; /* indeks baris, kolom */
typedef int ElTypeMatInt;
typedef struct {
    ElTypeMatInt Mem[BrsMaxMatInt+1][KolMaxMatInt+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS_INT;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

extern MATRIKS_INT Hubungan;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS_INT (int NB, int NK, MATRIKS_INT * M);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEffMatInt(M) (M).NBrsEff
#define NKolEffMatInt(M) (M).NKolEff
#define ElmtMatInt(M,i,j) (M).Mem[(i)][(j)]
/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeksMatInt GetFirstIdxBrsMatInt (MATRIKS_INT M);
/* Mengirimkan indeks baris terkecil M */
indeksMatInt GetFirstIdxKolMatInt (MATRIKS_INT M);
/* Mengirimkan indeks kolom terkecil M */
indeksMatInt GetLastIdxBrsMatInt (MATRIKS_INT M);
/* Mengirimkan indeks baris terbesar M */
indeksMatInt GetLastIdxKolMatInt (MATRIKS_INT M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEffMatInt (MATRIKS_INT M, indeksMatInt i, indeksMatInt j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKS_INT (MATRIKS_INT M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

#endif