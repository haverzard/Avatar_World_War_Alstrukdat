/* ********** Implementasi Body TYPE MATRIKS dengan indeks dan elemen integer ********** */
#include <stdio.h>
#include "matriksint.h"

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS_INT (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMin && i <= BrsMax)  &&(j >= KolMin && j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEff(M);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M))  &&(j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M)));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return ElmtMatInt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS_INT (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    /* KAMUS LOKAL */
    indeks i, j;
    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
		for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
            ElmtMatInt(*MHsl, i, j) = ElmtMatInt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS_INT (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    /* KAMUS LOKAL */
    indeks i, j;
    /* ALGORITMA */
    MakeMATRIKS(NB, NK, M);
	for (i = GetFirstIdxBrs(*M); i <= NB; i++) {
		for (j = GetFirstIdxKol(*M); j <= NK; j++) {
            scanf("%d", &ElmtMatInt(*M, i, j));
        }
    }
}
void TulisMATRIKS_INT (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /* KAMUS LOKAL */
    indeks i, j;
    /* ALGORITMA */
    for (i = GetFirstIdxBrs(M); i < GetLastIdxBrs(M); i++) {
		for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
            printf("%d ", Elmt(M, i, j));
        }
        printf("%d", Elmt(M, i, j));
        printf("\n");
    }
    i = GetLastIdxBrs(M);
    for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
        printf("%d ", Elmt(M, i, j));
    }
    printf("%d", Elmt(M, i, j));
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ_MATRIKS_INT (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt_MATRIKS_INT(M1) = NBElmt_MATRIKS_INT(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{   
    /* KAMUS LOKAL */
    boolean found = false;
    indeks i, j;
    /* ALGORITMA */
    if (NBElmt_MATRIKS_INT(M1) != NBElmt_MATRIKS_INT(M2)) {
        return false;
    } else {
        i = BrsMin;
        while (!found && i <= NBrsEff(M1)) {
            j = KolMin;
            while (!found && j <= NKolEff(M1)) {
                if (Elmt(M1, i, j) != Elmt(M2, i, j)) {
                    found = true;
                } else {
                    j++;
                }
            }
            i++;
        }
    }

    return !found;
}
boolean NEQ_MATRIKS_INT (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !(EQ_MATRIKS_INT(M1, M2));
}
boolean EQSize_MATRIKS_INT (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return ((GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) && (GetLastIdxKol(M1) == GetLastIdxKol(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt_MATRIKS_INT (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return GetLastIdxBrs(M) * GetLastIdxKol(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar_MATRIKS_INT (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return GetLastIdxBrs(M) == GetLastIdxKol(M);
}
boolean IsSimetri_MATRIKS_INT (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    /* KAMUS LOKAL */
    boolean found = false;
    indeks i, j;
    /* ALGORITMA */
    if (!IsBujurSangkar(M)) {
        return false;
    } else {
        i = BrsMin;
        while (!found && i <= NBrsEff(M)) {
            j = KolMin;
            while (!found && j <= NKolEff(M)) {
                if (Elmt(M, i, j) != Elmt(M, j, i)) {
                    found = true;
                } else {
                    j++;
                }
            }
            if (!found) { i++; }
        } 
    }

    return !found;
}