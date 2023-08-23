#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor[30];
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} ARVORE;

void inicializarArvore(ARVORE* a) {
    a->raiz = NULL;
}

No* inserirNo(No* raiz, No* no) {
    if (raiz == NULL) {
        return no;
    }
    if (strcmp(no->valor, raiz->valor) < 0) {
        raiz->esquerda = inserirNo(raiz->esquerda, no);
    } else if (strcmp(no->valor, raiz->valor) > 0) {
        raiz->direita = inserirNo(raiz->direita, no);
    } else {
        return raiz; // Avoid adding duplicate values
    }
    return raiz;
}

void adiciona(ARVORE* a, No* no) {
    a->raiz = inserirNo(a->raiz, no);
}

void adicionarArvore(ARVORE* a, char* palavra) {
    No* novono = malloc(sizeof(No));
    strcpy(novono->valor, palavra);
    novono->esquerda = NULL;
    novono->direita = NULL;
    adiciona(a, novono);
}

void percorrerLargura(ARVORE* a) {
    if (a->raiz == NULL) {
        return;
    }

    No* fila[100];
    int inicio = 0;
    int fim = 0;
    fila[fim++] = a->raiz;

    while (inicio != fim) {
        No* noAtual = fila[inicio++];
        printf("%s ", noAtual->valor);

        if (noAtual->esquerda != NULL) {
            fila[fim++] = noAtual->esquerda;
        }

        if (noAtual->direita != NULL) {
            fila[fim++] = noAtual->direita;
        }
    }
}

int main(){
    ARVORE a;
    inicializarArvore(&a);
    //printf("%d %d %d", 'a', 'b', 'c');
    adicionarArvore(&a, "j");
    adicionarArvore(&a, "k");
    adicionarArvore(&a, "l");
    adicionarArvore(&a, "b");
    adicionarArvore(&a, "a");
    
    percorrerLargura(&a);
    
    return 0;
}

