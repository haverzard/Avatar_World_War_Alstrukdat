/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"
#include "bangunan.h"
#include "arraydinpos.h"

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty_LL (List L)
/* Mengirim true jika list kosong */
{
	/* Algoritma */
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty_LL (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	/* Algoritma */
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = (ElmtList *) malloc (1 * sizeof(ElmtList));
	Info(P) = X;
	Next(P) = Nil;
	return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	/* Algoritma */
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/

address Search (List L, Bangunan X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	/* Kamus Lokal */
	address P;
	boolean found;

	/* Algoritma */
	P = First(L);
	found = EQ_Bangunan(ElmtArr(TB,Info(P)),X);
	while (Next(P) != Nil && !found) {
		P = Next(P);
		found  = EQ_Bangunan(ElmtArr(TB,Info(P)),X);
	}
	if (found) { return P; } else { return Nil; }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	/* Kamus Lokal */
	address P;
	address P2;

	/* Algoritma */
	P = Alokasi(X);
	if (IsEmpty_LL(*L)) {
		First(*L) = P;
	} else {
		P2 = First(*L);
		First(*L) = P;
		Next(P) = P2;
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	/* Kamus Lokal */
	address P;
	address P2;

	/* Algoritma */
	P = Alokasi(X);
	if (IsEmpty_LL(*L)) {
		First(*L) = P;
	} else {
		P2 = First(*L);
		while (Next(P2) != Nil) {
			P2 = Next(P2);
		}
		Next(P2) = P;
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = First(*L);
	*X = Info(P);
	First(*L) = Next(P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	/* Kamus Lokal */
	address P;
	address P2;

	/* Algoritma */
	P = First(*L);
	P2 = Nil;
	while (Next(P) != Nil) {
		P2 = P;
		P = Next(P);
	}
	if (P2 == Nil) {
		First(*L) = Nil;
	} else {
		Next(P2) = Nil;
	}
	*X = Info(P);
	Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	/* Kamus Lokal */
	address Paf;

	/* Algoritma */
	if (IsEmpty_LL(*L)) {
		First(*L) = P;
	} else {
		Paf = First(*L);
		First(*L) = P;
		Next(P) = Paf;
	}
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	/* Kamus Lokal */
	address P2;

	/* Algoritma */
	P2 = Next(Prec);
	Next(Prec) = P;
	Next(P) = P2;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	/* Kamus Lokal */
	address P2;

	/* Algoritma */
	if (IsEmpty_LL(*L)) {
		First(*L) = P;
	} else {
		P2 = First(*L);
		while (Next(P2) != Nil) {
			P2 = Next(P2);
		}
		Next(P2) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	/* Kamus Lokal */
	address P2;

	/* Algoritma */
	P2 = First(*L);
	*P = P2;
	First(*L) = Next(P2);
}

void DelP (List *L, Bangunan X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	address P;
	address P2;

	/* Algoritma */
	P = First(*L);
	P2 = Nil;
	while(Next(P) != Nil && !EQ_Bangunan(ElmtArr(TB,Info(P)),X)) {
		P2 = P;
		P = Next(P);
	}

	if (EQ_Bangunan(ElmtArr(TB,Info(P)),X)) {
		if (P2 == Nil) {
			First(*L) = Next(P);
		} else {
			Next(P2) = Next(P);
		}
		Dealokasi(&P);
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
	/* Kamus Lokal */
	address P2;
	address P3;

	/* Algoritma */
	P3 = First(*L);
	P2 = Nil;
	while (Next(P3) != Nil) {
		P2 = P3;
		P3 = Next(P3);
	}
	if (P2 == Nil) {
		First(*L) = Nil;
	} else {
		Next(P2) = Nil;
	}
	*P = P3;
	P3 = Nil;
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	/* Kamus Lokal */
	address P2;

	/* Algoritma */
	*Pdel = Next(Prec);
	if (*Pdel != Nil) {
		Next(Prec) = Next(*Pdel);
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	/* Kamus Lokal */
	address P;
	int i;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		i = 1;
		P = First(L);
		printf("%d. ", i);
		PrintInfoBangunan(ElmtArr(TB,Info(P)));
		while (Next(P) != Nil) {
			i++;
			P = Next(P);
			printf("%d. ", i);
			PrintInfoBangunan(ElmtArr(TB,Info(P)));
		}
	}
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	/* Kamus Lokal */
	int count;
	address P;

	/* Algoritma */
	if (IsEmpty_LL(L)) { return 0; }
	count = 1;
	P = First(L);
	while (Next(P) != Nil) {
		count++;
		P = Next(P);
	}
	return count;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	/* Algoritma */
	CreateEmpty_LL(L3);
	InsertFirst(L3,First(*L1));
	InsertLast(L3,First(*L2));
	First(*L1) = Nil;
	First(*L2) = Nil;
}

void UpdateAllBuildings(List L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		UpdateBangunan(&ElmtArr(TB,Info(P)));
		while (Next(P) != Nil) {
			P = Next(P);
			UpdateBangunan(&ElmtArr(TB,Info(P)));
		}
	}
}

void IndexLevelUp(List L, int idx) {
	/* Kamus Lokal */
	address P;
	int i;

	/* Algoritma */
	if (idx <= NbElmt(L)) {
		P = First(L);
		for (i = 1; i < idx; i++) {
			P = Next(P);
		}
		if (JumlahPasukan(ElmtArr(TB,Info(P))) >= M(ElmtArr(TB,Info(P)))/2) {
			LevelUpBangunan(&ElmtArr(TB,Info(P)));
			printf("Level ");
			switch(Jenis(ElmtArr(TB,Info(P)))) {
			 	case 'C': printf("Castle"); break;
			 	case 'T': printf("Tower"); break;
			 	case 'F': printf("Fort"); break;
			 	case 'V': printf("Village"); break;
			}
			printf("-mu meningkat menjadi %d.\n", Level(ElmtArr(TB,Info(P))));
		} else {
			printf("Jumlah pasukan ");
			switch(Jenis(ElmtArr(TB,Info(P)))) {
			 	case 'C': printf("Castle"); break;
			 	case 'T': printf("Tower"); break;
			 	case 'F': printf("Fort"); break;
			 	case 'V': printf("Village"); break;
			}
			printf(" kurang untuk level up\n");
		}
	} else {
		printf("Upgrade gagal!\n");
	}
}

void LevelUpAll(List L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		LevelUpBangunan(&ElmtArr(TB,Info(P)));
		while (Next(P) != Nil) {
			P = Next(P);
			LevelUpBangunan(&ElmtArr(TB,Info(P)));
		}
	}
}

void ShieldOn(List L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		P(ElmtArr(TB,Info(P))) = true;
		while (Next(P) != Nil) {
			P = Next(P);
			P(ElmtArr(TB,Info(P))) = true;
		}
	}
}


void ShieldOff(List L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		if (Jenis(ElmtArr(TB,Info(P))) != 'T') {
			P(ElmtArr(TB,Info(P))) = false;
		}
		while (Next(P) != Nil) {
			P = Next(P);
			if (Jenis(ElmtArr(TB,Info(P))) != 'T') {
				P(ElmtArr(TB,Info(P))) = false;
			}
		}
	}
}

void ReinforceAll(List L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		JumlahPasukan(ElmtArr(TB,Info(P))) += 5;
		while (Next(P) != Nil) {
			P = Next(P);
			JumlahPasukan(ElmtArr(TB,Info(P))) += 5;
		}
	}
}

void BarrageAll(List L) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		if (JumlahPasukan(ElmtArr(TB,Info(P))) >= 10) {
			JumlahPasukan(ElmtArr(TB,Info(P))) -= 10;
		}
		while (Next(P) != Nil) {
			P = Next(P);
			if (JumlahPasukan(ElmtArr(TB,Info(P))) >= 10) {
				JumlahPasukan(ElmtArr(TB,Info(P))) -= 10;
			}
		}
	}
}