/* ********** Implementasi Body TYPE MATRIKS dengan indeks dan elemen integer ********** */
#include <stdio.h>
#include "matriksint.h"

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS_INT (int NB, int NK, MATRIKS_INT * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEffMatInt(*M) = NB;
    NKolEffMatInt(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMinMatInt && i <= BrsMaxMatInt)  &&(j >= KolMinMatInt && j <= KolMaxMatInt));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeksMatInt GetFirstIdxBrsMatInt (MATRIKS_INT M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMinMatInt;
}
indeksMatInt GetFirstIdxKolMatInt (MATRIKS_INT M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMinMatInt;
}
indeksMatInt GetLastIdxBrsMatInt (MATRIKS_INT M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEffMatInt(M);
}
indeksMatInt GetLastIdxKolMatInt (MATRIKS_INT M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEffMatInt(M);
}
boolean IsIdxEffMatInt (MATRIKS_INT M, indeksMatInt i, indeksMatInt j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i >= BrsMinMatInt && i <= NBrsEffMatInt(M))  &&(j >= KolMinMatInt && j <= NKolEffMatInt(M)));
}

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKS_INT (MATRIKS_INT M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /* KAMUS LOKAL */
    indeksMatInt i, j;
    /* ALGORITMA */
    for (i = GetFirstIdxBrsMatInt(M); i < GetLastIdxBrsMatInt(M); i++) {
		for (j = GetFirstIdxKolMatInt(M); j < GetLastIdxKolMatInt(M); j++) {
            printf("%d ", ElmtMatInt(M, i, j));
        }
        printf("%d", ElmtMatInt(M, i, j));
        printf("\n");
    }
    i = GetLastIdxBrsMatInt(M);
    for (j = GetFirstIdxKolMatInt(M); j < GetLastIdxKolMatInt(M); j++) {
        printf("%d ", ElmtMatInt(M, i, j));
    }
    printf("%d", ElmtMatInt(M, i, j));
}
