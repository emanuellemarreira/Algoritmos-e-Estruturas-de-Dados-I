#include <stdio.h>
#include <stdlib.h>
#include "arvorearitexp"
void inicializarArvore(ARVORE* arvore) {
    arvore->raiz = NULL;
}

No* adicionarArvore(No* raiz, char valor) {
    if (raiz == NULL) {
        raiz = (No*)malloc(sizeof(No));
        raiz->valor = valor;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
    } else if (valor < raiz->valor) {
        raiz->esquerda = adicionarArvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = adicionarArvore(raiz->direita, valor);
    }
    return raiz;
}

No* pre_ordem(No* raiz) {
	if (raiz == NULL) {
		return NULL;
	}
	printf("%c", raiz->valor);
	pre_ordem(raiz->esquerda);
	pre_ordem(raiz->direita);
}

No* in_ordem(No* raiz) {
	if (raiz == NULL) {
		return NULL;
	}
	in_ordem(raiz->esquerda);
	printf("%c", raiz->valor);
	in_ordem(raiz->direita);
}

No* pos_ordem(No* raiz) {
	if (raiz == NULL) {
		return NULL;
	}
	pos_ordem(raiz->esquerda);
	pos_ordem(raiz->direita);
	printf("%c", raiz->valor);
}

