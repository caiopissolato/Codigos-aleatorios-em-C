#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void embaralhar(int *vet, int n){
    for (int i = 0; i < n; i++){
		int r = rand() % n;
        int temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}

void selection_sort(int vetor[], int n){
    int i, j, menor, troca;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i+1; j < n; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = troca;
        }
    }
}

void mega_sena(int *vet){
    int i, k, z, n, m;
    printf("Número de jogos da Mega-Sena: ");
    scanf("%i", &n);
    
    int bagunca[60];
    for(m = 0; m<60; m++){
        bagunca[m] = m+1;
    }
    printf("##################################################################################\n");
    for(k = 0; k<n; k++){
        embaralhar(bagunca, 60);
        for(i = 0; i<6; i++){
            vet[i] = bagunca[i];
        }    
        selection_sort(vet, 6);
        printf("Mega-Sena: ");
        for(z = 0; z<6; z++){
            printf("%i ", vet[z]);
        }
        printf("\n");
    }
    printf("##################################################################################\n");
}

void loto_facil(int *vet){
    int i, k, z, n;
    printf("Número de jogos da Loto-Fácil: ");
    scanf("%i", &n);

    int bagunca[25];
    for(int i = 0; i<25; i++){
        bagunca[i] = i+1;
    }
    printf("##################################################################################\n");
    for(k = 0; k<n; k++){
        embaralhar(bagunca, 25);
        for(i = 0; i<15; i++){
            vet[i] = bagunca[i];
        }
        printf("Loto-Fácil: ");
        selection_sort(vet, 15);
        for(z = 0; z<15; z++){
            printf("%i ", vet[z]);
        }
        printf("\n");
    }
    printf("##################################################################################\n");
}

void loto_mania(int *vet){
    int i, k, z, n;
    printf("Número de jogos da Loto-Mania: ");
    scanf("%i", &n);

    int bagunca[100];
    for(int i = 0; i<100; i++){
        bagunca[i] = i;
    }
    printf("##################################################################################\n");
    for(k = 0; k<n; k++){
        embaralhar(bagunca, 100);
        for(i = 0; i<50; i++){
            vet[i] = bagunca[i];
        }
        printf("Loto-Mania: ");
        selection_sort(vet, 50);
        for(z = 0; z<50; z++){
            printf("%i ", vet[z]);
        }
        printf("\n");
    }
    printf("##################################################################################\n");
}

void quina(int *vet){
    int i, k, z, n;
    printf("Número de jogos da Quina: ");
    scanf("%i", &n);

    int bagunca[80];
    for(int i = 0; i<80; i++){
        bagunca[i] = i+1;
    }
    printf("##################################################################################\n");
    for(k = 0; k<n; k++){
        embaralhar(bagunca, 80);
        for(i = 0; i<5; i++){
            vet[i] = bagunca[i];
        }
        printf("Quina: ");
        selection_sort(vet, 5);
        for(z = 0; z<5; z++){
            printf("%i ", vet[z]);
        }
        printf("\n");
    }
    printf("##################################################################################\n");
}

void dupla_sena(int *vet){
    int i, k, z, n, c, v, a;
    printf("Número de jogos da Dupla-Sena: ");
    scanf("%i", &n);

    int bagunca[50];
    for(int i = 0; i<50; i++){
        bagunca[i] = i+1;
    }
    printf("##################################################################################\n");
    for(k = 0; k<n; k++){
        embaralhar(bagunca, 50);
        for(i = 0; i<6; i++){
            vet[i] = bagunca[i];
        }
        printf("DUPLA-SENA\n");
        printf("Jogo 1: ");
        selection_sort(vet, 6);
        for(z = 0; z<6; z++){
            printf("%i ", vet[z]);
        }
        printf("\n");
        int vetor[50];
        for(a = 0; a<50; a++){
            vetor[a] = a+1;
        }
        embaralhar(vetor, 50);
        for(c = 0; c<6; c++){
            vet[c] = bagunca[c];
        }
        printf("Jogo 2: ");
        selection_sort(vetor, 6);
        for(v = 0; v<6; v++){
            printf("%i ", vetor[v]);
        }
        printf("\n");
    }
    printf("##################################################################################\n");
}

int main(){
    srand(time(NULL));
    int mega[6];
    int loto[15];
    int mania[50];
    int vet_quina[5];
    int dupla[6];
    int a;
    printf("Digite o número correspondente ao jogo que deseja gerar: \n");
    printf("1-Mega-Sena\n2-Loto-Fácil\n3-Loto-Mania\n4-Quina\n5-Dupla-Sena\n0-Sair\n");
    scanf("%i", &a);
    while(a != 0){
        switch (a){
            case 1:
                mega_sena(mega);
                printf("\n");
                break;
            case 2:    
                loto_facil(loto);
                printf("\n");
                break;
            case 3:    
                loto_mania(mania);
                printf("\n");
                break;
            case 4:    
                quina(vet_quina);
                printf("\n");
                break;
            case 5: 
                dupla_sena(dupla);
                printf("\n");
                break;
            default:
                printf("Opção Inválida\n");
        }
        int ka;
        printf("Deseja gerar algum outro jogo?\n1-Sim\n0-Nao\n");
        scanf("%i", &ka);
        if(ka == 1){
            printf("Digite o número correspondente ao jogo que deseja gerar: \n");
            printf("1-Mega-Sena\n2-Loto-Fácil\n3-Loto-Mania\n4-Quina\n5-Dupla-Sena\n0-Sair\n");
            scanf("%i", &a);
        }else{
            return 1;
        }    
    }
    return 1;
}