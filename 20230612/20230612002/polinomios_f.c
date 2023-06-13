#include <stdio.h>
#include <stdlib.h>
#include "polinomios.h"
void inicializarLista(Lista *l){
	l->inicio = NULL;
}
No *buscaElemEPred(Lista *m, int expt, No** pred){
	*pred = NULL;
	No* atual = m->inicio;
	while((atual != NULL)&&(atual->expoente > expt)){//troquei < por >
		*pred = atual;
		atual = atual->proximo;
	}
	if((atual != NULL)&&(atual->expoente == expt)){
		return atual;
	}
	return NULL;//nao encontrou
}
int inserir(Lista *m, int expt, int coef){//de forma ordenada
	No* pred;
	No* elem;
	elem = buscaElemEPred(m,expt,&pred);//verifica se ja existe
	if(elem != NULL){//se o valor ja existe
		return 0;
	}
	No *novono = malloc(sizeof(No));
	novono->expoente = expt;
	novono->coeficiente = coef;
	if(pred == NULL){//significa que  o valor sera o 1o da lista
		novono->proximo = m->inicio;
		m->inicio = novono;
	}else{
		novono->proximo = pred->proximo;
		pred->proximo = novono;
	}
	return 1;
}

void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
    while (inicio != NULL) {
        printf(" %dX^%d", inicio->coeficiente, inicio->expoente);
        if (inicio->proximo != NULL) {
            printf(" +");
        }
        inicio = inicio->proximo;
    }
}
Lista* somapolinomio(Lista* p1, Lista* p2) {
    Lista* soma = malloc(sizeof(Lista));
    inicializarLista(soma);
    No* inicio1 = p1->inicio;
    No* inicio2 = p2->inicio;

    while (inicio1 != NULL && inicio2 != NULL) {
        if (inicio1->expoente == inicio2->expoente) {
            inserir(soma, inicio1->expoente, inicio1->coeficiente + inicio2->coeficiente);
            inicio1 = inicio1->proximo;
            inicio2 = inicio2->proximo;
        } else if (inicio1->expoente > inicio2->expoente) {
            inserir(soma, inicio1->expoente, inicio1->coeficiente);
            inicio1 = inicio1->proximo;
        } else {
            inserir(soma, inicio2->expoente, inicio2->coeficiente);
            inicio2 = inicio2->proximo;
        }
    }

    while (inicio1 != NULL) {
        inserir(soma, inicio1->expoente, inicio1->coeficiente);
        inicio1 = inicio1->proximo;
    }

    while (inicio2 != NULL) {
        inserir(soma, inicio2->expoente, inicio2->coeficiente);
        inicio2 = inicio2->proximo;
    }

    return soma;
}


