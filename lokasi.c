/* ADT Lokasi */
/*  */

#include <stdio.h>
#include "lokasi.h"
#include "bangunan.h"
#include "boolean.h"
#include "point.h"

boolean EQ_LOKASI (Loc A, Loc B) {
	/* Untuk mendapat EQLoc harus cek semua properti atau cukup cek Jenis bangunan dan Koordinat aja ?????? PENTING BUAT SEARCH */
	return isEQBangunan(Bangunan(A), Bangunan(B)) && EQ_POINT(Koordinat(A), Koordinat(B)); 
}

boolean LOKASI_UNDEF(Loc A) {
	return (Jenis(Bangunan(A)) == JenisUndef) && !(Kuadran(Koordinat(A)) == 1);
}

void MakeUndefLoc(Loc * A) {
	InitUndef(&Bangunan(*A));
	Absis(Koordinat(*A)) = AbsisUndef;
	Ordinat(Koordinat(*A)) = OrdinatUndef;
}