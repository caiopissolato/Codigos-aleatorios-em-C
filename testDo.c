#include <stdio.h>

int main(){
    int resto;
    int num1;
    int num2;
    printf("Entre com o num1:");
    scanf("%d", &num1);
    printf("Entre com o num2:");
    scanf("%d", &num2);
    do{
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;
    }while(resto != 0);
    printf("O mdc entre num1 e num2 eh:");
    printf("%d\n", num1);


    return 1;
}