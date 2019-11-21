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

/* Variable Global */
int choice;
boolean EndGame;
boolean EndTurn = false;
Stack StatusP1, StatusP2;

void STARTGAME() {
	/* Algoritma */
	//printf("\033[01;33m");
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
	printl("HUHU -_-");
	SCAN();
	LOADGAME();
}

void LOADGAME() {
	/* Algoritma */
	if (choice == 1 || choice == 2) {
		STARTDATA();
	} else {
		printl("Inputnya yang benar dong!");
		EndGame = true;
	}
}

void CREATEPLAYER(Player *P1, Player *P2) {
	InitPlayer(1, P1);
	InitPlayer(2, P2);
}

void TURN(int NoPemain, MATRIKS Peta, Player P1, Player P2) {
	// UPDATESTATUS(NoPemain, P1, P2);
	TulisMATRIKSPETA(Peta);
	printf("Player %d\n", NoPemain);
	PrintListBangunan(NoPemain, P1, P2);
	ShowSkill(NoPemain, P1, P2);
	printl("COMMAND YANG TERSEDIA:");
	printl("1. ATTACK	5. END_TURN");
	printl("2. LEVEL_UP	6. SAVE");
	printl("3. SKILL	7. MOVE");
	printl("4. UNDO		8. EXIT");
	printf("ENTER COMMAND: ");
	SCANKATA();
	UPDATESTATUS(NoPemain, P1, P2);
	if (EQ_KATA(CKata, "ATTACK")) {
		ATTACK(NoPemain, P1, P2);
	} else if (EQ_KATA(CKata, "LEVEL_UP")) {
		LEVELUP(NoPemain, P1, P2);
	} else if (EQ_KATA(CKata, "SKILL")) {
		UseSkill(NoPemain,&P1,&P2);
	} else if (EQ_KATA(CKata, "UNDO")) {
		printl("UNDO!");
		UNDO(NoPemain, &P1, &P2);
	} else if (EQ_KATA(CKata, "END_TURN")) {
		EndTurn = true;
	} else if (EQ_KATA(CKata, "SAVE")) {
		printl("SAVE!");
	} else if (EQ_KATA(CKata, "MOVE")) {
		MOVE(NoPemain, P1, P2);
	} else if (EQ_KATA(CKata, "EXIT")) {
		printl("EXIT!");
		EndTurn = true;
		EndGame = true;
	} else {
		printl("Inputnya yang benar dong!");
	}
	
}

void ATTACK(int NoPemain, Player P1, Player P2) {
	/* Kamus Lokal */
	int choice, choice2, count, idx;
	Bangunan *B1, *B2;

	/* Algoritma */
	printf("Daftar bangunan: \n");
	PrintListBangunan(NoPemain, P1, P2);
	printf("Bangunan yang digunakan untuk menyerang: "); scanf("%d", &choice);
	// Critical
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
						SerangBangunan(B1, B2, count);
						if (JumlahPasukan(*B2) <= 0) {
							JumlahPasukan(*B2) = abs(JumlahPasukan(*B2));
							CaptureBuilding(NoPemain, B2, P1, P2);
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
	PrintListBangunan(NoPemain, P1, P2);
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

void UPDATESTATUS (int NoPemain, Player P1, Player P2) {
	UpdateStatus_Stack(&StatusP1, P1, P2, TB);
	// infotypeStack X; Pop(&StatusP1, &X); printf("INFO PLAYER: %d\n", NoPemain(InfoPlayer(X)));
}

void UNDO (int NoPemain, Player *P1, Player *P2) {
	// printf("NOOOO %d\n", NoPemain);
	Player temp1, temp2;
	UndoStatus_Stack(&StatusP1, P1, P2, &TB);
	UndoStatus_Stack(&StatusP1, P1, P2, &TB);
	PrintListBangunan(1,*P1,*P2);
	// *P1 = temp1; *P2 = temp2;
	// infotypeStack X; Pop(&StatusP1, &X); printf("INFO PLAYER: %d\n", NoPemain(InfoPlayer(X)));
}