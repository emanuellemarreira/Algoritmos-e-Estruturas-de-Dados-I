#include <stdio.h>
#include <stdlib.h>
#include "listaiterativorecursivo.h"

int main(){
	LISTA *lista1, *lista2;
	int valor, soma, acumula = 0, acumulaprod = 1, produto;
	lista1 = criar_lista();
	inserir_elementos_desordem(lista1);
	imprimir_elementos_iterativo(lista1);
	printf("\nIMPRESSAO DE MODO RECURSIVO\n");
	imprimir_elementos_recursivo(lista1, 0);
	printf("\nInforme valor para procurar na lista 1: ");
	scanf("%d", &valor);
	busca_sequencial_desordem(lista1, valor);
	lista2 = criar_lista();
	inserir_elementos_ordem(lista2);
	imprimir_elementos_iterativo(lista2);
	printf("\n\nIMPRESSAO DE MODO RECURSIVO\n\n");
	imprimir_elementos_recursivo(lista2, 0);
	printf("\nInforme valor para procurar na lista 2: ");
	scanf("%d", &valor);
	busca_sequencial_desordem(lista2, valor);
	busca_sequencial_ordem(lista2, valor);
	busca_binaria_iterativa(lista2, valor);
	int primeiro=0, meio=-1, ultimo = lista2->n-1;
	printf("\nBUSCA BINARIA RECURSIVA\n");
	int comp=0;
	busca_binaria_recursiva(lista2, valor, primeiro, ultimo, comp);
	buscar_maior_iterativo(lista1);
	buscar_menor_iterativo(lista1);
	printf("\nBUSCA MAIOR NUMERO MODO RECURSIVO\n");
	buscar_maior_recursivo(lista1, 0, lista1->num[0]);
	printf("\nBUSCA MENOR NUMERO MODO RECURSIVO\n");
	buscar_menor_recursivo(lista1, 0, lista1->num[0]);
	soma = soma_elementos_iterativo(lista1);
	printf("\nSOMA ELEMENTOS ITERATIVO = %d", soma);
	soma = soma_elementos_recursivo(lista1, 0, acumula);
	printf("\nSOMA ELEMENTOS RECURSIVO = %d", soma);
	produto = produto_elementos_iterativo(lista1);
	printf("\nPRODUTO ELEMENTOS ITERATIVO = %d", produto);
	produto = produto_elementos_recursivo(lista1, 0, acumulaprod);
	printf("\nPRODUTO ELEMENTOS RECURSIVO = %d", produto);
	liberar_memoria(lista1);
	liberar_memoria(lista2);
	return 0;
}
