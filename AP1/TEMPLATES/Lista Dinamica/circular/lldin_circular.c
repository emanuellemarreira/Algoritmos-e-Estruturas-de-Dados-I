#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;

void inicializarLista(Lista* l) {
    l->inicio = NULL;
}

int qtdElemValidos(Lista* l) {
    int tam = 0;
    No* inicio = l->inicio;
    if (inicio == NULL) {
        return tam;
    }
    tam++;
    No* atual = inicio->proximo;
    while (atual != inicio) {
        tam++;
        atual = atual->proximo;
    }
    return tam;
}

void imprimir(Lista* lista) {
    No* inicio = lista->inicio;
    if (inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    No* atual = inicio;
    do {
        printf("lista = %d\n", atual->valor);
        atual = atual->proximo;
    } while (atual != inicio);
}

No* buscaElemEPred(Lista* m, int valor, No** pred) {
    *pred = NULL;
    No* inicio = m->inicio;
    if (inicio == NULL) {
        return NULL;
    }
    No* atual = inicio;
    do {
        if (atual->valor == valor) {
            return atual;
        }
        *pred = atual;
        atual = atual->proximo;
    } while (atual != inicio);
    return NULL;
}

No* buscaElemEPredDesord(Lista* m, int valor, No** pred) {
    *pred = NULL;
    No* inicio = m->inicio;
    if (inicio == NULL) {
        return NULL;
    }
    No* atual = inicio;
    do {
        if (atual->valor == valor) {
            return atual;
        }
        *pred = atual;
        atual = atual->proximo;
    } while (atual != inicio);
    return NULL;
}

int inserir(Lista* m, int valor) {
    No* pred;
    No* elem;
    elem = buscaElemEPred(m, valor, &pred); // verifica se j� existe
    if (elem != NULL) { // se o valor j� existe
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->valor = valor;
    if (pred == NULL) { // significa que o valor ser� o primeiro da lista
        if (m->inicio == NULL) {
            novono->proximo = novono; // o novo n� aponta para si mesmo
        } else {
            No* ultimo = m->inicio;
            while (ultimo->proximo != m->inicio) { // encontra o �ltimo n�
                ultimo = ultimo->proximo;
            }
            novono->proximo = m->inicio; // o novo n� aponta para o primeiro n�
            ultimo->proximo = novono; // o �ltimo n� aponta para o novo n�
        }
        m->inicio = novono;
    } else {
        novono->proximo = pred->proximo;
        pred->proximo = novono;
    }
    return 1;
}

int inserirInicio(Lista* m, int valor) {
    No* pred;
    No* elem;
    elem = buscaElemEPred(m, valor, &pred); // verifica se j� existe
    if (elem != NULL) { // se o valor j� existe
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->valor = valor;
    if (m->inicio == NULL) {
        novono->proximo = novono; // o novo n� aponta para si mesmo
    } else {
        No* ultimo = m->inicio;
        while (ultimo->proximo != m->inicio) { // encontra o �ltimo n�
            ultimo = ultimo->proximo;
        }
        novono->proximo = m->inicio; // o novo n� aponta para o primeiro n�
        ultimo->proximo = novono; // o �ltimo n� aponta para o novo n�
    }
    m->inicio = novono;
    return 1;
}

int inserirFim(Lista* m, int valor) {
    No* pred;
    No* elem;
    elem = buscaElemEPred(m, valor, &pred); // verifica se j� existe
    if (elem != NULL) { // se o valor j� existe
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->valor = valor;
    if (m->inicio == NULL) {
        novono->proximo = novono; // o novo n� aponta para si mesmo
        m->inicio = novono;
    } else {
        No* ultimo = m->inicio;
        while (ultimo->proximo != m->inicio) { // encontra o �ltimo n�
            ultimo = ultimo->proximo;
        }
        novono->proximo = m->inicio; // o novo n� aponta para o primeiro n�
        ultimo->proximo = novono; // o �ltimo n� aponta para o novo n�
    }
    return 1;
}

int inserirEntreOrdem(Lista* m, int valor, int valorAnterior, int valorPosterior) {
    No* predAnterior, * predPosterior;
    No* elemAnterior = buscaElemEPred(m, valorAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior n�o foi encontrado na lista
        return 0;
    }
    No* elemPosterior = buscaElemEPred(m, valorPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior n�o foi encontrado na lista
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->valor = valor;
    
    novono->proximo = elemPosterior;
    elemAnterior->proximo = novono;
    
    return 1;
}

int inserirEntreDesordem(Lista* m, int valor, int valorAnterior, int valorPosterior) {
    No* predAnterior, * predPosterior;
    No* elemAnterior = buscaElemEPredDesord(m, valorAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior n�o foi encontrado na lista
        return 0;
    }
    No* elemPosterior = buscaElemEPredDesord(m, valorPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior n�o foi encontrado na lista
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->valor = valor;
    
    novono->proximo = elemPosterior;
    elemAnterior->proximo = novono;
    
    return 1;
}

int excluir(Lista* m, int valor) {
    if (m->inicio == NULL) {
        // A lista est� vazia, n�o h� elementos para excluir
        return 0;
    }
    
    No* pred;
    No* busca = buscaElemEPred(m, valor, &pred);
    if (busca == NULL) {
        // O valor n�o foi encontrado na lista
        return 0;
    }
    
    if (busca == m->inicio) {
        // O valor a ser exclu�do � o primeiro da lista
        No* ultimo = m->inicio;
        while (ultimo->proximo != m->inicio) { // encontra o �ltimo n�
            ultimo = ultimo->proximo;
        }
        m->inicio = busca->proximo; // atualiza o in�cio para o pr�ximo n�
        ultimo->proximo = m->inicio; // o �ltimo n� aponta para o novo primeiro n�
    } else {
        pred->proximo = busca->proximo; // o n� anterior ao valor exclu�do aponta para o pr�ximo n�
    }
    
    free(busca); // libera a mem�ria do n� exclu�do
    return 1;
}

int excluirInicio(Lista* m) {
    if (m->inicio == NULL) {
        // A lista est� vazia, n�o h� elementos para excluir
        return 0;
    }
    
    No* ultimo = m->inicio;
    while (ultimo->proximo != m->inicio) { // encontra o �ltimo n�
        ultimo = ultimo->proximo;
    }
    
    No* primeiro = m->inicio;
    m->inicio = primeiro->proximo; // atualiza o in�cio para o pr�ximo n�
    ultimo->proximo = m->inicio; // o �ltimo n� aponta para o novo primeiro n�
    
    free(primeiro); // libera a mem�ria do n� exclu�do
    return 1;
}

int excluirFim(Lista* m) {
    if (m->inicio == NULL) {
        // A lista est� vazia, n�o h� elementos para excluir
        return 0;
    }
    
    No* atual = m->inicio;
    No* busca = m->inicio;
    No* pred = NULL;
    while (atual->proximo != m->inicio) {
        pred = busca;
        busca = busca->proximo;
        atual = atual->proximo;
    }
    
    if (pred == NULL) {
        // A lista possui apenas um elemento
        free(busca);
        m->inicio = NULL;
    } else {
        pred->proximo = m->inicio; // o n� anterior ao �ltimo aponta para o primeiro n�
        free(busca);
    }
    
    return 1;
}

int excluirEntre(Lista* m, int valorAnterior, int valorPosterior) {
    No* predAnterior;//serve pra ordenada e desordenada por causa da minha funcao p buscar
    No* predPosterior;
    No* elemAnterior = buscaElemEPredDesord(m, valorAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior n�o foi encontrado na lista
        return 0;
    }
    No* elemPosterior = buscaElemEPredDesord(m, valorPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior n�o foi encontrado na lista
        return 0;
    }
    No* elemExcluir = elemAnterior->proximo;
    elemAnterior->proximo = elemPosterior;
    free(elemExcluir);
    return 1;
}
int alterar(Lista* m, int valor, int novovalor){
	No* pred;
	No* busca;
	busca = buscaElemEPred(m,valor,&pred);
	if(busca == NULL){//se nao encontrou o valor
		return 0;
	}
	busca->valor = novovalor;
	return 1;
}

void destruirLista(Lista* m) {
    while (m->inicio != NULL) {
        excluirInicio(m);
    }
}

int main() {
    Lista lista;
    inicializarLista(&lista);
    
    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    printf("\n==ordenada==\n");
    imprimir(&lista);
    inserirFim(&lista,4);
    inserirInicio(&lista,0);
    inserirEntreOrdem(&lista,33,2,3);
    inserirEntreDesordem(&lista, 44, 33, 3);
    printf("\n==+elementos==\n");
    imprimir(&lista);
    excluir(&lista, 2);
    excluirInicio(&lista);
    excluirFim(&lista);
    excluirEntre(&lista, 33,3);
    printf("\n==depois de excluir==\n");
    imprimir(&lista);
    alterar(&lista, 33, 1000);
    printf("\n==depois de alterar==\n");
    imprimir(&lista);
    destruirLista(&lista);
    return 0;
}

