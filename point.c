/* File: point.c */
/* Tanggal: 28 Agustus 2019 */
/* *** Realisasi ABSTRACT DATA TYPE POINT *** */


#include <stdio.h>
#include "boolean.h"
#include "point.h"

POINT MakePOINT(int x, int y) {
	/* Kamus Lokal */
	 POINT P;
	 
	/* Algoritma */
	 P.X = x;
	 P.Y = y;
	 return P;
}

void SetAbsis(POINT *P, int newX) {
	/* Algoritma */
	(*P).X = newX;
}

void SetOrdinat(POINT *P, int newY) {
	/* Algoritma */
	(*P).Y = newY;
}

void BacaPOINT(POINT *P) {
	/* Algoritma */
	scanf("%d ", &(*P).X);
	scanf("%d", &(*P).Y);
}

void TulisPOINT(POINT P) {
	/* Algoritma */
	printf("(%d,%d)", P.X, P.Y);
}

boolean EQ_POINT(POINT P1, POINT P2) {
	/* Algoritma */
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}


boolean NEQ_POINT(POINT P1, POINT P2) {
	/* Algoritma */
	return (!EQ_POINT(P1,P2));
}

boolean IsOrigin(POINT P) {
	/* Algoritma */
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX(POINT P) {
	/* Algoritma */
	return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P) {
	/* Algoritma */
	return (Absis(P) == 0);
}

int Kuadran(POINT P) {
	/* Algoritma */
	if (Absis(P) > 0) {
		if (Ordinat(P) > 0) {
			return 1;
		} else {
			return 4;
		}
	} else {
		if (Ordinat(P) > 0) {
			return 2;
		} else {
			return 3;
		}
	}
}