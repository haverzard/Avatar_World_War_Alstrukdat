/* Driver Mesin Kata */

#include <stdio.h>
#include "../../mesinkar/mesinkar.h"
#include "../../mesinkata/mesinkata.h"

int main() {
	/* Kamus */
	int i;

	/* Pembacaan dari program */
	SCANKATA();
	for (i = 1; i <= CKata.Length; i ++) {
		printf("%c", CKata.TabKata[i]);
	}
	printf("\n");
}