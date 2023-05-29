#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"
#define MAX 50

int main(){
    TURMA *turma1;
    int procurar;
	turma1 = criar_turma();
	inserir_alunos(turma1);
	printf("\nInforme o codigo do aluno que deseja procurar: ");
	scanf("%d", &procurar);
	printf("\nBusca sequencial\n");
	busca_sequencial(turma1, procurar);
	printf("\nBusca binaria recursiva\n");
	busca_binaria_recursiva(turma1, procurar, 0, turma1->qtd);
	impressao_cod_nome(turma1);
	liberar_memoria(turma1);
	
	return 0;
}
