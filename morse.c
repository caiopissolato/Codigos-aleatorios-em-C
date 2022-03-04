#include <stdio.h>
#include <stdlib.h>
#include "arv_morse.h"

int main(){
    FILE *i, *k;
    char ch, ch2;
    int num = 0;

    if((fopen("/home/caio-pissolato/Documentos/codigo_morse.txt", "r")) == NULL){
        perror("Erro: fopen\n");
        exit(EXIT_FAILURE);
    }

    Arv* a = inicializa_arv_bin();
    Arv* x;

    a = cria_arv_bin(a, 'n', 'n');

    ch = fgetc(i);
    while(ch != EOF){
        x = a;
        while(ch != '\n'){
            putchar(ch);

            if(num != 0){
                if((ch =='.')&&(x->esq == NULL)){
                    printf("\nesquerda\n");
                    x->esq = cria_arv_bin(x->esq, ch, 'n');
                    x = x->esq;
                }
                if((ch == '.') && (x->esq != NULL)){
                    printf("\nesquerda\n");
                    x = x->esq;
                }
                if((ch == '-') && (x->dir == NULL)){
                    printf("\ndireita\n");
                    x->dir = cria_arv_bin(x->dir, ch, 'n');
                    x = x->dir;
                }
                if((ch == '-')&&(x->dir != NULL)){
                    printf("\ndireita\n");
                    x = x->dir;
                }
            }else{
                ch2 = ch;
            }
            num++;
            ch = fgetc(i);
        }
        x->letra = ch2;
        num = 0;
        ch = fgetc(i);
    }

    if((k = fopen("/home/caio-pissolato/Documentos/mensagem.txt", "r")) == NULL){
        perror("Erro fopen\n");
        exit(EXIT_FAILURE);
    }
    x = a;

    do{
        ch = fgetc(k);
        if(ch == '.'){
            x = x->esq;
        }
        if(ch =='-'){
            x = x->dir;
        }
        if(ch == '/'){
            printf(" ");
        }
        if((ch == ' ') || (ch == EOF)){
            if(x->letra != 'n'){
                printf("%c", x->letra);
                x = a;
            }
        }
    }while(ch!=EOF);

    return 1;
}