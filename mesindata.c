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
	return (int) x-48;
}

void IgnoreBlank_DATA()
{
    /* Algoritma */
	while (CC == BLANK && CC != ENDLINE) {
		ADV();
	}
}

void STARTDATA() {
	/* Algoritma */
	START();
	IgnoreBlank_DATA();
}

void NEXTDATA() {
	/* Algoritma */
	ADV(); // ENDLINE
	ADV(); // ENDLINE2
	IgnoreBlank_DATA();
}

void INFOPETA(MATRIKS *Peta) {
	/* Kamus Lokal */
	int NB, NK;

	/* Algoritma */
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

void INFOBANGUNAN(TabBangunan *TB) {
	/* Kamus Lokal */
	int size;

	/* Algoritma */
	size = 0;
	while (CC != ENDLINE && CC != BLANK) {
		size = size * 10 + KarakterToInt(CC);
		ADV();
	}
	MakeEmpty(TB, size);
	NEXTDATA();
}

void LOKASIBANGUNAN(MATRIKS *Peta, TabBangunan *P, int i) {
	/* Kamus Lokal */
	int X, Y;

	/* Algoritma */
	InitBangunan(&ElmtArr(*P,i), CC);
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
	Koordinat(ElmtArr(*P,i)) = MakePOINT(Y, X);
	ElmtMat(*Peta,Y,X) = Jenis(ElmtArr(*P,i));
	NEXTDATA();
}

void HUBUNGANBANGUNAN (MATRIKS_INT * Hubungan) {
	/* Kamus Lokal */ 
	int i, j;
	/* Algoritma */
	IgnoreBlank_DATA();
	MakeMATRIKS_INT(20, 30, Hubungan);
	i = GetFirstIdxBrsMatInt(*Hubungan);
	while (CC != MARK) {
		j = GetFirstIdxKolMatInt(*Hubungan);
		while (CC != ENDLINE) {
			if (CC != BLANK) {
				ElmtMatInt(*Hubungan, i, j) = KarakterToInt(CC);
				j++;
			} 
			ADV();
		}
		i++;
		printf("\n");
		NEXTDATA();
	}
	NBrsEff(*Hubungan) = i-1;
	NKolEff(*Hubungan) = j-1;
}


// !feof(pita)