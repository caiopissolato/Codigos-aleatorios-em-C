#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

int main(){

    struct arv_bin* arv = cria_arvore_raiz(16);
    insere_arv_bin(&arv, 1);
    insere_arv_bin(&arv, 24);
    insere_arv_bin(&arv, 11);
    insere_arv_bin(&arv, 10);
    insere_arv_bin(&arv, 19);
    insere_arv_bin(&arv, 59);
    insere_arv_bin(&arv, 21);
    insere_arv_bin(&arv, 31);
    insere_arv_bin(&arv, 54);
    insere_arv_bin(&arv, 12);
    insere_arv_bin(&arv, 73);
    insere_arv_bin(&arv, 7);

    int retorno  = arv_busca(arv, 32);
    if(retorno == 1){
        printf("Valor na raiz.\n");
    }else if(retorno == 2){
        printf("Valor na esquerda.\n");
    }else if(retorno == 3){
        printf("Valor na direita.\n");
    }else{
        printf("Valor não encontrado.\n");
    }
    printf("Pre-Ordem: ");
    imprime_pre_ordem_arv(arv);
    printf("\n");
    printf("Pos-Ordem: ");
    imprime_pos_ordem_arv(arv);
    printf("\n");
    printf("Ordem: ");
    imprime_ordem_arv(arv);
    printf("\n");
    imprime_arvore_bin(arv);
    printf("\n");
    printf("Numero de nós: %i\n", conta_noh(arv));
    printf("Altura da arvore: %i\n", altura_arv_bin(arv));
    printf("Numero de nós folhas: %i\n", conta_folhas(arv));
    int c = 1;
    printf("Valores maiores que %i: %i\n", c, retorna_valor_maior(arv, c));
    return 1;
}