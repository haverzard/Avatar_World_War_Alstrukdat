/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

#ifndef ARRAYDINPOS_H
#define ARRAYDINPOS_H

#include "boolean.h"
#include "matriks.h"
#include "bangunan.h"

/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef Bangunan ElType_Array;  /* type elemen tabel */
typedef struct
{
  ElType_Array *TI; /* memori tempat penyimpan elemen (container) */
  int MaxElArr;  /* ukuran elemen */
} TabBangunan;
/* Indeks yang digunakan [IdxMin..MaxElArr] */
/* Jika T adalah TabBangunan, cara deklarasi dan akses: */
/* Deklarasi : T : TabBangunan */
/* Maka cara akses:
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: semua elemen bernilai ValUndef
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i terbesar
                                             sehingga T.TI[i] != ValUndef */

/* ********** SELEKTOR ********** */
#define TI(T) (T).TI
#define ElmtArr(T, i) (T).TI[(i)]
#define MaxElArr(T) (T).MaxElArr

extern TabBangunan TB;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabBangunan *T, int MaxElArr);
/* I.S. T sembarang, MaxElArr > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas MaxElArr + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

void Dealokasi_Array(TabBangunan *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxElArr(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NBElmt_Array(TabBangunan T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElArrement(TabBangunan T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabBangunan T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabBangunan T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid_Array(TabBangunan T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff_Array(TabBangunan T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty_Array(TabBangunan T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull_Array(TabBangunan T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsiPeta(TabBangunan *T, MATRIKS Peta);
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dari Peta dan mengisi nilainya */
void TulisIsiTab(TabBangunan T);
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabBangunan T1, TabBangunan T2);
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabBangunan T, ElType_Array X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabBangunan T, ElType_Array X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabBangunan Tin, TabBangunan *Tout);
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxElArr sama) */
/* Proses : Menyalin isi Tin ke Tout */

int CountJenisBangunan(TabBangunan T, JenisBangunan X);
/* Menghasilkan berapa banyak kemunculan JenisBangunan X di T */
/* Jika T kosong menghasilkan 0 */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabBangunan *T, ElType_Array X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabBangunan *T, ElType_Array *X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabBangunan *T, int num);
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabBangunan *T, int num);
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxElArr > num, dan Neff < MaxElArr - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabBangunan *T);
/* Proses : Mengurangi max element sehingga Neff = MaxElArr */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxElArr = Neff */

void DelEli (TabBangunan * T, IdxType i, ElType_Array * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */

#endif
