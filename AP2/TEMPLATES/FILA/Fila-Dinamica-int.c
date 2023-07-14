#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct No{
    int valor;
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


int inserirFila(FILA* f, int novo_valor){//inserir no fim
	No* i;
	i = malloc(sizeof(No));
	if(i == NULL){
		return 0;
	}
	i->valor = novo_valor;
	i->proximo = NULL;
	if(f->inicio == NULL){//se for primeira posicao da fila
		f->inicio = i;
	}else{
		f->fim->proximo = i; //insere no fim da lista;
	}
	f->fim = i;
	return 1;
}

int excluirFila(FILA* f){//excluir do inicio
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
		printf(" %d ", i->valor);
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

int primeiroValor(FILA* f){
	return f->inicio->valor;
}

No* retornaValorNaPosicao(FILA* f, int posicao) {
	No* i = f->inicio;
	int cont = 0;
	while (i != NULL && cont < posicao-1) {
		i = i->proximo;
		cont++;
	}
	if (i != NULL) {
		return i;
	} else {
		return NULL;
	}
}


int main(){
	FILA f;
	inicializarFila(&f);
	
	inserirFila(&f, 1);
	inserirFila(&f, 11);
	inserirFila(&f, 111);
	printf("\n==impressao==\n");
	imprimeFila(&f);
	
	printf("\nquantidade na fila: %d", qtdNaFila(&f));
	
	int primeirovalor = primeiroValor(&f);
	printf("\ndados do primeiro valor: %d ", primeirovalor);
	No* valor_posicao = retornaValorNaPosicao(&f, 2); // Retorna o avião na posição 2
	if (valor_posicao != NULL) {
		printf("\nDados da posicao 2: %d \n", valor_posicao->valor);
	} else {
		printf("Nao ha aviao na posicao 2.\n");
	}
	
	printf("\nExcluindo da fila\n");
	excluirFila(&f);
	imprimeFila(&f);
	reinicializarFila(&f);
	return 0;
}
