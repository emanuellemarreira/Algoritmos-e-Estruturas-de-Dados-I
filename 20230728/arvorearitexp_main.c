#include <stdio.h>
#include <stdlib.h>
#include "arvorearitexp"
int main() {
	ARVORE a;
	inicializarArvore(&a);
	a.raiz = adicionarArvore(a.raiz, 'a');
	a.raiz = adicionarArvore(a.raiz, '*');
	a.raiz = adicionarArvore(a.raiz, 'b');
	a.raiz = adicionarArvore(a.raiz, '-');
	a.raiz = adicionarArvore(a.raiz, 'c');
	a.raiz = adicionarArvore(a.raiz, '/');
	a.raiz = adicionarArvore(a.raiz, 'd');

	printf("\n=Pre ordem==\n");
	pre_ordem(a.raiz);
	printf("\n=in ordem==\n");
	in_ordem(a.raiz);
	printf("\n=pos ordem==\n");
	pos_ordem(a.raiz);

	return 0;
}

