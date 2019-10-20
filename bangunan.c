/* ADT Bangunan */
/*  */

#include <stdio.h>
#include "boolean.h"
#include "bangunan.h"

void InitCastle(Bangunan *X) {
	Kepemilikan(*X) = 0;
	Jenis(*X) = 'C';
	JumlahPasukan(*X) = 40-10;
	Level(*X) = 1;
	A(*X) = 10;
	M(*X) = 40;
	P(*X) = false;
}

void InitTower(Bangunan *X) {
	Kepemilikan(*X) = 0;
	Jenis(*X) = 'T';
	JumlahPasukan(*X) = 30-5;
	Level(*X) = 1;
	A(*X) = 5;
	M(*X) = 20;
	P(*X) = true;
}

void InitFort(Bangunan *X) {
	Kepemilikan(*X) = 0;
	Jenis(*X) = 'F';
	JumlahPasukan(*X) = 80-10;
	Level(*X) = 1;
	A(*X) = 10;
	M(*X) = 20;
	P(*X) = false;
}

void InitVillage(Bangunan *X) {
	Kepemilikan(*X) = 0;
	Jenis(*X) = 'V';
	JumlahPasukan(*X) = 20-5;
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