/* Driver STACK */

#include <stdio.h>
#include "../../stack/stack.c"

#define printnull() printf("Tidak Ada Isi Dalam Stack!\n")
#define printfull() printf("Stack Sudah Penuh!\n")
#define prints() printf("Masih Ada Slot Stack Yang Kosong!\n")
#define println() printf("\n")

int main () {
    /* KAMUS */
    Stack S;
    infotypeStack X;
    Player P1, P2;
    TabBangunan TB1;
    int i;

    /* ALGORITMA */
    
    /* Test Create Graph */
    printf("Test Create Graph\n"); println();
    CreateEmpty_Stack(&S);

    /* Test Isi Stack */
    printf("Test Isi Stack\n");
    if (IsEmpty_Stack(S)) printnull();
    else if (IsFull_Stack(S)) printfull();
    else prints();
    println();

    /* Test Add Stack */
    printf("Test Add Stack\n"); println();
    for (i=1; i<=10; i++){
        printf("MASUKKAN ISI STACK : ");
        scanf("%d", &X);
        Push(&S, X);
    }

    /* Test Isi Stack */
    printf("Test Isi Stack\n");
    if (IsEmpty_Stack(S)) printnull();
    else if (IsFull_Stack(S)) printfull();
    else prints();
    println();

    /* Test Remove Stack */
    for (i=1; i<=5; i++){
        Pop(&S, &X);
    }

    /* Test Isi Stack */
    printf("Test Isi Stack\n");
    if (IsEmpty_Stack(S)) printnull();
    else if (IsFull_Stack(S)) printfull();
    else prints();
    println();

    /* Test Update Status */


    /* Test Undo Status */


    /* Test Reset Status */
    printf("TEST RESET STATUS"); println();
    ResetStatus(&S);
    if (IsEmpty_Stack(S)) printnull();
    else if (IsFull_Stack(S)) printfull();
    else prints();

}