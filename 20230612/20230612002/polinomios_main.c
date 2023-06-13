#include <stdio.h>
#include <stdlib.h>
#include "polinomios.h"

int main(){
    Lista polin1, polin2, *s;
    s = malloc(sizeof(Lista));
    printf("\npolinomio 1: \n");
	inicializarLista(&polin1);
	inserir(&polin1, 0, -5);//exp coef
	inserir(&polin1, 2, 4);
	inserir(&polin1, 1, -10);
	imprimir(&polin1);
	
	inicializarLista(&polin2);
	printf("\npolinomio 2: \n");
	inserir(&polin2, 0, 12);//exp coef
	inserir(&polin2, 2, 0);
	inserir(&polin2, 1, 6);
	imprimir(&polin2);
	s = somapolinomio(&polin1, &polin2);
	printf("\npolinomio soma: \n");
	imprimir(s);
    return 0;
}
