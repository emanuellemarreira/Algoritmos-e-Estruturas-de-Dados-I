#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dequealuno.h"


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
	exibeDouI(&d, 5, 'i');
	//imprimirDeque(&d);
	reinicializarDeque(&d);
	
	return 0;
}
