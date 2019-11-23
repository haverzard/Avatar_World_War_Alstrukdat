/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen char ********** */

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"
#include "pcolor.h"
#include "arraydinpos.h"
#include "player.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	/* Kamus Lokal */
	int i, j;
	
	/* Algoritma */
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	for (i = BrsMin; i <= NB; i++) {
		for (j = KolMin; j <= NK; j++) {
			ElmtMat(*M,i,j) = ' ';
		}
	}
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid_Matriks (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	/* Algoritma */
	return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	/* Algoritma */
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	/* Algoritma */
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	/* Algoritma */
	return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	/* Algoritma */
	return NKolEff(M);
}

boolean IsIdxEff_Matriks (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	/* Algoritma */
	return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}

/* ********** KELOMPOK BACA/TULIS ********** */
void TulisMATRIKSPETA (MATRIKS M, Player P1, Player P2) 
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
{
	/* Kamus Lokal */
	int i, j;
	
	/* Algoritma */
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)+2; j++) {
		printf("=");
	}
	printf("\n");
	printf("=");
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)/2-5; j++) {
		printf(" ");
	}
	printf("PETA ARENA");
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)-5-GetLastIdxKol(M)/2; j++) {
		printf(" ");
	}
	printf("=");
	printf("\n");
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)+2; j++) {
		printf("=");
	}
	printf("\n");
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)+2; j++) {
		printf("*");
	}
	printf("\n");
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		printf("*");
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			if (ElmtMat(M,i,j) != ' ' && CheckOwnerByPosition(TB, i, j) == 1) {
				printByColorNum(Color(P1), ElmtMat(M,i,j));
			} else if (ElmtMat(M,i,j) != ' ' && CheckOwnerByPosition(TB, i, j) == 2)  {
				printByColorNum(Color(P2), ElmtMat(M,i,j));
			} else {
				printf("%c", ElmtMat(M,i,j));
			}
		}
		printf("*\n");
	}
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)+2; j++) {
		printf("*");
	}
	printf("\n");
}
