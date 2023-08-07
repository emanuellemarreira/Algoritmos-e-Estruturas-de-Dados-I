#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void inicializarArvore(ARVORE* a) {
    a->raiz = NULL;
}

int maximo(int v1, int v2) {
    if (v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

int altura(No* raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        return raiz->h;
    }
}

No* rot_direita(No* no_desb) {
    No* aux;
    aux = no_desb->esquerda;
    no_desb->esquerda = aux->direita;
    aux->direita = no_desb;

    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda)) + 1;
    aux->h = maximo(altura(aux->esquerda), altura(no_desb)) + 1;
    return aux;
}

No* rot_esquerda(No* no_desb) {
    No* aux;
    aux = no_desb->direita;
    no_desb->direita = aux->esquerda;
    aux->esquerda = no_desb;
    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda)) + 1;
    aux->h = maximo(altura(aux->direita), altura(no_desb)) + 1;
    return aux;
}

No* rot_esq_direita(No* no_desb) {
    no_desb->esquerda = rot_esquerda(no_desb->esquerda);
    return rot_direita(no_desb);
}

No* rot_dir_esquerda(No* no_desb) {
    no_desb->direita = rot_direita(no_desb->direita);
    return rot_esquerda(no_desb);
}

No* inserirAVL(No* raiz, No* no) {
    if (raiz == NULL) {  //condicao de parada
        return no;
    }
    if (raiz->valor > no->valor) {
        raiz->esquerda = inserirAVL(raiz->esquerda, no);
        if ((altura(raiz->direita) - altura(raiz->esquerda)) == 2) {
            if (no->valor < raiz->esquerda->valor) {
                raiz = rot_direita(raiz);
            } else {
                raiz = rot_esq_direita(raiz);
            }
        }
    } else {
        if (raiz->valor < no->valor) {
            raiz->direita = inserirAVL(raiz->direita, no);
            if ((altura(raiz->direita) - altura(raiz->esquerda)) == 2) {
                if (no->valor > raiz->direita->valor) {
                    raiz = rot_esquerda(raiz);
                } else {
                    raiz = rot_dir_esquerda(raiz);
                }
            }
        }
    }
    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita)) + 1;
    return raiz;
}

void adicionaAVL(ARVORE* a, int valor) {
    No* novono = malloc(sizeof(No));
    novono->valor = valor;
    novono->h = 0;
    novono->esquerda = NULL;
    novono->direita = NULL;
    a->raiz = inserirAVL(a->raiz, novono);
}

No* in_ordem(No* raiz) {  // esquerda  raiz   direita
    if (raiz == NULL) {
        return NULL;
    }
    in_ordem(raiz->esquerda);
    printf("%d\n", raiz->valor);
    in_ordem(raiz->direita);
    return NULL; // Adicione um retorno para tratar o caso base.
}
