/* ADT Menu Utama */
/* Mengatur segala output dan input user dan memprosesnya */

#include <stdio.h>
#include <stdlib.h>
#include "mainmenu.h"
#include "boolean.h"
#include "matriks.h"
#include "player.h"
#include "bangunan.h"
#include "mesindata.h"
#include "mesinkata.h"
#include "arraydinpos.h"
#include "stack.h"

#define printl(x) printf("%s\n", x);
#define println() printf("\n");

/* Variable Global */
int choice;
boolean EndGame;
boolean EndTurn = false;
boolean SkillUsed = false;
Stack Status;

void STARTGAME() 
/* 	I.S. Menampilkan menu awal dan menerima masukan user 
	F.S. Choice terisi dan game akan mulai di-load jika choice sesuai.
		 Jika choice tidak sesuai, balik lagi ke menu utama.
*/
{
	/* Algoritma */
	printl("█████████████████████████████████████████████████████");
	printl("██                                                 ██");
	printl("██       ███  █   █  ███  █████  ███  ███          ██");
	printl("██      █   █ █   █ █   █   █   █   █ █  █         ██");
	printl("██      █████  █ █  █████   █   █████ ███          ██");
	printl("██      █   █   █   █   █   █   █   █ █  █         ██");
	printl("██                    Where the world war          ██");
	printl("██                                  begins.....    ██");
	printl("█████████████████████████████████████████████████████");
	printl("");
	printl("Selamat datang di Game Avatar World War!");
	printl("Silahkan pilih menu yang diinginkan:");
	printl("1. Start New Game");
	printl("2. Load Game");
	printf("Masukkan Anda: "); scanf("%d", &choice);
	printl("HUHU -_-"); println();
	SCAN();
	LOADGAME();
}

void LOADGAME() {
	/* Algoritma */
	if (choice == 1 || choice == 2) {
		STARTDATA();
	} else {
		printl("Inputnya yang benar dong!"); println();
		EndGame = true;
	}
}

void CREATEPLAYER(Player *P1, Player *P2) 
/*	I.S. P1 dan P2 belum terdefinisi
	F.S. P1 dan P2 sudah terdefinisi termasuk atribut-atributnya
*/
{
	InitPlayer(1, P1);
	InitPlayer(2, P2);
}

void TURN(int NoPemain, MATRIKS Peta, Player *P1, Player *P2) 
/*	I.S. Menampilkan informasi player dan menerima masukan command user
	F.S. Memproses command player jika command ada di list command yang tersedia
		 Jika tidak command tidak valid, ditampilkan pesan "Inputnya yang benar dong!". 
*/
{
	TulisMATRIKSPETA(Peta); println();
	printf("Player %d\n", NoPemain);
	PrintListBangunan(NoPemain, *P1, *P2); println();
	ShowSkill(NoPemain, *P1, *P2); println();
	printl("COMMAND YANG TERSEDIA:");
	printl("1. ATTACK	5. END_TURN");
	printl("2. LEVEL_UP	6. SAVE");
	printl("3. SKILL	7. MOVE");
	printl("4. UNDO		8. EXIT");
	printf("ENTER COMMAND: ");
	SCANKATA();
	if (EQ_KATA(CKata, "ATTACK")) {
		ATTACK(NoPemain, *P1, *P2);
	} else if (EQ_KATA(CKata, "LEVEL_UP")) {
		LEVELUP(NoPemain, *P1, *P2);
	} else if (EQ_KATA(CKata, "SKILL")) {
		UseSkill(NoPemain, P1, P2);
		SkillUsed = true;
	} else if (EQ_KATA(CKata, "UNDO")) {
		UNDO(P1, P2, SkillUsed);
	} else if (EQ_KATA(CKata, "END_TURN")) {
		EndTurn = true;
		SkillUsed = false;
		ResetStatus(&Status);
	} else if (EQ_KATA(CKata, "SAVE")) {
		printl("SAVE!");
	} else if (EQ_KATA(CKata, "MOVE")) {
		MOVE(NoPemain, *P1, *P2);
	} else if (EQ_KATA(CKata, "EXIT")) {
		printl("EXIT!");
		EndTurn = true;
		EndGame = true;
	} else {
		printl("Inputnya yang benar dong!"); println();
	}
	printl("");
}

void ATTACK(int NoPemain, Player P1, Player P2) 
/*	I.S. Menampilkan daftar bangunan untuk menyerang.
	F.S. Jika tidak ada bangunan untuk diserang, ditampilkan pesan "Tidak ada bangunan yang dapat diserang".
		 Jika ada, pemain telah memilih bangunan untuk menyerang, bangunan untuk diserang, dan jumlah pasukan untuk menyerang.
		 Untuk semua input tidak valid, ada pesan error masing-masing.
*/
{
	/* Kamus Lokal */
	int choice, choice2, count, idx;
	Bangunan *B1, *B2;
	int Fdawal,Tdawal; //F itu Fort, T itu Tower, d itu defender
	int Fdakhir,Tdakhir;
	int jumlahBangunanP1awal;
	int jumlahBangunanP2awal;
	int jumlahBangunanP1akhir;
	int jumlahBangunanP2akhir;

	/* Algoritma */
	printf("Daftar bangunan: \n");
	PrintListBangunan(NoPemain, P1, P2);
	printf("Bangunan yang digunakan untuk menyerang: "); scanf("%d", &choice);
	if (choice <= NBElmtListB(NoPemain, P1, P2) && choice > 0) {
		B1 = &ElmtArr(TB, InfoMyBuilding(NoPemain, choice, P1, P2));
		if (AttackAvai(*B1)) {
			count = NBNotMyConnectedBuildings(NoPemain, choice, P1, P2);
			if (count) {
				PrintNotMyConnectedBuildings(NoPemain, choice, P1, P2);
				printf("Bangunan yang diserang: "); scanf("%d", &choice2);
				if (choice2 <= count && choice2 > 0) {
					printf("Jumlah pasukan: "); scanf("%d", &count);
					B2 = &ElmtArr(TB, InfoConnectedBuilding2(NoPemain, choice, choice2, P1, P2));
					if (count > 0 && count <= JumlahPasukan(*B1)) {
						HitungFort(NoPemain,P1,P2,&Fdawal);
						HitungTower(NoPemain,P1,P2,&Tdawal);
						jumlahBangunanP1awal = NbElmt(ListBangunan(P1));
						jumlahBangunanP2awal = NbElmt(ListBangunan(P2));
						if (isCurrentPCritical(NoPemain,P1,P2)){
							UPDATESTATUS(P1, P2);
							SerangCritical(B1, B2, count);
							CriticalOff(NoPemain,&P1,&P2);
						} else {
							UPDATESTATUS(P1, P2);
							SerangBangunan(B1, B2, count);	
						}
						// UPDATESTATUS(P1, P2);
						// SerangBangunan(B1, B2, count);
						if (JumlahPasukan(*B2) <= 0) {
							JumlahPasukan(*B2) = abs(JumlahPasukan(*B2));
							CaptureBuilding(NoPemain, B2, P1, P2);
							HitungFort(NoPemain,P1,P2,&Fdakhir);
							HitungTower(NoPemain,P1,P2,&Tdakhir);
							jumlahBangunanP1akhir = NbElmt(ListBangunan(P1));
							jumlahBangunanP2akhir = NbElmt(ListBangunan(P2));
							GetShield(NoPemain,&P1,&P2,jumlahBangunanP1awal,jumlahBangunanP1akhir,jumlahBangunanP2awal,jumlahBangunanP2akhir);
							GetExtraTurn(NoPemain,&P1,&P2,Fdawal,Fdakhir);
							GetAttackUp(NoPemain,&P1,&P2,Tdawal,Tdakhir);
							GetBarrage(NoPemain,&P1,&P2,jumlahBangunanP1awal,jumlahBangunanP1akhir,jumlahBangunanP2awal,jumlahBangunanP2akhir);
							printf("Bangunan menjadi milikku!\n");
						} else {
							printf("Bangunan gagal direbut.\n");
						}
					} else {
						printl("Jumlah pasukan tidak valid untuk ATTACK!");
					}
				} else {
					printl("Inputnya yang benar dong!");
				}
			} else {
				printl("Tidak ada bangunan yang dapat diserang");
			}
		} else {
			printl("Bangunan tidak tersedia untuk ATTACK!");
		}
	} else {
		printl("Inputnya yang benar dong!");
	}
	SCAN();
	
}

void MOVE(int NoPemain, Player P1, Player P2) {
	/* Kamus Lokal */
	int choice, choice2, count, idx;
	Bangunan *B1, *B2;

	/* Algoritma */
	printl("Daftar bangunan: ");
	PrintListBangunan(NoPemain, P1, P2); println();
	printf("Pilih bangunan: "); scanf("%d", &choice);
	if (choice <= NBElmtListB(NoPemain, P1, P2) && choice > 0) {
		B1 = &ElmtArr(TB, InfoMyBuilding(NoPemain, choice, P1, P2));
		if (MoveAvai(*B1)) {
			count = NBMyConnectedBuildings(NoPemain, choice, P1, P2);
			if (count) {
				PrintMyConnectedBuildings(NoPemain, choice, P1, P2);
				printf("Bangunan yang akan menerima: "); scanf("%d", &choice2);
				if (choice2 <= count && choice2 > 0) {
					printf("Jumlah pasukan: "); scanf("%d", &count);
					B2 = &ElmtArr(TB, InfoConnectedBuilding(NoPemain, choice, choice2, P1, P2));
					if (count > 0 && count <= JumlahPasukan(*B1)) {
						UPDATESTATUS(P1, P2);
						Move(B1, B2, count);
						printf("%d pasukan dari ", count); 
						PrintJenisByCode(Jenis(*B1)); printf(" ");
						TulisPOINT(Koordinat(*B1)); 
						printf(" telah berpindah ke ");
						PrintJenisByCode(Jenis(*B2)); printf(" ");
						TulisPOINT(Koordinat(*B2)); 
						printf("\n");
					} else {
						printl("Jumlah pasukan tidak valid untuk MOVE!");
					}
				} else {
					printl("Inputnya yang benar dong!");
				}
			} else {
				printl("Bangunan tidak memiliki keterhubungan!");
			}
		} else {
			printl("Bangunan tidak tersedia untuk MOVE!");
		}
	} else {
		printl("Inputnya yang benar dong!");
	}
	SCAN();
}

void LEVELUP(int NoPemain, Player P1, Player P2) {
	/* Kamus Lokal */
	int choice;

	/* Algoritma */
	PrintListBangunan(NoPemain, P1, P2);
	printf("Bangunan yang akan di level up: "); scanf("%d", &choice);
	LevelUpBP(NoPemain, P1, P2, choice);
	SCAN();
}

void UPDATESTATUS (Player P1, Player P2) {
	UpdateStatus_Stack(&Status, P1, P2, TB);
	// infotypeStack X; Pop(&Status, &X); printf("INFO PLAYER: %d\n", NoPemain(InfoPlayer(X)));
}

void UNDO (Player *P1, Player *P2, boolean isSkillUsed) {
	if (!isSkillUsed) {
		UndoStatus_Stack(&Status, P1, P2, &TB);
	} else {
		printf("Tidak bisa UNDO karena sudah menggunakan SKILL pada TURN ini.\n"); println();
	}
}