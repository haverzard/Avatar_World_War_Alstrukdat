/* ADT Player */
/* Menyimpan data pemain dan kepemilikannya */

#include <stdio.h>
#include "boolean.h"
#include "player.h"
#include "listlinier.h"
#include "queue.h"
#include "arraydinpos.h"
#include "bangunan.h"

//Global Variable
int extraTurn=0;
int attackUp = 0;



void InitPlayer(int num, Player *P) {
	Color(*P) = num;
	NoPemain(*P) = num;
	CreateEmpty_LL(&ListBangunan(*P));
	CreateEmpty_Queue(&Skill(*P), 10);
	First(ListBangunan(*P)) = Alokasi(num);
	Kepemilikan(ElmtArr(TB,num)) = num;
	IterateAndOwn(num, &ListBangunan(*P));
	shieldDuration(*P) = 0;
	Critical(*P) = false;
	// attackUpBool(*P) = false;
}

int NBElmtListB(int NoPemain, Player P1, Player P2) {
	if (NoPemain == 1) {
		return NbElmt(ListBangunan(P1));
	} else {
		return NbElmt(ListBangunan(P2));
	}
}

void PrintListBangunan(int num, Player P1, Player P2) {
	if (num == 1) {
		PrintInfo(ListBangunan(P1));
	} else {
		PrintInfo(ListBangunan(P2));
	}
}

void PrintMyConnectedBuildings(int num, int IdxList, Player P1, Player P2) {
	/* Algoritma */
    if (num == 1) {
    	ConnectedBuildings(InfoListByIndex(ListBangunan(P1), IdxList), ListBangunan(P1));
    } else {
    	ConnectedBuildings(InfoListByIndex(ListBangunan(P2), IdxList), ListBangunan(P2));
    }
}

void PrintNotMyConnectedBuildings(int num, int IdxList, Player P1, Player P2) {
	/* Algoritma */
    if (num == 1) {
    	ConnectedBuildings2(InfoListByIndex(ListBangunan(P1), IdxList), ListBangunan(P1));
    } else {
    	ConnectedBuildings2(InfoListByIndex(ListBangunan(P2), IdxList), ListBangunan(P2));
    }
}

int NBMyConnectedBuildings(int num, int IdxList, Player P1, Player P2) {
	/* Algoritma */
    if (num == 1) {
    	return NBConnectedBuildings(InfoListByIndex(ListBangunan(P1), IdxList), ListBangunan(P1));
    } else {
    	return NBConnectedBuildings(InfoListByIndex(ListBangunan(P2), IdxList), ListBangunan(P2));
    }
}

int NBNotMyConnectedBuildings(int num, int IdxList, Player P1, Player P2) {
	/* Algoritma */
    if (num == 1) {
    	return NBConnectedBuildings2(InfoListByIndex(ListBangunan(P1), IdxList), ListBangunan(P1));
    } else {
    	return NBConnectedBuildings2(InfoListByIndex(ListBangunan(P2), IdxList), ListBangunan(P2));
    }
}

int InfoMyBuilding(int num, int IdxList, Player P1, Player P2) {
	/* Algoritma */
    if (num == 1) {
    	return InfoListByIndex(ListBangunan(P1), IdxList);
    } else {
    	return InfoListByIndex(ListBangunan(P2), IdxList);
    }
}

int InfoConnectedBuilding(int num, int IdxList, int IdxConnected, Player P1, Player P2) {
	/* Algoritma */
    if (num == 1) {
    	return InfoConnectedBuildingByIdx(InfoListByIndex(ListBangunan(P1), IdxList), IdxConnected, ListBangunan(P1));
    } else {
    	return InfoConnectedBuildingByIdx(InfoListByIndex(ListBangunan(P2), IdxList), IdxConnected, ListBangunan(P2));
    }
}

int InfoConnectedBuilding2(int num, int IdxList, int IdxConnected, Player P1, Player P2) {
	/* Algoritma */
    if (num == 1) {
    	return InfoConnectedBuildingByIdx2(InfoListByIndex(ListBangunan(P1), IdxList), IdxConnected, ListBangunan(P1));
    } else {
    	return InfoConnectedBuildingByIdx2(InfoListByIndex(ListBangunan(P2), IdxList), IdxConnected, ListBangunan(P2));
    }
}

void CaptureBuilding(int num, Bangunan *B, Player P1, Player P2) {
	/* Algoritma */
	if (num == 1) {
		ChangeOwner(B, P1, P2);
	} else {
		ChangeOwner(B, P2, P1);
	}
}

void ChangeOwner(Bangunan *B, Player Me, Player Enemy) {
	Kepemilikan(*B) = NoPemain(Me);
	InsVLast(&ListBangunan(Me), Search1(TB,*B));
	if (Kepemilikan(*B) == NoPemain(Enemy)) {
		DelP(&ListBangunan(Enemy),*B);
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
    LevelUpAll(ListBangunan(*P));
}

void Shield (Player *P){
    ShieldOn(ListBangunan(*P));
	if(shieldDuration(*P)==0){
		shieldDuration(*P) += 4; //2 round = 4 endturn
	}
}

void ExtraTurn (Player *P){
	extraTurn = 1;
}

void AttackUp (Player *attacker,Player *defender){
	AttackUpAll(ListBangunan(*defender));
	attackUp = 1;
	// attackUpBool(*attacker) = true;
}

void CriticalHit (Player *user){
    Critical(*user) = true;
}

void InstantReinforcement (Player *P){
    ReinforceAll(ListBangunan(*P));
}

void Barrage (Player *P){
    BarrageAll(ListBangunan(*P));
}


/* *** Keep Skill *** */
void KeepSkill (Player *user, skilltype skillName){
	if (!IsFull_Queue(Skill(*user))){
		Add(&Skill(*user),skillName);	
	}    
}

/* *** Use Skill*** */
void UseSkillP (Player *user,Player *enemy){
	skilltype X;

	if (IsEmpty_Queue(Skill(*user))){
		printf("Tidak ada skill yang available\n");
	} else {
		if ((InfoHead(Skill(*user)) == 'U') || (InfoHead(Skill(*user)) == 'u')) {
			InstantUpgrade(user);
		} else if ((InfoHead(Skill(*user)) == 'S') || (InfoHead(Skill(*user)) == 's')){
			Shield(user);
		} else if ((InfoHead(Skill(*user)) == 'E') || (InfoHead(Skill(*user)) == 'e')){
			ExtraTurn(user);
			KeepSkill(enemy,'C');
			printf("Lawan anda mendapatkan skill Critical Hit");
		} else if ((InfoHead(Skill(*user)) == 'A') || (InfoHead(Skill(*user)) == 'a')){
			AttackUp(user,enemy);
		} else if ((InfoHead(Skill(*user)) == 'H') || (InfoHead(Skill(*user)) == 'h')){
			CriticalHit(user);
		} else if ((InfoHead(Skill(*user)) == 'R') || (InfoHead(Skill(*user)) == 'r')){
			InstantReinforcement(user);
		} else {
			Barrage(user);
		}
		Del(&Skill(*user),&X);
	}
}

void UseSkill(int num, Player *P1, Player *P2) {
	if (NoPemain(*P1) == num) {
		UseSkillP(P1,P2);
	} else{
		UseSkillP(P2,P1);
	}
}

void PrintSkill(Player P) {
	switch(InfoHead(Skill(P))) {
		case 'U': printf("Instant Upgrade"); break;
		case 'u': printf("Instant Upgrade"); break;
		case 'S': printf("Shield"); break;
		case 's': printf("Shield"); break;
		case 'E': printf("Extra Turn"); break;
		case 'e': printf("Extra Turn"); break;
		case 'A': printf("Attack Up"); break;
		case 'a': printf("Attack Up"); break;
		case 'H': printf("Critical Hit"); break;
		case 'h': printf("Critical Hit"); break;
		case 'R': printf("Instant Reinforcement"); break;
		case 'r': printf("Instant Reinforcement"); break;
		case 'B': printf("Barrage"); break;
		case 'b': printf("Barrage"); break;
	}
}

void ShowSkill(int num, Player P1, Player P2) {
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
	//Kamus Lokal
	address Q;
	boolean level4;

	//Algoritma
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
	KeepSkill(P,'U');
}

void GetShield(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2){
	if (num == NoPemain(*P1)){
		if ((buildingAwalP2==3) && (buildingAkhirP2 ==2)){
			KeepSkill(P2,'S');
		}
	} else {
		if ((buildingAwalP1==3) && (buildingAkhirP1 ==2)){
			KeepSkill(P1,'S');
		}
	}
	printf("Lawanmu mendapat skill Shield\n");
}

void GetExtraTurn(int num,Player *P1,Player *P2,int Fdawal,int Fdakhir){
	if (Fdakhir == Fdawal-1){
		if (num == NoPemain(*P1)){
			KeepSkill(P2,'E');
		} else {
			KeepSkill(P1,'E');
		}
		printf("Anda mendapat skill Extra Turn \n");	
	}
}

void GetAttackUp (int num,Player *P1,Player *P2,int Tdawal,int Tdakhir){
	if ((Tdawal == 4) && (Tdakhir ==3)){
		if (num == NoPemain(*P1)){
			KeepSkill(P1,'A');
		} else {
			KeepSkill(P2,'A');
		}
		printf("Lawanmu mendapat skill Attack Up\n");	
	}
}

void GetIReinforcement(int num, Player *P1,Player *P2){
	if (NoPemain(*P1) == num) {
		if (isAllLevel4(*P1)){
			KeepSkill(P1,'R');
		}
	} else {
		if (isAllLevel4(*P2)){
			KeepSkill(P2,'R');
		}
	}
	printf("Kamu mendapatkan skill Instant Reinforcement");
}

void GetBarrage(int num,Player *P1,Player *P2,int buildingAwalP1,int buildingAkhirP1,int buildingAwalP2 ,int buildingAkhirP2){
	if (num == NoPemain(*P1)){
		if ((buildingAwalP1==9) && (buildingAkhirP1 ==10)){
			KeepSkill(P2,'B');
		}
	} else {
		if ((buildingAwalP2==9) && (buildingAkhirP2 ==10)){
			KeepSkill(P1,'B');
		}
	}
	printf("Lawanmu mendapat skill Barrage\n");
}


void HitungFort(int num,Player P1,Player P2,int *F){
	//Kamus Lokal
	address Q;
	int fort;
	
	//Algoritma
	fort = 0;
	if (num = NoPemain(P1)){
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
	address Q;
	int tower;
	
	//Algoritma
	tower = 0;
	if (num = NoPemain(P1)){
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

void MinShieldDuration (int num,Player *P1,Player *P2){
//FS: Jika shieldDuration =0 tidak terjadi perubahan, Jika shieldDuration tidak nol maka dikurangin 1
	if(NoPemain(*P1) == num) {
		if (shieldDuration(*P1)>0){
			shieldDuration(*P1) -=1;
		}
	} else {
		if (shieldDuration(*P2)>0){
			shieldDuration(*P2) -=1;
		}
	}
}

void CriticalOff (int num,Player *P1,Player *P2){
//Prekondisi jika NoPemain(P) == num, maka Critical(P) adalah true 
	if (NoPemain(*P1) == num) {
		Critical(*P1) = false;
	} else {
		Critical(*P2) = false;
	}
}

// void HitungBangunan (Player P,int *C,int *T, int *F, int *V){
	// //Kamus Lokal
	// address Q;
	// int castle,tower,fort,village;
	
	// //Algoritma
	// castle = 0;
	// tower = 0;
	// village = 0;
	// fort = 0;

	// Q = First(ListBangunan(P));
	// while (Q != Nil){
	// 	if (Jenis(ElmtArr(TB,Info(Q))) == 'C'){
	// 		castle +=1;
	// 	}
	// 	if (Jenis(ElmtArr(TB,Info(Q))) == 'T'){
	// 		tower +=1;
	// 	}
	// 	if (Jenis(ElmtArr(TB,Info(Q))) == 'F'){
	// 		fort +=1;
	// 	}
	// 	if (Jenis(ElmtArr(TB,Info(Q))) == 'V'){
	// 		village +=1;
	// 	}
	// 	Q = Next(Q);
	// }
	// *C = castle;
	// *T = tower;
	// *F = fort;
	// *V = village;
// }


//procedure ini dipanggil di main ?????

// void SerangPlayer (int input,Player *attacker, Player *defender){
// 	//Kamus Lokal
// 	//attacker
// 	int CAawal,TAawal,FAawal,VAawal; //A -> Attacker
// 	int CAakhir,TAakhir,FAakhir,VAakhir;
// 	int TotalAwalA,TotalAkhirA;
// 	//defender
// 	int CDawal,TDawal,FDawal,VDawal;//D -> Defender
// 	int CDakhir,TDakhir,FDakhir,VDakhir;
// 	int TotalAwalD,TotalAkhirD;
// 	address ListDefender;

// 	//Algoritma
// 	HitungBangunan(*attacker,&CAawal,&TAawal,&FAawal,&VAawal);
// 	HitungBangunan(*defender,&CDawal,&TDawal,&FDawal,&VDawal);
// 	TotalAwalA  = CAawal+TAawal+FAawal+VAawal;
// 	TotalAwalD  = CDakhir+TDakhir+FDakhir+VDakhir;
// 	ListDefender = 	First(ListBangunan(*defender));
// 	for (int i=1;i <= input;i++){ //anggap input valid
// 		ListDefender = Next(ListDefender);
// 	}
// 	//if CriticalHit .......
// 	SerangBangunan(&ElmtArr(TB,Info(ListDefender)),JumlahPasukan(ElmtArr(TB,Info(ListDefender))));
// 	HitungBangunan(*defender,&CDakhir,&TDakhir,&FDakhir,&VDakhir);
// 	TotalAkhirA = CAakhir+TAakhir+FAakhir+VAakhir;
// 	TotalAkhirD = CDakhir+TDakhir+FDakhir+VDakhir;
// 	if (TotalAwalD==3 && TotalAkhirD==2){
// 		KeepSkill(defender,'S');
// 	}
// 	if (FDakhir == FDawal-1){
// 		KeepSkill(defender,'E');
// 	}
// 	if (TDawal==4 && TDakhir==3){// asumsi "towernya" itu tower lawan.
// 		KeepSkill(defender,'A');
// 	}
// }

// void PlayerCriticalAttack(Player *attacker,Player *defender){

// }


// void HitungFnT (int num,Player P1,Player 2,int *F,int *T){//hitung jumlah Fort dan Tower dari lawan
// 	//Kamus Lokal
// 	address Q;
// 	int castle,tower,fort,village;
	
// 	//Algoritma
// 	tower = 0;
// 	fort = 0;
// 	if (num = NoPemain(P1)){
// 		Q = First(ListBangunan(P2));
// 		while (Q != Nil){
// 			if (Jenis(ElmtArr(TB,Info(Q))) == 'T'){
// 				tower +=1;
// 			}
// 			if (Jenis(ElmtArr(TB,Info(Q))) == 'F'){
// 				fort +=1;
// 			}
// 			Q = Next(Q);
// 		}
// 		*T = tower;
// 		*F = fort;
// 	} else {
// 		Q = First(ListBangunan(P1));
// 		while (Q != Nil){
// 			if (Jenis(ElmtArr(TB,Info(Q))) == 'T'){
// 				tower +=1;
// 			}
// 			if (Jenis(ElmtArr(TB,Info(Q))) == 'F'){
// 				fort +=1;
// 			}
// 			Q = Next(Q);
// 		}
// 		*T = tower;
// 		*F = fort;
// 	}
// }

//Diset up di main
// void GetdExtraTurn();
// void GetAttackUp();
// void GetCriticalHit();
// void GetBarrage();


