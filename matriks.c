/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen char ********** */

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	/* Kamus Lokal */
	int i, j;
	
	/* Algoritma */
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	for (i = BrsMin; i <= NB; i++) {
		for (j = KolMin; j <= NK; j++) {
			ElmtMat(*M,i,j) = ' ';
		}
	}
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid_Matriks (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	/* Algoritma */
	return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	/* Algoritma */
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	/* Algoritma */
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	/* Algoritma */
	return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	/* Algoritma */
	return NKolEff(M);
}

boolean IsIdxEff_Matriks (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	/* Algoritma */
	return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}

ElType_Matriks GetElmtMatDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	/* Algoritma */
	return ElmtMat(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	/* Kamus Lokal */
	int i, j;
	
	/* Algoritma */
	NBrsEff(*MHsl) = NBrsEff(MIn);
	NKolEff(*MHsl) = NKolEff(MIn);
	for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
		for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
			ElmtMat(*MHsl,i,j) = ElmtMat(MIn,i,j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid_Matriks(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
	/* Kamus Lokal */
	int i, j;
	
	/* Algoritma */
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	for (i = GetFirstIdxBrs(*M); i <= NB; i++) {
		for (j = GetFirstIdxKol(*M); j <= NK; j++) {
			scanf("%c", &ElmtMat(*M,i,j));
		}
	}
}

void TulisMATRIKSPETA (MATRIKS M) //Modified
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
*/
{
	/* Kamus Lokal */
	int i, j;
	
	/* Algoritma */
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)+2; j++) {
		printf("=");
	}
	printf("\n");
	printf("=");
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)/2-5; j++) {
		printf(" ");
	}
	printf("PETA ARENA");
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)-5-GetLastIdxKol(M)/2; j++) {
		printf(" ");
	}
	printf("=");
	printf("\n");
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)+2; j++) {
		printf("=");
	}
	printf("\n");
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)+2; j++) {
		printf("*");
	}
	printf("\n");
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		printf("*");
		for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
			printf("%c", ElmtMat(M,i,j));
		}
		printf("%c*\n", ElmtMat(M,i,GetLastIdxKol(M)));
	}
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M)+2; j++) {
		printf("*");
	}
	printf("\n");
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ_MATRIKS (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmtMat_Matriks(M1) = NBElmtMat_Matriks(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ_MATRIKS karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	/* Kamus Lokal */
	int i, j;
	boolean sama;
	
	/* Algoritma */
	if (GetLastIdxKol(M1) == GetLastIdxKol(M2) && GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) {
		i = GetFirstIdxBrs(M1);
		sama = true;
		while (sama && i <= GetLastIdxBrs(M1)) {
			j = GetFirstIdxKol(M1);
			while (sama && j <= GetLastIdxKol(M1)) {
				sama = ElmtMat(M1,i,j) == ElmtMat(M2,i,j);
				j++;
			}
			i++;
		}
		return sama;
	}
	return false;
}
boolean NEQ_MATRIKS (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	/* Algoritma */
	return !(EQ_MATRIKS(M1,M2));
}
boolean EQ_MATRIKSSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	/* Algoritma */
	return (GetLastIdxKol(M1) == GetLastIdxKol(M2) && GetLastIdxBrs(M1) == GetLastIdxBrs(M2));
}

/* ********** Operasi lain ********** */
int NBElmtMat_Matriks (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	/* Algoritma */
	return GetLastIdxKol(M)*GetLastIdxBrs(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	/* Algoritma */
	return GetLastIdxKol(M) == GetLastIdxBrs(M);
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	/* Kamus Lokal */
	int i, j;
	boolean sama;
	
	/* Algoritma */
	if (IsBujurSangkar(M)) {
		i = 1;
		sama = true;
		while (sama && i <= GetLastIdxBrs(M)) {
			j = 1;
			while (sama && j <= GetLastIdxKol(M)) {
				sama = ElmtMat(M,i,j) == ElmtMat(M,j,i);
				j++;
			}
			i++;
		}
		return sama;
	}
	return false;
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	/* Kamus Lokal */
	int i, j, temp;
	MATRIKS MX;
	
	/* Algoritma */
	CopyMATRIKS(*M, &MX);
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
			ElmtMat(*M,j,i) = ElmtMat(MX,i,j);
		}
	}
}