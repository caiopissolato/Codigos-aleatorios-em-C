#include <stdio.h>
#include "arvore_bin.h"
#include <stdlib.h>

typedef struct arv_bin{
    int info;
    struct arv_bin* sae;
    struct arv_bin* sad;
}Arvore_Bin;

//Função que cria uma árvore binária vazia
struct arv_bin* cria_arvore_vazia(){
    return NULL;
}

//Função que cria uma árvore binária passando elementos como parâmetro
struct arv_bin* cria_arvore(int i, struct arv_bin* esq, struct arv_bin* dir){
    Arvore_Bin *arv;
    arv = (Arvore_Bin*)malloc(sizeof(struct arv_bin));
    arv->info = i;
    arv->sae = esq;
    arv->sad = dir;
    return arv;
}

//Função que cria árvore binária passando apenas a raiz
struct arv_bin* cria_arvore_raiz(int i){
    Arvore_Bin *arv;
    arv = (Arvore_Bin*)malloc(sizeof(struct arv_bin));
    arv->info = i;
    arv->sae = NULL;
    arv->sad = NULL;
    return arv;
}

//Função verifica se árvore binária está vazia
int arv_vazia(struct arv_bin* arv){
    return arv == NULL;
}

//Função insere árvore binária ordenada
void insere_arv_bin(struct arv_bin **a, int i){
    if((*a) == NULL){
        (*a) = cria_arvore_raiz(i);
    }else if(i < (*a)->info){
        insere_arv_bin(&(*a)->sae, i);
    }else if(i > (*a)->info){
        insere_arv_bin(&(*a)->sad, i);
    }else{
        printf("Valor ja existe na arvore.\n");
    }
}

//Função insere árvore binária ordem par ou impar
void insere_arv_bin_par_impar(struct arv_bin **a, int i){
    if((*a) == NULL){
        (*a) = cria_arvore_raiz(i);
    }else if(i % 2 == 0){
        insere_arv_bin_par_impar(&(*a)->sae, i);
    }else if(i % 2 == 1){
        insere_arv_bin_par_impar(&(*a)->sad, i);
    }    
}
//Função imprime em Pré-Ordem
void imprime_pre_ordem_arv(struct arv_bin* arv){
    if(!arv_vazia(arv)){
        printf("%i ", arv->info);
        imprime_pre_ordem_arv(arv->sae);
        imprime_pre_ordem_arv(arv->sad);
    }
}
//Função imprime em Ordem
void imprime_ordem_arv(struct arv_bin* arv){
    if(!arv_vazia(arv)){
        imprime_ordem_arv(arv->sae);
        printf("%i ", arv->info);
        imprime_ordem_arv(arv->sad);
    }
}
//Função imprime em Pós-Ordem
void imprime_pos_ordem_arv(struct arv_bin* arv){
    if(!arv_vazia(arv)){
        imprime_pos_ordem_arv(arv->sae);
        imprime_pos_ordem_arv(arv->sad);
        printf("%i ", arv->info);
    }
}

//Função de busca na árvore binária
int arv_busca(struct arv_bin* arv, int i){
    if(arv_vazia(arv)){
        return 0;
    }
    if(i == arv->info){
        return 1;
    }else if(arv_busca(arv->sae, i)){
        return 2;
    }else if(arv_busca(arv->sad, i)){
        return 3;
    }
}

void imprime_arvore_bin(struct arv_bin* arv){
    if(arv != NULL){
        printf("%i", arv->info);
        printf("(");
        imprime_arvore_bin(arv->sae);
        imprime_arvore_bin(arv->sad);
        printf(")");
    }
}

//Função conta nó árvora binária
int conta_noh(struct arv_bin* arv){
    if(arv_vazia(arv)){
        return 0;
    }else{
        return (conta_noh(arv->sae) + 1 + conta_noh(arv->sad));
    }
}

//Função altura da árvore binária
int altura_arv_bin(struct arv_bin* arv) {
   if (arv == NULL) 
      return -1; // altura da árvore vazia
   else {
      int esq = altura_arv_bin(arv->sae);
      int dir = altura_arv_bin(arv->sad);
      if (esq < dir) return dir + 1;
      else return esq + 1;
   }
}

//Função conta nós folhas
int conta_folhas(struct arv_bin* arv){
    if(arv == NULL)
        return 0;
    else
        if(arv->sae == arv->sad)
            return 1;
        else
            return conta_folhas(arv->sae) + conta_folhas(arv->sad);
}

//Função imprime folhas árvore binária
void MostraFolhas(struct arv_bin* arv){
    if(arv !=NULL){
        if(arv->sae == NULL && arv->sad == NULL){
        printf("%i\t", arv->info);
        }
    }
    MostraFolhas(arv->sae);
    MostraFolhas(arv->sad);
}

int retorna_valor_maior(struct arv_bin* arv, int valor){
    int i;
    if(arv == NULL){
        return 0;
    }else{
        while(arv->info < i){
            i++;
        }
    }
    retorna_valor_maior(arv->sae,valor);
    retorna_valor_maior(arv->sad,valor);
    return i+1;
}