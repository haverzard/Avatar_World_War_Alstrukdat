/* ADT Lokasi */
/*  */

#ifndef LOKASI_H
#define LOKASI_H

#include "boolean.h"
#include "point.h"

typedef struct {
	char Jenis;
	POINT Koordinat;
} Loc;

#define Jenis(X) (X).Jenis
#define Koordinat(X) (X).Koordinat

boolean EQ_LOKASI(Loc A, Loc B);

boolean LOKASI_UNDEF(Loc A);

#endif