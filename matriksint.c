/* ********** Implementasi Body TYPE MATRIKS dengan indeks dan elemen integer ********** */
#include <stdio.h>
#include "matriksint.h"

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS_INT (int NB, int NK, MATRIKS_INT * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEffMatInt(*M) = NB;
    NKolEffMatInt(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMinMatInt && i <= BrsMaxMatInt)  &&(j >= KolMinMatInt && j <= KolMaxMatInt));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeksMatInt GetFirstIdxBrsMatInt (MATRIKS_INT M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMinMatInt;
}
indeksMatInt GetFirstIdxKolMatInt (MATRIKS_INT M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMinMatInt;
}
indeksMatInt GetLastIdxBrsMatInt (MATRIKS_INT M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEffMatInt(M);
}
indeksMatInt GetLastIdxKolMatInt (MATRIKS_INT M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEffMatInt(M);
}
boolean IsIdxEffMatInt (MATRIKS_INT M, indeksMatInt i, indeksMatInt j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i >= BrsMinMatInt && i <= NBrsEffMatInt(M))  &&(j >= KolMinMatInt && j <= NKolEffMatInt(M)));
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS_INT (MATRIKS_INT MIn, MATRIKS_INT * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    /* KAMUS LOKAL */
    indeksMatInt i, j;
    /* ALGORITMA */
    MakeMATRIKS_INT(NBrsEffMatInt(MIn), NKolEffMatInt(MIn), MHsl);
    for (i = GetFirstIdxBrsMatInt(MIn); i <= GetLastIdxBrsMatInt(MIn); i++) {
		for (j = GetFirstIdxKolMatInt(MIn); j <= GetLastIdxKolMatInt(MIn); j++) {
            ElmtMatInt(*MHsl, i, j) = ElmtMatInt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS_INT (MATRIKS_INT * M, int NB, int NK)
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
    indeksMatInt i, j;
    /* ALGORITMA */
    MakeMATRIKS_INT(NB, NK, M);
	for (i = GetFirstIdxBrsMatInt(*M); i <= NB; i++) {
		for (j = GetFirstIdxKolMatInt(*M); j <= NK; j++) {
            scanf("%d", &ElmtMatInt(*M, i, j));
        }
    }
}
void TulisMATRIKS_INT (MATRIKS_INT M)
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
    indeksMatInt i, j;
    /* ALGORITMA */
    for (i = GetFirstIdxBrsMatInt(M); i < GetLastIdxBrsMatInt(M); i++) {
		for (j = GetFirstIdxKolMatInt(M); j < GetLastIdxKolMatInt(M); j++) {
            printf("%d ", ElmtMatInt(M, i, j));
        }
        printf("%d", ElmtMatInt(M, i, j));
        printf("\n");
    }
    i = GetLastIdxBrsMatInt(M);
    for (j = GetFirstIdxKolMatInt(M); j < GetLastIdxKolMatInt(M); j++) {
        printf("%d ", ElmtMatInt(M, i, j));
    }
    printf("%d", ElmtMatInt(M, i, j));
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ_MATRIKS_INT (MATRIKS_INT M1, MATRIKS_INT M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt_MATRIKS_INT(M1) = NBElmt_MATRIKS_INT(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrsMatInt(M1) = GetFirstIdxBrsMatInt(M2)
   dan GetLastIdxKolMatInt(M1) = GetLastIdxKolMatInt(M2) */
{   
    /* KAMUS LOKAL */
    boolean found = false;
    indeksMatInt i, j;
    /* ALGORITMA */
    if (NBElmt_MATRIKS_INT(M1) != NBElmt_MATRIKS_INT(M2)) {
        return false;
    } else {
        i = BrsMinMatInt;
        while (!found && i <= NBrsEffMatInt(M1)) {
            j = KolMinMatInt;
            while (!found && j <= NKolEffMatInt(M1)) {
                if (ElmtMatInt(M1, i, j) != ElmtMatInt(M2, i, j)) {
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
boolean NEQ_MATRIKS_INT (MATRIKS_INT M1, MATRIKS_INT M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !(EQ_MATRIKS_INT(M1, M2));
}
boolean EQSize_MATRIKS_INT (MATRIKS_INT M1, MATRIKS_INT M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return ((GetLastIdxBrsMatInt(M1) == GetLastIdxBrsMatInt(M2)) && (GetLastIdxKolMatInt(M1) == GetLastIdxKolMatInt(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt_MATRIKS_INT (MATRIKS_INT M)
/* Mengirimkan banyaknya elemen M */
{
    return GetLastIdxBrsMatInt(M) * GetLastIdxKolMatInt(M);
}
