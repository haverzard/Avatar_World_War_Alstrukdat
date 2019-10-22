/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#include "boolean.h"
#include "player.h"
#include "listlinier.h"
#include "queue.h"

void InitPlayer(int num, Player *P) {
	Color(*P) = num;
	NoPemain(*P) = num;
	CreateEmpty_LL(&ListBangunan(*P));
	First(ListBangunan(*P)) = Alokasi(num); 
}

void PrintListBangunan(int num, Player P1, Player P2) {
	if (num == 1) {
		PrintInfo(ListBangunan(P1));
	} else {
		PrintInfo(ListBangunan(P2));
	}
}

void UpdateListBangunan(int num, Player P1, Player P2) {
	if (num == 1) {
		UpdateAllBuildings(ListBangunan(P1));
	} else {
		UpdateAllBuildings(ListBangunan(P2));
	}
}

void LevelUpBP (int num, Player P1, Player P2, int idx) {
	if (num == 1) {
		IndexLevelUp(ListBangunan(P1), idx);
	} else {
		IndexLevelUp(ListBangunan(P2), idx);
	}
}

void InstantUpgrade(Player *P){ 
//IS: .......................Cara peroleh: Hanya di awal permainan
//FS: Semua bangunan pemain mengalami level up
    LevelUpAll(ListBangunan(*P));
}

void Shield (Player *P){
//IS .............................Cara peroleh: pemain diserang ,bangunannya berkurang 1 dan bersisa 2
//FS: Pertahanan Bangunan selama 2 kali turn, jika digunakan dua kali berturut-turut,durasi tidak bertambah,namun menjadi nilai maksimum 
    ShieldOn(ListBangunan(*P));
}

void ExtraTurn (Player *P){
//IS.........................Cara peroleh:Fort pemain tersebut direbut lawan
//FS: Player dapat turn 2 kali
    //diset up di menu
}

void AttackUp ( Player *attacker, Player *defender){
//IS: ...................................Cara peroleh skill ini : pemain menyerang tower lawan dan jumlah towernya menjadi 3
//FS: Pertahanan musuh tidak akan mempengaruhi penyerangan pd giliran ini setelah skill diaktifkan
    //Kamus
    // address addr;

    //Algoritma
    // addr = First(Bangunan(*defender));
    // while (addr != Nil){
    //     P(Bangunan(Info(addr))) = false;
    //     addr = Next(addr);
    // }
    //Untuk turn berikutnya yang bangunan yg dulunya ada pertahanan harus diaktifkan balek
}

void CriticalHit (Player *user){
//IS:.............................Cara peroleh: Jika lawan baru saja mengaktifkan skill Extra
//FS: Pada giliran ini, setelah skill diaktifkan jumlah pasukan pada bangunan yang melakukan serangan tepat selanjutnya hanya berkurang 1/2 dari yang seharusnya
    
    //tambahin boolean critical sbg atribut player
    Critical(*user) = true;
    //jika true jalanin proses supaya FS, ini realisasinya di command attack  
}

void InstantReinforcement (Player *P){
//IS: ..........................Cara peroleh skill: pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki memiliki level 4
//FS: Seluruh bangunan mendapatkan tambahan 5 pasukan

    //Setiap endturn harus cek
    ReinforceAll(ListBangunan(*P));
}

void Barrage (Player *P){
//IS..............................Pemain mendapat skill ini jika lawan baru saja bertaambah bangunannya menjadi 10 bangunan
//FS Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10 pasukan 
    BarrageAll(ListBangunan(*P));
}


/* *** Keep Skill *** */
void KeepSkill (Player *user, skilltype skillName){
    //IS: skillName merupakan salah satu dari nama singkatan skill seperti definisi 
    //FS
    
    //tambahin attribut Skill dengan datatype queue di player.h , misalnya Queue Skill;
    //Anggap selektornya Skill(*user) 
    Add(&Skill(*user),skillName); 
}

/* *** Use Skill*** */
void UseSkill(Player *user, Player *enemy) {
//IS: Skill(user) tidak kosong
//FS: elemen Head pada Queue Skill pada user dijalankan, dan skill hangus, Head dari Queue baru adalah skill berikutnya dari skill yang hangus dipakai
    //Kamus
    skilltype X;

    //Algoritma
    if ((Name(InfoHead(Skill(*user))) == 'U') || (Name(InfoHead(Skill(*user))) == 'u')) {
        InstantUpgrade(user);//ini belum tau parameternya bakalan player atau list
    } else if ((Name(InfoHead(Skill(*user))) == 'S') || (Name(InfoHead(Skill(*user))) == 's')){
        Shield(user);
    } else if ((Name(InfoHead(Skill(*user))) == 'E') || (Name(InfoHead(Skill(*user))) == 'e')){
        ExtraTurn(user);
    } else if ((Name(InfoHead(Skill(*user))) == 'A') || (Name(InfoHead(Skill(*user))) == 'a')){
        AttackUp(user,enemy);
    } else if ((Name(InfoHead(Skill(*user))) == 'H') || (Name(InfoHead(Skill(*user))) == 'h')){
        CriticalHit(user);
    } else if ((Name(InfoHead(Skill(*user))) == 'R') || (Name(InfoHead(Skill(*user))) == 'r')){
        InstantReinforcement(user);
    } else {
        Barrage(user);
    }
    Del(&Skill(*user),&X);
}
