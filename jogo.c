#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int x, y;
    int vet0[6] = {0, 1, 2, 3, 4, 5};
    int vet1[6] = {0, 1, 2, 3, 4, 5};

    for(int i = 0; i < 6; i++){
        x = rand() % 6;
        y = rand() % 6;
        if((vet0[x] >= 0) && (vet1[y] >= 0)){
            printf("%i - %i\n", vet0[x], vet1[y]);
            vet0[x] = -1;
            vet1[y] = -1;   
        }else{
            i--;
        }   
    }
    return 1;
}