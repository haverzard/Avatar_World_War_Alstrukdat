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
	Player p1, p2;

	/* Inisiasi */
	Jenis(BangunanUndef) = JenisUndef;
	
	/* Algoritma */
	STARTGAME(&p1, &p2);
	
	if (!EndGame) {
		i = 1;
		while (!EndGame) {
			while (!EndTurn) {
				TURN(i, &p1, &p2);
			}
			UpdateListBangunan(i, p1, p2);
			GetIUpgrade(&p1);GetIUpgrade(&p2);GetIUpgrade(&p1);GetIUpgrade(&p2);
			GetIReinforcement(i, &p1, &p2);
			//Ini buat testing doang
			// MinShieldDuration(i,&p1,&p2);
			// //Tambahin shield Duration
			// // if (extraTurn = 0){
			// // 	i = (i % 2 + 3) - 2; 
			// // } else {
			// // 	extraTurn -=1;
			// // }
			i = (i % 2 + 3) - 2; 
			if (attackUp){
				attackUp = 0;
			}
			EndTurn = false;
		}
	}
}