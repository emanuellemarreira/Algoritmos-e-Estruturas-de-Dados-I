#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* cabeca;
} Lista;

void inicializaLista(Lista* m) {
    No* cabeca = malloc(sizeof(No));
    cabeca->proximo = cabeca;
    m->cabeca = cabeca;
}

void imprimirLista(Lista* m) {
    No* i = m->cabeca->proximo;
    printf("\nlista: ");
    while (i != m->cabeca) {
        printf("%d ", i->valor);
        i = i->proximo;
    }
}

int tamanho(Lista* m) {
    int tam = 0;
    No* i = m->cabeca->proximo;
    while (i != m->cabeca) {
        tam++;
        i = i->proximo;
    }
    return tam;
}

No* buscaElem_e_Pred(Lista* m, int valor, No** pred) {
    *pred = m->cabeca;
    No* atual = m->cabeca->proximo;
    m->cabeca->valor = valor;
    while (atual->valor < valor) {
        *pred = atual;
        atual = atual->proximo;
    }
    if ((atual != m->cabeca) && (atual->valor == valor)) {
        return atual;
    }
    return NULL;
}

int inserir(Lista* m, int novo) {
    No* pred;
    No* i;
    i = buscaElem_e_Pred(m, novo, &pred);
    if (i != NULL) {
        return 0;
    }
    i = malloc(sizeof(No));
    i->valor = novo;
    i->proximo = pred->proximo;
    pred->proximo = i;
    return 1;
}

int excluir(Lista* m, int valor) {
    No* pred;
    No* i;
    i = buscaElem_e_Pred(m, valor, &pred);
    if (i == NULL) {
        return 0;
    }
    pred->proximo = i->proximo;
    free(i);
    return 1;
}

void reinicializar(Lista* m) {
    No* apagar;
    No* elem = m->cabeca->proximo;
    while (elem != m->cabeca) {
        apagar = elem;
        elem = elem->proximo;
        free(apagar);
    }
    m->cabeca->proximo = m->cabeca;
}

int main() {
    Lista l;
    inicializaLista(&l);
    printf("Tamanho: %d\n", tamanho(&l));
    inserir(&l, 0);
    inserir(&l, 1);
    inserir(&l, 2);
    imprimirLista(&l);
    excluir(&l, 1);
    printf("\ndepois de excluir\n");
    imprimirLista(&l);
    reinicializar(&l);
    printf("\ndepois de reinicializar\n");
    imprimirLista(&l);
    return 0;
}

