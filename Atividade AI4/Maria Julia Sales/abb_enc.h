#ifndef ABB_ENC_H    // INCLUDE GUARD
#define ABB_ENC_H

// INTERFACE DA ARVORE BINÁRIA DE BUSCA (ABB) ENCADEADA DE INTEIROS

typedef struct no no;
typedef struct arv arvore;

int adicionar_no_arv(arvore* a, int valor);
arvore* criar_arv(int valor_raiz);
no* criar_no(int valor);
no* get_raiz_arv(arvore* a);
no* sae_arv(no* n);
no* sad_arv(no* n);

int quantidade(no *n);

#endif // ARVORE_ENC_H