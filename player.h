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
	Queue Skill;
	boolean Critical; // Ini untuk skill Critical Hit
	//int skillDuration;
} Player;

#define Skill(P) P.Skill
#define ListBangunan(P) P.ListBangunan
#define Color(P)  P.Color
#define Critical(P) P.Critical 
#define NoPemain(P) (P).NoPemain


void InitPlayer(int num, Player *P);

void PrintListBangunan(int num, Player P1, Player P2);

void UpdateListBangunan(int num, Player P1, Player P2);

void LevelUpBP (int num, Player P1, Player P2, int idx);

#endif