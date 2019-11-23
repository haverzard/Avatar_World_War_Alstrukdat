/* Driver Graph */

#include <stdio.h>
#include "../../graph/graph.h"

int main() {
	/* Kamus */
	Graph G;
    int i;
    adrNode Pn;

	/* Algoritma */
	/* Test Create Graph */
	CreateGraph(1, &G);
	
    /* Test InsertNode */
    for (i = 20; i >= 15; i--) {
        InsertNode(&G, i, &Pn);
    }

    /* Test InsertEdge */
	for (i = 1; i <= 10; i++) {
        InsertEdge(&G, i, i+1);
    }

    /* Test SearchNode */
    if ((SearchNode(G, 15)) != NodeUndef) {
        printf("Test Search Node dengan Info bernilai 15: Success\n");
    } else {
        printf("Test Search Node dengan Info bernilai 15: Fail\n");
    }
    /* Test SearchEdge */
    if (SearchEdge(G, 3, 4) != NodeUndef) {
        printf("Test Search Node dengan Info bernilai 15: Success\n");
    } else {
        printf("Test Search Node dengan Info bernilai 15: Fail\n");
    }

    /* Test PrintAllHubunganBangunan */
    printf("Hubungan setiap simpul (sisi) yang terbentuk: \n");
    PrintAllHubunganBangunan(G);
}