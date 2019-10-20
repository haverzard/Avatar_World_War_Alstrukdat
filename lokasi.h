/* ADT Lokasi */
/* Berisi definisi dan semua primitif Lokasi */
/* Lokasi Koordinat selalu positif */

#ifndef LOKASI_H
#define LOKASI_H

#include "boolean.h"
#include "point.h"
#include "bangunan.h"

typedef struct {
	Bangunan Bangunan;
	POINT Koordinat;
} Loc;

#define Bangunan(X) (X).Bangunan
#define Koordinat(X) (X).Koordinat

boolean EQ_LOKASI(Loc A, Loc B);
boolean LOKASI_UNDEF(Loc A);

void MakeUndefLoc(Loc * A);

#endif