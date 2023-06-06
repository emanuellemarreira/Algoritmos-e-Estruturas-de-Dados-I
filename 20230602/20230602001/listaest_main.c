#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaest.h"
int main(int argc, char *argv[]) {
	LISTA_MATRICULA *m = inicializar_estrutura();
	if(m == NULL){
		printf("erro na alocacao");
	}
	printf("\n--------ANTES--------\n");
	printf("\nelem validos: %d", elementos_validos(m));
	printf("\nvazia: %d", vazia(m));
	printf("\ncheia: %d", cheia(m));
	ALUNO a;
	a.matricula=34;
	strcpy(a.nome, "alex");
	a.idade=19;
	inserir_aluno(m,a);
	a.matricula=28;
	strcpy(a.nome, "bea");
	a.idade=20;
	inserir_aluno(m,a);
	a.matricula=3;
	strcpy(a.nome, "carol");
	a.idade=21;
	inserir_aluno(m,a);
	printf("\n-----DPS DE ADD--------\n");
	printf("\nelem validos: %d", elementos_validos(m));
	printf("\nvazia: %d", vazia(m));
	printf("\ncheia: %d", cheia(m));
	exibir_elementos(m);
	printf("\n------EXCLUINDO--------\n");
	excluir_aluno(m,28);
	exibir_elementos(m);
	printf("\n------ALTERANDO--------\n");
	alterar_matricula(m,34,1234);
	exibir_elementos(m);
	liberar_lista(m);
	return 0;
}
