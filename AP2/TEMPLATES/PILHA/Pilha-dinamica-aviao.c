#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct{
	int cod;
	char nome[MAX];
}AVIAO;

typedef struct No{
	AVIAO aviao;
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

int inserirHangar(PILHA* p, AVIAO novo_aviao){//inserir no inicio
	No* i = malloc(sizeof(No));
	if(i == NULL){
		return 0;
	}
	i->aviao = novo_aviao;
	i->proximo = p->topo;
	p->topo = i;
	return 1;
}
int excluirHangar(PILHA* p){//excluir do inicio
	if(p->topo == NULL){
		return 0;//se for vazia
	}
	No* i = p->topo;
	p->topo = p->topo->proximo;
	free(i);
	return 1;
}
int excluirHangarPelaPosicao(PILHA* p, int posicao){
	if(posicao-1 == 0){//se for do inicio
		excluirHangar(p);
		return 1;
	}
	No* i = p->topo;
	int contpos = 0;
	PILHA aux;
	inicializarPilha(&aux);
	while(i != NULL && contpos < posicao-1){
		inserirHangar(&aux, i->aviao);
		excluirHangar(p);
		i = i->proximo;
		contpos++;
	}
	excluirHangar(p);//tirando o elemento que eu quero tirar depois de tirar todos os que estavam em cima dele
	i = aux.topo;
	while(i != NULL){
		inserirHangar(p, i->aviao);
		i = i->proximo;
	}
	reinicializarPilha(&aux);
	return 1;
}


void imprimePilha(PILHA *p){
	No* i = p->topo;
	while(i != NULL){
		printf(" %d | %s", i->aviao.cod, i->aviao.nome);
		printf("\n");
		i = i->proximo;
	}
}

AVIAO primeiroAviao(PILHA* p){
	return p->topo->aviao;
}

AVIAO retornaAviaoNaPosicao(PILHA* p, int posicao) {
	No* i = p->topo;
	int cont = 0;
	while (i != NULL && cont < posicao-1) {
		i = i->proximo;
		cont++;
	}
	if (i != NULL) {
		return i->aviao;
	} else {
		AVIAO aviao_vazio; // Avião com dados vazios
		aviao_vazio.cod = -1;
		strcpy(aviao_vazio.nome, "");
		return aviao_vazio;
	}
}


int main(){
	PILHA p;
	inicializarPilha(&p);
	
	AVIAO a;
	a.cod = 13;
	strcpy(a.nome, "1 GOL");
	inserirHangar(&p, a);
	a.cod = 20;
	strcpy(a.nome, "2 AZUL");
	inserirHangar(&p, a);
	a.cod = 22;
	strcpy(a.nome, "3 AMERICAN AIRLINES");
	inserirHangar(&p, a);
	a.cod = 123;
	strcpy(a.nome, "4 AIR FORCE");
	inserirHangar(&p, a);
	a.cod = 222;
	strcpy(a.nome, "5 AIR JORDAN");
	inserirHangar(&p, a);
	
	printf("\n==avioes na pilha de espera==\n");
	imprimePilha(&p);
	
	AVIAO primeiroaviao = primeiroAviao(&p);
	printf("\ndados do primeiro aviao da pilha: %d | %s ", primeiroaviao.cod, primeiroaviao.nome);
	AVIAO aviao_posicao = retornaAviaoNaPosicao(&p, 2); // Retorna o avião na posição 2
	if (aviao_posicao.cod != -1) {
		printf("\nDados do aviao na posicao 2: %d | %s\n", aviao_posicao.cod, aviao_posicao.nome);
	} else {
		printf("Nao ha aviao na posicao 2.\n");
	}
	printf("\nDecolagem: \n");
	//excluirHangar(&p);
	excluirHangarPelaPosicao(&p,3);
	imprimePilha(&p);
	
	reinicializarPilha(&p);
	return 0;
}
