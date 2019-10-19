/* ADT Mesin Data */
/* Membaca data file eksternal dengan memanfaatkan mesin karakter*/

#include <stdio.h>
#include "mesindata.h"
#include "boolean.h"
#include "mesinkar.h"
#include "matriks.h"
#include "lokasi.h"

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

void INFOBANGUNAN() {
	/* Kamus Lokal */
	ADV();
	ADV();
	NEXTDATA();
}

void LOKASIBANGUNAN(MATRIKS *Peta, Loc *P) {
	/* Kamus Lokal */
	int X, Y;
	char jenis;

	/* Algoritma */
	jenis = CC;
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
	Elmt(*Peta,Y,X) = jenis;
	NEXTDATA();
}