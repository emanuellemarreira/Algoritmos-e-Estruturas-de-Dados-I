#include <stdio.h>
#include <stdlib.h>
#include "llest3ok.h"

void inicializar(Lista *lista) {
    lista->inicio = -1;
    lista->livre = 0;
}

int obterNoLivre(Lista *lista) {
    int indice = lista->livre;
    lista->livre++;
    return indice;
}

void inserirFim(Lista *lista, int valor) {
    int novoIndice = obterNoLivre(lista);
    No *novo = &(lista->elementos[novoIndice]);
    novo->valor = valor;
    novo->proximo = -1;

    if (lista->inicio == -1) {
        lista->inicio = novoIndice;
    } else {
        No *ultimo = &(lista->elementos[lista->inicio]);
        while (ultimo->proximo != -1) {
            ultimo = &(lista->elementos[ultimo->proximo]);
        }
        ultimo->proximo = novoIndice;
    }
}

void remover(Lista *lista, int valor) {
    int atualIndice = lista->inicio;
    int anteriorIndice = -1;

    while (atualIndice != -1) {
        No *atual = &(lista->elementos[atualIndice]);

        if (atual->valor == valor) {
            if (anteriorIndice == -1) {
                lista->inicio = atual->proximo;
            } else {
                No *anterior = &(lista->elementos[anteriorIndice]);
                anterior->proximo = atual->proximo;
            }
            break;
        }

        anteriorIndice = atualIndice;
        atualIndice = atual->proximo;
    }
}

void imprimir(Lista *lista) {
    int indice = lista->inicio;
    while (indice != -1) {
        No *atual = &(lista->elementos[indice]);
        printf("\nlista = %d", atual->valor);
        indice = atual->proximo;
    }
}

void copiarLista(Lista *l1, Lista *l2){
	int indice = l1->inicio;
	while(indice != -1){
		No *atual = &(l1->elementos[indice]);
		inserirFim(l2, l1->elementos[indice].valor);
		indice = atual->proximo;
	}
}
void concatenarLista(Lista *l1, Lista *l2){
	int indice = l2->inicio;
	while(indice != -1){
		No *atual = &(l2->elementos[indice]);
		inserirFim(l1, l2->elementos[indice].valor);
		indice = atual->proximo;
	}
}
Lista intercalarListas(Lista *l1, Lista *l2)
{
    Lista listaIntercalada;
    inicializar(&listaIntercalada);

    int atualL1 = l1->inicio;
    int atualL2 = l2->inicio;

    while (atualL1 != -1 && atualL2 != -1)
    {
        inserirFim(&listaIntercalada, l1->elementos[atualL1].valor);
        inserirFim(&listaIntercalada, l2->elementos[atualL2].valor);

        atualL1 = l1->elementos[atualL1].proximo;
        atualL2 = l2->elementos[atualL2].proximo;
    }

    return listaIntercalada;
}
