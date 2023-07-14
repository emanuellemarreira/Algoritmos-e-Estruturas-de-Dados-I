#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 51

typedef struct{
	int cod_pac;
	char nome[20];
	char CPF[12];
	int idade;
}PACIENTE;

typedef struct No{
    PACIENTE paciente;
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

int excluir(tbhash t, int cod_pac) {
    int pos = m_hash(cod_pac);
    No* anterior = NULL;
    No* no = t[pos];

    while (no != NULL) {
        if (no->paciente.cod_pac == cod_pac) {
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

int main(){
	tbhash hash;
	PACIENTE p;
	inicializarHash(hash);
	p.cod_pac = 123;
	strcpy(p.nome, "Andreia");
	p.idade = 31;
	strcpy(p.CPF, "01234567810");
	inserirHash(hash, p);
	
	p.cod_pac = 225;
	strcpy(p.nome, "Andreia 2");
	p.idade = 32;
	strcpy(p.CPF, "11234567810");
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
	
	printf("\nresultado busca = %s\n", busca(hash, 111)->nome);
	excluir(hash, 123);
	
	imprimeHash(hash);
	return 0;
}


