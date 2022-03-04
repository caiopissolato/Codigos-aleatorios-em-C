#include <stdio.h>
void main(){
    int a, b;
    scanf("%d %i", &a, &b);
    if(a==b){
        printf("O JOGO DUROU %i HORA(S)\n", 24-a+b);
    }else if(a<=b){
        printf("O JOGO DUROU %i HORA(S)\n",b-a);
    }else{
        printf("O JOGO DUROU %i HORA(S)\n", 24-a+b);
    }
}