/* ADT Lokasi */
/*  */

#include <stdio.h>
#include "lokasi.h"
#include "bangunan.h"
#include "boolean.h"
#include "point.h"
#include "bangunan.h"

boolean EQ_LOKASI (Loc A, Loc B) {
	/* Untuk mendapat EQLoc harus cek semua properti atau cukup cek Jenis bangunan dan Koordinat aja ?????? PENTING BUAT SEARCH */
	return isEQBangunan(Bangunan(A), Bangunan(B)) && EQ_POINT(Koordinat(A), Koordinat(B)); 
}

void MakeUndefLoc(Loc * A) {
	InitUndef(&Bangunan(*A));
	Absis(Koordinat(*A)) = AbsisUndef;
	Ordinat(Koordinat(*A)) = OrdinatUndef;
	return EQ_POINT(Koordinat(A), Koordinat(B)); 
}

boolean LOKASI_UNDEF(Loc A) {
	return !(IsOrigin(Koordinat(A)) || IsOnSbX(Koordinat(A)) || IsOnSbY(Koordinat(A)) || (Kuadran(Koordinat(A)) == 1));
}

void PrintLokasi(Loc A) {
	Bangunan X = Building(A);
	if (Jenis(X) == 'C') {
		printf("Castle ");
	} else  if (Jenis(X) == 'T') {
		printf("Tower ");
	} else  if (Jenis(X) == 'F') {
		printf("Fort ");
	} else  if (Jenis(X) == 'V') {
		printf("Village ");
	}
	TulisPOINT(Koordinat(A));
	printf(" %d lv.%d\n", JumlahPasukan(X), Level(X));
}