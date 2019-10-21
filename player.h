/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "listlinier.h"

typedef struct {
	int Color;
	List Bangunan;
	Queue Skill;
	boolean Critical; // Ini untuk skill Critical Hit
	//int skillDuration;
} Player;

#define Skill(P) P.Skill
#define Bangunan(P) P.Bangunan
#define Color(P)  P.Color
#define Critical(P) P.Critical 


void STARTGAME();
/* 	I.S. Menampilkan menu awal dan menerima masukan user 
	F.S. Choice terisi dan game akan mulai di-load jika choice sesuai.
		 Jika choice tidak sesuai, balik lagi ke menu utama.
*/
void LOADGAME();
/*	I.S.
	F.S.
*/

#endif