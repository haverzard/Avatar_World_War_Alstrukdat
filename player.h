/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "listlinier.h"

typedef struct {
	int Color;
	int NoPemain;
	List ListBangunan;
} Player;

#define Color(X) (X).Color
#define NoPemain(X) (X).NoPemain
#define ListBangunan(X) (X).ListBangunan

void InitPlayer(int num, Player *P);

void PrintListBangunan(int num, Player P1, Player P2);

void UpdateListBangunan(int num, Player P1, Player P2);

void LevelUpBP (int num, Player P1, Player P2, int idx);

#endif