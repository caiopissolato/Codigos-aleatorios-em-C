#include <stdio.h>

int main(){
    int m;
    float total = 0.0f;
    printf("Numero de alunos: ");
    scanf("%i", &m);
    int vet[m];
    for(int i = 1; i <= m; i++){
        printf("Aluno %i: ", i,"\n");
        scanf("%f", &total);
        total += total;
    }
    float s = 0.0f;
    s = total/m;
    printf("Media: %.1f\n", s);
}