#include <stdio.h>
#include <stdlib.h>
#include "ldin2.h"
void inicializarLista(Lista *l){
	l->inicio = NULL;
}
void inserirFim(Lista *lista, int valor){
	No *novo = malloc(sizeof(No));//cria um novo nó
	novo->valor = valor;
	novo->proximo = NULL;//define o proximo como ultimo
	if(lista->inicio == NULL){//se a lista estiver vazia
		lista->inicio = novo;
		lista->fim = novo;
	}else{//lista nao vazia
		lista->fim->proximo = novo;
		lista->fim = novo;
	}
}
// remover um elemento da lista
void remover(Lista *lista, int valor) {
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No * noARemover = NULL; // ponteiro para o nó a ser removido

    if(inicio != NULL && lista->inicio->valor == valor) { // remover 1º elemento
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remoção no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL) {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
            if(inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }
    if(noARemover) {
        free(noARemover); // libera a memória do nó
    }
}


void imprimir(Lista *lista){
	No *inicio = lista->inicio;
	while(inicio != NULL){
		printf("\nlista= %d", inicio->valor);
		inicio = inicio->proximo;
	}
}
void a(Lista *l, Lista *l1){
	No *inicio = l->inicio;
	//No *inicio1 = l1->inicio;
	while(inicio != NULL){
		inserirFim(l1,inicio->valor);
		inicio = inicio->proximo;
	}
	inserirFim(l1,l->inicio->valor);
	remover(l1,l1->inicio->valor);
}

void b(Lista *l, Lista *l1){
    No *inicio = l->inicio;
    Lista listaAuxiliar; // Lista auxiliar para armazenar temporariamente os elementos

    listaAuxiliar.inicio = NULL;
    listaAuxiliar.fim = NULL;

    while (inicio != NULL) {
        inserirFim(&listaAuxiliar, inicio->valor); // Inserir os elementos na lista auxiliar e com & pq criei na funcao
        inicio = inicio->proximo;
    }

    while (listaAuxiliar.inicio != NULL) {
        inserirFim(l1, listaAuxiliar.fim->valor); // Inserir os elementos na lista l1 de trás para frente
        remover(&listaAuxiliar, listaAuxiliar.fim->valor); // Remover o elemento inserido da lista auxiliar, pq removendo o fim vai virar o penultimo e assim por diante
    }
}




