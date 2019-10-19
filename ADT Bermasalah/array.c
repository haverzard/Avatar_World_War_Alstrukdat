/* File: array.c */
/* Tanggal: 04 September 2019 */
/* Realisasi ADT Array Statis Integer */
/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include "boolean.h"
#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T) {
	/* I.S. T sembarang */
	/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	/* Algoritma */
	Neff(*T) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T) {
	/* Mengirimkan banyaknya elemen efektif tabel */
	/* Mengirimkan nol jika tabel kosong */
	/* *** Daya tampung container *** */
	/* Algoritma */
	return Neff(T);
}

int MaxNbEl (TabInt T) {
	/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	/* *** Selektor INDEKS *** */
	/* Algoritma */
	return IdxMax;
}

IdxType GetFirstIdx (TabInt T) {
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen T pertama */
	/* Algoritma */
	return IdxMin;
}

IdxType GetLastIdx (TabInt T) {
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen T terakhir */
	/* Algoritma */
	return Neff(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i) {
	/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
	/* yaitu antara indeks yang terdefinisi utk container*/
	/* Algoritma */
	return (i >= GetFirstIdx(T)) && (i <= MaxNbEl(T));
}

boolean IsIdxEff (TabInt T, IdxType i) {
	/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
	/* yaitu antara FirstIdx(T)..LastIdx(T) */
	/* Algoritma */
	return (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T) {
	/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	/* *** Test tabel penuh *** */
	/* Algoritma */
	return (Neff(T) == 0);
}

boolean IsFull (TabInt T) {
	/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	/* Algoritma */
	 return (Neff(T) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T) {
	/* I.S. T sembarang */
	/* F.S. Tabel T terdefinisi */
	/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
	/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
	/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
	/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
	/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
		  IdxMin satu per satu diakhiri enter */
	/*    Jika N = 0; hanya terbentuk T kosong */
	/* Kamus Lokal */
	int N, i;
	
	/* Algoritma */
	scanf("%d", &N);
	while (N < 0 || N > MaxNbEl(*T)) {
		scanf("%d", &N);
	}
	Neff(*T) = N;
	for (i = IdxMin; i <= Neff(*T); i++) {
		scanf("%d", &Elmt(*T,i));
	}
}

void BacaIsiTab (TabInt * T) {
	/* I.S. T sembarang */
	/* F.S. Tabel T terdefinisi */
	/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
	/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
	/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
	/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
	/* Kamus Lokal */
	int i, temp;
	
	/* Algoritma */
	i = IdxMin;
	Neff(*T) = 0;
	scanf("%d", &temp);
	while (temp != -9999 && Neff(*T) < IdxMax) {
		Elmt(*T,i) = temp;
		Neff(*T) += 1;
		i += 1;
		scanf("%d", &temp);
	}
}

void TulisIsi (TabInt T) {
	/* Proses : Menuliskan isi tabel dengan traversal */
	/* I.S. T boleh kosong */
	/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
	/*      Jika T kosong : Hanya menulis "Tabel kosong" */
	/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
	   Maka tercetak di layar:
	   [1]1
	   [2]20
	   [3]30
	   [4]50
	*/
	/* Kamus Lokal */
	int i;
	
	/* Algoritma */
	if (IsEmpty(T)) {
		printf("Tabel kosong\n");
	} else {
		for (i = IdxMin; i <= Neff(T); i++) {
			printf("[%d]%d\n", i, Elmt(T,i));
		}
	}
}
void TulisIsiTab (TabInt T) {
	/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
	   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
	   di tengah, atau di belakang, termasuk spasi dan enter */
	/* I.S. T boleh kosong */
	/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika tabel kosong : menulis [] */
	/* Kamus Lokal */
	int i;
	
	/* Algoritma */
	if (IsEmpty(T)) {
		printf("[]");
	} else {
		printf("[");
		for (i = IdxMin; i <= Neff(T)-1; i++) {
			printf("%d,", Elmt(T,i));
		}
		printf("%d]", Elmt(T,Neff(T)));
	}
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2) {
	/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
	/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
	/* Kamus Lokal */
	TabInt temp_T;
	int i;
	
	/* Algoritma */
	Neff(temp_T) = Neff(T1);
	for (i = IdxMin; i <= Neff(temp_T); i++) {
		Elmt(temp_T,i) = Elmt(T1,i) + Elmt(T2,i);
	}
	return temp_T;
}

TabInt MinusTab (TabInt T1, TabInt T2) {
	/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
	/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
	/* Kamus Lokal */
	TabInt temp_T;
	int i;
	
	/* Algoritma */
	Neff(temp_T) = Neff(T1);
	for (i = IdxMin; i <= Neff(temp_T); i++) {
		Elmt(temp_T,i) = Elmt(T1,i) - Elmt(T2,i);
	}
	return temp_T;
}

TabInt KaliTab (TabInt T1, TabInt T2) {
	/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
	/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
	/* Kamus Lokal */
	TabInt temp_T;
	int i;
	
	/* Algoritma */
	Neff(temp_T) = Neff(T1);
	for (i = IdxMin; i <= Neff(temp_T); i++) {
		Elmt(temp_T,i) = Elmt(T1,i) * Elmt(T2,i);
	}
	return temp_T;
}

TabInt KaliKons (TabInt Tin, ElType c) {
	/* Prekondisi : Tin tidak kosong */
	/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
	/* Kamus Lokal */
	TabInt temp_T;
	int i;
	
	/* Algoritma */
	Neff(temp_T) = Neff(Tin);
	for (i = IdxMin; i <= Neff(temp_T); i++) {
		Elmt(temp_T,i) = Elmt(Tin,i) * c;
	}
	return temp_T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2) {
	/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
	/* Kamus Lokal */
	boolean sama;
	int i;
	
	/* Algoritma */
	sama = true;
	if (Neff(T1) == Neff(T2)) {
		i = 1;
		while (sama && i <= Neff(T1)) {
			sama = (Elmt(T1,i) == Elmt(T2,i));
			i += 1;
		}
	} else {
		sama = false;
	}
	
	return sama;
}

boolean IsLess (TabInt T1, TabInt T2) {
	/* Mengirimkan true jika T1 < T2, */
	/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
	/* Kamus Lokal */
	boolean less, sama;
	int i, a, b;
	
	/* Algoritma */
	sama = true;
	less = false;
	if (Neff(T1) == Neff(T2)) {
		i = 1;
		while (sama && i <= Neff(T1)) {
			a = Elmt(T1,i);
			b = Elmt(T2,i);
			if (a == b) {
				sama = true;
			} else if (a < b) {
				less = true;
				sama = false;
			} else {
				less = false;
				sama = false;
			}
			i += 1;
		}
	} else if (Neff(T1) < Neff(T2)) {
		less = true;
	} // else do nothing
	
	return less;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X) {
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
	/* Jika tidak ada, mengirimkan IdxUndef */
	/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
	/* Memakai skema search TANPA boolean */
	/* Kamus Lokal */
	int i;
	
	/* Algoritma */
	if (!IsEmpty(T)) {
		i = IdxMin;
		while (Elmt(T,i) != X && i < Neff(T)) {
			i += 1;
		}
		if (Elmt(T,i) == X) {
			return i;
		}
	}
	return IdxUndef;
}

IdxType Search2 (TabInt T, ElType X) {
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
	/* Jika tidak ada, mengirimkan IdxUndef */
	/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
	/* Memakai skema search DENGAN boolean Found */
	/* Kamus Lokal */
	int i;
	boolean Found;
	
	/* Algoritma */
	if (!IsEmpty(T)) {
		i = IdxMin;
		Found = (Elmt(T,i) == X);
		while (!Found && i < Neff(T)) {
			i += 1;
			Found = (Elmt(T,i) == X);
		}
		
		if (Found) {
			return i;
		}
	}
	return IdxUndef;
}

boolean SearchB (TabInt T, ElType X) {
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
	/* Memakai Skema search DENGAN boolean */
	/* Algoritma */
	return (Search2(T,X) != IdxUndef);
}
boolean SearchSentinel (TabInt T, ElType X) {
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
	/* dengan metoda sequential search dengan sentinel */
	/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
		yang tidak dipakai dalam definisi tabel */
	/* Kamus Lokal */
	int i;
	
	/* Algoritma */
	if (!IsEmpty(T)) {
		i = Neff(T);
		while (Elmt(T,i) != X && i >= IdxMin) {
			i -= 1;
		}
		
		return (i != 0);
	}
	return false;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T) {
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan nilai maksimum tabel */
	/* Kamus Lokal */
	int i, maxvalue;
	
	/* Algoritma */
	maxvalue = Elmt(T, IdxMin);
	for (i = IdxMin+1; i <= Neff(T); i++) {
		if (maxvalue < Elmt(T,i)) {
			maxvalue = Elmt(T,i);
		}
	}
	return maxvalue;
}

ElType ValMin (TabInt T) {
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan nilai minimum tabel */
	/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
	/* Kamus Lokal */
	int i, minvalue;
	
	/* Algoritma */
	minvalue = Elmt(T, IdxMin);
	for (i = IdxMin+1; i <= Neff(T); i++) {
		if (minvalue > Elmt(T,i)) {
			minvalue = Elmt(T,i);
		}
	}
	return minvalue;
}

IdxType IdxMaxTab (TabInt T) {
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
	/* Kamus Lokal */
	int i, maxvalue, IdxMaxValue;
	
	/* Algoritma */
	maxvalue = Elmt(T, IdxMin);
	IdxMaxValue = IdxMin;
	for (i = IdxMin+1; i <= Neff(T); i++) {
		if (maxvalue < Elmt(T,i)) {
			maxvalue = Elmt(T,i);
			IdxMaxValue = i;
		}
	}
	return IdxMaxValue;
}

IdxType IdxMinTab (TabInt T) {
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
	/* Kamus Lokal */
	int i, minvalue, IdxMinValue;
	
	/* Algoritma */
	minvalue = Elmt(T, IdxMin);
	IdxMinValue = IdxMin;
	for (i = IdxMin+1; i <= Neff(T); i++) {
		if (minvalue > Elmt(T,i)) {
			minvalue = Elmt(T,i);
			IdxMinValue = i;
		}
	}
	return IdxMinValue;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout) {
	/* I.S. Tin terdefinisi, Tout sembarang */
	/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
	/* Proses : Menyalin isi Tin ke Tout */
	/* Kamus Lokal */
	int i;
	
	/* Algoritma */
	Neff(*Tout) = Neff(Tin);
	if (!IsEmpty(Tin)) {
		for (i = IdxMin; i <= Neff(*Tout); i++) {
			Elmt(*Tout,i) = Elmt(Tin,i);
		}
	} // else do nothing
}

TabInt InverseTab (TabInt T) {
	/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
	/* elemen pertama menjadi terakhir, */
	/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
	/* Tabel kosong menghasilkan tabel kosong */
	/* Kamus Lokal */
	TabInt temp_T;
	int i;
	
	/* Algoritma */
	Neff(temp_T) = Neff(T);
	if (!IsEmpty(T)) {
		for (i = IdxMin; i <= Neff(T); i++) {
			Elmt(temp_T,i) = Elmt(T,Neff(T)+1-i);
		}
	} // else do nothing
	return temp_T;
}

boolean IsSimetris (TabInt T) {
	/* Menghasilkan true jika tabel simetrik */
	/* Tabel disebut simetrik jika: */
	/*      elemen pertama = elemen terakhir, */
	/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
	/* Tabel kosong adalah tabel simetris */
	/* Kamus Lokal */
	int i;
	
	/* Algoritma */
	if (!IsEmpty(T)) {
		i = IdxMin;
		while (Elmt(T,i) == Elmt(T,Neff(T)+1-i) && i < Neff(T)) {
			i += 1;
		}
		return Elmt(T,i) == Elmt(T,Neff(T)+1-i);
	} // else do nothing
	return true;
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T) {
	/* I.S. T boleh kosong */
	/* F.S. T elemennya terurut menurun dengan Maximum Sort */
	/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
	/*          tanpa menggunakan tabel kerja */
	/* Kamus Lokal */
	int i, j, temp;
	
	/* Algoritma */
	if (!IsEmpty(*T)) {
		for (i = IdxMin; i <= Neff(*T)-1; i++) {
			for (j = i; j <= Neff(*T); j++) {
				if (Elmt(*T,i) < Elmt(*T,j)) {
					temp = Elmt(*T,i);
					Elmt(*T,i) = Elmt(*T,j);
					Elmt(*T,j) = temp;
				}
			}
		}
	}
}

void InsSortAsc (TabInt * T) {
	/* I.S. T boleh kosong */
	/* F.S. T elemennya terurut menaik dengan Insertion Sort */
	/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
	/*          tanpa menggunakan tabel kerja */
	/* Kamus Lokal */
	int i, j, value;
	
	/* Algoritma */
	if (!IsEmpty(*T)) {
		for (i = IdxMin+1; i <= Neff(*T); i++) {
			j = i-1;
			value = Elmt(*T,i);
			while (j >= IdxMin && value < Elmt(*T,j)) {
				Elmt(*T,j+1) = Elmt(*T,j);
				j -= 1;
			}
			Elmt(*T,j+1) = value;
		}
	}
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X) {
	/* Proses: Menambahkan X sebagai elemen terakhir tabel */
	/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
	/* F.S. X adalah elemen terakhir T yang baru */
	/* Algoritma */
	if (!IsFull(*T)) {
		Neff(*T) += 1;
		Elmt(*T,Neff(*T)) = X;
	}
}

void AddEli (TabInt * T, ElType X, IdxType i) {
	/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
	   terhadap elemen yang sudah ada */
	/* I.S. Tabel tidak kosong dan tidak penuh */
	/*      i adalah indeks yang valid. */
	/* F.S. X adalah elemen ke-i T yang baru */
	/* Proses : Geser elemen ke-i+1 s.d. terakhir */
	/*          Isi elemen ke-i dengan X */
	/* Kamus Lokal */
	int j;
	
	/* Algoritma */
	for (j = Neff(*T); j >= i; j--) {
		Elmt(*T,j+1) = Elmt(*T,j);
	}
	Elmt(*T,i) = X;
	Neff(*T) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X) {
	/* Proses : Menghapus elemen terakhir tabel */
	/* I.S. Tabel tidak kosong */
	/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
	/*      Banyaknya elemen tabel berkurang satu */
	/*      Tabel T mungkin menjadi kosong */
	/* Algoritma */
	if (!IsEmpty(*T)) {
		*X = Elmt(*T,Neff(*T));
		Neff(*T) -= 1;
	}
}

void DelEli (TabInt * T, IdxType i, ElType * X) {
	/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
	/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
	/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
	/*      Banyaknya elemen tabel berkurang satu */
	/*      Tabel T mungkin menjadi kosong */
	/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
	/*          Kurangi elemen efektif tabel */
	/* Kamus Lokal */
	int j;
	
	/* Algoritma */
	if (!IsEmpty(*T) && IsIdxEff(*T, i) && IsIdxValid(*T, i)) {
		*X = Elmt(*T,i);
		Neff(*T) -= 1;
		for (j = i; j <= Neff(*T); j++) {
			Elmt(*T,j) = Elmt(*T,j+1);
		}
	}
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X) {
	/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
	/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
	/*      dan semua elemennya bernilai unik, tidak terurut */
	/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
			jika belum ada elemen yang bernilai X. 
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
		dan dituliskan pesan "nilai sudah ada" */
	/* Proses : Cek keunikan dengan sequential search dengan sentinel */
	/*          Kemudian tambahkan elemen jika belum ada */
	if (!IsFull(*T) && !SearchSentinel(*T,X)) {
		Neff(*T) += 1;
		Elmt(*T,Neff(*T)) = X;
	} else {
		printf("nilai sudah ada\n");
	}
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X) {
	/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
	/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
	/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
	/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
	/* Kamus Lokal */
	int i;
	
	/* Algoritma */
	i = IdxMin;
	InsSortAsc(&T);
	while (i < Neff(T) && Elmt(T,i) < X) {
		i += 1;
	}
	
	if (Elmt(T,i) == X) {
		return i;
	} //else do nothing
	return IdxUndef;
}

ElType MaxUrut (TabInt T) {
	/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
	/* Mengirimkan nilai maksimum pada tabel */
	/* Algoritma */
	return Elmt(T,Neff(T));
}

ElType MinUrut (TabInt T) {
	/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
	/* Mengirimkan nilai minimum pada tabel*/
	/* Algoritma */
	return Elmt(T,GetFirstIdx(T));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min) {
	/* I.S. Tabel T tidak kosong, elemen terurut membesar */
	/* F.S. Max berisi nilai maksimum T;
			Min berisi nilai minimum T */
	/* Algoritma */
	InsSortAsc(&T);
	if (!IsEmpty(T)) {
		*Max = MaxUrut(T);
		*Min = MinUrut(T);
	}
}

void Add1Urut (TabInt * T, ElType X) {
	/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
	/* Nilai dalam tabel tidak harus unik. */
	/* I.S. Tabel T boleh kosong, boleh penuh. */
	/*      Jika tabel isi, elemennya terurut membesar. */
	/* F.S. Jika tabel belum penuh, menambahkan X. */
	/*      Jika tabel penuh, maka tabel tetap. */
	/* Proses : Search tempat yang tepat sambil geser */
	/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
	/* Kamus Lokal */
	int i, j;
	
	/* Algoritma */
	InsSortAsc(T);
	if (!IsFull(*T)) {
		i = IdxMin;
		while (i <= Neff(*T) && Elmt(*T,i) < X) {
			i += 1;
		}
		for (j = Neff(*T); j >= i; j--) {
			Elmt(*T,j+1) = Elmt(*T,j);
		}
		Elmt(*T,i) = X;
		Neff(*T) += 1;
	}
}

void Del1Urut (TabInt * T, ElType X) {
	/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
	/* I.S. Tabel tidak kosong */
	/* F.S. Jika ada elemen tabel bernilai X , */
	/*      maka banyaknya elemen tabel berkurang satu. */
	/*      Jika tidak ada yang bernilai X, tabel tetap. */
	/*      Setelah penghapusan, elemen tabel tetap kontigu! */
	/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
	/*          Delete jika ada. */
	/* Kamus Lokal */
	int i, j;
	
	/* Algoritma */
	InsSortAsc(T);
	if (!IsEmpty(*T)) {
		i = SearchUrut(*T,X);
		if (i != IdxUndef) {
			Neff(*T) -= 1;
			for (j = i; j <= Neff(*T); j++) {
				Elmt(*T,j) = Elmt(*T,j+1);
			}
		}
	}
}