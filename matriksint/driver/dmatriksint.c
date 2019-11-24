/* Driver Matriks Integer */

#include <stdio.h>
#include "../../matriksint/matriksint.h"

int main() {
	/* Kamus */
	MATRIKS_INT M;
    int i, j;
	/* Algoritma */
	/* Test Create Matriks */
	MakeMATRIKS_INT(3, 3, &M);
    /* Tes IsIdxValid */
    printf("Idx 5,5 valid? %d\n", IsIdxValid(5,5));
    /* Tes IsIdxEffMatInt */
    printf("Idx 5,5 eff? %d\n", IsIdxEffMatInt(M,5,5));
    /* Test Isi Matriks */
    printf("Masukkan isi matriks 3x3: \n");
    for (i = GetFirstIdxBrsMatInt(M); i <= GetLastIdxBrsMatInt(M); i++) {
        for (j = GetFirstIdxKolMatInt(M); j <= GetLastIdxKolMatInt(M); j++) {
            scanf("%d", &ElmtMatInt(M,i,j));
        }
    }
    /* Test Tulis Matriks */
    printf("\nIsi Matriks:\n");
    TulisMATRIKS_INT(M);
}