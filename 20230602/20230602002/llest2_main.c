#include <stdio.h>
#include <stdlib.h>
#include "llest2.h"
int main(int argc, char *argv[]) {
    Lista l, la, lb;
	l.inicio = NULL;
	l.fim = NULL;
	inserirFim(&l,1);
	inserirFim(&l,2);
	inserirFim(&l,3);
	inserirFim(&l,4);
	printf("\nLISTA 1\n");
	imprimir(&l);
	la.inicio = NULL;
	la.fim = NULL;
	a(&l, &la);
	printf("\n\nLISTA 2\n");
	imprimir(&la);
	lb.inicio = NULL;
	lb.fim = NULL;
	b(&l, &lb);
	printf("\n\nLISTA 3\n");
	imprimir(&lb);	
	return 0;
}
