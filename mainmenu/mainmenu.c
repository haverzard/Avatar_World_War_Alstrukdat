/* ADT Menu Utama */
/* Mengatur segala output dan input user dan memprosesnya */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../mainmenu/mainmenu.h"
#include "../boolean/boolean.h"
#include "../matrikskar/matriks.h"
#include "../player/player.h"
#include "../bangunan/bangunan.h"
#include "../mesindata/mesindata.h"
#include "../mesinkata/mesinkata.h"
#include "../arraydinpos/arraydinpos.h"
#include "../stack/stack.h"
#include "../graph/graph.h"
#include "../queue/queue.h"

#define printl(x) printf("%s\n", x);
#define println() printf("\n");

/* Variable Global */
int turn;
boolean EndGame;
boolean EndTurn = false;
boolean SkillUsed = false;
Stack Status;

void STARTGAME(Player *P1, Player *P2) 
/* 	I.S. Menampilkan menu awal dan menerima masukan user 
	F.S. Choice terisi dan game akan mulai di-load jika choice sesuai.
		 Jika choice tidak sesuai, balik lagi ke menu utama.
*/
{
	/* Kamus Lokal */
	int choice;
	char filename[150], temp[100];

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
	println();
	SCAN();
	if (choice == 1) {
		printf("Masukkan lokasi data template: "); scanf("%100s", temp);
		strcpy(filename, "templates/"); strcat(filename, temp);
		SCAN();
		STARTDATA(filename);
		INFOPETA(&Peta);
		INFOBANGUNAN(&TB);
		LOKASIBANGUNAN(&Peta, &TB);
		HUBUNGANBANGUNAN(&Hubungan, NBElmt_Array(TB));
		GenerateHubunganBangunan(&GHubungan, Hubungan);
		CREATEPLAYER(P1, P2);
		GetIUpgrade (P1);
		GetIUpgrade (P2);
	} else if (choice == 2) {
		printf("Masukkan lokasi file data save: "); scanf("%100s", temp);
		strcpy(filename, "savefiles/"); strcat(filename, temp);
		SCAN();
		STARTDATA(filename);
		NoPemain(*P1) = 1; NoPemain(*P2) = 2;
		INFOPETA(&Peta);
		INFOBANGUNAN(&TB);
		LOKASIBANGUNAN(&Peta, &TB);
		HUBUNGANBANGUNAN(&Hubungan, NBElmt_Array(TB));
		GenerateHubunganBangunan(&GHubungan, Hubungan);
		MOREINFOBANGUNAN(&TB);
		INFOTURN(&turn);
		INFOCOLOR(P1, P2);
		LOADBANGUNANPLAYER(P1, P2);
		LOADSKILL(P1, P2);
		CreateEmpty_Stack(&Status);
		shieldDuration(*P1) = 0; shieldDuration(*P2) = 0;
		Critical(*P1) = false; Critical(*P2) = false;
		printf("File berhasil di load!\n");
	} else {
		printl("Input yang benar dong!");
		EndGame = true;
	}
}

void SAVEGAME(int num, Player P1, Player P2) 
/*	I.S. P1, P2, TB, GHubungan terdefinisi
	F.S. Terbentuk file data save sesuai inputan player dengan spesifikasi khusus
*/
{
	/* Kamus Lokal */
	FILE * save;
	char filename[150], temp[100];
	int i, j, NbSkill1, NbSkill2;
	Bangunan B;
	address temp1, temp2;

	/* Algoritma */
	printf("Masukkan nama data save: "); scanf("%100s", temp);
	strcpy(filename, "savefiles/"); strcat(filename, temp);
	SCAN();
	save = fopen(filename,"w");
	/* Ukuran Peta */
	fprintf(save,"%d %d\n", NBrsEff(Peta), NKolEff(Peta));
	/* Ukuran Array */
	fprintf(save,"%d\n", MaxElArr(TB));
	/* Posisi Bangunan */
	for (i = 1; i <= MaxElArr(TB); i++) {
		B = ElmtArr(TB,i);
		fprintf(save, "%c %d %d\n", Jenis(B), Absis(Koordinat(B)), Ordinat(Koordinat(B)));
	}
	/* Hubungan Graph */
	for (i = 1; i <= MaxElArr(TB); i++) {
		fprintf(save, "%d", ElmtMatInt(Hubungan,i,1));
		for (j = 2; j <= MaxElArr(TB); j++) {
			fprintf(save, " %d", ElmtMatInt(Hubungan,i,j));
		}
		fprintf(save, "\n");
	}
	// =============== SUDAH BEDA SAMA PITAKAR =========================== 
	/* Info Bangunan */
	for (i = 1; i <= MaxElArr(TB); i++) {
		B = ElmtArr(TB,i);
		fprintf(save, "%d %d %d %d %d %d %d %d\n", Kepemilikan(B), JumlahPasukan(B), Level(B), A(B), M(B), P(B), AttackAvai(B), MoveAvai(B));
	}
	/* Turn */
	fprintf(save,"%d\n", num);
	/* Warna Pemain */
	fprintf(save,"%d %d\n", Color(P1), Color(P2));
	/* List Bangunan P1 */
	temp1 = First(ListBangunan(P1));
	if (temp1 != Nil) {
		fprintf(save, "%d", Info(temp1));
		temp1 = Next(temp1);
		while (temp1 != Nil) {
			fprintf(save, " %d", Info(temp1));
			temp1 = Next(temp1);
		}
	}
	fprintf(save, "\n");
	/* List Bangunan P2 */
	temp2 = First(ListBangunan(P2));
	if (temp2 != Nil) {
		fprintf(save, "%d", Info(temp2));
		temp2 = Next(temp2);
		while (temp2 != Nil) {
			fprintf(save, " %d", Info(temp2));
			temp2 = Next(temp2);
		}
	}
	fprintf(save, "\n");
	/* Isi Queue Skill P1 */
	NbSkill1 = NBElmt_Queue(Skill(P1));
	if (NbSkill1 > 0) {
		fprintf(save, "%c", Skill(P1).S[1]); 
		for (i = 2; i <= NbSkill1; i++) {
			fprintf(save, " %c", Skill(P1).S[i]);
		}
	}
	fprintf(save, "\n");
	/* Isi Queue Skill P2 */ 
	NbSkill2 = NBElmt_Queue(Skill(P2));
	if (NbSkill2 > 0) {
		fprintf(save, "%c", Skill(P2).S[1]);
		for (i = 2; i <= NbSkill2; i++) {
			fprintf(save, " %c", Skill(P2).S[i]);
		}
	}
	/* Stack */
	/* Setelah Proses Load diasumsikan pemain tidak dapat UNDO */
	printf("Game berhasil di save!\n");
	fclose(save);
}

void CREATEPLAYER(Player *P1, Player *P2) 
/*	I.S. P1 dan P2 belum terdefinisi
	F.S. P1 dan P2 sudah terdefinisi termasuk atribut-atributnya
*/
{
	InitPlayer(1, P1, *P2);
	InitPlayer(2, P2, *P1);
}

void TURN(int NoPemain, Player *P1, Player *P2)
/*	I.S. Menampilkan informasi player dan menerima masukan command user
	F.S. Memproses command player jika command ada di list command yang tersedia
		 Jika tidak command tidak valid, ditampilkan pesan "Inputnya yang benar dong!". 
		 Jika pemain menang, ditampilkan pesan selamat dan credits. 
*/
{
	/* Algoritma */
	TulisMATRIKSPETA(Peta, *P1, *P2); println();
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
		ATTACK(NoPemain, P1, P2);
	} else if (EQ_KATA(CKata, "LEVEL_UP")) {
		LEVELUP(NoPemain, *P1, *P2);
	} else if (EQ_KATA(CKata, "SKILL")) {
		UseSkill(NoPemain, P1, P2);
	} else if (EQ_KATA(CKata, "UNDO")) {
		UNDO(P1, P2, SkillUsed);
	} else if (EQ_KATA(CKata, "END_TURN")) {
		EndTurn = true;
		SkillUsed = false;
		ResetStatus(&Status);
	} else if (EQ_KATA(CKata, "SAVE")) {
		SAVEGAME(NoPemain, *P1, *P2);
	} else if (EQ_KATA(CKata, "MOVE")) {
		MOVE(NoPemain, *P1, *P2);
	} else if (EQ_KATA(CKata, "EXIT")) {
		printl("Selamat tinggal!");
		EndTurn = true;
		EndGame = true;
	} else {
		printl("Inputnya yang benar dong!"); println();
	}
	if (CheckWinOrNot(NoPemain, *P1, *P2)) {
		println();
		printf("Selamat kepada Pemain bernomor %d! Anda menang!\n", NoPemain);
		println();
		printl("***************CREDITS****************");
		printl("CREATED BY:");
		printl("   Kelompok ??? K-3 - Tony Eko");
		printl("                      Arthur Edgar");
		printl("                      Yonatan Viody");
		printl("                      Stephen Thajeb");
		EndTurn = true;
		EndGame = true;
	}
	println();
}

void ATTACK(int NoPemain, Player *P1, Player *P2) 
/*	I.S. Menampilkan daftar bangunan untuk menyerang.
	F.S. Jika tidak ada bangunan untuk diserang, ditampilkan pesan "Tidak ada bangunan yang dapat diserang".
		 Jika ada, pemain telah memilih bangunan untuk menyerang, bangunan untuk diserang, dan jumlah pasukan untuk menyerang.
		 Untuk semua input tidak valid, ada pesan error masing-masing.
*/
{
	/* Kamus Lokal */
	int choice, choice2, count, idx;
	Bangunan *B1, *B2;
	int Fdawal,TAawal; //F itu Fort, T itu Tower, d itu defender
	int Fdakhir,TAakhir;
	int jumlahBangunanP1awal;
	int jumlahBangunanP2awal;
	int jumlahBangunanP1akhir;
	int jumlahBangunanP2akhir;

	/* Algoritma */
	printf("Daftar bangunan: \n");
	PrintListBangunan(NoPemain, *P1, *P2);
	printf("Bangunan yang digunakan untuk menyerang: "); scanf("%d", &choice);
	if (choice <= NBElmtListB(NoPemain, *P1, *P2) && choice > 0) {
		B1 = &ElmtArr(TB, InfoMyBuilding(NoPemain, choice, *P1, *P2));
		if (AttackAvai(*B1)) {
			count = NBNotMyConnectedBuildings(NoPemain, choice, *P1, *P2);
			if (count) {
				PrintNotMyConnectedBuildings(NoPemain, choice, *P1, *P2);
				printf("Bangunan yang diserang: "); scanf("%d", &choice2);
				if (choice2 <= count && choice2 > 0) {
					printf("Jumlah pasukan: "); scanf("%d", &count);
					B2 = &ElmtArr(TB, InfoConnectedBuilding2(NoPemain, choice, choice2, *P1, *P2));
					if (count > 0 && count <= JumlahPasukan(*B1)) {
						HitungFort(NoPemain,*P1,*P2,&Fdawal);
						HitungTower(NoPemain,*P1,*P2,&TAawal);
						jumlahBangunanP1awal = NbElmt(ListBangunan(*P1));
						jumlahBangunanP2awal = NbElmt(ListBangunan(*P2));
						if (isCurrentPCritical(NoPemain,*P1,*P2)){
							UPDATESTATUS(*P1, *P2);
							printf("Serangan Critical !!!\n");
							SerangCritical(B1, B2, count);
							CriticalOff(NoPemain,P1,P2);
						} else {
							UPDATESTATUS(*P1, *P2);
							SerangBangunan(B1, B2, count);	
						}
						if (JumlahPasukan(*B2) <= 0) {
							JumlahPasukan(*B2) = abs(JumlahPasukan(*B2));
							CaptureBuilding(NoPemain, B2, P1, P2);
							HitungFort(NoPemain,*P1,*P2,&Fdakhir);
							HitungTower(NoPemain,*P1,*P2,&TAakhir);
							jumlahBangunanP1akhir = NbElmt(ListBangunan(*P1));
							jumlahBangunanP2akhir = NbElmt(ListBangunan(*P2));
							GetShield(NoPemain,P1,P2,jumlahBangunanP1awal,jumlahBangunanP1akhir,jumlahBangunanP2awal,jumlahBangunanP2akhir);
							GetExtraTurn(NoPemain,P1,P2,Fdawal,Fdakhir);
							GetAttackUp(NoPemain,P1,P2,TAawal,TAakhir);
							GetBarrage(NoPemain,P1,P2,jumlahBangunanP1awal,jumlahBangunanP1akhir,jumlahBangunanP2awal,jumlahBangunanP2akhir);
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

void MOVE(int NoPemain, Player P1, Player P2) 
/*	I.S. Menampilkan daftar bangunan untuk pindah pasukan.
	F.S. Jika tidak ada bangunan untuk menerima pasukan, ditampilkan pesan "Bangunan tidak memiliki keterhubungan!".
		 Jika ada, Pemain telah memilih bangunan untuk pindah pasukan, bangunan untuk menerima pasukan, dan jumlah pasukan untuk dipindahkan.
		 Untuk semua input tidak valid, ada pesan error masing-masing.
*/
{
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

void LEVELUP(int NoPemain, Player P1, Player P2) 
/*	I.S. Menampilkan daftar bangunan untuk dinaikkan level.
	F.S. Pemain telah memilih bangunan untuk dinaikkan level dan level bangunan akan dinaikkan.
		 Untuk semua input tidak valid, ada pesan error masing-masing.
*/
{
	/* Kamus Lokal */
	int choice;

	/* Algoritma */
	PrintListBangunan(NoPemain, P1, P2);
	printf("Bangunan yang akan di level up: "); scanf("%d", &choice);
	LevelUpBP(NoPemain, P1, P2, choice);
	SCAN();
}

void UPDATESTATUS (Player P1, Player P2) 
/*	I.S. Stack Global Status terdefinisi misal dengan isi keadaan permainan [A,B] (B adalah TOP) dan sekarang keadaan permainan di C.
	F.S. Stack Global Status berisi [A,B,C].
*/
{
	/* Algoritma */
	UpdateStatus_Stack(&Status, P1, P2, TB);
}

void UNDO (Player *P1, Player *P2, boolean isSkillUsed) 
/*	I.S. Stack Global Status terdefinisi misal dengan isi keadaan permainan [A,B] (B adalah TOP) dan sekarang keadaan permainan di C.
	F.S. Stack Global Status berisi [A] dan sekarang keadaan permainan di B.
*/
{
	/* Algoritma */
	if (!isSkillUsed) {
		UndoStatus_Stack(&Status, P1, P2, &TB);
	} else {
		printf("Tidak bisa UNDO karena sudah menggunakan SKILL pada TURN ini.\n"); println();
	}
}