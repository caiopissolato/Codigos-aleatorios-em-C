//Função que cria árvore vazia
struct arv_bin* cria_arvore_vazia();

//Função que cria árvore passando elementos como parâmetro
struct arv_bin* cria_arvore(int i, struct arv_bin* sae, struct arv_bin* sad);
void insere_arv_bin_par_impar(struct arv_bin **a, int i);
void imprime_arv(struct arv_bin* arv);
struct arv_bin* cria_arvore_raiz(int i);
void insere_arv_bin(struct arv_bin **a, int i);
int arv_vazia(struct arv_bin * arv);
int arv_busca(struct arv_bin* arv, int i);
void imprime_pos_ordem_arv(struct arv_bin* arv);
void imprime_ordem_arv(struct arv_bin* arv);
void imprime_pre_ordem_arv(struct arv_bin* arv);
void imprime_arvore_bin(struct arv_bin* arv);
int conta_noh(struct arv_bin* arv);
int altura_arv_bin(struct arv_bin* arv);
int conta_folhas(struct arv_bin* arv);
int retorna_valor_maior(struct arv_bin* arv, int valor);
/*
struct arv_bin* busca_no(struct arv_bin* arv, int i, struct arv_bin* *pai);
struct arv_bin* remove_no(struct arv_bin* arv, int i);
*/