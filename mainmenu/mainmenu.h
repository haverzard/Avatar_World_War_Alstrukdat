/* ADT Menu Utama */
/* Mengatur segala output dan input user dan memprosesnya */

#ifndef MAINMENU_H
#define MAINMENU_H

#include "../boolean/boolean.h"
#include "../mesindata/mesindata.h"
#include "../matrikskar/matriks.h"
#include "../player/player.h"
#include "../stack/stack.h"

extern int turn;
extern boolean EndGame;
extern boolean EndTurn;
extern boolean SkillUsed;
extern Stack Status;

void STARTGAME(Player *P1, Player *P2) ;
/* 	I.S. Menampilkan menu awal dan menerima masukan user 
	F.S. Choice terisi dan game akan mulai di-load jika choice sesuai.
		 Jika choice tidak sesuai, balik lagi ke menu utama.
*/

void SAVEGAME(int num, Player P1, Player P2);
/*	I.S. P1, P2, TB, GHubungan terdefinisi
	F.S. Terbentuk file data save sesuai inputan player dengan spesifikasi khusus
*/

void CREATEPLAYER(Player *P1, Player *P2);
/*	I.S. P1 dan P2 belum terdefinisi
	F.S. P1 dan P2 sudah terdefinisi termasuk atribut-atributnya
*/

void TURN(int NoPemain, Player *P1, Player *P2);
/*	I.S. Menampilkan informasi player dan menerima masukan command user
	F.S. Memproses command player jika command ada di list command yang tersedia
		 Jika tidak command tidak valid, ditampilkan pesan "Inputnya yang benar dong!". 
		 Jika pemain menang, ditampilkan pesan selamat dan credits. 
*/

void ATTACK(int NoPemain, Player *P1, Player *P2);
/*	I.S. Menampilkan daftar bangunan untuk menyerang.
	F.S. Jika tidak ada bangunan untuk diserang, ditampilkan pesan "Tidak ada bangunan yang dapat diserang".
		 Jika ada, pemain telah memilih bangunan untuk menyerang, bangunan untuk diserang, dan jumlah pasukan untuk menyerang.
		 Untuk semua input tidak valid, ada pesan error masing-masing.
*/

void MOVE(int NoPemain, Player P1, Player P2);
/*	I.S. Menampilkan daftar bangunan untuk pindah pasukan.
	F.S. Jika tidak ada bangunan untuk menerima pasukan, ditampilkan pesan "Bangunan tidak memiliki keterhubungan!".
		 Jika ada, Pemain telah memilih bangunan untuk pindah pasukan, bangunan untuk menerima pasukan, dan jumlah pasukan untuk dipindahkan.
		 Untuk semua input tidak valid, ada pesan error masing-masing.
*/

void LEVELUP(int NoPemain, Player P1, Player P2);
/*	I.S. Menampilkan daftar bangunan untuk dinaikkan level.
	F.S. Pemain telah memilih bangunan untuk dinaikkan level dan level bangunan akan dinaikkan.
		 Untuk semua input tidak valid, ada pesan error masing-masing.
*/

void UPDATESTATUS (Player P1, Player P2); 
/*	I.S. Stack Global Status terdefinisi misal dengan isi keadaan permainan [A,B] (B adalah TOP) dan sekarang keadaan permainan di C.
	F.S. Stack Global Status berisi [A,B,C].
*/


void UNDO (Player *P1, Player *P2, boolean isSkillUsed); 
/*	I.S. Stack Global Status terdefinisi misal dengan isi keadaan permainan [A,B] (B adalah TOP) dan sekarang keadaan permainan di C.
	F.S. Stack Global Status berisi [A] dan sekarang keadaan permainan di B.
*/

#endif