/* ADT Bangunan */
/*  */

#include <stdio.h>
#include "boolean.h"
#include "bangunan.h"
#include "point.h"

Bangunan BangunanUndef;

boolean IsBangunanValid(Bangunan X) {
	return Jenis(X) != JenisUndef;
}

boolean EQ_Bangunan(Bangunan X1, Bangunan X2) {
	return Jenis(X1) == Jenis(X2) && EQ_POINT(Koordinat(X1),Koordinat(X2)) && Kepemilikan(X1) == Kepemilikan(X2) && JumlahPasukan(X1) == JumlahPasukan(X2) && Level(X1) == Level(X2) && A(X1) == A(X2) && M(X1) == M(X2) && P(X1) == P(X2) && U(X1) == U(X2);
}

void InitCastle(Bangunan *X) {
	Jenis(*X) = 'C';
	Kepemilikan(*X) = 0;
	Jenis(*X) = 'C';
	JumlahPasukan(*X) = 40;
	Level(*X) = 1;
	A(*X) = 10;
	M(*X) = 40;
	P(*X) = false;
}

void InitTower(Bangunan *X) {
	Jenis(*X) = 'T';
	Kepemilikan(*X) = 0;
	Jenis(*X) = 'T';
	JumlahPasukan(*X) = 30;
	Level(*X) = 1;
	A(*X) = 5;
	M(*X) = 20;
	P(*X) = true;
}

void InitFort(Bangunan *X) {
	Jenis(*X) = 'F';
	Kepemilikan(*X) = 0;
	Jenis(*X) = 'F';
	JumlahPasukan(*X) = 80;
	Level(*X) = 1;
	A(*X) = 10;
	M(*X) = 20;
	P(*X) = false;
}

void InitVillage(Bangunan *X) {
	Jenis(*X) = 'V';
	Kepemilikan(*X) = 0;
	Jenis(*X) = 'V';
	JumlahPasukan(*X) = 20;
	Level(*X) = 1;
	A(*X) = 5;
	M(*X) = 20;
	P(*X) = false;
}

void InitBangunan(Bangunan *X, char jenisBangunan) {
	if (jenisBangunan == 'C') {
		InitCastle(X);
	} else if (jenisBangunan == 'T') {
		InitTower(X);
	} else if (jenisBangunan == 'F') {
		InitFort(X);
	} else if (jenisBangunan == 'V') {
		InitVillage(X);
	} else {
		printf("BANGUNAN TIDAK VALID! ULANG!");
	}
}

void UpdateBangunan(Bangunan *X) {
	if (JumlahPasukan(*X) < M(*X)) {
		JumlahPasukan(*X) += A(*X);
	}
}

void SerangBangunan(Bangunan *X, int N) {
	if (P(*X)) {
		JumlahPasukan(*X) -= (3*N)/4;
	} else {
		JumlahPasukan(*X) -= N;
	}
}

void LevelUpBangunan(Bangunan *X) {
	JumlahPasukan(*X) -= M(*X)/2;
	Level(*X) += 1;
	if (Jenis(*X) == 'C') {
		if (Level(*X) == 2) {
			A(*X) = 15;
			M(*X) = 60;
		} else if (Level(*X) == 3) {
			A(*X) = 20;
			M(*X) = 80;
		} else if (Level(*X) == 4) {
			A(*X) = 25;
			M(*X) = 100;
		}
	} else if (Jenis(*X) == 'T') {
		if (Level(*X) == 2) {
			A(*X) = 10;
			M(*X) = 30;
		} else if (Level(*X) == 3) {
			A(*X) = 20;
			M(*X) = 40;
		} else if (Level(*X) == 4) {
			A(*X) = 30;
			M(*X) = 50;
		}
	} else if (Jenis(*X) == 'F') {
		if (Level(*X) == 2) {
			A(*X) = 20;
			M(*X) = 40;
		} else if (Level(*X) == 3) {
			A(*X) = 30;
			M(*X) = 60;
		} else if (Level(*X) == 4) {
			A(*X) = 40;
			M(*X) = 80;
		}
	} else if (Jenis(*X) == 'V') {
		if (Level(*X) == 2) {
			A(*X) = 10;
			M(*X) = 30;
		} else if (Level(*X) == 3) {
			A(*X) = 15;
			M(*X) = 40;
		} else if (Level(*X) == 4) {
			A(*X) = 20;
			M(*X) = 50;
		}
	}
}

void PrintInfoBangunan(Bangunan X) {
	if (Jenis(X) == 'C') {
		printf("Castle ");
	} else  if (Jenis(X) == 'T') {
		printf("Tower ");
	} else  if (Jenis(X) == 'F') {
		printf("Fort ");
	} else  if (Jenis(X) == 'V') {
		printf("Village ");
	}
	TulisPOINT(Koordinat(X));
	printf(" %d lv.%d\n", JumlahPasukan(X), Level(X));
}