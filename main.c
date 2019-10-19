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
		INFOPETA(&Peta);
		INFOBANGUNAN();
		for (i = 1; i <= 17; i++) {
			LOKASIBANGUNAN(&Peta, &temp);
		}
		i = 1;
		while (!EndGame) {
			while (!EndTurn) {
				TURN(i, Peta);
			}
			i = (i % 2 + 3) - 2;
			EndTurn = false;
		}
	}
}