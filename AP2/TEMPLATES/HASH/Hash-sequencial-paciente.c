#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 51

typedef struct{
	int cod_pac;
	char nome[100];
	int idade;
	char CPF[100];
}PACIENTE;

typedef PACIENTE* tbhash[N];

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

int excluir(tbhash t, int cod_pac){
	int pos = dispersao_hash(cod_pac);
	while( t[pos] != NULL){
		if(t[pos]->cod_pac == cod_pac){
			free(t[pos]);
			t[pos]=NULL;
			return 1;
		}
		pos = (pos+1)%N;//proxima posicao
	}
	
	return 0;
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

int main(){
	tbhash hash;
	PACIENTE p;
	inicializarHash(hash);
	p.cod_pac = 123;
	strcpy(p.nome, "Andreia");
	p.idade = 31;
	strcpy(p.CPF, "01234567810");
	inserirHash(hash, p);
	
	p.cod_pac = 111;
	strcpy(p.nome, "Alexandre");
	p.idade = 32;
	strcpy(p.CPF, "05634567810");
	inserirHash(hash, p);
	
	p.cod_pac = 165;
	strcpy(p.nome, "Marcus");
	p.idade = 45;
	strcpy(p.CPF, "06543217810");
	inserirHash(hash, p);
	
	imprimeHash(hash);
	
	printf("\nresultado busca = %s", busca(hash, 111)->nome);
	excluir(hash, 111);
	imprimeHash(hash);
	return 0;
}


