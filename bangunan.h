/* ADT Bangunan */
/*  */

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"

typedef struct {
	int Kepemilikan;
	int JumlahPasukan;
	int Level;
	int A; //Penambahan pasukan
	int M; //Max penambahan pasukan
	boolean P; //Pertahanan
} Bangunan;

#define Kepemilikan(X) (X).Kepemilikan
#define JumlahPasukan(X) (X).JumlahPasukan
#define Level(X) (X).Level
#define A(X) (X).A
#define M(X) (X).M
#define P(X) (X).P
#define U(X) (X).U

void InitCastle(Bangunan *X);

void InitTower(Bangunan *X);

void InitFort(Bangunan *X);

void InitVillage(Bangunan *X);

void UpdateBangunan(Bangunan *X);

void SerangBangunan(Bangunan *X, int N);

void LevelUpBangunan(Bangunan *X);
/* Prekondisi: JumlahPasukan(*X) >= M(*X)/2 */

#endif