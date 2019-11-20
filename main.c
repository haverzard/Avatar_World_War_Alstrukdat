/* Program Utama */

/* List Lib */
#include <stdio.h>

/* List ADT */
#include "boolean.h"
#include "mainmenu.h"
#include "matriks.h"
#include "matriksint.h"
#include "player.h"
#include "point.h"
#include "listlinier.h"
#include "graph.h"
#include "stack.h"

int main() {
	/* Kamus */
	int i;
	MATRIKS Peta;
	MATRIKS_INT Hubungan; 
	Graph GHubungan;
	Player p1, p2;

	/* Inisiasi */
	Jenis(BangunanUndef) = JenisUndef;
	
	/* Algoritma */
	STARTGAME();
	if (!EndGame) {
		printf("HEHE");
		INFOPETA(&Peta);
		INFOBANGUNAN(&TB);
		
		for (i = 1; i <= MaxElArr(TB); i++) {
			LOKASIBANGUNAN(&Peta, &TB, i);
		}
		HUBUNGANBANGUNAN(&Hubungan, NBElmt_Array(TB));
		GenerateHubunganBangunan(&GHubungan, Hubungan);
		PrintAllHubunganBangunan(GHubungan);
		printf("\n");
		TulisMATRIKS_INT(Hubungan); printf("\n");
		CREATEPLAYER(&p1, &p2);
		KeepSkill(&p1,'U');
		CREATEPLAYER(&p1, &p2);
		KeepSkill(&p1,'U');
		KeepSkill(&p2,'U');
		i = 1;
		while (!EndGame) {
			while (!EndTurn) {
				TURN(i, Peta, &p1, &p2);
			}
			UpdateListBangunan(i, p1, p2);
			i = (i % 2 + 3) - 2;
			EndTurn = false;
		}
	}
}