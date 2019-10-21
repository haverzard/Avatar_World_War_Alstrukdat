/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#include "boolean.h"
#include "player.h"
#include "listlinier.h"

void InitPlayer(int num, Player *P) {
	Color(*P) = num;
	NoPemain(*P) = num;
	CreateEmpty(&Bangunan(*P));
}