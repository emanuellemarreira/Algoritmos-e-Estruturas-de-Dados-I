#include <stdio.h>
#include <stdlib.h>
#include "listalprak.h"
void inicializar_lista(Lista* lista) {
    lista->inicio = NULL;
}

void inserir_elemento(Lista* lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = lista->inicio;
    novo_no->anterior = NULL;

    if (lista->inicio != NULL) {
        lista->inicio->anterior = novo_no;
    }

    lista->inicio = novo_no;
}

void inserir_emk(Lista* lista, No* inserir) {
    inserir->proximo = lista->inicio;
    lista->inicio = inserir;
    inserir->anterior = NULL;
}

int buscar_maior_elemento(Lista* lista) {
    No* no = lista->inicio;
    int maior = no->valor;

    while (no != NULL) {
        if (no->valor > maior) {
            maior = no->valor;
        }
        no = no->proximo;
    }

    return maior;
}

No* buscaElem_e_Pred(Lista* m, int valor, No** pred) {
    *pred = NULL;
    No* atual = m->inicio;
    while ((atual != NULL) && atual->valor < valor) {
        *pred = atual;
        atual = atual->proximo;
    }
    if ((atual != NULL) && (atual->valor == valor)) {
        return atual;
    }
    return NULL;
}

No* remover_elemento(Lista* lista, int valor) {
    No* pred;
    No* i;
    i = buscaElem_e_Pred(lista, valor, &pred);
    if (i == NULL) {
        return NULL;
    }
    if (pred != NULL) {
        pred->proximo = i->proximo;
    } else {
        lista->inicio = i->proximo;
    }
    return i;
}

void armazenar_maior_elemento(Lista* L, Lista* K) {
    No* no = L->inicio;
    No* armazenar = NULL;
    int maior = buscar_maior_elemento(L);

    while (no != NULL) {
        if (no->valor == maior) {
            armazenar = remover_elemento(L, maior);
            inserir_emk(K, armazenar);
            break;
        }
        no = no->proximo;
    }
}

void imprimir_lista(Lista* lista) {
    No* no = lista->inicio;
    while (no != NULL) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n");
}
