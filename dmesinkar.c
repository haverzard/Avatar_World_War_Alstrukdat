/* Driver Mesin Karakter */

#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"

int main() {
	/* Pembacaan dari file */
	START("testDriverMesinKar");
	while (!EOP) {
		printf("%c", CC);
		ADV();
	}
	printf("\n");

	/* Pembacaan dari program */
	while (CC != '\n' && !feof(stdin)) {
		SCAN();
		printf("%c", CC);
	}
}