/* ADT Bangunan */
/* ADT untuk merepresentasikan Bangunan dan atributnya pada permainan */

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "../boolean/boolean.h"
#include "../point/point.h"


#define JenisUndef 'A'
#define ValIntUndef -999

typedef char JenisBangunan;

typedef struct {
	POINT Koordinat;
	int Kepemilikan;
	int JumlahPasukan;
	int Level;
	int A; //Penambahan pasukan
	int M; //Max penambahan pasukan
	int U; //Pasukan Awal
	boolean P; //Pertahanan
	boolean AttackAvai;
	boolean MoveAvai;
	JenisBangunan Jenis;
} Bangunan;

#define Kepemilikan(X) (X).Kepemilikan
#define Jenis(X) (X).Jenis
#define Koordinat(X) (X).Koordinat
#define JumlahPasukan(X) (X).JumlahPasukan
#define Level(X) (X).Level
#define AttackAvai(X) (X).AttackAvai
#define MoveAvai(X) (X).MoveAvai
#define A(X) (X).A
#define M(X) (X).M
#define P(X) (X).P
#define U(X) (X).U

extern Bangunan BangunanUndef;

boolean IsBangunanValid(Bangunan X);
/* Mengirimkan true jika Bangunan X adalah bangunan yang valid */
/* Bangunan yang valid adalah Bangunan yang tidak sama dengan JenisUndef */

boolean EQ_Bangunan(Bangunan X1, Bangunan X2);
/* Mengirimkan true jika Bangunan X1 dan Bangunan X2 adalah bangunan yang sama */

void InitCastle(Bangunan *X);
/* I.S. Bangunan X sembarang */
/* F.S. Bangunan X terdefinisi dengan JenisBangunan = 'C' */

void InitTower(Bangunan *X);
/* I.S. Bangunan X sembarang */
/* F.S. Bangunan X terdefinisi dengan JenisBangunan = 'T' */

void InitFort(Bangunan *X);
/* I.S. Bangunan X sembarang */
/* F.S. Bangunan X terdefinisi dengan JenisBangunan = 'F' */

void InitVillage(Bangunan *X);
/* I.S. Bangunan X sembarang */
/* F.S. Bangunan X terdefinisi dengan JenisBangunan = 'V' */

void InitBangunan(Bangunan *X, char jenisBangunan);
/* I.S. Bangunan X sembarang, jenisBangunan terdefinisi */
/* F.S. Bangunan X terdefinisi dengan JenisBangunan = jenisBangunan */

void UpdateBangunan(Bangunan *X);
/* I.S. bangunan X terdefinisi */
/* F.S. JumlahPasukan pada bangunan X telah terupdate jika JumlahPasukan < MaxPasukan */

void SerangBangunan(Bangunan *B1, Bangunan *B2, int N);
/* I.S. Bangunan B1, B2 dan N terdefinisi */
/* F.S. JumlahPasukan pada B1 berkurang sebanyak N dan 
   JumlahPasukan pada B2 berkurang sebanyak N jika B2 tidak memiliki pertahanan 
   atau berkurang sebanyak (3/4)N jika B2 memiliki pertahanan */

void SerangCritical(Bangunan *B1,Bangunan *B2,int N);
/* I.S. Bangunan B1, B2 dan N terdefinisi */
/* F.S. JumlahPasukan pada B1 berkurang sebanyak N/2 dan 
   JumlahPasukan pada B2 berkurang sebanyak N jika B2 tidak memiliki pertahanan 
   atau berkurang sebanyak (3/4)N jika B2 memiliki pertahanan */

void LevelUpBangunan(Bangunan *X);
/* Prekondisi: JumlahPasukan(*X) >= M(*X)/2 */
/* I.S. Bangunan X terdefinisi */
/* F.S. Level pada Bangunan X bertambah 1 dengan A, M, P mengikuti JenisBangunan */

void Move(Bangunan *B1, Bangunan *B2, int x);
/* I.S. Bangunan B1, B2, dan X terdefinisi */
/* F.S. JumlahPasukan B1 berkurang sebanyak X dan JumlahPasukan B2 bertambah sebanyak X */
/* Proses: memindahkan pasukan dari suatu bangunan ke bangunan 
			lain milik pemain yang terhubung dengan bangunan tersebut */

void PrintInfoBangunan(Bangunan X);
/* I.S. Bangunan X terdefinisi */
/* F.S. JenisBangunan, koordinat, jumlah pasukan, dan level bangunan X ditampilkan ke layar */

void PrintJenisByCode(char X);
/* I.S. X terdefinisi  */
/* F.S. Menampilkan "Castle" ke layar jika X='C' */
	/* Menampilkan "Tower" ke layar jika X='T' */
	/* Menampilkan "Fort" ke layar jika X='F' */
	/* Menampilkan "Village" ke layar jika X='V' */

#endif