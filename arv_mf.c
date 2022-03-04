void insere_arv_mf(tipo_arv_mf **arv, int valor){
    int i;
    if(*arv == NULL){
        (*arv) = aloca_no(valor);
    }else
     if((*arv)->qtd_dados < T){
        i = (*arv)->qtd_dados;
        while((i > 0) && ((*arv)->dados[i-1] > valor)){
            (*arv)->dados[i] = (*arv)->dados[i-1];
            i--;
        }
        (*arv)->dados[i] = valor;
        (*arv)->qtd_dados++;
    }else
     if((*arv)->qtd_dados == T){

     }
    
    
}

void impressao_posordem_mf(tipo_arv_mf *arv){
    if(arv != NULL){
        int i;
        for(i = 0; i < T+1; i++){
            if(arv->filhos[i] != NULL)
                impressao_posordem_mf(arv->filhos[i]);
        }
        printf("[");
        for(i = 0; i<arv->qtd_dados; i++){
            printf("%d,", arv->dados[i]);
        }
        printf("[qtd=%d\n", arv->qtd_dados);
    }
}

void impressao_preordem(tipo_arv_mf *arv){
    if(arv != NULL){
        int i;
        printf("[");
        for(i = 0; i < arv->qtd_dados; i++)
            printf("%d,", arv->dados[i]);
        printf("")    
    }
}

void impressao_ordem_mf(tipo_arv_mf){
    if(arv != NULL){
        int i;
        for(i = 0; i < arv->qtd_dados; i++){
            impressao_ordem_mf(arv->filhos[i]);
            printf("[%d]", arv->dados[i]);
        }
        impressao_ordem_mf(arv->filhos[i]);
    }
}

int qtd_dados_mf(tipo_arv_mf *arv){
    if(arv == NULL){
        return 0;
    }else{
        int i, qtd;
        qtd = arv->qtd_dados;
        for(i = 0; i<T+1; i++){
            qtd += qtd_dados_mf(arv->filhos[i]);
        }
        return qtd;
    }
}

int qtd_dados_nos(tipo_arv_mf *arv){
    if(arv == NULL){
        return 0;
    }else{
        int i, qtd;
        qtd = 1;
        for(i = 0; i<T+1; i++){
            qtd += qtd_dados_nos(arv->filhos[i]);
        }
        return qtd;
    }
}