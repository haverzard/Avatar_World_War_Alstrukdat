/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#include <stdio.h>
#include "../boolean/boolean.h"
#include "../player/player.h"
#include "../listlinier/listlinier.h"
#include "../queue/queue.h"
#include "../arraydinpos/arraydinpos.h"
#include "../bangunan/bangunan.h"
#include "../mainmenu/mainmenu.h"
#include "../mesinkata/mesinkata.h"

//Global Variable
int extraTurn=0;
int attackUp = 0;

void InitPlayer(int num, Player *P, Player Pother) 
/*	I.S. P belum terdefinisi
	F.S. P terdefinisi sebagai player ke-num dengan nama dan warna yang benar
*/
{
	/* Kamus Lokal */
	int choice;

	/* Algoritma */
	printf("Player %d\n", num);
	printf("Silahkan pilih warna!\n");
	printf("1. Red		4. Blue\n");
	printf("2. Green	5. Magenta\n");
	printf("3. Yellow	6. Cyan\n");
	printf("Masukan: "); scanf("%d", &choice);
	SCAN();
	while (choice > 6 || choice < 1 || (num == 2 && Color(Pother) == choice)) {
		printf("Input yang benar dong! Pastikan warna Anda berbeda!\n");
		printf("Masukan: "); scanf("%d", &choice);
		SCAN();
	}
	Color(*P) = choice;
	printf("\n");
	NoPemain(*P) = num;
	CreateEmpty_LL(&ListBangunan(*P));
	CreateEmpty_Queue(&Skill(*P), 10);
	First(ListBangunan(*P)) = Alokasi(num);
	Kepemilikan(ElmtArr(TB,num)) = num;
	IterateAndOwn(num, &ListBangunan(*P));
	shieldDuration(*P) = 0;
	Critical(*P) = false;
}

boolean CheckWinOrNot(int num, Player P1, Player P2) 
/*	Mengecek apakah semua bangunan player ke-num sudah dikalahkan atau diambil alih */
{
	/* Algoritma */
	if (num == 1) {
		return IsEmpty_LL(ListBangunan(P2));
	} else {
		return IsEmpty_LL(ListBangunan(P1));
	}
}

int NBElmtListB(int NoPemain, Player P1, Player P2) 
/*	Menghasilkan nilai ukuran list untuk player ke-NoPemain*/
{
	/* Algoritma */
	if (NoPemain == 1) {
		return NbElmt(ListBangunan(P1));
	} else {
		return NbElmt(ListBangunan(P2));
	}
}

void PrintListBangunan(int num, Player P1, Player P2) 
/*	I.S. P1 dan P2 sembarang
	F.S. Ditampilkan daftar bangunan berdasarkan ListBangunan player ke-num
*/
{
	/* Algoritma */
	if (num == 1) {
		PrintInfo(ListBangunan(P1));
	} else {
		PrintInfo(ListBangunan(P2));
	}
}

void PrintMyConnectedBuildings(int num, int IdxList, Player P1, Player P2) 
/*	I.S. P1 dan P2 sembarang, TB terdefinisi
	F.S. Ditampilkan daftar bangunan milik player ke-num yang terhubung dengan bangunan dengan indeks TB pada info list player ke-num ke-IdxList
*/
{
	/* Algoritma */
    if (num == 1) {
    	ConnectedBuildings(InfoListByIndex(ListBangunan(P1), IdxList), ListBangunan(P1));
    } else {
    	ConnectedBuildings(InfoListByIndex(ListBangunan(P2), IdxList), ListBangunan(P2));
    }
}

void PrintNotMyConnectedBuildings(int num, int IdxList, Player P1, Player P2) 
/*	I.S. P1 dan P2 sembarang, TB terdefinisi
	F.S. Ditampilkan daftar bangunan bukan milik player ke-num yang terhubung dengan bangunan dengan indeks TB pada info list player ke-num ke-IdxList
*/
{
	/* Algoritma */
    if (num == 1) {
    	ConnectedBuildings2(InfoListByIndex(ListBangunan(P1), IdxList), ListBangunan(P1));
    } else {
    	ConnectedBuildings2(InfoListByIndex(ListBangunan(P2), IdxList), ListBangunan(P2));
    }
}

int NBMyConnectedBuildings(int num, int IdxList, Player P1, Player P2) 
/*	Menghasilkan banyaknya bangunan milik player ke-num yang terhubungan dengan  bangunan dengan indeks TB pada info list player ke-num ke-IdxList */
{
	/* Algoritma */
    if (num == 1) {
    	return NBConnectedBuildings(InfoListByIndex(ListBangunan(P1), IdxList), ListBangunan(P1));
    } else {
    	return NBConnectedBuildings(InfoListByIndex(ListBangunan(P2), IdxList), ListBangunan(P2));
    }
}

int NBNotMyConnectedBuildings(int num, int IdxList, Player P1, Player P2)
/*	Menghasilkan banyaknya bangunan bukan milik player ke-num yang terhubungan dengan  bangunan dengan indeks TB pada info list player ke-num ke-IdxList */
{
	/* Algoritma */
    if (num == 1) {
    	return NBConnectedBuildings2(InfoListByIndex(ListBangunan(P1), IdxList), ListBangunan(P1));
    } else {
    	return NBConnectedBuildings2(InfoListByIndex(ListBangunan(P2), IdxList), ListBangunan(P2));
    }
}

int InfoMyBuilding(int num, int IdxList, Player P1, Player P2) 
/*	Menghasilkan info list player ke-num ke-IdxList */
{
	/* Algoritma */
    if (num == 1) {
    	return InfoListByIndex(ListBangunan(P1), IdxList);
    } else {
    	return InfoListByIndex(ListBangunan(P2), IdxList);
    }
}

int InfoConnectedBuilding(int num, int IdxList, int IdxConnected, Player P1, Player P2) 
/*	Menghasilkan indeks TB yang direpresentasikan IdxConnected sesuai urutan daftar bangunan dari prosedur PrintMyConnectedBuildings */
{
	/* Algoritma */
    if (num == 1) {
    	return InfoConnectedBuildingByIdx(InfoListByIndex(ListBangunan(P1), IdxList), IdxConnected, ListBangunan(P1));
    } else {
    	return InfoConnectedBuildingByIdx(InfoListByIndex(ListBangunan(P2), IdxList), IdxConnected, ListBangunan(P2));
    }
}

int InfoConnectedBuilding2(int num, int IdxList, int IdxConnected, Player P1, Player P2) 
/*	Menghasilkan indeks TB yang direpresentasikan IdxConnected sesuai urutan daftar bangunan dari prosedur PrintNotMyConnectedBuildings */
{
	/* Algoritma */
    if (num == 1) {
    	return InfoConnectedBuildingByIdx2(InfoListByIndex(ListBangunan(P1), IdxList), IdxConnected, ListBangunan(P1));
    } else {
    	return InfoConnectedBuildingByIdx2(InfoListByIndex(ListBangunan(P2), IdxList), IdxConnected, ListBangunan(P2));
    }
}

void CaptureBuilding(int num, Bangunan *B, Player *P1, Player *P2) 
/*	I.S. P1 dan P2 sembarang, TB terdefinisi
	F.S. Bangunan B diubah kepemilikannya menjadi milik player ke-num
*/
{
	/* Algoritma */
	if (num == 1) {
		ChangeOwner(B, P1, P2);
	} else {
		ChangeOwner(B, P2, P1);
	}
}

void ChangeOwner(Bangunan *B, Player *Me, Player *Enemy) 
/*	I.S. Me dan Enemy sembarang, TB terdefinisi
	F.S. Bangunan B diubah kepemilikannya menjadi milik player Me
		 Jika B milik Enemy, indeks TB untuk B dihapus dari ListBangunan Enemy
*/
{
	/* Kamus Lokal */
	int JumlahPasukanNow;
	/* Algoritma */
	JumlahPasukanNow = JumlahPasukan(*B);
	if (Kepemilikan(*B) == NoPemain(*Enemy)) {
		DelP(&ListBangunan(*Enemy),*B);
	}
	InitBangunan(B, Jenis(*B));
	Kepemilikan(*B) = NoPemain(*Me);
	JumlahPasukan(*B) = JumlahPasukanNow;
	InsVLast(&ListBangunan(*Me), Search1(TB,*B));
}

void UpdateListBangunan(int num, Player P1, Player P2) 
/*	I.S. P1 dan P2 sembarang
	F.S. Semua Bangunan milik player ke-num ditambah pasukannya sesuai spesifikasi
*/
{
	/* Algoritma */
	if (num == 1) {
		UpdateAllBuildings(ListBangunan(P1));
	} else {
		UpdateAllBuildings(ListBangunan(P2));
	}
}

void LevelUpBP (int num, Player P1, Player P2, int idx) 
/*	I.S. P1 dan P2 sembarang, TB terdefinisi, dan idx valid
	F.S. indeks TB pada info ListBangunan player ke-num ke-idx dinaikkan levelnya
*/
{
	/* Algoritma */
	if (num == 1) {
		IndexLevelUp(ListBangunan(P1), idx);
	} else {
		IndexLevelUp(ListBangunan(P2), idx);
	}
}

void InstantUpgrade(Player *P){ 
/*	I.S. P sembarang, TB terdefinisi
	F.S. semua bangunan milik player P pada TB dinaikkan levelnya
*/
	/* Algoritma */
    LevelUpAll(ListBangunan(*P));
}

void Shield (Player *P){
/*	I.S. P sembarang, TB terdefinisi
	F.S. semua bangunan milik player P pada TB diaktifkan pertahannya (P(*P) == true)
*/

	/* Algoritma */
    ShieldOn(ListBangunan(*P));
	if(shieldDuration(*P)==0){
		shieldDuration(*P) += 4; //2 round = 4 endturn
	} else { // Pemakaian Shield yg kedua kali
		shieldDuration(*P) = 4; //2 round = 4 endturn
	}
}

void ExtraTurn (Player *P){
/*	I.S. P sembarang, variabel global extraTurn terdefinisi
	F.S. extraTurn nilainya ditambah satu
*/
	/* Algoritma */
	extraTurn += 1;
}

void AttackUp (Player *attacker,Player *defender){
/*	I.S. attacker dan defender sembarang, TB terdefinisi
	F.S. semua bangunan milik player defender pada TB dinonaktifkan pertahannya (P(*defender) == false)
*/
	/* Algoritma */
	AttackUpAll(ListBangunan(*defender));
	attackUp = 1;
}

void CriticalHit (Player *user){
/*	I.S. user sembarang
	F.S. atribut Critical pada user bernilai true
*/
	/* Algoritma */
    Critical(*user) = true;
}

void InstantReinforcement (Player *P){
/*	I.S. P sembarang, TB terdefinisi
	F.S. semua bangunan milik player defender pada TB ditambah pasukannya sebanyak lima
*/
	/* Algoritma */
    ReinforceAll(ListBangunan(*P));
}

void Barrage (Player *user, Player *enemy){
/*	I.S. user dan enemy sembarang, TB terdefinisi
	F.S. semua bangunan milik player enemy pada TB berkurang pasukannya sebanyak sepuluh
		 Jika JumlahPasukan <= 10, maka JumlahPasukan menjadi nol
*/
	/* Algoritma */	
   BarrageAll(ListBangunan(*enemy));
}


/* *** Keep Skill *** */
void KeepSkill (Player *user, skilltype skillName){
/*	I.S. user sembarang, skillName dan Queue Skill terdefinisi
	F.S. Queue Skill pada user betambah satu elemen yaitu skillName
*/

	/* Algoritma */
	if (!IsFull_Queue(Skill(*user))){
		Add(&Skill(*user),skillName);	
	}    
}

/* *** Use Skill*** */
void UseSkillP (Player *user,Player *enemy){
/*	I.S. user dan enemy terdefinisi
	F.S. Queue Skill pada user berkurang satu elemen di Head 
*/
	/* Kamus Lokal */
	skilltype X;

	/* Algoritma */
	if (IsEmpty_Queue(Skill(*user))){
		printf("Tidak ada skill yang available\n");
	} else {
		if ((InfoHead(Skill(*user)) == 'U') || (InfoHead(Skill(*user)) == 'u')) {
			InstantUpgrade(user);
		} else if ((InfoHead(Skill(*user)) == 'S') || (InfoHead(Skill(*user)) == 's')){
			Shield(user);
		} else if ((InfoHead(Skill(*user)) == 'E') || (InfoHead(Skill(*user)) == 'e')){
			ExtraTurn(user);
			KeepSkill(enemy,'H');
			printf("Lawan anda mendapatkan skill Critical Hit");
		} else if ((InfoHead(Skill(*user)) == 'A') || (InfoHead(Skill(*user)) == 'a')){
			AttackUp(user,enemy);
		} else if ((InfoHead(Skill(*user)) == 'H') || (InfoHead(Skill(*user)) == 'h')){
			CriticalHit(user);
		} else if ((InfoHead(Skill(*user)) == 'R') || (InfoHead(Skill(*user)) == 'r')){
			InstantReinforcement(user);
		} else {
			Barrage (user,enemy);
		}
		Del(&Skill(*user),&X);
		SkillUsed = true;
	}
}

void UseSkill(int num, Player *P1, Player *P2) {
/*	I.S. user dan enemy terdefinisi
	F.S. memanggil prosedur UseSkillP dengan user = num dan enemy adalah lawannya
*/
	/* Algoritma */
	if (NoPemain(*P1) == num) {
		UseSkillP(P1,P2);
	} else{
		UseSkillP(P2,P1);
	}
}

void PrintSkill(Player P) {
/*	I.S. user dan enemy terdefinisi
	F.S. memanggil prosedur UseSkillP dengan user = num dan enemy adalah lawannya
*/
	/* Algoritma */
	switch(InfoHead(Skill(P))) {
		case 'U': printf("Instant Upgrade"); break;
		case 'S': printf("Shield"); break;
		case 'E': printf("Extra Turn"); break;
		case 'A': printf("Attack Up"); break;
		case 'H': printf("Critical Hit"); break;
		case 'R': printf("Instant Reinforcement"); break;
		case 'B': printf("Barrage"); break;
	}
}

void ShowSkill(int num, Player P1, Player P2) {
/*	I.S. num, P1, dan P2 terdefinisi
	F.S. menampilkan nama skill pada Head Queue Skill jika skill tersedia,
		 jika tidak maka menampilkan "-"
*/
	/* Algoritma */
	printf("Skill Available: ");
	if (NoPemain(P1) == num && !IsEmpty_Queue(Skill(P1))) {
		PrintSkill(P1);
	} else if (NoPemain(P2) == num && !IsEmpty_Queue(Skill(P2))) {
		PrintSkill(P2);
	} else {
		printf("-");
	}
	printf("\n");
}

boolean isAllLevel4 (Player P){
/* isAllLevel4 bernilai true jika semua bangunan player P memiliki level empat */
	/* Kamus Lokal */
	address Q;
	boolean level4;

	/* Algoritma */
	level4 = true;
	if (IsEmpty_LL(ListBangunan(P))){
		return false;
	} else {
		Q = First(ListBangunan(P));
		while ((Q != Nil) && (level4)){
			if (Level(ElmtArr(TB,Info(Q))) != 4){
				level4 = false;
			} else {
				Q = Next(Q);
			}
		}
		return (level4);
	}
}


//Kondisi peroleh skill
void GetIUpgrade (Player *P){
/*	I.S. P terdefinisi
	F.S. Player P mendapat Skill Instant Upgrade (U)
*/
	/* Algoritma */
	KeepSkill(P,'U');
}

void GetShield(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2){
/*	I.S. num, P1, P2, buildingAwalP1, buildingAkhirP1, buildingAwalP2, dan buildingAkhirP2 terdefinisi
	F.S. lawan dari Player num mendapat Skill Shield (S)
*/	
	/* Algoritma */
	if (num == NoPemain(*P1)){
		if ((buildingAwalP2==3) && (buildingAkhirP2 ==2)){
			KeepSkill(P2,'S');
			printf("Lawanmu mendapat skill Shield\n");
		}
	} else {
		if ((buildingAwalP1==3) && (buildingAkhirP1 ==2)){
			KeepSkill(P1,'S');
			printf("Lawanmu mendapat skill Shield\n");
		}
	}
}

void GetExtraTurn(int num,Player *P1,Player *P2,int Fdawal,int Fdakhir){
/*	I.S. num, P1, P2, Fdawal, dan Fdakhir terdefinisi
	F.S. lawan dari Player num mendapat Skill Extra Turn (E) apabila Fort-nya berkurang satu
*/
	/* Algoritma */
	if (Fdakhir == Fdawal-1){
		if (num == NoPemain(*P1)){
			KeepSkill(P2,'E');
			printf("Lawanmu mendapat skill Extra Turn \n");
			printf("SKILLL %c\n", InfoTail(Skill(*P2)));
		} else {
			KeepSkill(P1,'E');
			printf("Lawanmu mendapat skill Extra Turn \n");
		}	
	}
}

void GetAttackUp (int num,Player *P1,Player *P2,int TAawal,int TAakhir){
/*	I.S. num, P1, P2, TAawal, dan TAakhir terdefinisi
	F.S. Player num mendapat Skill Attack Up (A) apabila Tower-nya bertambah menjadi tiga
*/
	/* Algoritma */
	if ((TAawal == 2) && (TAakhir ==3)){
		if (num == NoPemain(*P1)){
			KeepSkill(P1,'A');
			printf("Kamu mendapat skill Attack Up\n");	
		} else {
			KeepSkill(P2,'A');
			printf("Kamu mendapat skill Attack Up\n");	
		}
	}
}

void GetIReinforcement(int num, Player *P1,Player *P2){
/*	I.S. num, P1 dan P2 terdefinisi
	F.S. Player num mendapat Skill Instant Reinforcement (R) apabila semua bangunannya berlevel empat
*/
	/* Algoritma */
	if (NoPemain(*P1) == num) {
		if (isAllLevel4(*P1)){
			KeepSkill(P1,'R');	
			printf("Kamu mendapatkan skill Instant Reinforcement\n");
		}
	} else {
		if (isAllLevel4(*P2)){
			KeepSkill(P2,'R');
			printf("Kamu mendapatkan skill Instant Reinforcement\n");
		}
	}
}


void GetBarrage(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2){
/*	I.S. num, P1, P2, buildingAwalP1, buildingAkhirP1, buildingAwalP2, dan buildingAkhirP2 terdefinisi
	F.S. lawan dari Player num mendapat Skill Barrage (B) apabila player num bertambah jumlah bangunannya menjadi sepuluh
*/
	/* Algoritma */
	if (num == NoPemain(*P1)){
		if ((buildingAwalP1==9) && (buildingAkhirP1 ==10)){
			KeepSkill(P2,'B');
			printf("Lawanmu mendapat skill Barrage\n");
		}
	} else {
		if ((buildingAwalP2==9) && (buildingAkhirP2 ==10)){
			KeepSkill(P1,'B');
			printf("Lawanmu mendapat skill Barrage\n");
		}
	}	
}


void HitungFort(int num,Player P1,Player P2,int *F){
/*	I.S. P1 dan P2 terdefinisi, F sembarang
	F.S. F berisi banyak Fort yang dimiliki lawan dari player num
*/
	/* Kamus Lokal */
	address Q;
	int fort;
	
	/* Algoritma */
	fort = 0;
	if (num == NoPemain(P1)){
		Q = First(ListBangunan(P2));
	} else {
		Q = First(ListBangunan(P1));
	}
	while (Q != Nil){
		if (Jenis(ElmtArr(TB,Info(Q))) == 'F'){
			fort +=1;
		}
		Q = Next(Q);
	}
	*F = fort;
}

void HitungTower(int num,Player P1,Player P2,int *T){
/*	I.S. P1 dan P2 terdefinisi, T sembarang
	F.S. F berisi banyak Tower yang dimiliki lawan dari player num
*/
	/* Kamus Lokal */
	address Q;
	int tower;
	
	/* Algoritma */
	tower = 0;
	if (num == NoPemain(P1)){
		Q = First(ListBangunan(P2));
	} else {
		Q = First(ListBangunan(P1));
	}
	while (Q != Nil){
		if (Jenis(ElmtArr(TB,Info(Q))) == 'T'){
			tower +=1;
		}
		Q = Next(Q);
	}
	*T = tower;
}

boolean isCurrentPCritical (int num,Player P1,Player P2){
/* bernilai true apabila atribut Critical pada player num bernilai true */
	/* Algoritma */
	if (NoPemain(P1) == num) {
		if (Critical(P1)){
			return true;
		} else {
			return false;
		}
	} else {
		if (Critical(P2)){
			return true;
		} else {
			return false;
		}
	}
}

void MinShieldDuration (int num,Player *P1,Player *P2)
/*	I.S. num, P1, dan P2 terdefinisi
	F.S. Jika shieldDuration =0 tidak terjadi perubahan, Jika shieldDuration nilai shildDuration berkurang satu
*/
{
	/* Algoritma */
	if(NoPemain(*P1) == num) {
		if (shieldDuration(*P1)>0) {
			shieldDuration(*P1) -=1;
			printf("Efek Shield tinggal %d turn\n",shieldDuration(*P2));
		} else {
			ShieldOff(ListBangunan(*P1));
		}
	} else {
		if (shieldDuration(*P2)>0) {
			shieldDuration(*P2) -=1;
			printf("Efek Shield tinggal %d turn\n",shieldDuration(*P2));
		} else {
			ShieldOff(ListBangunan(*P2));
		}
	}
}

void CriticalOff (int num,Player *P1,Player *P2)
/*	I.S. num, P1, dan P2 terdefinisi
	F.S. jika NoPemain(P) == num, maka Critical(P) adalah true 
*/
{
	/* Algoritma */
	if (NoPemain(*P1) == num) {
		Critical(*P1) = false;
	} else {
		Critical(*P2) = false;
	}
}