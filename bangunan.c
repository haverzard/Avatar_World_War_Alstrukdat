/* ADT Bangunan */
/*  */

#include <stdio.h>
#include "boolean.h"
#include "bangunan.h"

void InitCastle(Bangunan *X) {
	Kepemilikan(*X) = 0;
	JumlahPasukan(*X) = 40;
	Level(*X) = 1;
	A(*X) = 10;
	M(*X) = 40;
	P(*X) = false;
}

void InitTower(Bangunan *X) {
	Kepemilikan(*X) = 0;
	JumlahPasukan(*X) = 30;
	Level(*X) = 1;
	A(*X) = 5;
	M(*X) = 20;
	P(*X) = true;
}

void InitFort(Bangunan *X) {
	Kepemilikan(*X) = 0;
	JumlahPasukan(*X) = 80;
	Level(*X) = 1;
	A(*X) = 10;
	M(*X) = 20;
	P(*X) = false;
}

void InitVillage(Bangunan *X) {
	Kepemilikan(*X) = 0;
	JumlahPasukan(*X) = 20;
	Level(*X) = 1;
	A(*X) = 5;
	M(*X) = 20;
	P(*X) = false;
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
}