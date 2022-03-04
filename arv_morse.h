typedef struct arv Arv;

Arv* inicializa_arv_bin();
Arv* cria_arv_bin(Arv* arv, char simbolo, char letra);
Arv* insere_arv_bin(Arv* arv, char simbolo, char letra);
void imprime_arv_bin(Arv* arv);