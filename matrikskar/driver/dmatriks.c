/* Driver Matriks Kar */

#include <stdio.h>
#include "../../matrikskar/matriks.h"
#include "../../player/player.h"
#include "../../arraydinpos/arraydinpos.h"

int main() {
	/* Kamus */
	int NB, NK;
	Player P;

	/* Algoritma */
	/* Test Buat MATRIKS dengan validasi ukuran */
	printf("Masukkan ukuran matriks: "); scanf("%d %d", &NB, &NK);
	while (!IsIdxValid_Matriks(NB, NK)) {
		printf("Input yang benar dong!\n");
		printf("Masukkan ukuran matriks: "); scanf("%d %d", &NB, &NK);
	}
	MakeMATRIKS(NB,NK,&Peta);

	/* Test Tulis MATRIKS */
	TulisMATRIKSPETA(Peta,P,P);
}