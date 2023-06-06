#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaest.h"

LISTA_MATRICULA* inicializar_estrutura(){
	int i;
	LISTA_MATRICULA *m = malloc(sizeof(LISTA_MATRICULA)) ;
	for(i=0; i<MAX-1;i++){
		m->turma[i].proximo = i+1;
	}
	m->turma[MAX-1].proximo = -1;
	m->inicio = -1;
	m->disponivel = 0;
	if(m != NULL){
		return m;
	}else{
		return NULL;
	}
}

int elementos_validos(LISTA_MATRICULA *m){
	int tam=0;
	int i = m->inicio;
	while(i != -1){
		tam++;
		i = m->turma[i].proximo;
	}
	return tam;
}

int cheia(LISTA_MATRICULA *m){
	if(elementos_validos(m) == MAX){
		return 1;
	}else{
		return 0;
	}
}
int vazia(LISTA_MATRICULA *m){
	if(elementos_validos(m) == 0){
		return 1;
	}else{
		return 0;
	}
}

int obterNo(LISTA_MATRICULA* m){
	int disp = m->disponivel;
	if(m->disponivel != -1){
		m->disponivel = m->turma[disp].proximo;
	}
	return disp;
}
int inserir_aluno(LISTA_MATRICULA *m, ALUNO novo_aluno){
	if(m->disponivel == -1){
		return 0;
	}
	int i = m->inicio;
	int pos_inserir = -1;
	while((i!=-1)&&(novo_aluno.matricula > m->turma[i].alunos.matricula)){
		pos_inserir = i;
		i = m->turma[i].proximo;
	}
	if((i!=-1)&&(novo_aluno.matricula == m->turma[pos_inserir].alunos.matricula)){
		return 0;
	}
	i = obterNo(m);
	m->turma[i].alunos = novo_aluno;
	if(pos_inserir == -1){
		m->turma[i].proximo = m->inicio;
		m->inicio = i;
	}else{
		m->turma[i].proximo = m->turma[pos_inserir].proximo;
		m->turma[pos_inserir].proximo = i;
	}
	return 1;
}
void exibir_elementos(LISTA_MATRICULA *m){
	int i = m->inicio;
	while(i != -1){
		printf("\nALUNO %d", i);
		printf("\nCODIGO: %d", m->turma[i].alunos.matricula);
		printf("\nNOME: %s", m->turma[i].alunos.nome);
		printf("\nIDADE: %d", m->turma[i].alunos.idade);
		i = m->turma[i].proximo;
	}
}
void alocarNo(LISTA_MATRICULA *m, int i){
	m->turma[i].proximo = m->disponivel;
	m->disponivel = i;
}
int excluir_aluno(LISTA_MATRICULA *m, int cod){
	int i = m->inicio;
	int anterior = -1;
	while(i!=-1 && m->turma[i].alunos.matricula < cod){
		anterior = i;
		i = m->turma[i].proximo;
	}
	if(i!=-1 && m->turma[i].alunos.matricula != cod){
		return 0;
	}
	if(anterior == -1){
		m->inicio = m->turma[i].proximo;
	}else{
		m->turma[anterior].proximo = m->turma[i].proximo;
	}
	alocarNo(m,i);
	return 1;
}
int alterar_matricula(LISTA_MATRICULA *m, int cod, int novocod){
	int i = m->inicio;
	while(i != -1 && m->turma[i].alunos.matricula < cod){
		i = m->turma[i].proximo;
	}
	if(i != -1 && m->turma[i].alunos.matricula == cod){
	    m->turma[i].alunos.matricula = novocod;
		return 1;
	}
	return 0;
}
void liberar_lista(LISTA_MATRICULA *m){
	free(m);
}

