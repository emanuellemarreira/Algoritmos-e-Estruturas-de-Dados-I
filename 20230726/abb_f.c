#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
void inicializarArvore(ARVORE *a){
	a->raiz = NULL;
}
No* inserirNo(No* raiz, No* no){
	if(raiz == NULL){//condicao de parada
	    return no;
	}
	if(no->valor < raiz->valor){
		raiz->esquerda = inserirNo(raiz->esquerda, no);
	}else{
		raiz->direita = inserirNo(raiz->direita, no);
	}
	return raiz;
}

void adiciona(ARVORE *a, No* no){
	a->raiz = inserirNo(a->raiz, no);
}

void adicionarArvore(ARVORE *a, int valor){
	No* novono = malloc(sizeof(No));
	novono->valor = valor;
	novono->esquerda = NULL;
	novono->direita = NULL;
	adiciona(a, novono);
}

void listarNos(No* raiz){
	if(raiz!=NULL){
		printf("Endereco: %p\n", raiz);
		printf("Esquerda: %p  Direita:%p\n", raiz->esquerda, raiz->direita);
		printf("Valor: %d\n", raiz->valor);
		listarNos(raiz->esquerda);
		listarNos(raiz->direita);
	}
}

void imprimirArvore(ARVORE *a){
	listarNos(a->raiz);
}

No* buscarNo(No* raiz, int valor){
	if(raiz==NULL){
		return NULL;
	}
	if(raiz->valor == valor){
		return raiz;
	}
	if(valor < raiz->valor ){
		return buscarNo(raiz->esquerda, valor);
	}else{
		return buscarNo(raiz->direita, valor);
	}
}

No* buscar(ARVORE *a, int valor){
	return buscarNo(a->raiz, valor);
}

int contarNos(No* raiz){
	if(raiz == NULL){
		return 0;
	}
	return (contarNos(raiz->esquerda) + 1 + contarNos(raiz->direita));
}

No* pre_ordem(No* raiz){//raiz  esquerda  direita
	if(raiz == NULL){
		return NULL;
	}
	printf("%d\n", raiz->valor);
	pre_ordem(raiz->esquerda);
	pre_ordem(raiz->direita);	
}

No* in_ordem(No* raiz){//esquerda  raiz   direita
	if(raiz == NULL){
		return NULL;
	}
	in_ordem(raiz->esquerda);
	printf("%d\n", raiz->valor);
	in_ordem(raiz->direita);
}

No* pos_ordem(No* raiz){//esquerda   direita  raiz
	if(raiz == NULL){
		return NULL;
	}
	in_ordem(raiz->esquerda);
	in_ordem(raiz->direita);
	printf("%d\n", raiz->valor);
}

