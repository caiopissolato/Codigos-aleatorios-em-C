struct tipoArvM{
    int vls[K];
    struct tipoArvM *filhos[K+1];
    int qtd;
};

struct tipoArvBin{
    int vl;
    struct tipoArvBin *esq;
    struct tipoArvBin *dir;
};

/*1-Considere uma árvore com múltiplos filhos, que armazena valores inteiros positivos,
com parâmetro K = 3(ou seja, cada nó da árvore tem capacidade de armazenar 3 valores). 
Implemente uma função que faça o percursso em ordem na árvore com múltiplos filhos e
que cada valor seja inserido em uma árvore binária, retornando a árvore construída como resposta.
Considere as estruturas apresentadas abaixo e o protótipo das funções que devem ser implementadas.*/

void insereOrdem(struct tipoArv*, struct tipoArvBin**);
void insereArv(struct tipoArvBin**, int);
struct tipoArvBin* percorreArvM(struct tipoArvM*);

void insereOrdem(struct tipoArvM* arvM, struct tipoArvBin** arvB){
    int i;
    if(arvM != NULL){
        for(i = 0; i < arvM->qtd; i++){
            insereOrdem(arvM->filhos[i], arvB);
            insereArv(arvB, arvM->vls[i]);
        }
        insereOrdem(arvM->filhos[arvM->qtd], arvB);
    }
}

struct tipoArvBin* percorreArvM(struct tipoArvM* arvM){
    struct tipoArvBin *arvB;
    arvB=NULL;
    insereOrdem(arvM, &arvB);
    return arvB;
}

/*2- Considere como entrada um vetor ordenado contendo números inteiros positivos,
com quantidade de valores conhecida. Implemente uma função que escolha apropriadamente
os valores no vetor e insira numa árvore binária, de modo que ela fique o melhor possível
balanceada.*/

typedef struct LISTA{
    int vetor[N];
    int qtd;
}tipoLista;

void insereArv(tipoArvBin**, int);
void insercao(tipoLista*, int, int, tipoArvBin**);

void insercao(tipoLista* lista, int comeco, int fim, tipoArvBin* arv){
    int pos;
    pos = comeco +((fim-comeco)/2);
    if(comeco < fim){
        insereArv(arv, lista->vetor[pos]);
        insercao(lista,comeco,pos-1,arv);
        insercao(lista,pos+1,fim,arv);
    }else if(comeco == fim){
        insereArv(arv, lista->vetor[pos]);
    }
}

void insereArv(tipoArvBin** arv, int valor){
    if(*arv == NULL){
        *arv = malloc(sizeof(tipoArvBin));
        (*arv)->vl = valor;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
    }else{
        if(valor < (*arv)->vl){
            insereArv(&((*arv)->esq), valor);
        }else{
            insereArv(&((*arv)->dir), valor);
        }
    }
}

/*3-Considere uma árvore com múltiplos filhos, com capacidade de K
valores. Imagine a necessidade de percorrer os valores armazenados
em ordem inversa, ou seja, do maior para o menor. Defina o tipo de
dado desta árvore, especifique os protótipos e implemente as funções
que percorrem esta árvore em pré-ordem, em ordem e em pós-ordem.*/

typedef struct ARVORE{
    int valores[K];
    struct ARVORE* filhos [K+1];
    int qtd;
}tipoArvore;

void ordem(tipoArvore*);
void preOrdem(tipoArvore*);
void posOrdem(tipoArvore*);

void ordem(tipoArvore* arv){
    int i;
    if(arv != NULL){
        ordem(arv->filhos[arv->qtd]);
        for(i = arv->qtd-1; i>0; i--){
            printf("[%i]", arv->valores[i]);
            ordem(arv->filhos[i]);
        }
    }
}

void preOrdem(tipoArvore* arv){
    int i;
    if(arv != NULL){
        for(i = arv->qtd-1; i >= 0; i--){
            printf("[%i]", arv->valores[i]);
        }
        for(i = arv->qtd; i >= 0; i--){
            preOrdem(arv->filhos[i]);
        }
    }
}

void posOrdem(tipoArvore* arv){
    int i;
    if(arv != NULL){
        for(i = arv->qtd; i>0; i--){
            posOrdem(arv->filhos[i]);
        }
        for(i = arv->qtd-1; i >= 0; i--){
            printf("[%i]", arv->valores[i]);
        }
    }
}