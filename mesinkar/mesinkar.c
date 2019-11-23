/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include <stdio.h>
#include "../mesinkar/mesinkar.h"

char CC;
boolean EOP;
FILE * pita;
static int retval;

void START(char *filename) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pita = fopen(filename,"r");
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
}

void CLOSE() {
/* I.S. : sembarang
   F.S. : pembacaan pita dihentikan dan pita di-close */
    /* Algoritma */
    fclose(pita);
}

void SCAN() {
/* I.S. : sembarang
   F.S. : membaca karakter yang ada pada pita */
    /* Algoritma */
    scanf("%c", &CC);
}