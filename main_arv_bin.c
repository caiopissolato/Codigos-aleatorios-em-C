#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

int main(){
    struct arv_bin* arv = cria_arvore_vazia();
    printf("Arvore vazia criada com sucesso!\n");

    struct arv_bin* arv1 = cria_arvore_vazia();

    struct arv_bin* arv_cheia = cria_arvore(16, arv, arv1);
    imprime_arv(arv_cheia);
    printf("\nArvore com elementos criada com sucesso!\n");
    

    return 1;
}