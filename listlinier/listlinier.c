/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "../listlinier/listlinier.h"
#include "../boolean/boolean.h"
#include "../bangunan/bangunan.h"
#include "../arraydinpos/arraydinpos.h"
#include "../graph/graph.h"

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

address Search (List L, Bangunan B)
/* Mencari apakah ada elemen list dengan TB.TI[Info(P)]=B */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	/* Kamus Lokal */
	address P;
	boolean found;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		found = EQ_Bangunan(ElmtArr(TB,Info(P)),B);
		while (Next(P) != Nil && !found) {
			P = Next(P);
			found  = EQ_Bangunan(ElmtArr(TB,Info(P)),B);
		}
		if (found) { return P; } else { return Nil; }
	} else {
		return Nil;
	}
}

address SearchInfo (List L, int X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	/* Kamus Lokal */
	address P;
	boolean found;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		found = Info(P) == X;
		while (Next(P) != Nil && !found) {
			P = Next(P);
			found  = Info(P) == X;
		}
		if (found) { return P; } else { return Nil; }
	} else {
		return Nil;
	}
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

void CopyList(List Lin, List *Lout) 
/*	I.S. Lout kosong.
	F.S. Semua elemen dan indeks di Lout sama dengan semua elemen dan indeks di Lin.
*/
{
	address P;
	CreateEmpty_LL(Lout);
	P = First(Lin); 
	while (P != Nil) {
		InsVLast(Lout, Info(P));
		P = Next(P);
	}
}

int InfoListByIndex (List L, int idx)
/* Prekonsidi: idx tidak melebihi ukuran L */
/* Menghasilkan info elemen ke-idx pada List; mengirimkan 0 jika list kosong */
{
	/* Kamus Lokal */
	address P;
	int i;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		i = 1;
		P = First(L);
		while (P != Nil && i < idx) {
			i++;
			P = Next(P);
		}
		return Info(P);
	}
	return 0;
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
void IterateAndOwn(int num, List *L) 
/*	I.S. L dan GHubungan terdefinisi dan num adalah indeks TB yang valid
	F.S. Semua bangunan yang terhubung dengan TB.TI[num] menjadi milik player bernomor num
*/
{
	/* Kamus Lokal */
	int i;

	/* Algoritma */
	i = 3;
	while (i <= NBElmt_Array(TB)) {
		if (SearchEdge(GHubungan, num, i) != Nil) {
			InsVLast(L,i);
			Kepemilikan(ElmtArr(TB,i)) = num;
		}
		i++;
	}

}

void UpdateAllBuildings(List L) 
/*	I.S. L, TB, dan GHubungan terdefinisi
	F.S. Semua elemen array berindeks info semua elemen L ditambah jumlah pasukannya sesuai spesifikasi
*/
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		while (P != Nil) {
			UpdateBangunan(&ElmtArr(TB,Info(P)));
			P = Next(P);
		}
	}
}

void ConnectedBuildings(int NoBangunan, List L) 
/*	I.S. L, TB, dan GHubungan terdefinisi dan NoBangunan adalah indeks TB yang valid
	F.S. Ditampilkan semua bangunan dengan indeks TB dalam list L yang terhubung dengan TB.TI[NoBangunan]
*/
{
	/* Kamus Lokal */
	int i;
	address P;

	/* Algoritma */
    i = 1;
    P = First(L);
    printf("Daftar bangunan terdekat: \n");
    while (P != Nil) {
    	if (SearchEdge(GHubungan, NoBangunan, Info(P)) != Nil) {
            printf("%d. ", i);
            PrintInfoBangunan(ElmtArr(TB,Info(P)));
        	i++;
    	}
        P = Next(P);
    }
}

void ConnectedBuildings2(int NoBangunan, List L) 
/*	I.S. L, TB, dan GHubungan terdefinisi dan NoBangunan adalah indeks TB yang valid
	F.S. Ditampilkan semua bangunan dengan indeks TB tidak dalam list L yang terhubung dengan TB.TI[NoBangunan]
*/
{
	/* Kamus Lokal */
	int i, idx;
	address P;

	/* Algoritma */
	i = 1;
	idx = 1;
	printf("Daftar bangunan yang dapat diserang: \n");
	while (idx <= NBElmt_Array(TB)) {
    	if (SearchInfo(L,idx) == Nil && SearchEdge(GHubungan, NoBangunan, idx) != Nil) {
            printf("%d. ", i);
            PrintInfoBangunan(ElmtArr(TB,idx));
            i++;
    	}
    	idx++;
	}
}

int InfoConnectedBuildingByIdx(int NoBangunan, int idx, List L) 
/*	Menghasilkan indeks TB yang direpresentasikan idx berdasarkan penomoran dari prosedur ConnectedBuildings*/
{
	/* Kamus Lokal */
	int i;
	address P;
	adrSuccNode found;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
        i = 1;
        P = First(L);
        found = SearchEdge(GHubungan, NoBangunan, Info(P));
        while (P != Nil && (i != idx || found == Nil)) {
        	if (found != Nil) {
            	i++;
        	}
            P = Next(P);
        	found = SearchEdge(GHubungan, NoBangunan, Info(P));
        }
    }
    return Info(P);
}

int InfoConnectedBuildingByIdx2(int NoBangunan, int idx, List L) 
/*	Menghasilkan indeks TB yang direpresentasikan idx berdasarkan penomoran dari prosedur ConnectedBuildings2*/
{
	/* Kamus Lokal */
	int i, idxtemp;
	address P;
	boolean found;

	/* Algoritma */
    i = 1;
    idxtemp = 1;
    found = SearchInfo(L,idxtemp) == Nil && SearchEdge(GHubungan, NoBangunan, idxtemp) != Nil;
	while (idxtemp <= NBElmt_Array(TB) && (i != idx || !found)) {
    	if (found) {
            i++;
    	}
    	idxtemp++;
    	found = SearchInfo(L,idxtemp) == Nil && SearchEdge(GHubungan, NoBangunan, idxtemp) != Nil;
	}
    return idxtemp;
}

int NBConnectedBuildings(int NoBangunan, List L) 
/*	Menghasilkan jumlah bangunan dengan indeks TB dalam list L yang terhubung dengan TB.TI[NoBangunan] */
{
	/* Kamus Lokal */
	int i;
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
        i = 1;
        P = First(L);
        while (P != Nil) {
        	if (SearchEdge(GHubungan, NoBangunan, Info(P)) != Nil) {
            	i++;
        	}
            P = Next(P);
        }
    }
    return i-1;
}

int NBConnectedBuildings2(int NoBangunan, List L) 
/*	Menghasilkan jumlah bangunan dengan indeks TB tidak dalam list L yang terhubung dengan TB.TI[NoBangunan] */
{
	/* Kamus Lokal */
	int i, idx;
	address P;

	/* Algoritma */
    i = 1;
    idx = 1;
	while (idx <= NBElmt_Array(TB)) {
    	if (SearchInfo(L,idx) == Nil && SearchEdge(GHubungan, NoBangunan, idx) != Nil) {
            i++;
    	}
    	idx++;
	}
    return i-1;
}

void IndexLevelUp(List L, int idx) 
/*	I.S. L dan TB terdefinisi
	F.S. Jika idx tidak valid, ditampilkan pesan "Upgrade gagal!"
		 Jika level sudah maksimum, ditampilkan pesan "Gagal! Level <Jenis> sudah bernilai maksimum"
		 Jika jumlah pasukan mencukupi, bangunan dengan indeks TB pada elemen L ke-idx di-levelup
		 Jika jumlah pasukan tidak mencukupi, ditampilkan pesan "Jumlah pasukan <Jenis> kurang untuk level up"
*/
{
	/* Kamus Lokal */
	address P;
	int i;

	/* Algoritma */
	if (idx <= NbElmt(L)) {
		P = First(L);
		for (i = 1; i < idx; i++) {
			P = Next(P);
		}
		if (Level(ElmtArr(TB,Info(P))) < 4) {
			if (JumlahPasukan(ElmtArr(TB,Info(P))) >= M(ElmtArr(TB,Info(P)))/2) {
				LevelUpBangunan(&ElmtArr(TB,Info(P)));
				printf("Level ");
				PrintJenisByCode(Jenis(ElmtArr(TB,Info(P))));
				printf("-mu meningkat menjadi %d.\n", Level(ElmtArr(TB,Info(P))));
			} else {
				printf("Jumlah pasukan ");
				PrintJenisByCode(Jenis(ElmtArr(TB,Info(P))));
				printf(" kurang untuk level up\n");
			}
		} else {
			printf("Gagal! Level ");
			PrintJenisByCode(Jenis(ElmtArr(TB,Info(P))));
			printf(" sudah bernilai maksimum!");
		}
	} else {
		printf("Upgrade gagal!\n");
	}
}

void LevelUpAll(List L) 
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan level di bawah 4 dengan indeks TB pada list L di-level up dengan prosedur LevelUpBangunan.
*/
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = First(L);
	while (P != Nil) {
		if (Level(ElmtArr(TB,Info(P))) < 4) {
			JumlahPasukan(ElmtArr(TB,Info(P))) += M(ElmtArr(TB,Info(P)))/2;
			LevelUpBangunan(&ElmtArr(TB,Info(P)));
		}
		P = Next(P);
	}
}

void ShieldOn(List L) 
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L diaktifkan pertahanannya
*/
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = First(L);
	while (P != Nil) {
		P(ElmtArr(TB,Info(P))) = true;
		P = Next(P);
	}
}


void ShieldOff(List L) 
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L dikembalikan pertahanannya ke keadaan aslinya
*/
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = First(L);
	while (P != Nil) {
		if (Jenis(ElmtArr(TB,Info(P))) != 'T') {
			P(ElmtArr(TB,Info(P))) = false;
		}
		if ((Jenis(ElmtArr(TB,Info(P))) != 'F') && ((Level(ElmtArr(TB,Info(P))) == 3) || (Level(ElmtArr(TB,Info(P))) == 4 ))){
			P(ElmtArr(TB,Info(P))) = false;
		}
		P = Next(P);
	}
}

void ReinforceAll(List L) 
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L ditambahkan pasukannya sebanyaknya 5
*/
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = First(L);
	while (P != Nil) {
		JumlahPasukan(ElmtArr(TB,Info(P))) += 5;
		P = Next(P);
	}
}

void BarrageAll(List Lenemy) {
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L dikurang pasukannya sebanyaknya 10
*/
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(Lenemy)) {
		P = First(Lenemy);
		if (JumlahPasukan(ElmtArr(TB,Info(P))) > 10) {
			JumlahPasukan(ElmtArr(TB,Info(P))) -= 10;
		} else {
			JumlahPasukan(ElmtArr(TB,Info(P))) = 0;
		}
		while (Next(P) != Nil) {
			P = Next(P);
			if (JumlahPasukan(ElmtArr(TB,Info(P))) > 10) {
				JumlahPasukan(ElmtArr(TB,Info(P))) -= 10;
			} else {
				JumlahPasukan(ElmtArr(TB,Info(P))) = 0;
			}
		}
	}
}

void AttackUpAll (List L)
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L dimatikan pertahanannya
*/
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		while (P != Nil) {
			P(ElmtArr(TB,Info(P))) = false;
			P = Next(P);
		}
	}
}

void AttackUpAllOff (List L)
/*	I.S. L dan TB terdefinisi
	F.S. Semua bangunan dengan indeks TB pada list L dikembalikan pertahanannya ke keadaan aslinya
*/
{ 
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	if (!IsEmpty_LL(L)) {
		P = First(L);
		if (Jenis(ElmtArr(TB,Info(P))) != 'T'){
			P(ElmtArr(TB,Info(P))) = true;
		}
		if ((Jenis(ElmtArr(TB,Info(P))) != 'F') && ((Level(ElmtArr(TB,Info(P))) == 3) || (Level(ElmtArr(TB,Info(P))) == 4 ))){
			P(ElmtArr(TB,Info(P))) = true;
		}
		while (Next(P) != Nil) {
			P = Next(P);
			if (Jenis(ElmtArr(TB,Info(P))) != 'T') {
				P(ElmtArr(TB,Info(P))) = true;
			}
			if ((Jenis(ElmtArr(TB,Info(P))) != 'F') && ((Level(ElmtArr(TB,Info(P))) == 3) || (Level(ElmtArr(TB,Info(P))) == 4 ))){
				P(ElmtArr(TB,Info(P))) = true;
			}
		}
	}
}

