#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct No{
	int valor;
	int h;
	struct No* esquerda;
	struct No* direita;
}No;

typedef struct{
	No* raiz;
}ARVORE;

void inicializarArvore(ARVORE* a);
int maximo(int v1, int v2);
int altura(No* raiz);
No* rot_direita(No* no_desb);
No* rot_esquerda(No* no_desb);
No* rot_esq_direita(No* no_desb);
No* rot_dir_esquerda(No* no_desb);
No* inserirAVL(No* raiz, No* no);
void adicionaAVL(ARVORE* a, int valor);
No* in_ordem(No* raiz);



#endif
