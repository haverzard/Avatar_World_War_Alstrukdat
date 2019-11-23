/* File: point.c */
/* Tanggal: 28 Agustus 2019 */
/* *** Realisasi ABSTRACT DATA TYPE POINT *** */


#include <stdio.h>
#include "boolean.h"
#include "point.h"

POINT MakePOINT(int x, int y) {
/* Membentuk sebuah POINT dari komponen-komponennya */
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
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
	/* Algoritma */
	scanf("%d ", &(*P).X);
	scanf("%d", &(*P).Y);
}

void TulisPOINT(POINT P) {
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
	/* Algoritma */
	printf("(%d,%d)", P.X, P.Y);
}

boolean EQ_POINT(POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
	/* Algoritma */
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}


boolean NEQ_POINT(POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
	/* Algoritma */
	return (!EQ_POINT(P1,P2));
}