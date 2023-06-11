#include <stdio.h>
#include <stdlib.h>
#define "ldin3.h"
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
	copiarlista(&l, &la);
	printf("\n\nLISTA 2\n");
	imprimir(&la);
	la.inicio = NULL;//meio que pra esvaziar a lista
	la.fim = NULL;
	inserirFim(&la,5);
	inserirFim(&la,6);
	concatenar(&l,&la);
	printf("\n\nLISTA 1 concatenada\n");
	imprimir(&l);
	la.inicio = NULL;//meio que pra esvaziar a lista
	la.fim = NULL;
	inserirFim(&la,11);
	inserirFim(&la,22);
	inserirFim(&la,33);
	inserirFim(&la,44);
	inserirFim(&la,55);
	lb.inicio = NULL;
	lb.fim = NULL;
	printf("\n\nLISTA 1 INTERCALADA\n");
	intercalar(&l,&la,&lb);
	imprimir(&lb);
	return 0;
}
