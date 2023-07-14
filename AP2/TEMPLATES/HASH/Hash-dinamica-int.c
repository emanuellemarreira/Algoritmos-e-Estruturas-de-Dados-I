#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 51
typedef struct No{
    int valor;
    struct No* proximo;
}No;

typedef No* tbhash[N];

void inicializarHash(tbhash t){
	int i;
	for(i=0; i<N; i++){
		t[i]=NULL;
	}
}

int m_hash(int cod_pac){
	return cod_pac%N;
}

int inserirHash(tbhash t, No novovalor){
	int pos = m_hash(novovalor.valor);
	No* anterior = NULL;
	No* no = t[pos];
	while(no != NULL){//espaco nao vazio entao percorre a lista que está posicao pos p adicionar
		if(no->valor == novovalor.valor){
			return 0;//se ja existe
		}
		anterior = no;
		no = no->proximo;
	}
	if(no == NULL){//achou espaço vazio
		no = malloc(sizeof(No));
		no->valor = novovalor.valor;
		no->proximo = NULL;
		if(anterior == NULL){// primeiro da lista da posicao pos
			t[pos] = no;
		}else{
			anterior->proximo = no;
		}
	}
	return 1;
}

int excluir(tbhash t, int valor) {
    int pos = m_hash(valor);
    No* anterior = NULL;
    No* no = t[pos];

    while (no != NULL) {
        if (no->valor == valor) {
            if (anterior == NULL) { //o primeiro no da lista
                t[pos] = no->proximo;
            } else {
                anterior->proximo = no->proximo;
            }

            free(no);
            return 1;
        }

        anterior = no;
        no = no->proximo;
    }

    return 0; 
}

No* busca(tbhash t, int valor){
	int pos = m_hash(valor);
	No* no = t[pos];
	while(no != NULL){
		if(no->valor == valor){
			return no;
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
			printf("\n %d ", i);
			while(no != NULL){
				printf(" %d ", no->valor);
				no = no->proximo;
			}
			printf(" NULL ");
		}else{
			printf("\n Paciente %d NULL", i);
		}
	}
}

int main(){
	tbhash hash;
	No p;
	inicializarHash(hash);
	p.valor = 123;
	inserirHash(hash, p);
	
	p.valor = 225;
	inserirHash(hash, p);

	p.valor = 111;
	inserirHash(hash, p);
	
	p.valor = 165;
	inserirHash(hash, p);
	
	imprimeHash(hash);
	
	printf("\nresultado busca = %d\n", busca(hash, 111)->valor);
	excluir(hash, 123);
	
	imprimeHash(hash);
	return 0;
}


