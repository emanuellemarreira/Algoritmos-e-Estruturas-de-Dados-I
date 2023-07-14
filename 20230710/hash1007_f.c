#include <stdlib.h>
#include <stdio.h>
#include "hash1007.h"

void inicializarHash(tbhash t){
	int i;
	for(i=0; i<N; i++){
		t[i] = NULL;
	}
}

int sondagem_linear(tbhash t, Elemento e){
	int i, pos, colisoes=0;
	for(i = 0; i<N; i++){
		pos = (e.valor + i)%N;
		if(t[pos] == NULL){
			break;
		}else{
			colisoes++;
		}
	}
	//peguei a posicao disponivel com essa funcao hash
	t[pos] = malloc(sizeof(Elemento));
	*(t[pos]) = e;
	return colisoes;
}

int sondagem_quadratica(tbhash t, Elemento e){
	int i, pos, colisoes = 0;
	for(i = 0; i<N; i++){
		pos = (e.valor + i*i)%N;
		if(t[pos] == NULL){
			break;
		}else{
			colisoes++;
		}
	}
	t[pos] = malloc(sizeof(Elemento));
	*(t[pos]) = e;
	return colisoes;
}

int sondagem_quadratica2(tbhash t, Elemento e){
	int i, pos, colisoes = 0;
	for(i = 0; i<N; i++){
		pos = (e.valor + 2*i + i*i)%N;
		if(t[pos] == NULL){
			break;
		}else{
			colisoes++;
		}
	}
	t[pos] = malloc(sizeof(Elemento));
	*(t[pos]) = e;
	return colisoes;
}

int hash_duplo(tbhash t, Elemento e){
	int pos, colisoes = 0;
	pos = e.valor%N;
	if(t[pos] != NULL){
		pos = 7-(e.valor%7);
		colisoes++;
	}
	t[pos] = malloc(sizeof(Elemento));
	*(t[pos]) = e;
	return colisoes;
}

void imprimeHash(tbhash t){
	int i;
	for(i = 0; i<N; i++){
		if(t[i]!=0){
			printf("%d | %d\n", i, t[i]->valor);
		}
		else{
			printf("%d | NULO\n", i);
		}
	}
}


