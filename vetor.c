#include <stdio.h>

int main(){
    int vet[16];
    for(int i = 0; i < 17; i++){
        scanf("%i", &vet[i]);
        if(vet[1] == 16){ 
            for(int c = 0; c < 17; c++){
                vet[c] = 16;
            }
        }
    }
    printf("%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i\n", vet[0], vet[1], vet[2], vet[3], vet[4], vet[5], vet[6], vet[7], vet[8], vet[9], vet[10], vet[11], vet[12], vet[13], vet[14], vet[15], vet[16]);
    return 1;
}