/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen char ********** */

#include <stdio.h>
#include "../matrikskar/matriks.h"
#include "../boolean/boolean.h"
#include "../pcolor/pcolor.h"
#include "../arraydinpos/arraydinpos.h"
#include "../player/player.h"

/* Variabel Global */
MATRIKS Peta;

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
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOO================================OOOOOOOOOO
OOOOOOOOOO=          PETA ARENA          =OOOOOOOOOO
OOOOOOOOOO================================OOOOOOOOOO
OOOOOOOOOO********************************OOOOOOOOOO
OOOOOOOOOO********        V   T C*********OOOOOOOOOO
OOOOOOOOOO********  C            *********OOOOOOOOOO
OOOOOOOOOO********T      V     C *********OOOOOOOOOO
OOOOOOOOOO********    F          *********OOOOOOOOOO
OOOOOOOOOO********           F   *********OOOOOOOOOO
OOOOOOOOOO********  T            *********OOOOOOOOOO
OOOOOOOOOO********         T     *********OOOOOOOOOO
OOOOOOOOOO******** C   V        T*********OOOOOOOOOO
OOOOOOOOOO********            C  *********OOOOOOOOOO
OOOOOOOOOO********C T            *********OOOOOOOOOO
OOOOOOOOOO********************************OOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
*/
{
	/* Kamus Lokal */
	int i, j, k;
	
	/* Algoritma */
	for (i = 1; i <= 3; i++) {
		for (j = GetFirstIdxKol(M); j <= 20+KolMax+2; j++) {
			printf("O");
		}
		printf("\n");
	}
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	for (j = GetFirstIdxKol(M); j <= KolMax+2; j++) {
		printf("=");
	}
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	printf("\n");
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	printf("=");
	for (j = GetFirstIdxKol(M); j <= KolMax/2-5; j++) {
		printf(" ");
	}
	printf("PETA ARENA");
	for (j = GetFirstIdxKol(M); j <= KolMax-5-KolMax/2; j++) {
		printf(" ");
	}
	printf("=");
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	printf("\n");
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	for (j = GetFirstIdxKol(M); j <= KolMax+2; j++) {
		printf("=");
	}
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	printf("\n");
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	for (j = GetFirstIdxKol(M); j <= KolMax+2; j++) {
		printf("*");
	}
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	printf("\n");
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		for (k = GetFirstIdxKol(M); k <= 10; k++) {
			printf("O");
		}
		for (k = GetFirstIdxKol(M); k <= (KolMax-GetLastIdxKol(M)+2)/2; k++) {
			printf("*");
		}
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			if (ElmtMat(M,i,j) != ' ' && CheckOwnerByPosition(TB, i, j) == 1) {
				printByColorNum(Color(P1), ElmtMat(M,i,j));
			} else if (ElmtMat(M,i,j) != ' ' && CheckOwnerByPosition(TB, i, j) == 2)  {
				printByColorNum(Color(P2), ElmtMat(M,i,j));
			} else {
				printf("%c", ElmtMat(M,i,j));
			}
		}
		for (k = GetFirstIdxKol(M); k <= KolMax-GetLastIdxKol(M)+2-(KolMax-GetLastIdxKol(M)+2)/2; k++) {
			printf("*");
		}
		for (k = GetFirstIdxKol(M); k <= 10; k++) {
			printf("O");
		}
		printf("\n");
	}
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	for (j = GetFirstIdxKol(M); j <= KolMax+2; j++) {
		printf("*");
	}
	for (j = GetFirstIdxKol(M); j <= 10; j++) {
		printf("O");
	}
	printf("\n");
	for (i = 1; i <= 3; i++) {
		for (j = GetFirstIdxKol(M); j <= 20+KolMax+2; j++) {
			printf("O");
		}
		printf("\n");
	}
}
