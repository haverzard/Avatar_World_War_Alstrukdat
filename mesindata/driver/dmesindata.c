/* Driver Mesin Data */

#include <stdio.h>
#include <stdlib.h>
#include "../../mesindata/mesindata.h"
#include "../../matrikskar/matriks.h"
#include "../../matriksint/matriksint.h"
#include "../../arraydinpos/arraydinpos.h"
#include "../../graph/graph.h"
#include "../../mainmenu/mainmenu.h"
#include "../../stack/stack.h"
#include "../../queue/queue.h"
#include "../../player/player.h"

int main() {
	/* Kamus */
	char *filename;
	Player *P1, *P2;

	/* Inisiasi */
	P1 = (Player*) malloc(sizeof(Player));
	P2 = (Player*) malloc(sizeof(Player));

	/* Algoritma */
	/* Pembacaan file template */
	filename = "mesindata/driver/testtemplate";
	STARTDATA(filename);
	INFOPETA(&Peta);
	INFOBANGUNAN(&TB);
	LOKASIBANGUNAN(&Peta, &TB);
	HUBUNGANBANGUNAN(&Hubungan, NBElmt_Array(TB));
	GenerateHubunganBangunan(&GHubungan, Hubungan);
	TulisMATRIKSPETA(Peta, *P1, *P2);
	printf("BERHASIL!\n\n");

	/* Pembacaan file save */
	filename = "mesindata/driver/testsave";
	STARTDATA(filename);
	NoPemain(*P1) = 1; NoPemain(*P2) = 2;
	INFOPETA(&Peta);
	INFOBANGUNAN(&TB);
	LOKASIBANGUNAN(&Peta, &TB);
	HUBUNGANBANGUNAN(&Hubungan, NBElmt_Array(TB));
	GenerateHubunganBangunan(&GHubungan, Hubungan);
	MOREINFOBANGUNAN(&TB);
	INFOTURN(&turn);
	INFOCOLOR(P1, P2);
	LOADBANGUNANPLAYER(P1, P2);
	LOADSKILL(P1, P2);
	CreateEmpty_Stack(&Status);
	shieldDuration(*P1) = 0; shieldDuration(*P2) = 0;
	Critical(*P1) = false; Critical(*P2) = false;
	TulisMATRIKSPETA(Peta, *P1, *P2);
	printf("BERHASIL!\n\n");

	/* Pembacaan file aneh */
	filename = "mesindata/driver/testlala";
	STARTDATA(filename);
	INFOPETA(&Peta);
	INFOBANGUNAN(&TB);
	LOKASIBANGUNAN(&Peta, &TB);
	HUBUNGANBANGUNAN(&Hubungan, NBElmt_Array(TB));
	GenerateHubunganBangunan(&GHubungan, Hubungan);
	MOREINFOBANGUNAN(&TB);
	INFOTURN(&turn);
	INFOCOLOR(P1, P2);
	LOADBANGUNANPLAYER(P1, P2);
	LOADSKILL(P1, P2);
}