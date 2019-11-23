/* ADT Mesin Data */
/* Membaca data file eksternal dengan memanfaatkan mesin karakter*/

#include <stdio.h>
#include "mesindata.h"
#include "boolean.h"
#include "mesinkar.h"
#include "matriks.h"
#include "matriksint.h"
#include "arraydinpos.h"
#include "bangunan.h"
#include "point.h"

char Baris[NMax_DATA+1];

int KarakterToInt(char x) {
/*	KarakterToInt mengonversi tipe data x menjadi integer	*/
	return (int) x-48;
}

void IgnoreBlank_DATA()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = ENDLINE */
{
    /* Algoritma */
	while (CC == BLANK && CC != ENDLINE) {
		ADV();
	}
}

void STARTDATA(char *filename) 
/* Memulai pembacaan data
   I.S. : File data belum diakses
   F.S. : Pembacaan sudah bisa dimulai dan CC ≠ BLANK */
{
	/* Algoritma */
	START(filename);
	IgnoreBlank_DATA();
}

void NEXTDATA() 
/*	I.S. CC mungkin berisi ENDLINE atau BLANK
	F.S. CC adalah karakter yang akan dibaca selanjutnya
*/
{
	/* Algoritma */
	ADV(); // ENDLINE
	ADV(); // ENDLINE2
	IgnoreBlank_DATA();
}

void INFOPETA(MATRIKS *Peta)
/* Mengambil informasi ukuran peta dari data
   I.S. : Peta belum terdefinisi
   F.S. : Peta terdefinisi dengan ukuran dari data */
 {
	/* Kamus Lokal */
	int NB, NK;

	/* Algoritma */
	IgnoreBlank_DATA();
	NB = 0;
	NK = 0;
	while (CC != BLANK) {
		NB = NB * 10 + KarakterToInt(CC);
		ADV();
	}
	IgnoreBlank_DATA();
	while (CC != ENDLINE && CC != BLANK) {
		NK = NK * 10 + KarakterToInt(CC);
		ADV();
	}
	MakeMATRIKS(NB,NK,Peta);
	NEXTDATA();
}

void INFOBANGUNAN(TabBangunan *TB) 
/*	I.S. TB belum terdefinisi
	F.S. TB terdefinisi dengan ukuran sesuai konfigurasi dari file eksternal
*/
{
	/* Kamus Lokal */
	int size;

	/* Algoritma */
	IgnoreBlank_DATA();
	size = 0;
	while (CC != ENDLINE && CC != BLANK) {
		size = size * 10 + KarakterToInt(CC);
		ADV();
	}
	MakeEmpty(TB, size);
	NEXTDATA();
}

void LOKASIBANGUNAN(MATRIKS *Peta, TabBangunan *TB) 
/*	I.S. TB sembarang 
	F.S. Terbentuk TabBangunan TB sesuai konfigurasi dari file eksternal
*/
{
	/* Kamus Lokal */
	int X, Y, i;

	/* Algoritma */
	for (i = 1; i <= MaxElArr(*TB); i++) {
		InitBangunan(&ElmtArr(*TB,i), CC);
		ADV();
		IgnoreBlank_DATA();
		X = 0;
		Y = 0;
		while (CC != BLANK) {
			Y = Y * 10 + KarakterToInt(CC);
			ADV();
		}
		IgnoreBlank_DATA();
		while (CC != ENDLINE) {
			X = X * 10 + KarakterToInt(CC);
			ADV();
		}
		Koordinat(ElmtArr(*TB,i)) = MakePOINT(Y, X);
		ElmtMat(*Peta,Y,X) = Jenis(ElmtArr(*TB,i));
		NEXTDATA();
	}
}

void HUBUNGANBANGUNAN (MATRIKS_INT * Hubungan, int BanyakBangunan) {
/*	I.S. Matriks Hubungan sembarang dan BanyakHubungan terdefinisi 
	F.S. Terbentuk Matriks Hubungan sesuai konfigurasi dari file eksternal	*/
	/* Kamus Lokal */ 
	int i, j;
	IgnoreBlank_DATA();
	MakeMATRIKS_INT(BanyakBangunan,BanyakBangunan, Hubungan);
	i = GetFirstIdxBrsMatInt(*Hubungan);
	while (i <= BanyakBangunan) {
		j = GetFirstIdxKolMatInt(*Hubungan);
		while (j <= BanyakBangunan) {
			if (CC != BLANK) {
				ElmtMatInt(*Hubungan, i, j) = KarakterToInt(CC);
				j++;
			} 
			ADV();
		}
		i++;
		NEXTDATA();
	}
	NBrsEff(*Hubungan) = i-1;
	NKolEff(*Hubungan) = j-1;
}

void MOREINFOBANGUNAN(TabBangunan *TB)
/*	I.S. TB terdefinisi
	F.S. Informasi Bangunan TB di-load dari file eksternal
*/
{
	/* Kamus Lokal */
	int i, A;

	/* Algoritma */
	for (i = 1; i <= MaxElArr(*TB); i++) {
		ADV();
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		Kepemilikan(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		JumlahPasukan(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		Level(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		A(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		M(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		P(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		AttackAvai(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != ENDLINE) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		MoveAvai(ElmtArr(*TB,i)) = A;
		NEXTDATA();
	}
}