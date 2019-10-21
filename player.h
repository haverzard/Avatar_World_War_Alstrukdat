/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "listlinier.h"

typedef struct {
	int Color;
	int NoPemain;
	List Bangunan;
} Player;

#define Color(X) (X).Color
#define NoPemain(X) (X).NoPemain
#define Bangunan(X) (X).Bangunan

void InitPlayer(int num, Player *P);

#endif