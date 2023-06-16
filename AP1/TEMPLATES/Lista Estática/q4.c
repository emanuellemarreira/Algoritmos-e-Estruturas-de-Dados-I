#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
	int matricula;
	char nome[100];
	int idade;
	int filhos;
}ALUNO;

typedef struct{ 
	ALUNO alunos;
	int proximo;
}ELEMENTO;

typedef struct{
	ELEMENTO turma[MAX];
	int inicio;
	int disponivel;
}LISTA_MATRICULA;

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

int buscarMaiorIdade(LISTA_MATRICULA *m) {
    int i = m->inicio;
    int maioridade = m->turma[m->inicio].alunos.idade;
    //Aluno maior = m->turma[m->inicio];
    while (i != -1) {
        if (m->turma[i].alunos.idade > maioridade) {
		    return i;
		}
        i = m->turma[i].proximo;
    }
    
    return -1; // Aluno não encontrado
}


int main(){
    LISTA_MATRICULA *m = inicializar_estrutura();
	if(m == NULL){
		printf("erro na alocacao");
	}
	ALUNO aluno1;
    aluno1.matricula = 1;
    aluno1.filhos = 0;
    aluno1.idade = 21;
    strcpy(aluno1.nome, "Daniel");

    ALUNO aluno2;
    aluno2.matricula = 2;
    aluno2.filhos = 0;
    aluno2.idade = 19;
    strcpy(aluno2.nome, "Suzan");

    ALUNO aluno3;
    aluno3.matricula = 3;
    aluno3.filhos = 1;
    aluno3.idade = 24;
    strcpy(aluno3.nome, "Danilo");
    
    ALUNO aluno4;
    aluno4.matricula = 4;
    aluno4.filhos = 0;
    aluno4.idade = 18;
    strcpy(aluno4.nome, "Camila");

    ALUNO aluno5;
    aluno5.matricula = 5;
    aluno5.filhos = 1;
    aluno5.idade = 22;
    strcpy(aluno5.nome, "Carlos");
    
    inserir_aluno(m, aluno1);
    inserir_aluno(m, aluno2);
    inserir_aluno(m, aluno3);
    inserir_aluno(m, aluno4);
    inserir_aluno(m, aluno5);
    int maior = buscarMaiorIdade(m);
    printf("\nAluno com maior idade\n");
    printf("%d | %s  %d   %d",m->turma[maior].alunos.matricula, m->turma[maior].alunos.nome, m->turma[maior].alunos.idade, m->turma[maior].alunos.filhos);

}










