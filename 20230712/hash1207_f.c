#include <stdlib.h>
#include <stdio.h>
#include "hash1207.h"


void inicializarHash(hash t){
	int i;
	for(i=0; i<M; i++){
		t[i]=NULL;
	}
}

int m_hash(int valor){
	return (2*valor+5)%M;
}

int inserirHash(hash t, int valor){
	int pos = m_hash(valor);
	No* anterior = NULL;
	No* no = t[pos];
	while(no != NULL){//espaco nao vazio entao percorre a lista que está posicao pos p adicionar
		if(no->valor == valor){
			return 0;//se ja existe
		}
		anterior = no;
		no = no->proximo;
	}
	if(no == NULL){//achou espaço vazio
		no = malloc(sizeof(No));
		no->valor = valor;
		no->proximo = NULL;
		if(anterior == NULL){// primeiro da lista da posicao pos
			t[pos] = no;
		}else{
			anterior->proximo = no;
		}
	}
	return 1;
}

int busca(hash t, int valor){
	int pos = m_hash(valor);
	No* no = t[pos];
	while(no != NULL){
		if(no->valor == valor){
			return no->valor;
		}
		no = no->proximo;
	}
	return 0;
}

void imprimirHash(hash t){
	No* no;
	int i;
	for(i=0; i<M; i++){
		if(t[i] != NULL){
			no = t[i];
			printf("\n Valor %d ", i);
			while(no != NULL){
				printf(" / %d / ", no->valor);
				no = no->proximo;
			}
			printf(" NULL ");
		}else{
			printf("\n Valor %d NULL", i);
		}
	}
}


