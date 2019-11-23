/* ADT Mesin Data */
/* Membaca data file eksternal dengan memanfaatkan mesin karakter*/

#ifndef MESINDATA_H
#define MESINDATA_H

#include "boolean.h"
#include "mesinkar.h"
#include "matriks.h"
#include "matriksint.h"
#include "arraydinpos.h"

#define NMax_DATA 600
#define ENDLINE '\r'
#define ENDLINE2 '\n'
#define BLANK ' '

extern FILE * pita;

extern char Baris[NMax_DATA+1];

int KarakterToInt(char x);
/* KarakterToInt mengonversi tipe data x menjadi integer */

void IgnoreBlank_DATA();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = ENDLINE */

void STARTDATA(char *filename);
/* Memulai pembacaan data
   I.S. : File data belum diakses
   F.S. : Pembacaan sudah bisa dimulai dan CC ≠ BLANK */

void NEXTDATA();
/* I.S. CC mungkin berisi ENDLINE atau BLANK
   F.S. CC adalah karakter yang akan dibaca selanjutnya
*/

void INFOPETA(MATRIKS *Peta);
/* Mengambil informasi ukuran peta dari data
   I.S. : Peta belum terdefinisi
   F.S. : Peta terdefinisi dengan ukuran dari data */

void INFOBANGUNAN(TabBangunan *TB);
/* I.S. TB belum terdefinisi
   F.S. TB terdefinisi dengan ukuran sesuai konfigurasi dari file eksternal
*/

void LOKASIBANGUNAN(MATRIKS *Peta, TabBangunan *TB);
/* I.S. TB sembarang 
   F.S. Terbentuk TabBangunan TB sesuai konfigurasi dari file eksternal
*/

void HUBUNGANBANGUNAN (MATRIKS_INT *Hubungan, int BanyakBangunan);
/* I.S. Matriks Hubungan sembarang dan BanyakHubungan terdefinisi 
   F.S. Terbentuk Matriks Hubungan sesuai konfigurasi dari file eksternal
*/

void MOREINFOBANGUNAN(TabBangunan *TB);
/* I.S. TB terdefinisi
   F.S. Informasi Bangunan TB di-load dari file eksternal
*/

void INFOTURN(int *turn);
/*  I.S. turn sembarang
    F.S. turn terdefinisi
*/

void INFOCOLOR(Player *P1, Player *P2);
/*  I.S. Color pada P1 dan P2 sembarang
    F.S. Color pada P1 dan P2 terdefinisi
*/

void LOADBANGUNANPLAYER(Player *P1, Player *P2);
/*  I.S. bangunan milik P1 dan P2 sembarang
    F.S. bangunan milik P1 dan P2 terdefinisi
*/

void LOADSKILL(Player *P1, Player *P2);
/*  I.S. skill milik P1 dan P2 sembarang
    F.S. skill milik P1 dan P2 terdefinisi
*/
#endif