#include <stdio.h>
#include <stdlib.h>



Arv* inicializa(){
    return NULL;
}

Arv* cria(Arv* a, char simbolo, char letra){
    a = (Arv*)malloc(sizeof(Arv));
    a->simbolo = simbolo;
    a->letra = letra;
    a->esq = a->dir = NULL;
    return a;
}

Arv* insere(Arv* a, char simbolo, char letra){
    if((a->simbolo == '.') && (a->esq != NULL)){
        a->esq = cria(a->esq, simbolo, letra);
        return a->esq;
    }

    if((a->simbolo == '_') && (a->dir != NULL)){
        a->dir = cria(a->dir, simbolo, letra);
        return a->dir;
    }
}

void imprime(Arv* a){
    if(a!=NULL){
        if(a->letra != 'n'){
            printf("%c %c\n", a->simbolo, a->letra);
        }else{
            printf("%c %c", a->simbolo, a->letra);
            imprime(a->dir);
            imprime(a->esq);
        }
    }
}