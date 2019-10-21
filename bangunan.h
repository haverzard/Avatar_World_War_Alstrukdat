/* ADT Bangunan */
/*  */

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"

#define JenisUndef 'A'
#define ValIntUndef -999

typedef char JenisBangunan;
typedef struct {
	JenisBangunan Jenis;
	int Kepemilikan;
	char Jenis;
	int JumlahPasukan;
	int Level;
	int A; //Penambahan pasukan
	int M; //Max penambahan pasukan
	int U; //Pasukan Awal
	boolean P; //Pertahanan
} Bangunan;

#define Jenis(X) (X).Jenis
#define Kepemilikan(X) (X).Kepemilikan
#define Jenis(X) (X).Jenis
#define JumlahPasukan(X) (X).JumlahPasukan
#define Level(X) (X).Level
#define A(X) (X).A
#define M(X) (X).M
#define P(X) (X).P
#define U(X) (X).U

boolean isJenisBangunanValid(JenisBangunan X);
boolean isEQBangunan(Bangunan X1, Bangunan X2);

void InitUndef(Bangunan *X);

void InitCastle(Bangunan *X);

void InitTower(Bangunan *X);

void InitFort(Bangunan *X);

void InitVillage(Bangunan *X);

void InitBangunan(Bangunan *X, char jenisBangunan);

void UpdateBangunan(Bangunan *X);

void SerangBangunan(Bangunan *X, int N);

void LevelUpBangunan(Bangunan *X);
/* Prekondisi: JumlahPasukan(*X) >= M(*X)/2 */

#endif