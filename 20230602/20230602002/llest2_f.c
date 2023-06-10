#include <stdio.h>
#include <stdlib.h>
#include "llest2ok.h"

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
void inserirInicio(Lista *lista, int valor) {
    int novoIndice = obterNoLivre(lista);
    No *novo = &(lista->elementos[novoIndice]);
    novo->valor = valor;
    novo->proximo = lista->inicio;

    lista->inicio = novoIndice;
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

void a(Lista *l, Lista *l1) {
    if (l->inicio != -1) {
        int prim = l->inicio;
        int atual = l->elementos[prim].proximo;//recebe o segundo

        while (atual != -1) {
            inserirFim(l1, l->elementos[atual].valor);
            atual = l->elementos[atual].proximo;
        }

        inserirFim(l1, l->elementos[prim].valor);
    }
}

void b(Lista *l, Lista *l1) {
    int indice = l->inicio;
    Lista listaAuxiliar;
    inicializar(&listaAuxiliar);

    while (indice != -1) {
        No *atual = &(l->elementos[indice]);
        inserirFim(&listaAuxiliar, atual->valor);
        indice = atual->proximo;
    }

    indice = listaAuxiliar.inicio;
    while (indice != -1) {
        No *atual = &(listaAuxiliar.elementos[indice]);
        inserirInicio(l1, atual->valor); 
        indice = atual->proximo;
    }
}
