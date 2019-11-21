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
//IS: .......................Cara peroleh: Hanya di awal permainan
//FS: Semua bangunan pemain mengalami level up


void Shield (Player *P);
//IS .............................Cara peroleh: pemain diserang ,bangunannya berkurang 1 dan bersisa 2
//FS: Pertahanan Bangunan selama 2 kali turn, jika digunakan dua kali berturut-turut,durasi tidak bertambah,namun menjadi nilai maksimum 
    

void ExtraTurn (Player *P);
//IS.........................Cara peroleh:Fort pemain tersebut direbut lawan
//FS: Player dapat turn 2 kali

void AttackUp (Player *attacker, Player *defender);
//IS: ...................................Cara peroleh skill ini : pemain menyerang tower lawan dan jumlah towernya menjadi 3
//FS: Pertahanan musuh tidak akan mempengaruhi penyerangan pd giliran ini setelah skill diaktifkan


void CriticalHit (Player *user);
//IS:.............................Cara peroleh: Jika lawan baru saja mengaktifkan skill Extra
//FS: Pada giliran ini, setelah skill diaktifkan jumlah pasukan pada bangunan yang melakukan serangan tepat sealnjutnya hanya berkurang 1/2 dari yang seharusnya
    

void InstantReinforcement (Player *P);
//IS: ..........................Cara peroleh skill: pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki memiliki level 4
//FS: Seluruh bangunan mendapatkan tambahan 5 pasukan

void Barrage (Player *P);
//IS..............................Pemain mendapat skill ini jika lawan baru saja bertaambah bangunannya menjadi 10 bangunan
//FS looping dari list bangunan pemain 

/* *** Keep Skill *** */
void KeepSkill (Player *user, skilltype skillName);
    //IS
    //FS
    //Add()

/* *** Use Skill*** */
void UseSkillP (Player *user,Player *enemy);

void UseSkill(int num,Player *user, Player *enemy);
//IS:
//FS:
    //If (Player.S.Name == 's' or Player.S.name == 'S') then Shield()
    //Pake counter untuk track jumlah pemakaian suatu skill berturut''

void ShowSkill(int num, Player P1, Player P2);

void GetIUpgrade(Player *P);

void GetIReinforcement(int num, Player *P1,Player *P2);

boolean isAllLevel4 (Player P);

void HitungBangunan (Player P,int *C,int *T, int *F, int *V);

#endif