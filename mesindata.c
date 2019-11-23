/* ADT Mesin Data */
/* Membaca data file eksternal dengan memanfaatkan mesin karakter*/

#include <stdio.h>
#include <stdlib.h>
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

void ERROR() {
	printf("File eksternal tidak sesuai spesifikasi! Load file gagal!\n");
	exit(1);
}

void IgnoreBlank_DATA()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = ENDLINE */
{
    /* Algoritma */
	while (CC == BLANK && CC != ENDLINE && CC != ENDLINE2 && !feof(pita)) {
		ADV();
	}
}

void STARTDATA(char *filename) 
/* Memulai pembacaan data
   I.S. : File data belum diakses
   F.S. : Pembacaan sudah bisa dimulai dan CC ≠ BLANK */
{
	/* Algoritma */
	if (fopen(filename,"r")) {
		START(filename);
		IgnoreBlank_DATA();
	} else {
		ERROR();
	}
}

void NEXTDATA() 
/*	I.S. CC mungkin berisi ENDLINE atau BLANK
	F.S. CC adalah karakter yang akan dibaca selanjutnya
*/
{
	/* Algoritma */
	if (CC == ENDLINE) {
		ADV(); // ENDLINE
	}
	if (CC == ENDLINE2) {
		ADV(); // ENDLINE2
	}
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
	while (CC != BLANK && !feof(pita)) {
		NB = NB * 10 + KarakterToInt(CC);
		ADV();
	}
	IgnoreBlank_DATA();
	while (CC != ENDLINE && CC != ENDLINE2 && CC != BLANK && !feof(pita)) {
		NK = NK * 10 + KarakterToInt(CC);
		ADV();
	}
	if (NB > 0 && NB <= 20 && NK > 0 && NK <= 30 && !feof(pita)) {
		MakeMATRIKS(NB,NK,Peta);
	} else {
		ERROR();
	}
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
	while (CC != ENDLINE && CC != ENDLINE2 && CC != BLANK && !feof(pita)) {
		size = size * 10 + KarakterToInt(CC);
		ADV();
	}
	if (size <= NBrsEff(Peta)*NKolEff(Peta) && !feof(pita)) {
		MakeEmpty(TB, size);
	} else {
		ERROR();
	}
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
		while (CC != BLANK && !feof(pita)) {
			Y = Y * 10 + KarakterToInt(CC);
			ADV();
		}
		IgnoreBlank_DATA();
		while (CC != ENDLINE && CC != ENDLINE2 && !feof(pita)) {
			X = X * 10 + KarakterToInt(CC);
			ADV();
		}
		if (X > 0 && X <= NKolEff(*Peta) && Y > 0 && Y <= NBrsEff(*Peta) && ElmtMat(*Peta,Y,X) == ' ' && !feof(pita)) {
			Koordinat(ElmtArr(*TB,i)) = MakePOINT(Y, X);
			ElmtMat(*Peta,Y,X) = Jenis(ElmtArr(*TB,i));
			NEXTDATA();
		} else {
			ERROR();
		}
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
	while (i <= BanyakBangunan && !feof(pita)) {
		j = GetFirstIdxKolMatInt(*Hubungan);
		while (j <= BanyakBangunan && !feof(pita)) {
			if (CC != BLANK) {
				if (CC == '1' || CC == '0') {
					ElmtMatInt(*Hubungan, i, j) = KarakterToInt(CC);
					j++;
				} else {
					ERROR();
				}
			} 
			ADV();
		}
		i++;
		NEXTDATA();
	}
	if (i == BanyakBangunan+1 && j == BanyakBangunan+1) {
		NBrsEff(*Hubungan) = i-1;
		NKolEff(*Hubungan) = j-1;
	} else {
		ERROR();
	}
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
		while (CC != BLANK && !feof(pita)) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		if (feof(pita) || A != 2 || A != 1) { ERROR(); }
		Kepemilikan(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK && !feof(pita)) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		if (feof(pita) || A < 0) { ERROR(); }
		JumlahPasukan(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK && !feof(pita)) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		if (feof(pita) || A < 0 || A > 4) { ERROR(); }
		Level(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK && !feof(pita)) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		if (feof(pita) || A < 0) { ERROR(); }
		A(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK && !feof(pita)) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		if (feof(pita) || A < 0) { ERROR(); }
		M(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK && !feof(pita)) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		if (feof(pita) || A != true || A != false) { ERROR(); }
		P(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != BLANK && !feof(pita)) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		if (feof(pita) || A != true || A != false) { ERROR(); }
		AttackAvai(ElmtArr(*TB,i)) = A;
		IgnoreBlank_DATA();
		A = 0;
		while (CC != ENDLINE && CC != ENDLINE2 && !feof(pita)) {
			A = A * 10 + KarakterToInt(CC);
			ADV();
		}
		if (feof(pita) || A != true || A != false) { ERROR(); }
		MoveAvai(ElmtArr(*TB,i)) = A;
		NEXTDATA();
	}
}

void INFOTURN(int *turn) 
/*  I.S. turn sembarang
    F.S. turn terdefinisi
*/
{
	/* Algoritma */
	*turn = 0;
	while (CC != ENDLINE && CC != ENDLINE2 && !feof(pita)) {
		*turn = *turn * 10 + KarakterToInt(CC);
		ADV();
	}
	if (feof(pita) || *turn != 2 || *turn != 1) { ERROR(); }
	NEXTDATA();
}