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
	// boolean attackUpBool;
} Player;

extern int extraTurn;
extern int attackUp;

#define Skill(P) (P).Skill
#define ListBangunan(P) (P).ListBangunan
#define Color(P)  (P).Color
#define Critical(P) (P).Critical 
#define NoPemain(P) (P).NoPemain
#define shieldDuration(P) (P).shieldDuration
#define extraTurn(P) (P).extraTurn
// #define attackUpBool(P) (P).attackUpBool

/* ********* List x Player ********* */
void InitPlayer(int num, Player *P);
/*	I.S. P belum terdefinisi
	F.S. P terdefinisi sebagai player ke-num
*/

int NBElmtListB(int NoPemain, Player P1, Player P2);
/*	Menghasilkan nilai ukuran list untuk player ke-NoPemain*/

void PrintListBangunan(int num, Player P1, Player P2);
/*	I.S. P1 dan P2 sembarang
	F.S. Ditampilkan daftar bangunan berdasarkan ListBangunan player ke-num
*/

void PrintMyConnectedBuildings(int num, int IdxList, Player P1, Player P2);
/*	I.S. P1 dan P2 sembarang, TB terdefinisi
	F.S. Ditampilkan daftar bangunan milik player ke-num yang terhubung dengan bangunan dengan indeks TB pada info list player ke-num ke-IdxList
*/

void PrintNotMyConnectedBuildings(int num, int IdxList, Player P1, Player P2);
/*	I.S. P1 dan P2 sembarang, TB terdefinisi
	F.S. Ditampilkan daftar bangunan bukan milik player ke-num yang terhubung dengan bangunan dengan indeks TB pada info list player ke-num ke-IdxList
*/

int NBMyConnectedBuildings(int num, int IdxList, Player P1, Player P2);
/*	Menghasilkan banyaknya bangunan milik player ke-num yang terhubungan dengan  bangunan dengan indeks TB pada info list player ke-num ke-IdxList */


int NBNotMyConnectedBuildings(int num, int IdxList, Player P1, Player P2);
/*	Menghasilkan banyaknya bangunan bukan milik player ke-num yang terhubungan dengan  bangunan dengan indeks TB pada info list player ke-num ke-IdxList */

int InfoMyBuilding(int num, int IdxList, Player P1, Player P2);
/*	Menghasilkan info list player ke-num ke-IdxList */

int InfoConnectedBuilding(int num, int IdxList, int IdxConnected, Player P1, Player P2);
/*	Menghasilkan indeks TB yang direpresentasikan IdxConnected sesuai urutan daftar bangunan dari prosedur PrintMyConnectedBuildings */

int InfoConnectedBuilding2(int num, int IdxList, int IdxConnected, Player P1, Player P2);
/*	Menghasilkan indeks TB yang direpresentasikan IdxConnected sesuai urutan daftar bangunan dari prosedur PrintNotMyConnectedBuildings */

void CaptureBuilding(int num, Bangunan *B, Player P1, Player P2);
/*	I.S. P1 dan P2 sembarang, TB terdefinisi
	F.S. Bangunan B diubah kepemilikannya menjadi milik player ke-num
*/

void ChangeOwner(Bangunan *B, Player Me, Player Enemy);
/*	I.S. Me dan Enemy sembarang, TB terdefinisi
	F.S. Bangunan B diubah kepemilikannya menjadi milik player Me
		 Jika B milik Enemy, indeks TB untuk B dihapus dari ListBangunan Enemy
*/

void UpdateListBangunan(int num, Player P1, Player P2);
/*	I.S. P1 dan P2 sembarang
	F.S. Semua Bangunan milik player ke-num ditambah pasukannya sesuai spesifikasi
*/

void LevelUpBP (int num, Player P1, Player P2, int idx);
/*	I.S. P1 dan P2 sembarang, TB terdefinisi, dan idx valid
	F.S. indeks TB pada info ListBangunan player ke-num ke-idx dinaikkan levelnya
*/

/* ********* Prototype ********* */
void InstantUpgrade(Player *P);

void Shield (Player *P);

void ExtraTurn (Player *P);

void AttackUp (Player *attacker, Player *defender);

void CriticalHit (Player *user);

void InstantReinforcement (Player *P);

void Barrage (Player *user, Player *enemy);

/* *** Keep Skill *** */
void KeepSkill (Player *user, skilltype skillName);

/* *** Use Skill*** */
void UseSkillP (Player *user,Player *enemy);

void UseSkill(int num,Player *user, Player *enemy);

void ShowSkill(int num, Player P1, Player P2);

void GetIUpgrade(Player *P);

void GetShield(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2);

void GetExtraTurn(int num,Player *P1,Player *P2,int Fdawal,int Fdakhir);

void GetAttackUp (int num,Player *P1,Player *P2,int TAawal,int TAakhir);

void GetBarrage(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2);

void GetIReinforcement(int num, Player *P1,Player *P2);

boolean isAllLevel4 (Player P);

void HitungFort(int num,Player P1,Player P2,int *F);

void HitungTower(int num,Player P1,Player P2,int *T);

boolean isCurrentPCritical (int num,Player P1,Player P2);

void GetShield(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2);

void CriticalOff (int num,Player *P1,Player *P2);

void MinShieldDuration (int num,Player *P1,Player *P2);
// void SerangPlayer (int input,Player *attacker, Player *defender);
// void HitungBangunan (Player P,int *C,int *T, int *F, int *V);

#endif