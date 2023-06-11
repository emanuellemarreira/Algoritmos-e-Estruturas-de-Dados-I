#ifndef LDIN3_H_INCLUDED
#define LDIN3_H_INCLUDED
typedef struct No{
	int valor;
	struct No *proximo;
}No;

typedef struct {
	No *inicio, *fim;//ponteiro do fim é opcional
}Lista;

void inserirFim(Lista *lista, int valor);
void copiarlista(Lista *l, Lista *l1);
void concatenar(Lista *l, Lista *l1);
void intercalar(Lista *l, Lista *l1, Lista *l2);
void imprimir(Lista *lista);

#endif
