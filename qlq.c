#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int main(){
    int vet[16] = {25,36,2,23,34,24,59,7,16,11,18,93,43,67,27,10};
    heap_sort(vet, 16);

    for(int i = 0; i<16; i++){
        printf("%i ", vet[i]);
    }
    printf("\n");
    return 1;
}