#ifndef ARVOREARITEXP_H_INCLUDED
#define ARVOREARITEXP_H_INCLUDED
typedef struct No{
    char valor; 
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct{
	No* raiz;
} ARVORE;

void inicializarArvore(ARVORE* arvore);
No* adicionarArvore(No* raiz, char valor);
No* pre_ordem(No* raiz);
No* in_ordem(No* raiz);
No* pos_ordem(No* raiz);

#endif
