#include <stdio.h>
#include <stdlib.h>
#include "listadin.h"

int main(){
	Lista l1;
	inicializarLista(&l1);
	printf("\nQtd de elementos validos: %d", qtdElemValidos(&l1));
	inserir(&l1, 3);
	inserir(&l1, 2);
	inserir(&l1, 1);
	inserir(&l1, 4);
	excluir(&l1, 2);
	imprimir(&l1);
	printf("\nQtd de elementos validos: %d", qtdElemValidos(&l1));
	reinicializar(&l1);
	printf("\nQtd de elementos validos: %d", qtdElemValidos(&l1));
	return 0;
}
