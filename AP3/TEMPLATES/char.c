#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
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
    if (no->valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, no);
    } else if (no->valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, no);
    } else {
        return raiz; // Avoid adding duplicate values
    }
    return raiz;
}

void adiciona(ARVORE* a, No* no) {
    a->raiz = inserirNo(a->raiz, no);
}

No* criarNo(char valor) {
    No* novoNo = malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->valor = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

void adicionarArvore(ARVORE* a, char valor) {
    No* novono = criarNo(valor);
    if (novono != NULL) {
        adiciona(a, novono);
    } else {
        printf("Failed to add node with value %c due to memory allocation failure.\n", valor);
    }
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
        printf("%c ", noAtual->valor);

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
    adicionarArvore(&a, 'j');
    adicionarArvore(&a, 'k');
    adicionarArvore(&a, 'l');
    adicionarArvore(&a, 'b');
    adicionarArvore(&a, 'a');
    
    percorrerLargura(&a);
    
    return 0;
}

