#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 51

typedef struct{
	int valor;
}Elemento;

typedef Elemento* tbhash[N];

void inicializarHash(tbhash t){
	int i;
	for(i=0; i<N; i++){
		t[i] = NULL;
	}
}

int dispersao_hash(int cod_pac){
	return (cod_pac%N);
}

int inserirHash(tbhash t, Elemento e){
	int pos = dispersao_hash(e.valor);
	while( t[pos] != NULL){
		if(t[pos]->valor == e.valor){
			return 0;//se ja existe
		}
		pos = (pos+1)%N;//proxima posicao
	}
	if(t[pos] == NULL){//encontrou espaço vazio
		t[pos] = malloc(sizeof(Elemento));
		*(t[pos]) = e;//insere
	}
	return 1;
}

int excluir(tbhash t, Elemento e){
	int pos = dispersao_hash(e.valor);
	while( t[pos] != NULL){
		if(t[pos]->valor == e.valor){
			free(t[pos]);
			t[pos]=NULL;
			return 1;
		}
		pos = (pos+1)%N;//proxima posicao
	}
	
	return 0;
}

Elemento* busca(tbhash t, Elemento e){//da pra ajustar pra retornar a posicao
    int	pos = dispersao_hash(e.valor);
    while(t[pos] != NULL){
    	if(t[pos]->valor == e.valor){
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
			printf(" %d | %d \n", i, t[i]->valor);
		}
		else{
			printf("%d | NULO\n", i);
		}
	}
}

int main(){
	tbhash hash;
	Elemento p;
	inicializarHash(hash);
	p.valor = 123;
	inserirHash(hash, p);
	
	p.valor = 111;
	inserirHash(hash, p);
	
	p.valor = 165;
	inserirHash(hash, p);
	
	imprimeHash(hash);
	
	Elemento procurar;
	procurar.valor = 165;
	printf("\nresultado busca = %d\n", busca(hash, procurar)->valor);
	excluir(hash, procurar);
	imprimeHash(hash);
	return 0;
}


