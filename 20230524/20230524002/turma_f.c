#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"
#define MAX 50

TURMA* criar_turma(){
	TURMA *minhaturma = malloc(sizeof(TURMA));
	printf("\nQuantidade de alunos da turma: ");
	scanf("%d", &minhaturma->qtd);
	return minhaturma;
}

int inserir_alunos(TURMA *minhaturma){
	int i;
	if(minhaturma==NULL){
		return 0;
	}
	for(i=0;i<minhaturma->qtd;i++){
		printf("\nInsira codigo do aluno %d: ", i+1);
		scanf("%d", &minhaturma->turma[i].cod);
		printf("\nInsira nome do aluno %d: ", i+1);
		scanf(" %100[^\n]", minhaturma->turma[i].nome);
		printf("\nInsira idade do aluno %d: ", i+1);
		scanf("%d", &minhaturma->turma[i].idade);
		printf("\nInsira coeficiente do aluno %d: ", i+1);
		scanf("%f", &minhaturma->turma[i].coef);
	}

	return 1;
}

int busca_sequencial(TURMA *minhaturma, int valor){
	if (minhaturma == NULL){
		return 0;
	}
	int i;
	for(i=0; i<minhaturma->qtd;i++){
		if(minhaturma->turma[i].cod == valor){
			printf("\n-Aluno encontrado por busca sequencial-\n");
			printf("\ncodigo = %d", minhaturma->turma[i].cod);
			printf("\nnome = %s", minhaturma->turma[i].nome);
			printf("\nidade = %d", minhaturma->turma[i].idade);
			printf("\ncoeficiente = %.2f", minhaturma->turma[i].coef);
			return 1;
		}
	}
	printf("\nAluno nao encontrado!\n");
	return 1;
}
int busca_binaria_recursiva(TURMA *minhaturma, int valor, int primeiro, int ultimo){
	if (minhaturma == NULL){
		return 0;
	}
	if(primeiro>ultimo){
		printf("\nAluno nao encontrado!\n"); 
		return 1;
	}
	int meio = (primeiro + ultimo)/2;
	if(valor == minhaturma->turma[meio].cod){
		printf("\n-Aluno encontrado por busca binaria recursiva-\n");
		printf("\ncodigo = %d", minhaturma->turma[meio].cod);
		printf("\nnome = %s", minhaturma->turma[meio].nome);
		printf("\nidade = %d", minhaturma->turma[meio].idade);
		printf("\ncoeficiente = %.2f", minhaturma->turma[meio].coef);
		return 1;
	}
	if(valor < minhaturma->turma[meio].cod){
	    busca_binaria_recursiva(minhaturma, valor, primeiro, meio-1);
	}else{
		busca_binaria_recursiva(minhaturma, valor, meio+1, ultimo);
	}
	return 1;
}

int impressao_cod_nome(TURMA *minhaturma){
	if (minhaturma == NULL){
		return 0;
	}
	
	int i;
	for(i=0;i<minhaturma->qtd;i++){
		printf("\n  %d  |  codigo: %d  |  nome: %s \n", i+1, minhaturma->turma[i].cod, minhaturma->turma[i].nome);
	}
	return 1;
}

void liberar_memoria(TURMA *minhaturma){
	free(minhaturma);
}


