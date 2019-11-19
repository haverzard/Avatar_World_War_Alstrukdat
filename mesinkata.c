/* File: mesinkata.c */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include <stdio.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "boolean.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    /* Algoritma */
	while (CC == BLANK && CC != MARK) {
		ADV();
	}
}
void SCANKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    /* Algoritma */
    SCAN();
	IgnoreBlank();
	if (CC == ENDCOMMAND) { 
		EndKata = true;
	} else if (feof(stdin)) {
		CKata.TabKata[1] = 'E';
		CKata.TabKata[2] = 'X';
		CKata.TabKata[3] = 'I';
		CKata.TabKata[4] = 'T';
		CKata.Length = 4;
	} else { 
		EndKata = false; 
		SalinKata(); 
	}
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    /* Kamus Lokal */
	int i;
	
    /* Algoritma */
	i = 1;
	while (CC != ENDCOMMAND && i <= NMax) {
		CKata.TabKata[i] = CC;
		SCAN();
		i++;
	}
	CKata.Length = i-1;
}

boolean EQ_KATA(Kata X, char Y[]) {
	/* Kamus Lokal */
	int i;
	boolean sama;

	/* Algoritma */
	sama = true;
	i = 1;
	while (Y[i] && sama) {
		sama = (X.TabKata[i] == Y[i-1]);
		i++;
	}
	return sama;
}