#include <stdio.h>

void main(){
    int cod, qtd;
    float preco;
    scanf("%i %i", &cod, &qtd);
    if(cod == 1){
        preco = 4.00;
        preco = preco * qtd;
    }else if(cod == 2){
        preco = 4.50;
        preco = preco * qtd;
    }else if(cod == 3){
        preco = 5.00;
        preco = preco * qtd;
    }else if(cod == 4){
        preco = 2.00;
        preco = preco * qtd;
    }else if(cod == 5){
        preco = 1.50;
        preco = preco * qtd;
    }

    printf("Total: R$ %.2f\n", preco);
}