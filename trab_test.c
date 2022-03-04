#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ordenacao.h"

int main(){

    void bubble_sort (int vetor[], int n) {
        int i, j, aux;
        long long int flag = 0;
        for(i = 0; i<n; i++){
            for(j = 0; j<n; j++){
                if(vetor[j]>vetor[j+1]){
                    flag++;
                    aux = vetor[j];
                    vetor[j] = vetor[j+1];
                    vetor[j+1] = aux;
                }
            }
        }
        printf("Trocas: %lli\n", flag);
    }

    void insert_sort(int vetor[], int n){
        int i, j, valor;
        long long int flag = 0;
        for(i = 1; i < n; i++){
            valor = vetor[i];
            for(j = i - 1; j >= 0 && vetor[j] > valor; j--){
                flag++;
                vetor[j+1] = vetor[j];
            }
            vetor[j+1] = valor;
        }
        printf("Trocas: %lli\n", flag);
    }

    void selection_sort(int vetor[], int n){
        int i, j, menor, troca;
        long long int flag;
        for(i = 0; i < n-1; i++){
            menor = i;
            for(j = i+1; j < n; j++){
                if(vetor[j] < vetor[menor]){
                    menor = j;
                }
            }
            if(i != menor){
                flag++;
                troca = vetor[i];
                vetor[i] = vetor[menor];
                vetor[menor] = troca;
            }
        }
        printf("Trocas: %lli\n", flag);
    }

    void shell_sort(int vetor[], int n){
        int i = (n - 1) / 2;
        int chave, k, aux;
        long long int flag = 0;

        while (i != 0){
            do{
                chave = 1;
                for (k = 0; k < n - i; ++k){
                    if (vetor[k] > vetor[k + i]){
                        flag++;
                        aux = vetor[k];
                        vetor[k] = vetor[k + i];
                        vetor[k + i] = aux;
                        chave = 0;
                    }
                }
            }    
            while (chave == 0);
            i = i / 2;
        }
        printf("Trocas: %lli\n", flag);
    }

    void merge(int *vetor, int ini, int meio, int fim){
        int *temp, p1, p2, n, i, j, k;
        int fim1 = 0, fim2 = 0;
        n = fim-ini+1;
        p1 = ini;
        p2 = meio+1;
        temp = (int *) malloc(n*sizeof(int));
        if(temp != NULL){
            for(i=0; i<n; i++){
                if(!fim1 && !fim2){
                    if(vetor[p1] < vetor[p2]){
                        temp[i] = vetor[p1++];
                    }else{
                        temp[i] = vetor[p2++];
                    }
                    if(p1>meio) fim1=1;
                    if(p2>fim) fim2=1;
                }else{
                    if(!fim1){
                        temp[i]=vetor[p1++];
                    }else{
                        temp[i]=vetor[p2++];
                    }
                }
            }
            for(j = 0, k = ini; j<n; j++, k++){
                vetor[k]=temp[j];
            }
        }
        free(temp);
    }

    void merge_sort(int *vetor, int ini, int fim){
        int meio;
        if(ini < fim){
            meio = floor((ini+fim)/2);
            merge_sort(vetor, ini, meio);
            merge_sort(vetor, meio+1, fim);
            merge(vetor, ini, meio, fim);
        }
    }

    int quick(int *vetor, int ini, int fim){
        int esq, dir, pivo, aux;
        esq = ini;
        dir = fim;
        pivo = vetor[ini];
        while(esq < dir){
            while(vetor[esq] <= pivo)
                esq++;
            while(vetor[dir] > pivo)
                dir--;
            if(esq < dir){
                aux = vetor[esq];
                vetor[esq] = vetor[dir];
                vetor[dir] = aux;
            }        
        }
        vetor[ini] = vetor[dir];
        vetor[dir] = pivo;
        return dir;
    }

    void quick_sort(int *vetor, int ini, int fim){
        int pivo;
        if(fim > ini){
            pivo = quick(vetor, ini, fim);
            quick_sort(vetor, ini, pivo-1);
            quick_sort(vetor, pivo+1, fim);
        }
    }

    void le_arquivo1000(char *end, int *vet){
        FILE *file = fopen(end, "r");
        int i = 0, retorno_scanf;
        if(file == NULL){
            printf("ERRO ao abrir arquivo.\n");
            exit(1);
        }else{
            for(i = 0; i<1000; i++){
                if(retorno_scanf != EOF){
                    retorno_scanf = fscanf(file, "%i", &vet[i]);
                }
            }
        }   
        fclose(file);     
    }

    void le_arquivo10000(char *end, int *vet){
        FILE *file = fopen(end, "r");
        int i = 0, retorno_scanf;
        if(file == NULL){
            printf("ERRO ao abrir arquivo.\n");
            exit(1);
        }else{
            for(i = 0; i<10000; i++){
                if(retorno_scanf != EOF){
                    retorno_scanf = fscanf(file, "%i", &vet[i]);
                }
            }
        }   
        fclose(file);     
    }

    void le_arquivo100000(char *end, int *vet){
        FILE *file = fopen(end, "r");
        int i = 0, retorno_scanf;
        if(file == NULL){
            printf("ERRO ao abrir arquivo.\n");
            exit(1);
        }else{
            for(i = 0; i<100000; i++){
                if(retorno_scanf != EOF){
                    retorno_scanf = fscanf(file, "%i", &vet[i]);
                }
            }
        }   
        fclose(file);     
    }

    float ordena_bub(int *vet, int n){
        float tempo;
        time_t t_ini, t_fim;
        t_ini = time(NULL);
        bubble_sort(vet, n);
        t_fim = time(NULL);
        tempo = difftime(t_fim, t_ini);
        return tempo;
    }

    float ordena_insert(int *vet, int n){
        float tempo;
        time_t t_ini, t_fim;
        t_ini = time(NULL);
        insert_sort(vet, n);
        t_fim = time(NULL);
        tempo = difftime(t_fim, t_ini);
        return tempo;
    }

    float ordena_selection(int *vet, int n){
        float tempo;
        time_t t_ini, t_fim;
        t_ini = time(NULL);
        selection_sort(vet, n);
        t_fim = time(NULL);
        tempo = difftime(t_fim, t_ini);
        return tempo;
    }

    float ordena_shell(int *vet, int n){
        float tempo;
        time_t t_ini, t_fim;
        t_ini = time(NULL);
        shell_sort(vet, n);
        t_fim = time(NULL);
        tempo = difftime(t_fim, t_ini);
        return tempo;
    }

    float ordena_merge(int *vet, int n){
        float tempo;
        time_t t_ini, t_fim;
        t_ini = time(NULL);
        merge_sort(vet, 0, n);
        t_fim = time(NULL);
        tempo = difftime(t_fim, t_ini);
        return tempo;
    }

    float ordena_quick(int *vet, int n){
        float tempo;
        time_t t_ini, t_fim;
        t_ini = time(NULL);
        quick_sort(vet, 0, n);
        t_fim = time(NULL);
        tempo = difftime(t_fim, t_ini);
        return tempo;
    }

    int vetor1000bub_Arq1[1000], vetor1000bub_Arq2[1000], vetor1000bub_Arq3[1000], vetor1000bub_Arq4[1000], vetor1000bub_Arq5[1000], vetor10000bub_Arq1[10000], vetor10000bub_Arq2[10000], vetor10000bub_Arq3[10000], vetor10000bub_Arq4[10000], vetor10000bub_Arq5[10000], vetor100000bub_Arq1[100000], vetor100000bub_Arq2[100000], vetor100000bub_Arq3[100000], vetor100000bub_Arq4[100000], vetor100000bub_Arq5[100000];
    int vetor1000insert_Arq1[1000], vetor1000insert_Arq2[1000], vetor1000insert_Arq3[1000], vetor1000insert_Arq4[1000], vetor1000insert_Arq5[1000], vetor10000insert_Arq1[10000], vetor10000insert_Arq2[10000], vetor10000insert_Arq3[10000], vetor10000insert_Arq4[10000], vetor10000insert_Arq5[10000], vetor100000insert_Arq1[100000], vetor100000insert_Arq2[100000], vetor100000insert_Arq3[100000], vetor100000insert_Arq4[100000], vetor100000insert_Arq5[100000];
    int vetor1000sel_Arq1[1000], vetor1000sel_Arq2[1000], vetor1000sel_Arq3[1000], vetor1000sel_Arq4[1000], vetor1000sel_Arq5[1000], vetor10000sel_Arq1[10000], vetor10000sel_Arq2[10000], vetor10000sel_Arq3[10000], vetor10000sel_Arq4[10000], vetor10000sel_Arq5[10000], vetor100000sel_Arq1[100000], vetor100000sel_Arq2[100000], vetor100000sel_Arq3[100000], vetor100000sel_Arq4[100000], vetor100000sel_Arq5[100000];
    int vetor1000shell_Arq1[1000], vetor1000shell_Arq2[1000], vetor1000shell_Arq3[1000], vetor1000shell_Arq4[1000], vetor1000shell_Arq5[1000], vetor10000shell_Arq1[10000], vetor10000shell_Arq2[10000], vetor10000shell_Arq3[10000], vetor10000shell_Arq4[10000], vetor10000shell_Arq5[10000], vetor100000shell_Arq1[100000], vetor100000shell_Arq2[100000], vetor100000shell_Arq3[100000], vetor100000shell_Arq4[100000], vetor100000shell_Arq5[100000];
    int vetor1000merge_Arq1[1000], vetor1000merge_Arq2[1000], vetor1000merge_Arq3[1000], vetor1000merge_Arq4[1000], vetor1000merge_Arq5[1000], vetor10000merge_Arq1[10000], vetor10000merge_Arq2[10000], vetor10000merge_Arq3[10000], vetor10000merge_Arq4[10000], vetor10000merge_Arq5[10000], vetor100000merge_Arq1[100000], vetor100000merge_Arq2[100000], vetor100000merge_Arq3[100000], vetor100000merge_Arq4[100000], vetor100000merge_Arq5[100000];
    int vetor1000quick_Arq1[1000], vetor1000quick_Arq2[1000], vetor1000quick_Arq3[1000], vetor1000quick_Arq4[1000], vetor1000quick_Arq5[1000], vetor10000quick_Arq1[10000], vetor10000quick_Arq2[10000], vetor10000quick_Arq3[10000], vetor10000quick_Arq4[10000], vetor10000quick_Arq5[10000], vetor100000quick_Arq1[100000], vetor100000quick_Arq2[100000], vetor100000quick_Arq3[100000], vetor100000quick_Arq4[100000], vetor100000quick_Arq5[100000];

    le_arquivo1000("1000-arq1.txt", vetor1000bub_Arq1); le_arquivo1000("1000-arq2.txt", vetor1000bub_Arq2); le_arquivo1000("1000-arq3.txt", vetor1000bub_Arq3); le_arquivo1000("1000-arq4.txt", vetor1000bub_Arq4); le_arquivo1000("1000-arq5.txt", vetor1000bub_Arq5);le_arquivo1000("1000-arq1.txt", vetor1000insert_Arq1); le_arquivo1000("1000-arq2.txt", vetor1000insert_Arq2); le_arquivo1000("1000-arq3.txt", vetor1000insert_Arq3); le_arquivo1000("1000-arq4.txt", vetor1000insert_Arq4); le_arquivo1000("1000-arq5.txt", vetor1000insert_Arq5);le_arquivo1000("1000-arq1.txt", vetor1000sel_Arq1); le_arquivo1000("1000-arq2.txt", vetor1000sel_Arq2); le_arquivo1000("1000-arq3.txt", vetor1000sel_Arq3); le_arquivo1000("1000-arq4.txt", vetor1000sel_Arq4); le_arquivo1000("1000-arq5.txt", vetor1000sel_Arq5); le_arquivo1000("1000-arq1.txt", vetor1000shell_Arq1); le_arquivo1000("1000-arq2.txt", vetor1000shell_Arq2); le_arquivo1000("1000-arq3.txt", vetor1000shell_Arq3); le_arquivo1000("1000-arq4.txt", vetor1000shell_Arq4); le_arquivo1000("1000-arq5.txt", vetor1000shell_Arq5);le_arquivo1000("1000-arq1.txt", vetor1000merge_Arq1); le_arquivo1000("1000-arq2.txt", vetor1000merge_Arq2); le_arquivo1000("1000-arq3.txt", vetor1000merge_Arq3); le_arquivo1000("1000-arq4.txt", vetor1000merge_Arq4); le_arquivo1000("1000-arq5.txt", vetor1000merge_Arq5);le_arquivo1000("1000-arq1.txt", vetor1000quick_Arq1); le_arquivo1000("1000-arq2.txt", vetor1000quick_Arq2); le_arquivo1000("1000-arq3.txt", vetor1000quick_Arq3); le_arquivo1000("1000-arq4.txt", vetor1000quick_Arq4); le_arquivo1000("1000-arq5.txt", vetor1000quick_Arq5);  
    le_arquivo10000("10000-arq1.txt", vetor10000bub_Arq1); le_arquivo10000("10000-arq2.txt", vetor10000bub_Arq2); le_arquivo10000("10000-arq3.txt", vetor10000bub_Arq3); le_arquivo10000("10000-arq4.txt", vetor10000bub_Arq4); le_arquivo10000("10000-arq5.txt", vetor10000bub_Arq5);le_arquivo10000("10000-arq1.txt", vetor10000insert_Arq1); le_arquivo10000("10000-arq2.txt", vetor10000insert_Arq2); le_arquivo10000("10000-arq3.txt", vetor10000insert_Arq3); le_arquivo10000("10000-arq4.txt", vetor10000insert_Arq4); le_arquivo10000("10000-arq5.txt", vetor10000insert_Arq5);le_arquivo10000("10000-arq1.txt", vetor10000sel_Arq1); le_arquivo10000("10000-arq2.txt", vetor10000sel_Arq2); le_arquivo10000("10000-arq3.txt", vetor10000sel_Arq3); le_arquivo10000("10000-arq4.txt", vetor10000sel_Arq4); le_arquivo10000("10000-arq5.txt", vetor10000sel_Arq5);le_arquivo10000("10000-arq1.txt", vetor10000shell_Arq1); le_arquivo10000("10000-arq2.txt", vetor10000shell_Arq2); le_arquivo10000("10000-arq3.txt", vetor10000shell_Arq3); le_arquivo10000("10000-arq4.txt", vetor10000shell_Arq4); le_arquivo10000("10000-arq5.txt", vetor10000shell_Arq5);le_arquivo10000("10000-arq1.txt", vetor10000merge_Arq1); le_arquivo10000("10000-arq2.txt", vetor10000merge_Arq2); le_arquivo10000("10000-arq3.txt", vetor10000merge_Arq3); le_arquivo10000("10000-arq4.txt", vetor10000merge_Arq4); le_arquivo10000("10000-arq5.txt", vetor10000merge_Arq5);le_arquivo10000("10000-arq1.txt", vetor10000quick_Arq1); le_arquivo10000("10000-arq2.txt", vetor10000quick_Arq2); le_arquivo10000("10000-arq3.txt", vetor10000quick_Arq3); le_arquivo10000("10000-arq4.txt", vetor10000quick_Arq4); le_arquivo10000("10000-arq5.txt", vetor10000quick_Arq5);  
    le_arquivo100000("100000-arq1.txt", vetor100000bub_Arq1); le_arquivo100000("100000-arq2.txt", vetor100000bub_Arq2); le_arquivo100000("100000-arq3.txt", vetor100000bub_Arq3); le_arquivo100000("100000-arq4.txt", vetor100000bub_Arq4); le_arquivo100000("100000-arq5.txt", vetor100000bub_Arq5);le_arquivo100000("100000-arq1.txt", vetor100000insert_Arq1); le_arquivo100000("100000-arq2.txt", vetor100000insert_Arq2); le_arquivo100000("100000-arq3.txt", vetor100000insert_Arq3); le_arquivo100000("100000-arq4.txt", vetor100000insert_Arq4); le_arquivo100000("100000-arq5.txt", vetor100000insert_Arq5);le_arquivo100000("100000-arq1.txt", vetor100000sel_Arq1); le_arquivo100000("100000-arq2.txt", vetor100000sel_Arq2); le_arquivo100000("100000-arq3.txt", vetor100000sel_Arq3); le_arquivo100000("100000-arq4.txt", vetor100000sel_Arq4); le_arquivo100000("100000-arq5.txt", vetor100000sel_Arq5);le_arquivo100000("100000-arq1.txt", vetor100000shell_Arq1); le_arquivo100000("100000-arq2.txt", vetor100000shell_Arq2); le_arquivo100000("100000-arq3.txt", vetor100000shell_Arq3); le_arquivo100000("100000-arq4.txt", vetor100000shell_Arq4); le_arquivo100000("100000-arq5.txt", vetor100000shell_Arq5); le_arquivo100000("100000-arq1.txt", vetor100000merge_Arq1); le_arquivo100000("100000-arq2.txt", vetor100000merge_Arq2); le_arquivo100000("100000-arq3.txt", vetor100000merge_Arq3); le_arquivo100000("100000-arq4.txt", vetor100000merge_Arq4); le_arquivo100000("100000-arq5.txt", vetor100000merge_Arq5);le_arquivo100000("100000-arq1.txt", vetor100000quick_Arq1); le_arquivo100000("100000-arq2.txt", vetor100000quick_Arq2); le_arquivo100000("100000-arq3.txt", vetor100000quick_Arq3); le_arquivo100000("100000-arq4.txt", vetor100000quick_Arq4); le_arquivo100000("100000-arq5.txt", vetor100000quick_Arq5);  

    float result1 = ordena_bub(vetor1000bub_Arq1, 1000);
    printf("Tempo Bubble Sort Arq1{1000}: %.5f\n", result1);

    float result2 = ordena_bub(vetor1000bub_Arq2, 1000);
    printf("Tempo Bubble Sort Arq2{1000}: %.5f\n", result2);

    float result3 = ordena_bub(vetor1000bub_Arq3, 1000);
    printf("Tempo Bubble Sort Arq3{1000}: %.5f\n", result3);

    float result4 = ordena_bub(vetor1000bub_Arq4, 1000);
    printf("Tempo Bubble Sort Arq4{1000}: %.5f\n", result4);

    float result5 = ordena_bub(vetor1000bub_Arq5, 1000);
    printf("Tempo Bubble Sort Arq5{1000}: %.5f\n", result5);


    float result6 = ordena_insert(vetor1000insert_Arq1, 1000);
    printf("Tempo Insert Sort Arq1{1000}: %.5f\n", result6);

    float result7 = ordena_insert(vetor1000insert_Arq2, 1000);
    printf("Tempo Insert Sort Arq2{1000}: %.5f\n", result7);

    float result8 = ordena_insert(vetor1000insert_Arq3, 1000);
    printf("Tempo Insert Sort Arq3{1000}: %.5f\n", result8);

    float result9 = ordena_insert(vetor1000insert_Arq4, 1000);
    printf("Tempo Insert Sort Arq4{1000}: %.5f\n", result9);

    float result10 = ordena_insert(vetor1000insert_Arq5, 1000);
    printf("Tempo Insert Sort Arq5{1000}: %.5f\n", result10);

    float result11 = ordena_selection(vetor1000sel_Arq1, 1000);
    printf("Tempo Selection Sort Arq1{1000}: %.5f\n", result11);

    float result12 = ordena_selection(vetor1000sel_Arq2, 1000);
    printf("Tempo Selection Sort Arq2{1000}: %.5f\n", result12);

    float result13 = ordena_selection(vetor1000sel_Arq3, 1000);
    printf("Tempo Selection Sort Arq3{1000}: %.5f\n", result13);

    float result14 = ordena_selection(vetor1000sel_Arq4, 1000);
    printf("Tempo Selection Sort Arq4{1000}: %.5f\n", result14);

    float result15 = ordena_selection(vetor1000sel_Arq5, 1000);
    printf("Tempo Selection Sort Arq5{1000}: %.5f\n", result15);

    float result16 = ordena_shell(vetor1000shell_Arq1, 1000);
    printf("Tempo Shell Sort Arq1{1000}: %.5f\n", result16);

    float result17 = ordena_shell(vetor1000shell_Arq2, 1000);
    printf("Tempo Shell Sort Arq2{1000}: %.5f\n", result17);

    float result18 = ordena_shell(vetor1000shell_Arq3, 1000);
    printf("Tempo Shell Sort Arq3{1000}: %.5f\n", result18);

    float result19 = ordena_shell(vetor1000shell_Arq4, 1000);
    printf("Tempo Shell Sort Arq4{1000}: %.5f\n", result19);

    float result20 = ordena_shell(vetor1000shell_Arq5, 1000);
    printf("Tempo Shell Sort Arq5{1000}: %.5f\n", result20);

    float result21 = ordena_merge(vetor1000merge_Arq1, 1000);
    printf("Tempo Merge Sort Arq1{1000}: %.5f\n", result21);

    float result22 = ordena_merge(vetor1000merge_Arq2, 1000);
    printf("Tempo Merge Sort Arq2{1000}: %.5f\n", result22);

    float result23 = ordena_merge(vetor1000merge_Arq3, 1000);
    printf("Tempo Merge Sort Arq3{1000}: %.5f\n", result23);

    float result24 = ordena_merge(vetor1000merge_Arq4, 1000);
    printf("Tempo Merge Sort Arq4{1000}: %.5f\n", result24);

    float result25 = ordena_merge(vetor1000merge_Arq5, 1000);
    printf("Tempo Merge Sort Arq5{1000}: %.5f\n", result25);

    float result26 = ordena_quick(vetor1000quick_Arq1, 1000);
    printf("Tempo Quick Sort Arq1{1000}: %.5f\n", result26);

    float result27 = ordena_quick(vetor1000quick_Arq2, 1000);
    printf("Tempo Quick Sort Arq2{1000}: %.5f\n", result27);

    float result28 = ordena_quick(vetor1000quick_Arq3, 1000);
    printf("Tempo Quick Sort Arq3{1000}: %.5f\n", result28);

    float result29 = ordena_quick(vetor1000quick_Arq4, 1000);
    printf("Tempo Quick Sort Arq4{1000}: %.5f\n", result29);

    float result30 = ordena_quick(vetor1000quick_Arq5, 1000);
    printf("Tempo Quick Sort Arq5{1000}: %.5f\n", result30);

    float result31 = ordena_bub(vetor10000bub_Arq1, 10000);
    printf("Tempo Bubble Sort Arq1{10000}: %.5f\n", result31);

    float result32 = ordena_bub(vetor10000bub_Arq2, 10000);
    printf("Tempo Bubble Sort Arq2{10000}: %.5f\n", result32);

    float result33 = ordena_bub(vetor10000bub_Arq3, 10000);
    printf("Tempo Bubble Sort Arq3{10000}: %.5f\n", result33);

    float result34 = ordena_bub(vetor10000bub_Arq4, 10000);
    printf("Tempo Bubble Sort Arq4{10000}: %.5f\n", result34);

    float result35 = ordena_bub(vetor10000bub_Arq5, 10000);
    printf("Tempo Bubble Sort Arq5{10000}: %.5f\n", result35);


    float result36 = ordena_insert(vetor10000insert_Arq1, 10000);
    printf("Tempo Insert Sort Arq1{10000}: %.5f\n", result36);

    float result37 = ordena_insert(vetor10000insert_Arq2, 10000);
    printf("Tempo Insert Sort Arq2{10000}: %.5f\n", result37);

    float result38 = ordena_insert(vetor10000insert_Arq3, 10000);
    printf("Tempo Insert Sort Arq3{10000}: %.5f\n", result38);

    float result39 = ordena_insert(vetor10000insert_Arq4, 10000);
    printf("Tempo Insert Sort Arq4{10000}: %.5f\n", result39);

    float result40 = ordena_insert(vetor10000insert_Arq5, 10000);
    printf("Tempo Insert Sort Arq5{10000}: %.5f\n", result40);

    float result41 = ordena_selection(vetor10000sel_Arq1, 10000);
    printf("Tempo Selection Sort Arq1{10000}: %.5f\n", result41);

    float result42 = ordena_selection(vetor10000sel_Arq2, 10000);
    printf("Tempo Selection Sort Arq2{10000}: %.5f\n", result42);

    float result43 = ordena_selection(vetor10000sel_Arq3, 10000);
    printf("Tempo Selection Sort Arq3{10000}: %.5f\n", result43);

    float result44 = ordena_selection(vetor10000sel_Arq4, 10000);
    printf("Tempo Selection Sort Arq4{10000}: %.5f\n", result44);

    float result45 = ordena_selection(vetor10000sel_Arq5, 10000);
    printf("Tempo Selection Sort Arq5{10000}: %.5f\n", result45);

    float result46 = ordena_shell(vetor10000shell_Arq1, 10000);
    printf("Tempo Shell Sort Arq1{10000}: %.5f\n", result46);

    float result47 = ordena_shell(vetor10000shell_Arq2, 10000);
    printf("Tempo Shell Sort Arq2{10000}: %.5f\n", result47);

    float result48 = ordena_shell(vetor10000shell_Arq3, 10000);
    printf("Tempo Shell Sort Arq3{10000}: %.5f\n", result48);

    float result49 = ordena_shell(vetor10000shell_Arq4, 10000);
    printf("Tempo Shell Sort Arq4{10000}: %.5f\n", result49);

    float result50 = ordena_shell(vetor10000shell_Arq5, 10000);
    printf("Tempo Shell Sort Arq5{10000}: %.5f\n", result50);

    float result51 = ordena_merge(vetor10000merge_Arq1, 10000);
    printf("Tempo Merge Sort Arq1{10000}: %.5f\n", result51);

    float result52 = ordena_merge(vetor10000merge_Arq2, 10000);
    printf("Tempo Merge Sort Arq2{10000}: %.5f\n", result52);

    float result53 = ordena_merge(vetor10000merge_Arq3, 10000);
    printf("Tempo Merge Sort Arq3{10000}: %.5f\n", result53);

    float result54 = ordena_merge(vetor10000merge_Arq4, 10000);
    printf("Tempo Merge Sort Arq4{10000}: %.5f\n", result54);

    float result55 = ordena_merge(vetor10000merge_Arq5, 10000);
    printf("Tempo Merge Sort Arq5{10000}: %.5f\n", result55);

    float result56 = ordena_quick(vetor10000quick_Arq1, 10000);
    printf("Tempo Quick Sort Arq1{10000}: %.5f\n", result56);

    float result57 = ordena_quick(vetor10000quick_Arq2, 10000);
    printf("Tempo Quick Sort Arq2{10000}: %.5f\n", result57);

    float result58 = ordena_quick(vetor10000quick_Arq3, 10000);
    printf("Tempo Quick Sort Arq3{10000}: %.5f\n", result58);

    float result59 = ordena_quick(vetor10000quick_Arq4, 10000);
    printf("Tempo Quick Sort Arq4{10000}: %.5f\n", result59);

    float result60 = ordena_quick(vetor10000quick_Arq5, 10000);
    printf("Tempo Quick Sort Arq5{10000}: %.5f\n", result60);


    float result61 = ordena_bub(vetor100000bub_Arq1, 100000);
    printf("Tempo Bubble Sort Arq1{100000}: %.5f\n", result61);

    float result62 = ordena_bub(vetor100000bub_Arq2, 100000);
    printf("Tempo Bubble Sort Arq2{100000}: %.5f\n", result62);

    float result63 = ordena_bub(vetor100000bub_Arq3, 100000);
    printf("Tempo Bubble Sort Arq3{100000}: %.5f\n", result63);

    float result64 = ordena_bub(vetor100000bub_Arq4, 100000);
    printf("Tempo Bubble Sort Arq4{100000}: %.5f\n", result64);

    float result65 = ordena_bub(vetor100000bub_Arq5, 100000);
    printf("Tempo Bubble Sort Arq5{100000}: %.5f\n", result65);


    float result66 = ordena_insert(vetor100000insert_Arq1, 100000);
    printf("Tempo Insert Sort Arq1{100000}: %.5f\n", result66);

    float result67 = ordena_insert(vetor100000insert_Arq2, 100000);
    printf("Tempo Insert Sort Arq2{100000}: %.5f\n", result67);

    float result68 = ordena_insert(vetor100000insert_Arq3, 100000);
    printf("Tempo Insert Sort Arq3{100000}: %.5f\n", result68);

    float result69 = ordena_insert(vetor100000insert_Arq4, 100000);
    printf("Tempo Insert Sort Arq4{100000}: %.5f\n", result69);

    float result70 = ordena_insert(vetor100000insert_Arq5, 100000);
    printf("Tempo Insert Sort Arq5{100000}: %.5f\n", result70);

    float result71 = ordena_selection(vetor100000sel_Arq1, 100000);
    printf("Tempo Selection Sort Arq1{100000}: %.5f\n", result71);

    float result72 = ordena_selection(vetor100000sel_Arq2, 100000);
    printf("Tempo Selection Sort Arq2{100000}: %.5f\n", result72);

    float result73 = ordena_selection(vetor100000sel_Arq3, 100000);
    printf("Tempo Selection Sort Arq3{100000}: %.5f\n", result73);

    float result74 = ordena_selection(vetor100000sel_Arq4, 100000);
    printf("Tempo Selection Sort Arq4{100000}: %.5f\n", result74);

    float result75 = ordena_selection(vetor100000sel_Arq5, 100000);
    printf("Tempo Selection Sort Arq5{100000}: %.5f\n", result75);

    float result76 = ordena_shell(vetor100000shell_Arq1, 100000);
    printf("Tempo Shell Sort Arq1{100000}: %.5f\n", result76);

    float result77 = ordena_shell(vetor100000shell_Arq2, 100000);
    printf("Tempo Shell Sort Arq2{100000}: %.5f\n", result77);

    float result78 = ordena_shell(vetor100000shell_Arq3, 100000);
    printf("Tempo Shell Sort Arq3{100000}: %.5f\n", result78);

    float result79 = ordena_shell(vetor100000shell_Arq4, 100000);
    printf("Tempo Shell Sort Arq4{100000}: %.5f\n", result79);

    float result80 = ordena_shell(vetor100000shell_Arq5, 100000);
    printf("Tempo Shell Sort Arq5{100000}: %.5f\n", result80);

    float result81 = ordena_merge(vetor100000merge_Arq1, 100000);
    printf("Tempo Merge Sort Arq1{100000}: %.5f\n", result81);

    float result82 = ordena_merge(vetor100000merge_Arq2, 100000);
    printf("Tempo Merge Sort Arq2{100000}: %.5f\n", result82);

    float result83 = ordena_merge(vetor100000merge_Arq3, 100000);
    printf("Tempo Merge Sort Arq3{100000}: %.5f\n", result83);

    float result84 = ordena_merge(vetor100000merge_Arq4, 100000);
    printf("Tempo Merge Sort Arq4{100000}: %.5f\n", result84);

    float result85 = ordena_merge(vetor100000merge_Arq5, 100000);
    printf("Tempo Merge Sort Arq5{100000}: %.5f\n", result85);

    float result86 = ordena_quick(vetor100000quick_Arq1, 100000);
    printf("Tempo Quick Sort Arq1{100000}: %.5f\n", result86);

    float result87 = ordena_quick(vetor100000quick_Arq2, 100000);
    printf("Tempo Quick Sort Arq2{100000}: %.5f\n", result87);

    float result88 = ordena_quick(vetor100000quick_Arq3, 100000);
    printf("Tempo Quick Sort Arq3{100000}: %.5f\n", result88);

    float result89 = ordena_quick(vetor100000quick_Arq4, 100000);
    printf("Tempo Quick Sort Arq4{100000}: %.5f\n", result89);

    float result90 = ordena_quick(vetor100000quick_Arq5, 100000);
    printf("Tempo Quick Sort Arq5{100000}: %.5f\n", result90);

    return 1;
}