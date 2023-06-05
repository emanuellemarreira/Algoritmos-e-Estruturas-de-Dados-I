#ifndef LISTAEST_H_INCLUDED
#define LISTAEST_H_INCLUDED
#define MAX 100
typedef struct{
	int matricula;
	char nome[100];
	int idade;
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

LISTA_MATRICULA* inicializar_estrutura();
int elementos_validos(LISTA_MATRICULA *m);
int obterNo(LISTA_MATRICULA* m);
int inserir_aluno(LISTA_MATRICULA *m, ALUNO novo_aluno);
int cheia(LISTA_MATRICULA *m);
int vazia(LISTA_MATRICULA *m);
void exibir_elementos(LISTA_MATRICULA *m);
void alocarNo(LISTA_MATRICULA *m, int i);
int alterar_matricula(LISTA_MATRICULA *m, int cod, int novocod);
int excluir_aluno(LISTA_MATRICULA *m, int cod);

#endif
