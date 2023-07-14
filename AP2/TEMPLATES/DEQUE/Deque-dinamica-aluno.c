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

No* procurarNo(DEQUE* d, int pos){
	No* i = d->cabeca->proximo;
	int cont = 0;
	while(i != d->cabeca){
		if(cont == pos){
			return i;
		}
		cont++;
		i = i->proximo;
	}
	return NULL;
}

int excluirPosicao(DEQUE* d, int pos) {
	if(d->cabeca->proximo == d->cabeca){
		return 0;//lista vazia
	}
	No* no = procurarNo(d, pos-1);
	if (no != NULL) {
		no->anterior->proximo = no->proximo;
		no->proximo->anterior = no->anterior;
		free(no);
	}
	return 1;
}

int exibeDouI(DEQUE* d, int pos, char ordem){
	No* posaluno = procurarNo(d, pos-1); //recebo em ordem normal, envio contando do zero
	if(posaluno == NULL){
		return 0;
	}
	No* i = posaluno;
	if(ordem == 'd'){
		while( i != d->cabeca ){
		    printf(" %s ", i->aluno.nome);
			printf("\n");
			i = i->proximo;
		}
	}
	if(ordem == 'i'){
		while( i != d->cabeca ){
		    printf(" %s ", i->aluno.nome);
			printf("\n");
			i = i->anterior;
		}
	}
	return 1;
}

int main(){
	DEQUE d;
	inicializarDeque(&d);
	ALUNO a;
	strcpy(a.nome, "1 Andrey");
	inserirInicio(&d, a);
	strcpy(a.nome, "2 Beatriz");
	inserirFim(&d, a);
	strcpy(a.nome, "3 Carlos");
	inserirFim(&d, a);
	strcpy(a.nome, "4 Danilo");
	inserirFim(&d, a);
	strcpy(a.nome, "5 Emanuelle Marreira");
	inserirFim(&d, a);
	strcpy(a.nome, "6 Guilherme");
	inserirFim(&d, a);
	strcpy(a.nome, "7 Italo");
	inserirFim(&d, a);
	strcpy(a.nome, "8 Joao");
	inserirFim(&d, a);
	strcpy(a.nome, "9 Luigi");
	inserirFim(&d, a);
	strcpy(a.nome, "10 William");
	inserirFim(&d, a);
	//excluirInicio(&d);
	//excluirFim(&d);
	//exibeDouI(&d, 5, 'd');
	//exibeDouI(&d, 5, 'i');
	excluirPosicao(&d, 5);
	imprimirDeque(&d);
	reinicializarDeque(&d);
	
	return 0;
}
