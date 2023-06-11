#ifndef LDIN2_H_INCLUDED
#define LDIN2_H_INCLUDED
#define TAM 10
typedef struct No{
	int valor;
	struct No *proximo;
}No;

typedef struct {
	No *inicio, *fim;//ponteiro do fim é opcional
}Lista;
void inserirFim(Lista *lista, int valor);
void remover(Lista *lista, int valor);
void imprimir(Lista *lista);
void a(Lista *l, Lista *l1);
void b(Lista *l, Lista *l1);
#endif

