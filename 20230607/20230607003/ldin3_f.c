#include <stdio.h>
#include <stdlib.h>
#include "ldin3.h"
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
void copiarlista(Lista *l, Lista *l1){
	No *inicio = l->inicio;
	while(inicio != NULL){
		inserirFim(l1,inicio->valor);
		inicio = inicio->proximo;
	}
}
void concatenar(Lista *l, Lista *l1){
	No *inicio = l->fim;
	No *inicio2 = l1->inicio;
	while(inicio2 != NULL){
		inserirFim(l,inicio2->valor);
		inicio = inicio->proximo;
		inicio2 = inicio2->proximo;
	}
}
void intercalar(Lista *l, Lista *l1, Lista *l2){
	No *inicio = l->inicio;
	No *inicio1 = l1->inicio;
	int cont=0;
	
	while(inicio != NULL && inicio1 != NULL){
	    if(cont%2==0){
	    	inserirFim(l2, inicio->valor);
	    	inicio = inicio->proximo;
		}else{
			inserirFim(l2, inicio1->valor);
			inicio1 = inicio1->proximo;
		}
		cont++;
	}
}
void imprimir(Lista *lista){
	No *inicio = lista->inicio;
	while(inicio != NULL){
		printf("\nlista= %d", inicio->valor);
		inicio = inicio->proximo;
	}
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


