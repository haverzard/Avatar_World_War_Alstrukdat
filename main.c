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
	Player p1, p2;

	/* Inisiasi */
	Jenis(BangunanUndef) = JenisUndef;
	turn = 0;

	/* Algoritma */
	STARTGAME(&p1, &p2);

	if (!EndGame) {
		if (turn == 0) {
			turn = 1;
		}
		while (!EndGame) {
			while (!EndTurn) {
				TURN(turn, &p1, &p2);
			}
			UpdateListBangunan(turn, p1, p2);
			GetIReinforcement(turn,&p1,&p2);
			if (extraTurn == 0){
				turn = (turn % 2 + 3) - 2;
				MinShieldDuration(turn,&p1,&p2);
			} else {
				extraTurn -=1;
				printf("Anda memiliki extra turn %d kali\n",extraTurn);
			}
			// turn = (turn % 2 + 3) - 2; 
			if (attackUp){
				attackUp = 0;
			}
			EndTurn = false;
		}
	}
}