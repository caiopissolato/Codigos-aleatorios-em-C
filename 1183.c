#include <stdio.h>

int main(){
    float M[12][12], med = 0.0, soma = 0.0;
    char O;
    int i, j;
    scanf("%c", &O);
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%f", &M[i][j]);
            if(j > i){
                soma = soma + M[i][j];
                med++;
            }
        }
    }
    if(O == 'S'){
        printf("%.1f\n", soma);
    } else if(O == 'M'){
        med = soma/med;
        printf("%.1f\n", med);
    }
    return 1;
}