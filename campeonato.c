#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    typedef struct nomes{
        char nome[10];
    }Nome;

    typedef struct times{
        char time[25];
    }Time;

    void embaralhar_nome(Nome *vet, int n){
        for (int i = 0; i < n; i++){
		    int r = rand() % n;
            Nome temp = vet[i];
		    vet[i] = vet[r];
		    vet[r] = temp;
	    }
    }

    void embaralhar_time(Time *vet, int n){
        for (int i = 0; i < n; i++){
		    int r = rand() % n;
            Time temp = vet[i];
		    vet[i] = vet[r];
		    vet[r] = temp;
	    }
    }

    Nome nomec[6] = {"Caio", "Celso", "Edemir", "Geferson", "Luckas", "Netto"};
    Time timec[6] = {"Barcelona", "Juventus", "Liverpool", "Manchester City", "PSG", "Real Madrid"};

    embaralhar_nome(nomec, 6);
    embaralhar_time(timec, 6);
    
    for(int i = 0; i < 6; i++){
        printf("%s - %s\n", nomec[i].nome, timec[i].time);       
    }

    return 1;
}