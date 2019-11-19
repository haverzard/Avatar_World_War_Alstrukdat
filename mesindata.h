/* ADT Mesin Data */
/* Membaca data file eksternal dengan memanfaatkan mesin karakter*/

#ifndef MESINDATA_H
#define MESINDATA_H

#include "boolean.h"
#include "mesinkar.h"
#include "matriks.h"
#include "arraydinpos.h"

#define NMax_DATA 600
#define ENDLINE '\n'
#define BLANK ' '

extern char Baris[NMax_DATA+1];

void IgnoreBlank_DATA();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = ENDLINE */

void STARTDATA();
/* Memulai pembacaan data
   I.S. : File data belum diakses
   F.S. : Pembacaan sudah bisa dimulai dan CC ≠ BLANK */

void NEXTDATA();

void INFOPETA(MATRIKS *Peta);
/* Mengambil informasi ukuran peta dari data
   I.S. : Peta belum terdefinisi
   F.S. : Peta terdefinisi dengan ukuran dari data */

void INFOBANGUNAN(TabBangunan *TB);

void LOKASIBANGUNAN(MATRIKS *Peta, TabBangunan *TB, int i);


#endif