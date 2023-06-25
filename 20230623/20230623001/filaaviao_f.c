#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaaviao.h"

void inicializarFila(FILA* f){
	f->inicio = NULL;
	f->fim = NULL;
}

void reinicializarFila(FILA* f){
    No* apagar;
    No* i = f->inicio;
    while(i != NULL){
        apagar = i;
        i = i->proximo;
        free(apagar);
    }
    inicializarFila(f);
}


int inserirListadeEspera(FILA* f, AVIAO novo_aviao){//inserir no fim
	No* i;
	i = malloc(sizeof(No));
	if(i == NULL){
		return 0;
	}
	i->aviao = novo_aviao;
	i->proximo = NULL;
	if(f->inicio == NULL){//se for primeira posicao da fila
		f->inicio = i;
	}else{
		f->fim->proximo = i; //insere no fim da lista;
	}
	f->fim = i;
	return 1;
}

int excluirDaListadeEspera(FILA* f){//excluir do inicio
    if(f->inicio == NULL){//lista vazia
    	return 0;
	}
	No* i = f->inicio;
	f->inicio = f->inicio->proximo;
	free(i);
	return 1;
}

void imprimeFila(FILA *f){
	No* i = f->inicio;
	while(i != NULL){
		printf(" %d | %s", i->aviao.id, i->aviao.nome);
		printf("\n");
		i = i->proximo;
	}
}

int qtdNaFila(FILA* f){
	No* i = f->inicio;
	int cont = 0;
	while(i != NULL){
		cont++;
		i = i->proximo;
	}
	return cont;
}

AVIAO primeiroAviao(FILA* f){
	return f->inicio->aviao;
}

