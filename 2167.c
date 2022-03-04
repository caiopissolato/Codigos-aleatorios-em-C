#include <stdio.h>
int main(){
    int N, i, R = 0, cno = 0; // cno força a pegar o primeiro valor
    scanf("%i", &N);
    int vet[N];
    if((N > 1)&&(N <= 100)){
        for(i = 1; i <= N; i++){
            scanf("%i", &vet[i]);
            if(vet[i] > 1){
                if(cno < 1){
                    if((vet[i-1]) > vet[i]){
                        R = i;
                        cno++;
                    }
                }    
            }
        }
    }    
    printf("%i\n", R);
    return 1;
}