#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;//fim nao é mais necessario
} Lista;

void inicializarLista(Lista *l) {
    l->inicio = NULL;
}

int qtdElemValidos(Lista *l) {
    int tam = 0;
    No *inicio = l->inicio;
    
    if (inicio != NULL) {
        tam++;
        No *atual = inicio->proximo;
        while (atual != inicio) {//percorre ate achar o inicio de novo pois circular
            tam++;
            atual = atual->proximo;
        }
    }
    
    return tam;
}

void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
    
    if (inicio != NULL) {
        No *atual = inicio;
        do {
            printf("\nlista = %d", atual->valor);
            atual = atual->proximo;
        } while (atual != inicio);//percorre ate achar o inicio de novo pois circular
    }
}

No *buscaElemEPred(Lista *m, int valor, No **pred) {
    *pred = NULL;
    No *inicio = m->inicio;
    
    if (inicio != NULL) {
        No *atual = inicio;
        do {
            if (atual->valor == valor) {
                return atual;
            }
            *pred = atual;
            atual = atual->proximo;
        } while (atual != inicio);//percorre ate achar o inicio de novo pois circular
    }
    
    return NULL; // não encontrou
}

int inserir(Lista *m, int valor) {
    No *pred;
    No *elem;
    elem = buscaElemEPred(m, valor, &pred); // verifica se já existe
    if (elem != NULL) { // se o valor já existe
        return 0;
    }
    
    No *novono = malloc(sizeof(No));
    novono->valor = valor;//atribui o valor desejado
    
    if (pred == NULL) { // significa que o valor será o primeiro da lista
        if (m->inicio == NULL) { // se a lista está vazia
            novono->proximo = novono; // o próximo nó aponta para si mesmo(lista circ de um unico nó)
        } else {//se a lista nao estiver vazia
            No *ultimo = m->inicio;
            while (ultimo->proximo != m->inicio) {//enquanto nao chegar no fim
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = novono;
            novono->proximo = m->inicio;
        }
        m->inicio = novono;
    } else {//se pred != null = inserir no meio
        novono->proximo = pred->proximo;
        pred->proximo = novono;
    }
    
    return 1;
}

int excluir(Lista *m, int valor) {
    No *pred;
    No *busca;
    busca = buscaElemEPred(m, valor, &pred);
    if (busca == NULL) { // se não encontrou o valor
        return 0;
    }
    
    if (pred == NULL) { // se for o primeiro elemento
        No *ultimo = m->inicio;
        while (ultimo->proximo != m->inicio) {
            ultimo = ultimo->proximo;//só pega o ultimo elemento
        }
        if (m->inicio->proximo == m->inicio) { // se houver apenas um nó na lista
            m->inicio = NULL;//para indicar que a lista está vazia
        } else {
            m->inicio = busca->proximo;
            ultimo->proximo = m->inicio;//para garantir a circularidade
        }
    } else {//se pred != NULL
        pred->proximo = busca->proximo;
    }
    
    free(busca);
    return 1;
}

void reinicializar(Lista *m) {
    No *apagar;
    No *atual = m->inicio;
    
    while (atual != NULL) {
        apagar = atual;
        atual = atual->proximo;
        free(apagar);
        
        if (atual == m->inicio) {//interrompe caso chegue ao fim
            break;
        }
    }
    
    m->inicio = NULL;
}

int main() {
    Lista l1;
    inicializarLista(&l1);
    printf("\nQtd de elementos válidos: %d", qtdElemValidos(&l1));
    inserir(&l1, 3);
    inserir(&l1, 2);
    inserir(&l1, 1);
    inserir(&l1, 4);
    excluir(&l1, 2);
    imprimir(&l1);
    printf("\nQtd de elementos válidos: %d", qtdElemValidos(&l1));
    reinicializar(&l1);
    printf("\nQtd de elementos válidos: %d", qtdElemValidos(&l1));
    return 0;
}

