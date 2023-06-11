#ifndef LISTADIN_H_INCLUDED
#define LISTADIN_H_INCLUDED
typedef struct No{
	int valor;
	struct No *proximo;
}No;

typedef struct {
	No *inicio, *fim;
}Lista;

void inicializarLista(Lista *l);
int qtdElemValidos(Lista *l);
void imprimir(Lista *lista);
No *buscaElemEPred(Lista *m, int valor, No** pred);
int inserir(Lista *m, int valor);//de forma ordenada
int excluir(Lista* m, int valor);
void reinicializar(Lista* m);

#endif
