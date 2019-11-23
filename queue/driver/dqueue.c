#include "..\queue.h"
#include <stdio.h>
#include <stdlib.h>

int main (){
    //Kamus
    Queue Q,Qout,Qout2;
    int i=1;
    skilltype temp;


    CreateEmpty_Queue(&Q,5);
    printf("First In\n");
    while (!IsFull_Queue(Q)){
        printf("%d ditambahkan ke dalam queue\n",i);
        Add(&Q,i);
        i +=1;
    }
    CopyQueue (Q,&Qout);
    printf("NbElmt of Qout :%d\n",NBElmt_Queue(Q));
    printf("First Out\n");
    while (!IsEmpty_Queue(Q)){
        Del(&Q,&temp);
        printf("%d dihapus dari queue\n",temp);
    }
    CopyQueue (Q,&Qout2);
    printf("NbElmt of Qout :%d\n",NBElmt_Queue(Qout2));
    return 0;
}