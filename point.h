/* File: point.h */
/* *** Definisi ABSTRACT DATA TYPE POINT TERMODIFIKASI *** */
/* Absis dan Ordinat selalu positif */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

/*  Kamus Umum */
#define AbsisUndef -9999
/* Indeks minimum array */
#define OrdinatUndef -9999
/* Indeks tak terdefinisi*/

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

void SetAbsis(POINT *P, int newX);
/* I.S. POINT P dan newX terdefinisi */
/* F.S. Mengeset Nilai Absis(P) = newX */

void SetOrdinat(POINT *P, int newY);
/* I.S. POINT P dan newY terdefinisi */
/* F.S. Mengeset Nilai Ordinat(P) = newY */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P);
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ_POINT (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ_POINT (POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

#endif