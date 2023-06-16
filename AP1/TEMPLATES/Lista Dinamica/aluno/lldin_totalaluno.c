#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    int cod, idade, filhos;
    char nome[MAX];
} Aluno;

typedef struct No {
    Aluno aluno;
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
    while (inicio != NULL) {
        tam++;
        inicio = inicio->proximo;
    }
    return tam;
}

void imprimir(Lista* lista) {
    No* inicio = lista->inicio;
    while (inicio != NULL) {
        printf("\nAluno: %s, Código: %d, Idade: %d, Número de filhos: %d",
            inicio->aluno.nome, inicio->aluno.cod, inicio->aluno.idade, inicio->aluno.filhos);
        inicio = inicio->proximo;
    }
}

No* buscaElemEPred(Lista* m, int cod, No** pred) {
    *pred = NULL;
    No* atual = m->inicio;
    while (atual != NULL && (atual->aluno.cod < cod)) {
        *pred = atual;
        atual = atual->proximo;
    }
    if ((atual != NULL) && (atual->aluno.cod == cod)) {
        return atual;
    }
    return NULL; // não encontrou
}

No* buscaElemEPredDesord(Lista* m, int cod, No** pred) {
    *pred = NULL;
    No* atual = m->inicio;
    while (atual != NULL) {
        *pred = atual;
        if (atual->aluno.cod == cod) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL; // não encontrou
}

int inserir(Lista* m, Aluno aluno) { // de forma ordenada
    No* pred;
    No* elem;
    elem = buscaElemEPred(m, aluno.cod, &pred); // verifica se já existe
    if (elem != NULL) { // se o valor já existe
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->aluno = aluno;
    if (pred == NULL) { // significa que o valor será o 1o da lista
        novono->proximo = m->inicio;
        m->inicio = novono;
    }
    else {
        novono->proximo = pred->proximo;
        pred->proximo = novono;
    }
    return 1;
}

int inserirInicio(Lista* m, Aluno aluno) {
    No* pred;
    No* elem;
    elem = buscaElemEPred(m, aluno.cod, &pred); // verifica se já existe
    if (elem != NULL) { // se o valor já existe
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->aluno = aluno;
    novono->proximo = m->inicio;
    m->inicio = novono;
    return 1;
}

int inserirFim(Lista* m, Aluno aluno) {
    No* pred;
    No* elem;
    elem = buscaElemEPred(m, aluno.cod, &pred); // verifica se já existe
    if (elem != NULL) { // se o valor já existe
        return 0;
    }
    No* i = m->inicio;
    while (i != NULL && i->proximo != NULL) { // pega o último nó
        i = i->proximo;
    }
    No* novono = malloc(sizeof(No));
    novono->aluno = aluno;
    if (i == NULL) { // se for o 1o da lista
        novono->proximo = NULL;
        m->inicio = novono;
    }
    else {
        novono->proximo = NULL;
        i->proximo = novono;
    }
    return 1;
}

int inserirEntreOrdem(Lista* m, Aluno aluno, int codAnterior, int codPosterior) { // em uma lista ordenada
    No* predAnterior, * predPosterior;
    No* elemAnterior = buscaElemEPred(m, codAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior não foi encontrado na lista
        return 0;
    }
    No* elemPosterior = buscaElemEPred(m, codPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior não foi encontrado na lista
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->aluno = aluno;

    // Verifica se o elemento anterior é o último elemento da lista
    if (elemAnterior->proximo == NULL) {
        elemAnterior->proximo = novono;
        novono->proximo = NULL;
    }
    else {
        novono->proximo = elemPosterior;
        elemAnterior->proximo = novono;
    }
    return 1;
}

int inserirEntreDesordem(Lista* m, Aluno aluno, int codAnterior, int codPosterior) { // em uma lista desordenada
    No* predAnterior, * predPosterior;
    No* elemAnterior = buscaElemEPredDesord(m, codAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior não foi encontrado na lista
        return 0;
    }
    No* elemPosterior = buscaElemEPredDesord(m, codPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior não foi encontrado na lista
        return 0;
    }
    No* novono = malloc(sizeof(No));
    novono->aluno = aluno;

    // Verifica se o elemento anterior é o último elemento da lista
    if (elemAnterior->proximo == NULL) {
        elemAnterior->proximo = novono;
        novono->proximo = NULL;
    }
    else {
        novono->proximo = elemPosterior;
        elemAnterior->proximo = novono;
    }
    return 1;
}

int excluir(Lista* m, int cod) {
    No* pred;
    No* busca;
    busca = buscaElemEPred(m, cod, &pred);
    if (busca == NULL) { // se não encontrou o valor
        return 0;
    }
    if (pred == NULL) { // se for o primeiro elemento
        m->inicio = busca->proximo;
    }
    else {
        pred->proximo = busca->proximo;
    }
    free(busca);
    return 1;
}

int excluirInicio(Lista* m) {
    if (m->inicio == NULL) {
        // A lista está vazia, não há elementos para excluir
        return 0;
    }
    No* primeiro = m->inicio;
    m->inicio = primeiro->proximo;
    free(primeiro);
    return 1;
}

int excluirFim(Lista* m) {
    if (m->inicio == NULL) {
        // A lista está vazia, não há elementos para excluir
        return 0;
    }

    No* atual = m->inicio;
    No* busca = m->inicio;
    No* pred = NULL;
    while (atual->proximo != NULL) {
        pred = busca;
        busca = busca->proximo;
        atual = atual->proximo;
    }

    if (pred == NULL) {
        // A lista possui apenas um elemento
        free(busca);
        m->inicio = NULL;
    }
    else {
        pred->proximo = NULL;
        free(busca);
    }

    return 1;
}

int excluirEntre(Lista* m, int codAnterior, int codPosterior) {
    No* predAnterior; // serve para ordenada e desordenada por causa da minha função de busca
    No* predPosterior;
    No* elemAnterior = buscaElemEPredDesord(m, codAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior não foi encontrado na lista
        return 0;
    }
    No* elemPosterior = buscaElemEPredDesord(m, codPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior não foi encontrado na lista
        return 0;
    }
    No* elemExcluir = elemAnterior->proximo;
    if (elemExcluir == NULL || elemExcluir == elemPosterior) {
        // Não há elementos para excluir entre os dois valores
        return 0;
    }
    elemAnterior->proximo = elemExcluir->proximo;
    free(elemExcluir);
    return 1;
}

int alterar(Lista* m, int cod, Aluno novoAluno) {
    No* pred;
    No* busca;
    busca = buscaElemEPred(m, cod, &pred);
    if (busca == NULL) { // se não encontrou o valor
        return 0;
    }
    busca->aluno = novoAluno;
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
    Lista l1;
    inicializarLista(&l1);
    //printf("\nQtd de elementos válidos: %d", qtdElemValidos(&l1));
    printf("\n==ordenada==\n");
    Aluno aluno1 = { 1, 20, 0, "ana" };
    Aluno aluno2 = { 2, 19, 1, "bia" };
    Aluno aluno3 = { 3, 21, 0, "carlos" };
    Aluno aluno4 = { 4, 22, 2, "daniel" };

    inserir(&l1, aluno3);
    inserir(&l1, aluno2);
    inserir(&l1, aluno1);
    inserir(&l1, aluno4);
    excluirInicio(&l1);
    inserirEntreOrdem(&l1,aluno1, 3, 4);

    //printf("\nQtd de elementos válidos: %d", qtdElemValidos(&l1));
    imprimir(&l1);

    printf("\n==desordenada==\n");
    Lista l2;
    inicializarLista(&l2);
    Aluno aluno5 = { 1, 20, 0, "alda" };
    Aluno aluno6 = { 2, 19, 1, "belo" };
    Aluno aluno7 = { 3, 21, 0, "carla" };
    Aluno aluno8 = { 4, 22, 2, "dani" };

    inserirInicio(&l2, aluno6);
    inserirFim(&l2, aluno7);
    inserirEntreDesordem(&l2, aluno5, 2, 3);
    inserirFim(&l2, aluno8);

    //printf("\nQtd de elementos válidos: %d", qtdElemValidos(&l2));
    imprimir(&l2);
    printf("\n==alterando==\n");
    Aluno novoaluno = { 13, 20, 0, "lula" };
    alterar(&l2, 3, novoaluno);
    imprimir(&l2);
    
    printf("\n==excluindo==\n");
    excluir(&l2, 13);
    imprimir(&l2);
    printf("\n==excluindo entre==\n");
    excluirEntre(&l2, 2, 4);
    imprimir(&l2);
    printf("\n==excluindo inicio e fim==\n");
    excluirInicio(&l2);
    excluirFim(&l2);
    imprimir(&l2);
    printf("fim");
    return 0;
}

