#ifndef POLINOMIOS_H_INCLUDED
#define POLINOMIOS_H_INCLUDED
typedef struct No{
	int coeficiente;
	int expoente;
	struct No *proximo;
}No;

typedef struct {
	No *inicio;
}Lista;

void inicializarLista(Lista *l);
No *buscaElemEPred(Lista *m, int expt, No** pred);
int inserir(Lista *m, int expt, int coef);
void imprimir(Lista *lista);
Lista* somapolinomio(Lista* p1, Lista* p2);

#endif
