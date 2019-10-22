/* ADT Menu Utama */
/* Mengatur segala output dan input user dan memprosesnya */

#include <stdio.h>
#include "mainmenu.h"
#include "boolean.h"
#include "matriks.h"
#include "player.h"
#include "bangunan.h"
#include "mesindata.h"
#include "mesinkata.h"

#define printl(x) printf("%s\n", x);

/* Variable Global */
int choice;
boolean EndGame;
boolean EndTurn = false;

void STARTGAME() {
	/* Algoritma */
	printf("\033[02;30m");
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

void TURN(int NoPemain, MATRIKS Peta, Player *P1, Player *P2) {
	TulisMATRIKSPETA(Peta);
	printf("Player %d\n", NoPemain);
	PrintListBangunan(NoPemain, *P1, *P2);
	printl("COMMAND YANG TERSEDIA:");
	printl("1. ATTACK	5. END_TURN");
	printl("2. LEVEL_UP	6. SAVE");
	printl("3. SKILL	7. MOVE");
	printl("4. UNDO		8. EXIT");
	printf("ENTER COMMAND: ");
	SCANKATA();
	if (EQ_KATA(CKata, "ATTACK")) {
		ATTACK(NoPemain, P1, P2);
	} else if (EQ_KATA(CKata, "LEVEL_UP")) {
		LEVELUP(NoPemain, *P1, *P2);
	} else if (EQ_KATA(CKata, "SKILL")) {
		printl("SKILL!");
	} else if (EQ_KATA(CKata, "UNDO")) {
		printl("UNDO!");
	} else if (EQ_KATA(CKata, "END_TURN")) {
		EndTurn = true;
	} else if (EQ_KATA(CKata, "SAVE")) {
		printl("SAVE!");
	} else if (EQ_KATA(CKata, "MOVE")) {
		printl("MOVE!");
	} else if (EQ_KATA(CKata, "EXIT")) {
		printl("EXIT!");
		EndTurn = true;
		EndGame = true;
	} else {
		printl("Inputnya yang benar dong!");
	}
}

void ATTACK(int NoPemain, Player *P1, Player *P2) {
	/* Kamus Lokal */
	int choice;

	/* Algoritma */
	PrintListBangunan(NoPemain, *P1, *P2);
	printf("Bangunan yang digunakan untuk menyerang: "); scanf("%d", &choice);
	// Critical
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