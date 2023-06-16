#include <stdio.h>
#include <stdlib.h>
#include "listaiterativorecursivo.h"

LISTA* criar_lista(){
	LISTA *minhalista = malloc(sizeof(LISTA));
	printf("\nQuantidade de elementos do vetor: ");
	scanf("%d", &minhalista->n);
	while(minhalista->n<0){
		printf("\nINVALIDO, digite novamente: ");
		scanf("%d", &minhalista->n);
	}
	minhalista->num=malloc(minhalista->n*sizeof(int));
	return minhalista;
}

int inserir_elementos_desordem(LISTA *minhalista){
	int i;
	if (minhalista == NULL){
		return 0;
	}
	printf("\nInserindo elementos de forma desordenada no vetor\n");
		for(i=0;i<minhalista->n;i++){
			printf("\nlista[%d] = ", i);
			scanf("%d", &minhalista->num[i]);
		}
	return 1;
}

int inserir_elementos_ordem(LISTA *minhalista){
	int i;
	if (minhalista == NULL){
		return 0;
	}
	printf("\nInserindo elementos de forma ordenada no vetor\n");
	for(i=0;i<minhalista->n;i++){
		printf("\nlista[%d] = ", i);
		scanf("%d", &minhalista->num[i]);
		if(i>0){
			while(minhalista->num[i]< minhalista->num[i-1]){
				printf("\nDIGITE UM VALOR MAIOR: ");
				scanf("%d", &minhalista->num[i]);		
			}
		}
	}
	return 1;
}
int imprimir_elementos_iterativo(LISTA *minhalista){
	int i;
	if (minhalista == NULL){
		return 0;
	}
	printf("\nIMPRESSAO DE MODO ITERATIVO\n");
	for(i=0;i<minhalista->n;i++){
		printf("lista[%d] = %d\n", i, minhalista->num[i]);
	}
	return 1;
}

int imprimir_elementos_recursivo(LISTA *minhalista, int i){
	if (minhalista == NULL){
		return 0;
	}
	if(i==minhalista->n){
		return 1;
	}
	printf("\nlista[%d] = %d", i, minhalista->num[i]);
	imprimir_elementos_recursivo(minhalista, i+1);
	return 1;
}

int busca_sequencial_desordem(LISTA *minhalista, int valor){
	if (minhalista == NULL){
		return 0;
	}
	int i, comp = 0;
	printf("\nBUSCA SEQUENCIAL - lista desordenada\n");
	for(i=0; i<minhalista->n;i++){
		comp++;
		if(minhalista->num[i] == valor){
			printf("\nvalor encontrado em lista[%d]", i);
			printf("\nquantidade de comparacoes necessarias: %d\n", comp);
			return 1;
		}
	}
	printf("\nvalor nao encontrado!");
	return 1;
}
int busca_sequencial_ordem(LISTA *minhalista, int valor){
	if (minhalista == NULL){
		return 0;
	}
	int i, comp=0;
	printf("\nBUSCA SEQUENCIAL - lista ordenada\n");
	for(i=0; i<minhalista->n;i++){
		comp++;
		if(minhalista->num[i]>=valor){
			comp++;
			if(minhalista->num[i] == valor){
			    printf("\nvalor encontrado em lista[%d]", i);
			    printf("\nquantidade de comparacoes necessarias: %d\n", comp);
			    return 1;
		    }
		}
	}
	printf("\nvalor nao encontrado!");
	return 1;
}
int busca_binaria_iterativa(LISTA *minhalista, int valor){
	if (minhalista == NULL){
		return 0;
	}
	int i, primeiro=0, meio=-1, ultimo=minhalista->n-1, comp=0;
	printf("\nBUSCA BINARIA ITERATIVA\n");
	while(primeiro<=ultimo){
		meio = primeiro + (ultimo-primeiro)/2;
		comp++;
		if(valor == minhalista->num[meio]){
			printf("\nvalor encontrado em lista[%d]", meio);
			printf("\nquantidade de comparacoes necessarias: %d\n", comp);
			return 1;
		}else{
			comp++;
			if(valor > minhalista->num[meio]){
				primeiro = meio+1;
			}else{
				comp++;
				ultimo = meio-1;
			}
		}
	}
	printf("\nvalor nao encontrado!");
	return 1;
}
int busca_binaria_recursiva(LISTA *minhalista, int valor, int primeiro, int ultimo, int comp){
	if (minhalista == NULL){
		return 0;
	}
	comp++;
	if(primeiro>ultimo){
		printf("\nvalor nao encontrado!"); 
		return 1;
	}
	int meio = (primeiro + ultimo)/2;
	comp++;
	if(valor == minhalista->num[meio]){
		printf("\nvalor encontrado em lista[%d]", meio);
		printf("\nquantidade de comparacoes necessarias: %d\n", comp);
		return 1;
	}
	comp++;
	if(valor < minhalista->num[meio]){
	    busca_binaria_recursiva(minhalista, valor, primeiro, meio-1, comp);
	}else{
		comp++;
		busca_binaria_recursiva(minhalista, valor, meio+1, ultimo, comp);
	}
	return 1;
}
int buscar_maior_iterativo(LISTA *minhalista){
	int i, maior;
	if (minhalista == NULL){
		return 0;
	}
	printf("\nBUSCA MAIOR NUMERO MODO ITERATIVO\n");
	for(i=0;i<minhalista->n;i++){
		if(i==0){
			maior = minhalista->num[i];
		}else{
			if(minhalista->num[i]>maior){
				maior = minhalista->num[i];
			}
		}
	}
	printf("\nMAIOR NUMERO: %d", maior);
	return 1;
}
int buscar_menor_iterativo(LISTA *minhalista){
	int i, menor;
	if (minhalista == NULL){
		return 0;
	}
	printf("\nBUSCA MENOR NUMERO MODO ITERATIVO\n");
	for(i=0;i<minhalista->n;i++){
		if(i==0){
			menor = minhalista->num[i];
		}else{
			if(minhalista->num[i]<menor){
				menor = minhalista->num[i];
			}
		}
	}
	printf("\nMENOR NUMERO: %d", menor);
	return 1;
}

int buscar_maior_recursivo(LISTA *minhalista, int i, int maior){
	if (minhalista == NULL){
		return 0;
	}
	if(i == minhalista->n){
		printf("\nMAIOR NUMERO: %d", maior);
		return 1;
	}
	if(minhalista->num[i] > maior){
		maior = minhalista->num[i];
	}
	buscar_maior_recursivo(minhalista, i+1, maior);
	return 1;
}
int buscar_menor_recursivo(LISTA *minhalista, int i, int menor){
	if (minhalista == NULL){
		return 0;
	}
	if(i == minhalista->n){
		printf("\nMENOR NUMERO: %d", menor);
		return 1;
	}
	if(minhalista->num[i] < menor){
		menor = minhalista->num[i];
	}
	buscar_menor_recursivo(minhalista, i+1, menor);
	return 1;
}
int soma_elementos_iterativo (LISTA *minhalista){
	if (minhalista == NULL){
		return 0;
	}
	int i, soma = 0;
	for(i=0;i<minhalista->n;i++){
		soma += minhalista->num[i];
	}
	return soma;
}
int soma_elementos_recursivo (LISTA *minhalista, int i, int acumula){
	if (minhalista == NULL){
		return 0;
	}
	if(i == minhalista->n){
		return acumula;
	}
	int soma = minhalista->num[i]+acumula;
	return soma_elementos_recursivo(minhalista, i+1, soma);
}
int produto_elementos_iterativo (LISTA *minhalista){
	if (minhalista == NULL){
		return 0;
	}
	int i, prod = 1;
	for(i=0;i<minhalista->n;i++){
		prod *= minhalista->num[i];
	}
	return prod;
}
int produto_elementos_recursivo (LISTA *minhalista, int i, int acumulaprod){
	if (minhalista == NULL){
		return 0;
	}
	if(i == minhalista->n){
		return acumulaprod;
	}
	int prod = minhalista->num[i]*acumulaprod;
	return produto_elementos_recursivo(minhalista, i+1, prod);
}
void liberar_memoria(LISTA *minhalista){
	free(minhalista);
}


