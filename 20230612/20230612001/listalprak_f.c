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

void remover_elemento(Lista* lista, No* no) {
    if (lista->inicio == no) {
        lista->inicio = no->proximo;
    }

    if (no->proximo != NULL) {
        no->proximo->anterior = no->anterior;
    }

    if (no->anterior != NULL) {
        no->anterior->proximo = no->proximo;
    }

    free(no);
}

void armazenar_maior_elemento(Lista* L, Lista* K) {
    int maior = buscar_maior_elemento(L);
    No* no = L->inicio;

    while (no != NULL) {
        if (no->valor == maior) {
            remover_elemento(L, no);
            inserir_elemento(K, maior);
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


