/* Driver Bangunan */

#include <stdio.h>
#include "../../bangunan/bangunan.h"
#include "../../point/point.h"

int main() {
	/* Kamus */
	Bangunan B1, B2, B3;
	POINT temp;

	/* Inisiasi */
	Jenis(BangunanUndef) = JenisUndef;
	temp = MakePOINT(5,5);

	/* Algoritma */
	/* Test Init & Print */
	InitBangunan(&B1,'C');
	InitBangunan(&B2,'F');
	InitBangunan(&B3,'T');
	Koordinat(B1) = temp;
	Koordinat(B2) = temp;
	Koordinat(B3) = temp;
	printf("Bangunan B1: "); PrintInfoBangunan(B1);
	printf("Bangunan B2: "); PrintInfoBangunan(B2);
	printf("Bangunan B3: "); PrintInfoBangunan(B3);
	
	/* Test Valid */
	printf("Validasi B1: %d\n", IsBangunanValid(B1));
	printf("Validasi BangunanUndef: %d\n", IsBangunanValid(BangunanUndef));
	
	/* Test EQ */
	printf("EQ B1-B1: %d\n", EQ_Bangunan(B1, B1));
	printf("EQ B1-B2: %d\n", EQ_Bangunan(B1, B2));

	/* Test Move */
	Move(&B2, &B3, 10);
	printf("Pindah 10 pasukan dari B2 ke B3\n");
	printf("Bangunan B2: "); PrintInfoBangunan(B2);
	printf("Bangunan B3: "); PrintInfoBangunan(B3);

	/* Test Serang */
	SerangBangunan(&B3, &B2, 8);
	printf("Serang B2 dengan 8 pasukan dari B3\n");
	printf("Bangunan B2: "); PrintInfoBangunan(B2);
	printf("Bangunan B3: "); PrintInfoBangunan(B3);
	SerangCritical(&B2, &B3, 40);
	printf("Serang B3 dengan 40 pasukan dari B2\n");
	printf("Bangunan B2: "); PrintInfoBangunan(B2); 
	printf("Bangunan B3: "); PrintInfoBangunan(B3);

	/* Test Update Bangunan */
	UpdateBangunan(&B1);
	UpdateBangunan(&B2);
	printf("Bangunan B1: "); PrintInfoBangunan(B1);
	printf("Bangunan B2: "); PrintInfoBangunan(B2);

	/* Test Level Up */
	LevelUpBangunan(&B1);
	printf("Bangunan B1: "); PrintInfoBangunan(B1);

}