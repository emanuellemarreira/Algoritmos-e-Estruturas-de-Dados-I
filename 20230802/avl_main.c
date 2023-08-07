#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
	ARVORE a;
	inicializarArvore(&a);
	adicionaAVL(&a, 1);
	adicionaAVL(&a, 2);
	adicionaAVL(&a, 3);
	adicionaAVL(&a, 4);
	adicionaAVL(&a, 5);
	adicionaAVL(&a, 6);
	adicionaAVL(&a, 7);
	adicionaAVL(&a, 15);
	adicionaAVL(&a, 14);
	adicionaAVL(&a, 13);
	adicionaAVL(&a, 12);
	adicionaAVL(&a, 11);
	adicionaAVL(&a, 10);
	adicionaAVL(&a, 9);
	adicionaAVL(&a, 8);
	printf("\n=in ordem==\n");
	in_ordem(a.raiz);
	return 0;
}
