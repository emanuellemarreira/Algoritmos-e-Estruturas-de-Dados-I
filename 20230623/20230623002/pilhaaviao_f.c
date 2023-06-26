#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaaviao.h"

void reinicializarPilha(PILHA* p){
    No* apagar;
    No* i = p->topo;
    while(i != NULL){
        apagar = i;
        i = i->proximo;
        free(apagar);
    }
    inicializarPilha(p);
}

int inserirHangar(PILHA* p, AVIAO novo_aviao){//inserir no inicio
	No* i = malloc(sizeof(No));
	if(i == NULL){
		return 0;
	}
	i->aviao = novo_aviao;
	i->proximo = p->topo;
	p->topo = i;
	return 1;
}
int excluirHangar(PILHA* p){//excluir do inicio
	if(p->topo == NULL){
		return 0;//se for vazia
	}
	No* i = p->topo;
	p->topo = p->topo->proximo;
	free(i);
	return 1;
}
int excluirHangarPelaPosicao(PILHA* p, int posicao){
	if(posicao-1 == 0){//se for do inicio
		excluirHangar(p);
		return 1;
	}
	No* i = p->topo;
	int contpos = 0;
	PILHA aux;
	inicializarPilha(&aux);
	while(i != NULL && contpos < posicao-1){
		inserirHangar(&aux, i->aviao);
		excluirHangar(p);
		i = i->proximo;
		contpos++;
	}
	excluirHangar(p);//tirando o elemento que eu quero tirar depois de tirar todos os que estavam em cima dele
	i = aux.topo;
	while(i != NULL){
		inserirHangar(p, i->aviao);
		i = i->proximo;
	}
	reinicializarPilha(&aux);
	return 1;
}


void imprimePilha(PILHA *p){
	No* i = p->topo;
	while(i != NULL){
		printf(" %d | %s", i->aviao.cod, i->aviao.nome);
		printf("\n");
		i = i->proximo;
	}
}

AVIAO primeiroAviao(PILHA* p){
	return p->topo->aviao;
}

