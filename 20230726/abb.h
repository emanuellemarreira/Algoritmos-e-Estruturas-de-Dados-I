#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct No{
    int valor;
    struct No* esquerda;
    struct No* direita;
}No;

typedef struct{
	No* raiz;
}ARVORE;

void inicializarArvore(ARVORE *a);
No* inserirNo(No* raiz, No* no);
void adiciona(ARVORE *a, No* no);
void adicionarArvore(ARVORE *a, int valor);
void listarNos(No* raiz);
void imprimirArvore(ARVORE *a);
No* buscarNo(No* raiz, int valor);
No* buscar(ARVORE *a, int valor);
int contarNos(No* raiz);
No* pre_ordem(No* raiz);
No* in_ordem(No* raiz);
No* pos_ordem(No* raiz);

#endif
