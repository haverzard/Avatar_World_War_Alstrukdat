//Sepertinya parameter untuk skill akan diganti dr List jadi Player

#include <stdio.h>
#include "skill.h"
#include "queue.h"
#include "player.h"
#include "listlinier.h"

void InstantUpgrade(Player *P){ 
//IS: .......................Cara peroleh: Hanya di awal permainan
//FS: Semua bangunan pemain mengalami level up
    LevelUpAll(ListBangunan(*P))
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
void KeepSkill (Player *user,skilltype skillName){
    //IS: skillName merupakan salah satu dari nama singkatan skill seperti definisi 
    //FS
    
    //tambahin attribut Skill dengan datatype queue di player.h , misalnya Queue Skill;
    //Anggap selektornya Skill(*user) 
    Add(&Skill(*user),skillName); 
}

/* *** Use Skill*** */
void UseSkill(Player *user,Player *enemy){
//IS: Skill(user) tidak kosong
//FS: elemen Head pada Queue Skill pada user dijalankan, dan skill hangus, Head dari Queue baru adalah skill berikutnya dari skill yang hangus dipakai
    //Kamus
    skilltype X;

    //Algoritma
    if ((Head(Skill(*user)) == 'U') || (Head(Skill(*user)) == 'u')){
        InstantUpgrade(user);//ini belum tau parameternya bakalan player atau list
    } else if ((Head(Skill(*user)) == 'S') || (Head(Skill(*user)) == 's')){
        Shield(user);
    } else if ((Head(Skill(*user)) == 'E') || (Head(Skill(*user)) == 'e')){
        ExtraTurn(user);
    } else if ((Head(Skill(*user)) == 'A') || (Head(Skill(*user)) == 'a')){
        AttackUp(user,enemy);
    } else if ((Head(Skill(*user)) == 'H') || (Head(Skill(*user)) == 'h')){
        CriticalHit(user,enemy);
    } else if ((Head(Skill(*user)) == 'R') || (Head(Skill(*user)) == 'r')){
        InstantReinforcement(user);
    } else {
        Barrage(user);
    }
    Del(&Skill(*user),&X);
}
