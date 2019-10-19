/* MODUL TABEL LOKASI TERMODIFIKASI */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "arraydinpos.h"
#include "lokasi.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	/* Kamus Lokal */
	IdxType i;
	
	/* Algoritma */
	MaxEl(*T) = maxel;
	TI(*T) = (int *) malloc ((maxel+1) * sizeof(int));
	for (i = IdxMin; i <= maxel; i++) {
		Elmt(*T,i) = ValUndef;
	}
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
	/* Algoritma */
	free(TI(*T));
	MaxEl(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	/* Kamus Lokal */
	IdxType i;
	
	/* Algoritma */
	i = IdxMin;
	while (i <= MaxEl(T) && Elmt(T,i) != ValUndef) {
		i++;
	}
	i--;
	return i;
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	/* Algoritma */
	return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	/* Algoritma */
	return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return NbElmt(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	/* Algoritma */
	return (i >= IdxMin) && (i <= MaxEl(T));
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	/* Algoritma */
	return (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	return (NbElmt(T) == 0);
}

boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	/* Algoritma */
	return (NbElmt(T) == MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	/* Kamus Lokal */
	IdxType N, i;
	
	/* Algoritma */
	N = -1;
	
	if (N > 0) {
	} else {
		MakeEmpty(T,MaxEl(*T));
	}
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	/* Kamus Lokal */
	IdxType i;
	
	/* Algoritma */
	if (IsEmpty(T)) {
		printf("[]");
	} else {
	}
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
	/* Kamus Lokal */
	boolean sama;
	IdxType i;
	
	/* Algoritma */
	sama = true;
	if (GetLastIdx(T1) == GetLastIdx(T2) &&  GetFirstIdx(T1) == GetFirstIdx(T2)) {
		i = 1;
		while (sama && i <= GetLastIdx(T1)) {
			sama = (Elmt(T1,i) == Elmt(T2,i));
			i += 1;
		}
	} else {
		sama = false;
	}
	
	return sama;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	/* Kamus Lokal */
	IdxType i;
	
	/* Algoritma */
	if (!IsEmpty(T)) {
		i = GetFirstIdx(T);
		while (Elmt(T,i) != X && i < GetLastIdx(T)) {
			i += 1;
		}
		if (Elmt(T,i) == X) {
			return i;
		}
	}
	return IdxUndef;
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
	/* Algoritma */
	return (Search1(T,X) != IdxUndef);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	/* Kamus Lokal */
	IdxType i;
	
	/* Algoritma */
	*Max = Elmt(T, GetFirstIdx(T));
	*Min = Elmt(T, GetFirstIdx(T));
	for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
		if (*Max < Elmt(T,i)) {
			*Max = Elmt(T,i);
		}
		if (*Min > Elmt(T,i)) {
			*Min = Elmt(T,i);
		}
	}
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
	/* Kamus Lokal */
	IdxType i;
	
	/* Algoritma */
	Dealokasi(Tout);
	MakeEmpty(Tout,MaxEl(Tin));
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
		Elmt(*Tout,i) = Elmt(Tin,i);
	}
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	/* Kamus Lokal */
	ElType sum;
	IdxType i;
	
	/* Algoritma */
	sum = 0;
	if (!IsEmpty(T)) {
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
			sum += Elmt(T,i);
		}
	}
	return sum;
}

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	/* Kamus Lokal */
	int count;
	IdxType i;
	
	/* Algoritma */
	count = 0;
	if (!IsEmpty(T)) {	
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
			if (Elmt(T,i) == X) {
				count++;
			}
		}
	}
	return count;
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
	/* Kamus Lokal */
	IdxType i;
	boolean genap;
	
	/* Algoritma */
	genap = false;
	if (!IsEmpty(T)) {
		i = GetFirstIdx(T);
		genap = true;
		while (genap && i <= GetLastIdx(T)) {
			genap = (Elmt(T,i)%2 == 0);
			i += 1;
		}
	}
	return genap;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
	/* Kamus Lokal */
	IdxType i, j;
	ElType temp;
	
	/* Algoritma */
	if (!IsEmpty(*T)) {
		if (asc) {
			for (i = GetFirstIdx(*T)+1; i <= GetLastIdx(*T); i++) {
				j = i-1;
				temp = Elmt(*T,i);
				while (j >= GetFirstIdx(*T) && temp < Elmt(*T,j)) {
					Elmt(*T,j+1) = Elmt(*T,j);
					j -= 1;
				}
				Elmt(*T,j+1) = temp;
			}
		} else {
			for (i = GetFirstIdx(*T); i <= GetLastIdx(*T)-1; i++) {
				for (j = i; j <= GetLastIdx(*T); j++) {
					if (Elmt(*T,i) < Elmt(*T,j)) {
						temp = Elmt(*T,i);
						Elmt(*T,i) = Elmt(*T,j);
						Elmt(*T,j) = temp;
					}
				}
			}
		}
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	/* Algoritma */
	if (IsEmpty(*T)) {
		Elmt(*T,IdxMin) = X;
	} else {
		Elmt(*T,GetLastIdx(*T)+1) = X;
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	/* Algoritma */
	*X = Elmt(*T,GetLastIdx(*T));
	Elmt(*T,GetLastIdx(*T)) = ValUndef;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
	/* Kamus Lokal */
	TabInt TX;
	
	/* Algoritma */
	MaxEl(*T) += num;
	MakeEmpty(&TX,MaxEl(*T));
	CopyTab(*T,&TX);
	CopyTab(TX,T);
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
	/* Kamus Lokal */
	TabInt TX;
	
	/* Algoritma */
	MaxEl(*T) -= num;
	MakeEmpty(&TX,MaxEl(*T));
	CopyTab(*T,&TX);
	CopyTab(TX,T);
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
	/* Kamus Lokal */
	TabInt TX;
	
	/* Algoritma */
	MaxEl(*T) = GetLastIdx(*T);
	MakeEmpty(&TX,MaxEl(*T));
	CopyTab(*T,&TX);
	CopyTab(TX,T);
}