/* ADT Bangunan */
/*  */

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"
#include "point.h"


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

boolean EQ_Bangunan(Bangunan X1, Bangunan X2);

void InitUndef(Bangunan *X);

void InitCastle(Bangunan *X);

void InitTower(Bangunan *X);

void InitFort(Bangunan *X);

void InitVillage(Bangunan *X);

void InitBangunan(Bangunan *X, char jenisBangunan);

void UpdateBangunan(Bangunan *X);

void SerangBangunan(Bangunan *B1, Bangunan *B2, int N);

void SerangCritical(Bangunan *B1,Bangunan *B2,int N)

void LevelUpBangunan(Bangunan *X);
/* Prekondisi: JumlahPasukan(*X) >= M(*X)/2 */

void Move(Bangunan *B1, Bangunan *B2, int x);

void PrintInfoBangunan(Bangunan X);

void PrintJenisByCode(char X);

#endif