#include <stdio.h>

int main(){
    float a, p;

    printf("Entre com o valor de alfa: \n");
    scanf("%f", &a);

    printf("Entre com o valor de p: \n");
    scanf("%f", &p);

    if(a > p){
        printf("Alfa maior.\n");
    }else if(p > a){
        printf("p maior.\n");
    }else{
        return 0;
    }

    return 0;

}