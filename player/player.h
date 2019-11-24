/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#ifndef PLAYER_H
#define PLAYER_H

#include "../boolean/boolean.h"
#include "../listlinier/listlinier.h"
#include "../queue/queue.h"


typedef struct {
	int Color;
	int NoPemain;
	List ListBangunan;
	Queue Skill;
	boolean Critical; // Ini untuk skill Critical Hit
	int shieldDuration;
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

/* ********* List x Player ********* */
void InitPlayer(int num, Player *P, Player Pother);
/*	I.S. P belum terdefinisi
	F.S. P terdefinisi sebagai player ke-num
*/

boolean CheckWinOrNot(int num, Player P1, Player P2);
/*	Mengecek apakah semua bangunan player ke-num sudah dikalahkan atau diambil alih */

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

void CaptureBuilding(int num, Bangunan *B, Player *P1, Player *P2);
/*	I.S. P1 dan P2 sembarang, TB terdefinisi
	F.S. Bangunan B diubah kepemilikannya menjadi milik player ke-num
*/

void ChangeOwner(Bangunan *B, Player *Me, Player *Enemy);
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

void InstantUpgrade(Player *P);
/*	I.S. P dan TB terdefinisi
	F.S. semua bangunan milik player P pada TB dinaikkan levelnya
*/

void Shield (Player *P);
/*	I.S. P dan TB terdefinisi
	F.S. semua bangunan milik player P pada TB diaktifkan pertahannya (P(*P) == true)
*/

void ExtraTurn (Player *P);
/*	I.S. P dan variabel global extraTurn terdefinisi
	F.S. extraTurn nilainya ditambah satu
*/

void AttackUp (Player *attacker, Player *defender);
/*	I.S. attacker, defender, dan TB terdefinisi
	F.S. semua bangunan milik player defender pada TB dinonaktifkan pertahannya (P(*defender) == false)
*/

void CriticalHit (Player *user);
/*	I.S. user terdefinisi
	F.S. atribut Critical pada user bernilai true
*/

void InstantReinforcement (Player *P);
/*	I.S. P dan TB terdefinisi
	F.S. semua bangunan milik player defender pada TB ditambah pasukannya sebanyak lima
*/

void Barrage (Player *user, Player *enemy);
/*	I.S. user, enemy, dan TB terdefinisi
	F.S. semua bangunan milik player enemy pada TB berkurang pasukannya sebanyak sepuluh
		 Jika JumlahPasukan <= 10, maka JumlahPasukan menjadi nol
*/

/* *** Keep Skill *** */
void KeepSkill (Player *user, skilltype skillName);
/*	I.S. user sembarang, skillName dan Queue Skill terdefinisi
	F.S. Queue Skill pada user betambah satu elemen yaitu skillName
*/

/* *** Use Skill*** */
void UseSkillP (Player *user,Player *enemy);
/*	I.S. user dan enemy terdefinisi
	F.S. Queue Skill pada user berkurang satu elemen di Head 
*/

void UseSkill(int num,Player *user, Player *enemy);
/*	I.S. user dan enemy terdefinisi
	F.S. memanggil prosedur UseSkillP dengan user = num dan enemy adalah lawannya
*/

void PrintSkill(Player P);
/*	I.S. P terdefinisi
	F.S. menampilkan nama skill pada Head Queue Skill
*/

void ShowSkill(int num, Player P1, Player P2);
/*	I.S. num, P1, dan P2 terdefinisi
	F.S. menampilkan nama skill pada Head Queue Skill jika skill tersedia,
		 jika tidak maka menampilkan "-"
*/

boolean isAllLevel4 (Player P);
/* isAllLevel4 bernilai true jika semua bangunan player P memiliki level empat */

/****************** PROSEDUR UNTUK MEMPEROLEH SKILL ******************/  
void GetIUpgrade(Player *P);
/*	I.S. P terdefinisi
	F.S. Player P mendapat Skill Instant Upgrade (U)
*/

void GetShield(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2);
/*	I.S. num, P1, P2, buildingAwalP1, buildingAkhirP1, buildingAwalP2, dan buildingAkhirP2 terdefinisi
	F.S. lawan dari Player num mendapat Skill Shield (S)
*/

void GetExtraTurn(int num,Player *P1,Player *P2,int Fdawal,int Fdakhir);
/*	I.S. num, P1, P2, Fdawal, dan Fdakhir terdefinisi
	F.S. lawan dari Player num mendapat Skill Extra Turn (E) apabila Fort-nya berkurang satu
*/

void GetAttackUp (int num,Player *P1,Player *P2,int TAawal,int TAakhir);
/*	I.S. num, P1, P2, TAawal, dan TAakhir terdefinisi
	F.S. Player num mendapat Skill Attack Up (A) apabila Tower-nya bertambah menjadi tiga
*/

void GetIReinforcement(int num, Player *P1,Player *P2);
/*	I.S. num, P1 dan P2 terdefinisi
	F.S. Player num mendapat Skill Instant Reinforcement (R) apabila semua bangunannya berlevel empat
*/

void GetBarrage(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2);
/*	I.S. num, P1, P2, buildingAwalP1, buildingAkhirP1, buildingAwalP2, dan buildingAkhirP2 terdefinisi
	F.S. lawan dari Player num mendapat Skill Barrage (B) apabila player num bertambah jumlah bangunannya menjadi sepuluh
*/

void HitungFort(int num,Player P1,Player P2,int *F);
/*	I.S. P1 dan P2 terdefinisi, F sembarang
	F.S. F berisi banyak Fort yang dimiliki lawan dari player num
*/

void HitungTower(int num,Player P1,Player P2,int *T);
/*	I.S. P1 dan P2 terdefinisi, T sembarang
	F.S. F berisi banyak Tower yang dimiliki lawan dari player num
*/

boolean isCurrentPCritical (int num,Player P1,Player P2);
/* bernilai true apabila atribut Critical pada player num bernilai true */

void MinShieldDuration (int num,Player *P1,Player *P2);
/*	I.S. num, P1, dan P2 terdefinisi
	F.S. Jika shieldDuration =0 tidak terjadi perubahan, Jika shieldDuration nilai shildDuration berkurang satu
*/

void CriticalOff (int num,Player *P1,Player *P2);
/*	I.S. num, P1, dan P2 terdefinisi
	F.S. jika NoPemain(P) == num, dan Critical (P) bernilai true maka Critical(P) adalah menjadi false,Jika Critical(P) = false, tidak terjadi perubahan 
*/

#endif