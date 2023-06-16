#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct{ 
	int valor;
	int proximo;
}ELEMENTO;

typedef struct{
	ELEMENTO elementos[MAX];
	int inicio;
	int disponivel;
}LISTA;

LISTA* inicializar_estrutura(){
	int i;
	LISTA *m = malloc(sizeof(LISTA)) ;
	for(i=0; i<MAX-1;i++){
		m->elementos[i].proximo = i+1;
	}
	m->elementos[MAX-1].proximo = -1;
	m->inicio = -1;
	m->disponivel = 0;
	if(m != NULL){
		return m;
	}else{
		return NULL;
	}
}
int obterNo(LISTA * m){
	int disp = m->disponivel;
	if(m->disponivel != -1){
		m->disponivel = m->elementos[disp].proximo;
	}
	return disp;
}
void inserirFim(LISTA *lista, int novovalor) {
    int novoIndice = obterNo(lista);
    ELEMENTO *novo = &(lista->elementos[novoIndice]);
	lista->elementos[novoIndice].valor = novovalor;
	lista->elementos[novoIndice].proximo = -1;

    if (lista->inicio == -1) {
        lista->inicio = novoIndice;
    } else {
        ELEMENTO *ultimo = &(lista->elementos[lista->inicio]);
        while (ultimo->proximo != -1) {
            ultimo = &(lista->elementos[ultimo->proximo]);
        }
        ultimo->proximo = novoIndice;
    }
}
void alocarNo(LISTA *m, int i){
	m->elementos[i].proximo = m->disponivel;
	m->disponivel = i;
}
int excluir(LISTA *m, int elem) {
    int i = m->inicio;
    int anterior = -1;
    
    while (i != -1 && m->elementos[i].valor != elem) {
        anterior = i;
        i = m->elementos[i].proximo;
    }
    
    if (i == -1) {
        return 0; // Elemento não encontrado na lista
    }
    
    if (anterior == -1) {
        m->inicio = m->elementos[i].proximo;
    } else {
        m->elementos[anterior].proximo = m->elementos[i].proximo;
    }
    
    alocarNo(m, i);
    return 1; // Elemento excluído com sucesso
}

void procuraMaior(LISTA *m) {
    int i = m->inicio;
    int maior = m->inicio;
    int guarda = m->elementos[m->inicio].valor;
    
    while (i != -1) {
        if (m->elementos[i].valor > guarda) {
            maior = i;
            guarda = m->elementos[i].valor;
        }
        i = m->elementos[i].proximo;
    }
    
    //if (maior != -1) {
        excluir(m, m->elementos[maior].valor);
        printf("\nMaior elemento excluido: %d\n", guarda);
    //} else {
    //    printf("\nNao foi encontrado um maior elemento na lista.\n");
  //  }
}


void exibir_elementos(LISTA *m){
	int i = m->inicio;
	while(i != -1){
		printf("\nLista: %d", m->elementos[i].valor);
		i = m->elementos[i].proximo;
	}
}

void liberar_lista(LISTA *m){
	free(m);
}

int main(){
	LISTA *m = inicializar_estrutura();
	if(m == NULL){
		printf("erro na alocacao");
	}
	
	inserirFim(m, 15);
	inserirFim(m, 28);
	inserirFim(m, 9);
	inserirFim(m, 31);
	inserirFim(m, 2);
	exibir_elementos(m);
	int i = m->inicio;
	procuraMaior(m);
	liberar_lista(m);
	return 0;
}






