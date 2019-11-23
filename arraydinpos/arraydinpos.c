/* MODUL TABEL LOKASI TERMODIFIKASI */
/* Berisi definisi dan semua primitif pemrosesan tabel berelemen Loc */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "../boolean/boolean.h"
#include "../arraydinpos/arraydinpos.h"
#include "../matrikskar/matriks.h"
#include "../bangunan/bangunan.h"

/* Variabel Global */
TabBangunan TB;	

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabBangunan *T, int MaxElArr)
/* I.S. T sembarang, MaxElArr > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElArr + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan LocUndef */
{
	/* Kamus Lokal */
	IdxType i;
	/* Algoritma */
	MaxElArr(*T) = MaxElArr;
	TI(*T) = (Bangunan *) malloc ((MaxElArr+1) * sizeof(Bangunan));
	for (i = IdxMin; i <= MaxElArr; i++) {
		ElmtArr(*T,i) = BangunanUndef;
	}
}

void Dealokasi_Array(TabBangunan *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElArr(T)=0; Neff(T)=0 */
{
	/* Algoritma */
	free(TI(*T));
	MaxElArr(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NBElmt_Array(TabBangunan T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	/* Kamus Lokal */
	IdxType i;
	/* Algoritma */
	i = IdxMin;
	while (i <= MaxElArr(T) && IsBangunanValid(ElmtArr(T,i))) {
		i++;
	}
	i--;
	return i;
}

/* *** Daya tampung container *** */
int MaxElArrement(TabBangunan T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	/* Algoritma */
	return MaxElArr(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabBangunan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	/* Algoritma */
	return IdxMin;
}

IdxType GetLastIdx(TabBangunan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return NBElmt_Array(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid_Array(TabBangunan T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	/* Algoritma */
	return (i >= IdxMin) && (i <= MaxElArr(T));
}

boolean IsIdxEff_Array(TabBangunan T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	/* Algoritma */
	return (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty_Array(TabBangunan T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	return (NBElmt_Array(T) == 0);
}

boolean IsFull_Array(TabBangunan T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	/* Algoritma */
	return (NBElmt_Array(T) == MaxElArr(T));
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabBangunan T1, TabBangunan T2)
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
			sama = EQ_Bangunan(ElmtArr(T1,i), ElmtArr(T2,i));
			i += 1;
		}
	} else {
		sama = false;
	}
	return sama;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabBangunan T, ElType_Array X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	/* Kamus Lokal */
	IdxType i;
	/* Algoritma */
	if (!IsEmpty_Array(T)) {
		i = GetFirstIdx(T);
		while (!EQ_Bangunan(ElmtArr(T,i), X) && i < GetLastIdx(T)) {
			i += 1;
		}
		if (EQ_Bangunan(ElmtArr(T,i), X)) {
			return i;
		}
	}
	return IdxUndef;
}

boolean SearchB(TabBangunan T, ElType_Array X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
	/* Algoritma */
	return (Search1(T,X) != IdxUndef);
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabBangunan Tin, TabBangunan *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxElArr sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
	/* Kamus Lokal */
	IdxType i;
	
	/* Algoritma */
	//Dealokasi_Array(Tout);
	MakeEmpty(Tout,MaxElArr(Tin));
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
		ElmtArr(*Tout,i) = ElmtArr(Tin,i);
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabBangunan *T, ElType_Array X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	/* Algoritma */
	if (IsEmpty_Array(*T)) {
		ElmtArr(*T,IdxMin) = X;
	} else {
		ElmtArr(*T,GetLastIdx(*T)+1) = X;
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabBangunan *T, ElType_Array *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	/* Algoritma */
	*X = ElmtArr(*T, GetLastIdx(*T));
	ElmtArr(*T, GetLastIdx(*T)) = BangunanUndef;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void DelEli (TabBangunan * T, IdxType i, ElType_Array * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
{
    /* KAMUS LOKAL */
    int j = i;
    /* MENGGESER ELEMEN KE-i+1 S.D TERAKHIR */
    *X = ElmtArr(*T, i);
    while (j < NBElmt_Array(*T)) {
        ElmtArr(*T, j) = ElmtArr(*T, j+1);
        j++;
    }
	ElmtArr(*T, NBElmt_Array(*T)) = BangunanUndef;
}

int CheckOwnerByPosition(TabBangunan T, int X, int Y) {
/* Cek Posisi Bangunan yang berlokasi (X,Y) pada TabBangunan T */
/* Kemudian mengembalikan indeks T dimana bangunan yang berlokasi (X,Y) berada */
	/* Kamus Lokal */
	int i;
	POINT temp;

	/* Algoritma */
	temp = MakePOINT(X,Y);
	i = 0;
	do {
		i++;
	} while (!EQ_POINT(Koordinat(ElmtArr(T,i)),temp) && i < MaxElArr(T));
	return Kepemilikan(ElmtArr(T,i));
}