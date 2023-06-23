#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef struct{
	char nome[MAX];
	int id;
}AVIAO;

typedef struct No{
    AVIAO aviao;
	struct No* proximo;	
}No;

typedef struct{
	No* inicio;
	No* fim;
}FILA;

void inicializarFila(FILA* f){
	f->inicio = NULL;
	f->fim = NULL;
}

void reinicializar(FILA* f){
	No* apagar;
	No* i = f->inicio;
	while(i != NULL){
		apagar = i;
		i = i->proximo;
		free(apagar);
	f->inicio = NULL;
	}
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

int main(){
	FILA f;
	inicializarFila(&f);
	
	AVIAO a;
	a.id = 13;
	strcpy(a.nome, "air jordan");
	inserirListadeEspera(&f, a);
	a.id = 20;
	strcpy(a.nome, "air max");
	inserirListadeEspera(&f, a);
	a.id = 22;
	strcpy(a.nome, "air force");
	inserirListadeEspera(&f, a);
	imprimeFila(&f);
	printf("\n----------\n");
	excluirDaListadeEspera(&f);
	imprimeFila(&f);
	return 0;
}
