#include <stdio.h>
#include <stdlib.h>
#include "arv_morse.h"

typedef struct arv{
    char letra;
    char simbolo;
    struct arv* esq;
    struct arv* dir;
}Arv;

Arv* inicializa_arv_bin(){
    return NULL;
}

Arv* cria_arv_bin(Arv* arv, char simbolo, char letra){
    arv = (Arv*)malloc(sizeof(Arv));
    arv->simbolo = simbolo;
    arv->letra = letra;
    arv->esq = arv->dir = NULL;
    return arv;
}

Arv* insere_arv_bin(Arv* arv, char simbolo, char letra){
    if((arv->simbolo == '.') && (arv->esq != NULL)){
        arv->esq = cria_arv_bin(arv->esq, simbolo, letra);
        return arv->esq;
    }

    if((arv->simbolo == '_') && (arv->dir != NULL)){
        arv->dir = cria_arv_bin(arv->dir, simbolo, letra);
        return arv->dir;
    }
}

void imprime_arv_bin(Arv* arv){
    if(arv != NULL){
        if(arv->letra != 'n'){
            printf("%c %c\n", arv->simbolo, arv->letra);
        }else{
            printf("%c %c", arv->simbolo, arv->letra);
            imprime_arv_bin(arv->dir);
            imprime_arv_bin(arv->esq);
        }
    }
}