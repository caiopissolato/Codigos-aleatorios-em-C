#include <stdio.h>

int main(){
    struct jogador{
        char nome[100];
        int S;
        int B;
        int A;
    };

    typedef struct jogador jog;
    int N, i, j, vet[3];
    scanf("%i", &N);

    jog jog1[N];
    for(i = 1; i <= N; i++){
        scanf("%i", jog1[i]);
    }
    for(j = 1; j < 4; j++){
        scanf("%i", vet[i]);
    }





    return 1;
}