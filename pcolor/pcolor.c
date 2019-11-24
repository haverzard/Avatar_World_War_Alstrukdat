/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include "../pcolor/pcolor.h"

void print_red(char c) {
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}

void print_green(char c) {
    printf("%s%c", GREEN, c);
    printf("%s", NORMAL);
}

void print_yellow(char c) {
    printf("%s%c", YELLOW, c);
    printf("%s", NORMAL);
}

void print_blue(char c) {
    printf("%s%c", BLUE, c);
    printf("%s", NORMAL);
}

void print_magenta(char c) {
    printf("%s%c", MAGENTA, c);
    printf("%s", NORMAL);
}

void print_cyan(char c) {
    printf("%s%c", CYAN, c);
    printf("%s", NORMAL);
}

void printByColorNum(int num, char c) 
/*  I.S. num terdefinisi
    F.S. Ditampilkan karakter c dengan warna berdasarkan num
*/
{
    switch(num) {
        case 1: print_red(c); break;
        case 2: print_green(c); break;
        case 3: print_yellow(c); break;
        case 4: print_blue(c); break;
        case 5: print_magenta(c); break;
        case 6: print_cyan(c); break;
    }
}


void printSByColorNum(int num)
/*  I.S. num terdefinisi
    F.S. Ditampilkan string selanjutnya dengan warna berdasarkan num
*/
{
    switch(num) {
        case 1: printf("%s",RED); break;
        case 2: printf("%s",GREEN); break;
        case 3: printf("%s",YELLOW); break;
        case 4: printf("%s",BLUE); break;
        case 5: printf("%s",MAGENTA); break;
        case 6: printf("%s",CYAN); break;
        default: printf("%s",NORMAL);
    }
}