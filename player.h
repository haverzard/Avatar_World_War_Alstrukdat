/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "listlinier.h"
#include "queue.h"


typedef struct {
	int Color;
	int NoPemain;
	List ListBangunan;
	Queue Skill;
	boolean Critical; // Ini untuk skill Critical Hit
	int shieldDuration;
} Player;

extern int extraTurn;

#define Skill(P) (P).Skill
#define ListBangunan(P) (P).ListBangunan
#define Color(P)  (P).Color
#define Critical(P) (P).Critical 
#define NoPemain(P) (P).NoPemain
#define shieldDuration(P) (P).shieldDuration
#define extraTurn(P) (P).extraTurn

void InitPlayer(int num, Player *P);

int NBElmtListB(int NoPemain, Player P1, Player P2);

void PrintListBangunan(int num, Player P1, Player P2);

void PrintMyConnectedBuildings(int num, int NoBangunan, Player P1, Player P2);

void PrintNotMyConnectedBuildings(int num, int IdxList, Player P1, Player P2);

int NBMyConnectedBuildings(int num, int IdxList, Player P1, Player P2);

int NBNotMyConnectedBuildings(int num, int IdxList, Player P1, Player P2);

int InfoMyBuilding(int num, int IdxList, Player P1, Player P2);

int InfoConnectedBuilding(int num, int IdxList, int IdxConnected, Player P1, Player P2);

int InfoConnectedBuilding2(int num, int IdxList, int IdxConnected, Player P1, Player P2);

void CaptureBuilding(int num, Bangunan *B, Player P1, Player P2);

void ChangeOwner(Bangunan *B, Player Me, Player Enemy);

void UpdateListBangunan(int num, Player P1, Player P2);

void LevelUpBP (int num, Player P1, Player P2, int idx);

/* ********* Prototype ********* */
void InstantUpgrade(Player *P);

void Shield (Player *P);

void ExtraTurn (Player *P);

void AttackUp (Player *attacker, Player *defender);

void CriticalHit (Player *user);

void InstantReinforcement (Player *P);

void Barrage (Player *P);

/* *** Keep Skill *** */
void KeepSkill (Player *user, skilltype skillName);

/* *** Use Skill*** */
void UseSkillP (Player *user,Player *enemy);

void UseSkill(int num,Player *user, Player *enemy);

void ShowSkill(int num, Player P1, Player P2);

void GetIUpgrade(Player *P);

// void GetShield(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2);

// void GetExtraTurn(int num,Player *P1,Player *P2,int Fdawal,int Fdakhir);

// void GetAttackUp (int num,Player *P1,Player *P2,int Tdawal,int Tdakhir);

// void GetBarage(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2);

// void GetIReinforcement(int num, Player *P1,Player *P2);

// boolean isAllLevel4 (Player P);

// void HitungFort(int num,Player P1,Player P2,int *F);

// void HitungTower(int num,Player P1,Player P2,int *T);

// boolean isCurrentPCritical (int num,Player P1,Player P2);

// void GetShield(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2)


// void SerangPlayer (int input,Player *attacker, Player *defender);
// void HitungBangunan (Player P,int *C,int *T, int *F, int *V);

#endif