#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	
	Graph G;
	CreateGraph(1, &G);
	
    for (int i = 1; i <= 9; i++) {
    InsertEdge(&G, i, i+1);
    }
	
    InsertEdge(&G, 1, 13);
    InsertEdge(&G, 1, 17);
    InsertEdge(&G, 17,1);

	/* Print all edges */
	adrNode P = First(G);
	while(P != NodeUndef){
		int NoBangunan1 = NoBangunan(P);
		adrSuccNode Ps = Trail(P);
		while (Ps != NodeUndef) {
			int NoBangunan2 = NoBangunan(Succ(Ps));
			printf("%d %d\n", NoBangunan1, NoBangunan2);
			Ps = Next(Ps);
		}
		P = Next(P);
	}
}