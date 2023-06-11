#include <stdio.h>
#include <stdlib.h>
#include "listadin.h"
void inicializarLista(Lista *l){
	l->inicio = NULL;
}
int qtdElemValidos(Lista *l){
	int tam=0;
	No *inicio = l->inicio;
	while(inicio != NULL){
		tam++;
		inicio = inicio->proximo;
	}
	return tam;
}
void imprimir(Lista *lista){
	No *inicio = lista->inicio;
	while(inicio != NULL){
		printf("\nlista= %d", inicio->valor);
		inicio = inicio->proximo;
	}
}
No *buscaElemEPred(Lista *m, int valor, No** pred){
	*pred = NULL;
	No* atual = m->inicio;
	while((atual != NULL)&&(atual->valor < valor)){
		*pred = atual;
		atual = atual->proximo;
	}
	if((atual != NULL)&&(atual->valor == valor)){
		return atual;
	}
	return NULL;//nao encontrou
}
int inserir(Lista *m, int valor){//de forma ordenada
	No* pred;
	No* elem;
	elem = buscaElemEPred(m,valor,&pred);//verifica se ja existe
	if(elem != NULL){//se o valor ja existe
		return 0;
	}
	No *novono = malloc(sizeof(No));
	novono->valor = valor;
	if(pred == NULL){//significa que  o valor sera o 1o da lista
		novono->proximo = m->inicio;
		m->inicio = novono;
	}else{
		novono->proximo = pred->proximo;
		pred->proximo = novono;
	}
	return 1;
}
int excluir(Lista* m, int valor){
	No* pred;
	No* busca;
	busca = buscaElemEPred(m,valor,&pred);
	if(busca == NULL){//se nao encontrou o valor
		return 0;
	}
	if(pred == NULL){//se for o primeiro elem
		m->inicio = busca->proximo;
	}else{
		pred->proximo = busca->proximo;
	}
	free(busca);
	return 1;
}
void reinicializar(Lista* m){
	No* apagar;
	No* elem = m->inicio;
	while(elem != NULL){
		apagar = elem;
		elem = elem->proximo;
		free(apagar);
	}
	m->inicio = NULL;
}
