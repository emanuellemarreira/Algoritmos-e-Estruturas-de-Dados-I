#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct{
	char nome[MAX];
}ALUNO;

typedef struct No{
    ALUNO aluno;
	struct No* anterior;
	struct No* proximo; 	
}No;
//circular
typedef struct{
	No* cabeca;
}DEQUE;

void inicializarDeque(DEQUE *d){
	d->cabeca = malloc(sizeof(No));
	d->cabeca->anterior = d->cabeca;
	d->cabeca->proximo = d->cabeca;
}

void reinicializarDeque(DEQUE *d){
	No* apagar;
	No* no = d->cabeca->proximo;
	while( no != d->cabeca ){
		apagar = no;
		no = no->proximo;
		free(apagar);
	}
	d->cabeca->anterior = d->cabeca;
	d->cabeca->proximo = d->cabeca;
}

int inserirInicio(DEQUE *d, ALUNO novo_aluno){
	No* i = malloc(sizeof(No));
	i->aluno = novo_aluno;
	i->proximo = d->cabeca->proximo;
	i->anterior = d->cabeca;
	d->cabeca->proximo->anterior = i;
	d->cabeca->proximo = i;
	return 1;
}

int inserirFim(DEQUE* d, ALUNO novo_aluno){
	No* i = malloc(sizeof(No));
	i->aluno = novo_aluno;
	i->proximo = d->cabeca;
	i->anterior = d->cabeca->anterior;
	d->cabeca->anterior->proximo = i;
	d->cabeca->anterior = i;
	return 1;
}

int excluirInicio(DEQUE* d){
	if(d->cabeca->proximo == d->cabeca){
		return 0;//lista vazia
	}
		No* i = d->cabeca->proximo;
		d->cabeca->proximo = i->proximo;
		i->proximo->anterior = d->cabeca;
		free(i);
		return 1;
}

int excluirFim(DEQUE* d){
	if(d->cabeca->proximo == d->cabeca){
		return 0;//lista vazia
	}
	No* i = d->cabeca->anterior;//ou seja recebe o ultimo
	d->cabeca->anterior = i->anterior;
	i->anterior->proximo = d->cabeca;
	free(i);
	return 1;
}

No* returnInicio(DEQUE* d){
	return d->cabeca->proximo;
}

No* returnFim(DEQUE* d){
	return d->cabeca->anterior;
}

void imprimirDeque(DEQUE* d){
	No* i = d->cabeca->proximo;
	while( i != d->cabeca ){
		printf(" %s ", i->aluno.nome);
		printf("\n");
		i = i->proximo;
	}
}

int main(){
	DEQUE d;
	inicializarDeque(&d);
	ALUNO a;
	strcpy(a.nome, "andrey");
	inserirInicio(&d, a);
	ALUNO b;
	strcpy(b.nome, "beatriz");
	inserirFim(&d, b);
	imprimirDeque(&d);
	reinicializarDeque(&d);
	
	return 0;
}
