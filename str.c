#include <stdio.h>
int main(){
    struct Pessoa{
        int idade;
        char nome[25];
        int cpf;
    };

    struct Pessoa p;
    fflush(stdin);
    scanf("%i", &p.idade);
    gets(&p.nome);
    scanf("%i", &p.cpf);

    printf("Nome: %s\nIdade: %i\nCPF: %i\n", p.nome, p.idade, p.cpf);
    
    return 1;
}