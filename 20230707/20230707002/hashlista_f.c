#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashlista.h"

void inicializarHash(tbhash t){
	int i;
	for(i=0; i<N; i++){
		t[i]=NULL;
	}
}

int m_hash(int cod_pac){
	return cod_pac%N;
}

int inserirHash(tbhash t, PACIENTE p){
	int pos = m_hash(p.cod_pac);
	No* anterior = NULL;
	No* no = t[pos];
	while(no != NULL){//espaco nao vazio entao percorre a lista que está posicao pos p adicionar
		if(no->paciente.cod_pac == p.cod_pac){
			return 0;//se ja existe
		}
		anterior = no;
		no = no->proximo;
	}
	if(no == NULL){//achou espaço vazio
		no = malloc(sizeof(No));
		no->paciente = p;
		no->proximo = NULL;
		if(anterior == NULL){// primeiro da lista da posicao pos
			t[pos] = no;
		}else{
			anterior->proximo = no;
		}
	}
	return 1;
}

PACIENTE* busca(tbhash t, int cod_pac){
	int pos = m_hash(cod_pac);
	No* no = t[pos];
	while(no != NULL){
		if(no->paciente.cod_pac == cod_pac){
			return &no->paciente;
		}
		no = no->proximo;
	}
	return NULL;
}

void imprimeHash(tbhash t){
	No* no;
	int i;
	for(i=0; i<N; i++){
		if(t[i] != NULL){
			no = t[i];
			printf("\n Paciente %d ", i);
			while(no != NULL){
				printf(" %s-%d-%d-%s ", no->paciente.nome, no->paciente.idade, no->paciente.cod_pac, no->paciente.CPF);
				no = no->proximo;
			}
			printf(" NULL ");
		}else{
			printf("\n Paciente %d NULL", i);
		}
	}
}

