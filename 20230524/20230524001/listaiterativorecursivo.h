#ifndef LISTAITERATIVORECURSIVO_H_INCLUDED
#define LISTAITERATIVORECURSIVO_H_INCLUDED

typedef struct{
	int *num;
	int n;
}LISTA;

LISTA* criar_lista();
int inserir_elementos_desordem(LISTA *minhalista);
int inserir_elementos_ordem(LISTA *minhalista);
int imprimir_elementos_iterativo(LISTA *minhalista);
int imprimir_elementos_recursivo(LISTA *minhalista, int i);
int busca_sequencial_desordem(LISTA *minhalista, int valor);
int busca_sequencial_ordem(LISTA *minhalista, int valor);
int busca_binaria_iterativa(LISTA *minhalista, int valor);
int busca_binaria_recursiva(LISTA *minhalista, int valor, int primeiro, int ultimo, int comp);
int buscar_maior_iterativo(LISTA *minhalista);
int buscar_menor_iterativo(LISTA *minhalista);
int buscar_maior_recursivo(LISTA *minhalista, int i, int maior);
int buscar_menor_recursivo(LISTA *minhalista, int i, int menor);
int soma_elementos_iterativo (LISTA *minhalista);
int soma_elementos_recursivo (LISTA *minhalista, int i, int acumula);
int produto_elementos_iterativo (LISTA *minhalista);
int produto_elementos_recursivo (LISTA *minhalista, int i, int acumulaprod);
void liberar_memoria(LISTA *minhalista);

#endif
