#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
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

int qtdNaFila(FILA* f){
	No* i = f->inicio;
	int cont = 0;
	while(i != NULL){
		cont++;
		i = i->proximo;
	}
	return cont;
}

AVIAO primeiroAviao(FILA* f){
	return f->inicio->aviao;
}

AVIAO retornaAviaoNaPosicao(FILA* f, int posicao) {
	No* i = f->inicio;
	int cont = 0;
	while (i != NULL && cont < posicao-1) {
		i = i->proximo;
		cont++;
	}
	if (i != NULL) {
		return i->aviao;
	} else {
		AVIAO aviao_vazio; // Avião com dados vazios
		aviao_vazio.id = -1;
		strcpy(aviao_vazio.nome, "");
		return aviao_vazio;
	}
}


int main(){
	FILA f;
	inicializarFila(&f);
	
	AVIAO a;
	a.id = 13;
	strcpy(a.nome, "GOL");
	inserirListadeEspera(&f, a);
	a.id = 20;
	strcpy(a.nome, "AZUL");
	inserirListadeEspera(&f, a);
	a.id = 22;
	strcpy(a.nome, "AMERICAN AIRLINES");
	inserirListadeEspera(&f, a);
	
	printf("\n==avioes na lista de espera==\n");
	imprimeFila(&f);
	
	printf("\nquantidade de avioes na lista de espera: %d", qtdNaFila(&f));
	
	AVIAO primeiroaviao = primeiroAviao(&f);
	printf("\ndados do primeiro aviao da fila: %d | %s ", primeiroaviao.id, primeiroaviao.nome);
	
	AVIAO aviao_posicao = retornaAviaoNaPosicao(&f, 2); // Retorna o avião na posição 2
	if (aviao_posicao.id != -1) {
		printf("\nDados do aviao na posicao 2: %d | %s\n", aviao_posicao.id, aviao_posicao.nome);
	} else {
		printf("Nao ha aviao na posicao 2.\n");
	}
	
	printf("\nDecolagem do primeiro aviao da fila: \n");
	excluirDaListadeEspera(&f);
	imprimeFila(&f);
	reinicializarFila(&f);
	return 0;
}
