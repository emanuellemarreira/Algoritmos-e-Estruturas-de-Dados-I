#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashvetor.h"

void inicializarHash(tbhash t){
	int i;
	for(i=0; i<N; i++){
		t[i] = NULL;
	}
}

int dispersao_hash(int cod_pac){
	return (cod_pac%N);
}

int inserirHash(tbhash t, PACIENTE p){
	int pos = dispersao_hash(p.cod_pac);
	while( t[pos] != NULL){
		if(t[pos]->cod_pac == p.cod_pac){
			return 0;//se ja existe
		}
		pos = (pos+1)%N;//proxima posicao
	}
	if(t[pos] == NULL){//encontrou espaço vazio
		t[pos] = malloc(sizeof(PACIENTE));
		*(t[pos]) = p;//insere
	}
	return 1;
}

PACIENTE* busca(tbhash t, int cod_pac){
    int	pos = dispersao_hash(cod_pac);
    while(t[pos] != NULL){
    	if(t[pos]->cod_pac == cod_pac){
    		return t[pos];
		}
	pos = (pos+1)%N;
	}
	return NULL;
}

void imprimeHash(tbhash t){
	int i;
	for(i = 0; i<N; i++){
		if(t[i]!=NULL){
			printf("%d | %s %d %d %s \n", i, t[i]->nome, t[i]->idade, t[i]->cod_pac, t[i]->CPF);
		}
		else{
			printf("%d | NULO\n", i);
		}
	}
}

