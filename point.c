/* File: point.c */
/* Tanggal: 28 Agustus 2019 */
/* *** Realisasi ABSTRACT DATA TYPE POINT *** */


#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include <math.h>

#define toDegrees(Sudut) Sudut*180/M_PI
#define toRads(Sudut) Sudut*M_PI/180

POINT MakePOINT(int x, int y) {
	/* Kamus Lokal */
	 POINT P;
	 
	/* Algoritma */
	 P.X = x;
	 P.Y = y;
	 return P;
}

void FixZero(POINT *P) {
	if ((int)(Absis(*P)*100) == 0) { GeserKeSbY(P); }
	if ((int)(Ordinat(*P)*100) == 0) { GeserKeSbX(P); }
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

POINT NextX(POINT P) {
	/* Algoritma */
	P.X += 1;
	return P;
}

POINT NextY(POINT P) {
	/* Algoritma */
	P.Y += 1;
	return P;
}

POINT PlusDelta(POINT P, int deltaX, int deltaY) {
	/* Algoritma */
	P.X += deltaX;
	P.Y += deltaY;
	return P;
}

POINT MirrorOf(POINT P, boolean SbX) {
	/* Algoritma */
	if (SbX) {
		P.Y *= -1;
	} else {
		P.X *= -1;
	}
	return P;
}

int Jarak0(POINT P) {
	/* Algoritma */
	return (pow(pow(P.X,2)+pow(P.Y,2),0.5));
}

int Panjang(POINT P1, POINT P2) {
	/* Algoritma */
	return (pow(pow(P1.X-P2.X,2)+pow(P1.Y-P2.Y,2),0.5));
}

void Geser(POINT *P, int deltaX, int deltaY) {
	/* Algoritma */
	(*P).X += deltaX;
	(*P).Y += deltaY;
}

void GeserKeSbX(POINT *P) {
	/* Algoritma */
	SetOrdinat(P, 0);
}

void GeserKeSbY(POINT *P) {
	/* Algoritma */
	SetAbsis(P, 0);
}

void Mirror(POINT *P, boolean SbX) {
	/* Algoritma */
	if (SbX) {
		(*P).Y *= -1;
	} else {
		(*P).X *= -1;
	}
}