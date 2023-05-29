#ifndef TURMA_H_INCLUDED
#define TURMA_H_INCLUDED
#define MAX 50
typedef struct{
	int cod;
	char nome[100];
	int idade;
	float coef;
}ALUNO;
typedef struct{
	int qtd;
	ALUNO turma[MAX];
}TURMA;

TURMA* criar_turma();
int inserir_alunos(TURMA *minhaturma);
int busca_sequencial(TURMA *minhaturma, int valor);
int busca_binaria_recursiva(TURMA *minhaturma, int valor, int primeiro, int ultimo);
int impressao_cod_nome(TURMA *minhaturma);
void liberar_memoria(TURMA *minhaturma);

#endif

