#ifndef skill_H
#define skill_H

#include "boolean.h"
#include "queue.h"
#include "listlinier.h"
#include "bangunan.h"
#include "player.h"
#include <string.h>


//masuk ke dalam adt player ?

/* Definisi elemen dan address */
typedef struct {
    char Name;
} Skill;
//Nama Skill
//Instant Upgrade       U atau u
//Shield                S atau s
//Extra Turn            E atau e
//Attack Up             A atau a
//Critical Hit          H atau h
//Instant Reinforcement R atau r
//Barrage               B atau b

/* ********* AKSES (Selektor) ********* */
#define  Name(Skill) (Skill).Name

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


void CriticalHit (Player *user,Player *enemy);
//IS:.............................Cara peroleh: Jika lawan baru saja mengaktifkan skill Extra
//FS: Pada giliran ini, setelah skill diaktifkan jumlah pasukan pada bangunan yang melakukan serangan tepat sealnjutnya hanya berkurang 1/2 dari yang seharusnya
    

void InstantReinforcement (Player *P);
//IS: ..........................Cara peroleh skill: pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki memiliki level 4
//FS: Seluruh bangunan mendapatkan tambahan 5 pasukan

void Barrage (Player *P);
//IS..............................Pemain mendapat skill ini jika lawan baru saja bertaambah bangunannya menjadi 10 bangunan
//FS looping dari list bangunan pemain 


/* *** Keep Skill *** */
void KeepSkill (Player *user,skilltype skillName);
    //IS
    //FS
    //Add()

/* *** Use Skill*** */
void UseSkill(Player *user);
//IS:
//FS:
    //If (Player.S.Name == 's' or Player.S.name == 'S') then Shield()
    //Pake counter untuk track jumlah pemakaian suatu skill berturut''
#endif
