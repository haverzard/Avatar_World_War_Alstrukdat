/* Program Utama */

/* List Lib */
#include <stdio.h>

/* List ADT */
#include "boolean.h"
#include "mainmenu.h"
#include "matriks.h"
#include "player.h"
#include "point.h"
#include "listlinier.h"
#include "lokasi.h"

int main() {
	/* Kamus */
	int i;
	MATRIKS Peta;
	Player p1, p2;
	Loc temp;
	
	/* Algoritma */
	STARTGAME();
	if (!EndGame) {
		CREATEPLAYER(&p1, &p2);
		INFOPETA(&Peta);
		INFOBANGUNAN();
		LOKASIBANGUNAN(&Peta, &temp);
		InsVFirst(&Bangunan(p1), temp);
		LOKASIBANGUNAN(&Peta, &temp);
		InsVFirst(&Bangunan(p2), temp);
		for (i = 1; i <= 15; i++) {
			LOKASIBANGUNAN(&Peta, &temp);
		}
		i = 1;
		while (!EndGame) {
			while (!EndTurn) {
				TURN(i, Peta, &p1, &p2);
			}
			i = (i % 2 + 3) - 2;
			EndTurn = false;
		}
	}
}