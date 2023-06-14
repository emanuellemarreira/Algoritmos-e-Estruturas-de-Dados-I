#include <stdio.h>
#include <stdlib.h>
typedef struct No{
	int valor;
	struct No* anterior;
	struct No *proximo;
}No;

typedef struct {
	No *inicio;
}Lista;

void inicializarLista(Lista* l){
	l->inicio = NULL;
}

No* buscaElementoePred(Lista* l, int valor, No** pred){//lista desordenada
	*pred = NULL;
	No* atual = l->inicio;
	while(atual != NULL){
		if((atual != NULL) && (atual->valor == valor)){
		return atual;
		}
		*pred = atual;
		atual = atual->proximo;
	}
	return NULL;
}

int inserirElementos(Lista* l, int valor){//normal, sem ser desordenada
	No* pred;
	No* elem;
	elem = buscaElementoePred(l, valor, &pred);
	if(elem != NULL){
		return 0;  
	}
	No *novono = malloc(sizeof(No));
	novono->valor = valor;
	if(pred == NULL){
		novono->proximo = l->inicio;
		novono->anterior = NULL;
		l->inicio = novono;
	}else if(pred->proximo == NULL){
		novono->proximo = pred->proximo;
		novono->anterior = pred;
		pred->proximo = novono;
	}else{
		novono->proximo = pred->proximo;
		novono->anterior = pred;
		pred->proximo->anterior = novono;
		pred->proximo = novono;
	}
	
}
int excluir(Lista* m, int valor){
	No* pred;
	No* busca;
	busca = buscaElementoePred(m,valor,&pred);
	if(busca == NULL){//se nao encontrou o valor
		return 0;
	}
	if(pred == NULL){//se for o primeiro elem
		m->inicio = busca->proximo;
	}else{
		pred->proximo = busca->proximo;
	}
	free(busca);
	return 1;
}
void imprimir(Lista *lista){
	No *inicio = lista->inicio;
	while(inicio != NULL){
		printf("\nlista= %d", inicio->valor);
		inicio = inicio->proximo;
	}
}
int main(){
	Lista L;
	inserirElementos(&L, 3);
	inserirElementos(&L, 1);
	inserirElementos(&L, 2);
	imprimir(&L);
	return 0;
}
