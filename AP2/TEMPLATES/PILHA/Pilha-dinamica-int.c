#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct No{
	int valor;
	struct No* proximo;
}No;

typedef struct{
	No* topo;
}PILHA;

void inicializarPilha(PILHA* p){
	p->topo = NULL;
}

void reinicializarPilha(PILHA* p){
    No* apagar;
    No* i = p->topo;
    while(i != NULL){
        apagar = i;
        i = i->proximo;
        free(apagar);
    }
    inicializarPilha(p);
}

int inserirPilha(PILHA* p, int novo_valor){//inserir no inicio
	No* i = malloc(sizeof(No));
	if(i == NULL){
		return 0;
	}
	i->valor = novo_valor;
	i->proximo = p->topo;
	p->topo = i;
	return 1;
}
int excluirPilha(PILHA* p){//excluir do inicio
	if(p->topo == NULL){
		return 0;//se for vazia
	}
	No* i = p->topo;
	p->topo = p->topo->proximo;
	free(i);
	return 1;
}
int excluirPelaPosicao(PILHA* p, int posicao){
	if(posicao-1 == 0){//se for do inicio
		excluirPilha(p);
		return 1;
	}
	No* i = p->topo;
	int contpos = 0;
	PILHA aux;
	inicializarPilha(&aux);
	while(i != NULL && contpos < posicao-1){
		inserirPilha(&aux, i->valor);
		excluirPilha(p);
		i = i->proximo;
		contpos++;
	}
	excluirPilha(p);//tirando o elemento que eu quero tirar depois de tirar todos os que estavam em cima dele
	i = aux.topo;
	while(i != NULL){
		inserirPilha(p, i->valor);
		i = i->proximo;
	}
	reinicializarPilha(&aux);
	return 1;
}


void imprimePilha(PILHA *p){
	No* i = p->topo;
	while(i != NULL){
		printf(" %d ", i->valor);
		printf("\n");
		i = i->proximo;
	}
}

int primeiroValor(PILHA* p){
	return p->topo->valor;
}

No* retornaValorNaPosicao(PILHA* p, int posicao) {
	No* i = p->topo;
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
	PILHA p;
	inicializarPilha(&p);
	
	inserirPilha(&p, 5);
	inserirPilha(&p, 55);
	inserirPilha(&p, 555);
	
	printf("\n==impressao==\n");
	imprimePilha(&p);
	
	int primeirovalor = primeiroValor(&p);
	printf("\ndados do primeiro valor: %d ",primeirovalor);
	No* valor_posicao = retornaValorNaPosicao(&p, 2); // Retorna o avião na posição 2
	if (valor_posicao != NULL) {
		printf("\nDados do valor na posicao 2: %d \n", valor_posicao->valor);
	} else {
		printf("Nao ha valor na posicao 2.\n");
	}
	printf("\nExcluindo 2: \n");
	//excluirPilha(&p);
	excluirPelaPosicao(&p,2);
	imprimePilha(&p);
	
	reinicializarPilha(&p);
	return 0; 
}
