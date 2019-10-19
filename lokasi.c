/* ADT Lokasi */
/*  */

#include <stdio.h>
#include "lokasi.h"
#include "boolean.h"
#include "point.h"

boolean EQ_LOKASI (Loc A, Loc B) {
	return (Jenis(A) == Jenis(B)) && EQ_POINT(Koordinat(A), Koordinat(B)); 
}

boolean LOKASI_UNDEF(Loc A) {
	return (Jenis(A) == 'A') && !(IsOrigin(Koordinat(A)) || IsOnSbX(Koordinat(A)) || IsOnSbY(Koordinat(A)) || (Kuadran(Koordinat(A)) == 1));
}