#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* anterior;
    struct No* proximo;
}No;
typedef struct{
    No* inicio;
}Lista;

void inicializaLista(Lista* m) {
    m->inicio = NULL;
}

void imprimirLista(Lista* m) {
    No* i = m->inicio;
    printf("\nlista: ");
    while (i != NULL) {
        printf("%d ", i->valor);
        i = i->proximo;
    }
}

int tamanho(Lista* m) {
    int tam = 0;
    No* i = m->inicio;
    while (i != NULL) {
        tam++;
        i = i->proximo;
    }
    return tam;
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

int inserir(Lista* m, int novo) {
    No* pred;
    No* i;
    i = buscaElem_e_Pred(m, novo, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(No));
    i->valor = novo;
    if(pred == NULL){//inserir no inicio
        i->proximo = m->inicio;
        i->anterior = NULL;
        m->inicio = i;
    } else if(pred->proximo == NULL){//inserir no final
        i->proximo = pred->proximo;
        i->anterior = pred;
        pred->proximo = i;
    }else{
        i->proximo = pred->proximo;
        i->anterior = pred;
        pred->proximo->anterior = i;
        pred->proximo = i;
    }
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
    No* elem = m->inicio;
    while (elem != NULL) {
        apagar = elem;
        elem = elem->proximo;
        free(apagar);
    }
    m->inicio = NULL;
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

