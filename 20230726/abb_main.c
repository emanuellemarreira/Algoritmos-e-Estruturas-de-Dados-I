#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main(){
	ARVORE a;
	inicializarArvore(&a);
	adicionarArvore(&a, 24);
	adicionarArvore(&a, 10);
	adicionarArvore(&a, 32);
	adicionarArvore(&a, 5);
	adicionarArvore(&a, 12);
	adicionarArvore(&a, 29);
	adicionarArvore(&a, 35);
	imprimirArvore(&a);
	No* busca = malloc(sizeof(No));
	busca = buscar(&a, 14);
	printf("\nbusca\nendereco:%p  esq:%p  dir:%p  num:%d", busca, busca->esquerda, busca->direita, busca->valor);
	printf("\nquantidade de nos: %d", contarNos(a.raiz));
	printf("\n=Pre ordem==\n");
	pre_ordem(a.raiz);
	printf("\n=in ordem==\n");
	in_ordem(a.raiz);
	printf("\n=pos ordem==\n");
	pos_ordem(a.raiz);
	return 0;
}
