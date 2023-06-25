#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaaviao.h"

int main(){
	FILA f;
	inicializarFila(&f);
	
	AVIAO a;
	a.id = 13;
	strcpy(a.nome, "GOL");
	inserirListadeEspera(&f, a);
	a.id = 20;
	strcpy(a.nome, "AZUL");
	inserirListadeEspera(&f, a);
	a.id = 22;
	strcpy(a.nome, "AMERICAN AIRLINES");
	inserirListadeEspera(&f, a);
	
	printf("\n==avioes na lista de espera==\n");
	imprimeFila(&f);
	
	printf("\nquantidade de avioes na lista de espera: %d", qtdNaFila(&f));
	
	AVIAO primeiroaviao = primeiroAviao(&f);
	printf("\ndados do primeiro aviao da fila: %d | %s ", primeiroaviao.id, primeiroaviao.nome);
	
	printf("\nDecolagem do primeiro aviao da fila: \n");
	excluirDaListadeEspera(&f);
	imprimeFila(&f);
	reinicializarFila(&f);
	return 0;
}
