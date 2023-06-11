#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct{
	int matriculas[MAX];
	int qtd_elem_validos;
}Lista;

Lista* inicializarLista(){
	Lista* m;
	m = malloc(sizeof(Lista));
	if(m != NULL){
		m->qtd_elem_validos = 0;
	}else{
		return NULL;
	}
	return m;
}
int tamanho(Lista* lista){
	if(lista == NULL){
		return 0;
	}
	else{
		return lista->qtd_elem_validos;
	}
}

int cheia(Lista* lista){
	if(lista == NULL){
		return 0;
	}
	if(lista->qtd_elem_validos == MAX){
		return 1;
	}else{
		return 0;
	}
}
int vazia(Lista* lista){
	if(lista == NULL){
		return 0;
	}
	if(lista->qtd_elem_validos == 0){
		return 1;
	}else{
		return 0;
	}
}
void imprimir(Lista* lista){
	int i;
	for(i=0;i<lista->qtd_elem_validos;i++){
		printf(" %d ", lista->matriculas[i]);
	}
}
int inserirFim(Lista* lista, int novamat){
	if(cheia(lista)==1){
		return 0;
	}
	lista->matriculas[lista->qtd_elem_validos] = novamat;
	lista->qtd_elem_validos++;
}
int inserirInicio(Lista* lista, int novamat){
	int i;
	if(cheia(lista)==1){
		return 0;
	}
	for(i=lista->qtd_elem_validos-1;i>=0;i--){
		lista->matriculas[i+1] = lista->matriculas[i];
	}
	lista->matriculas[0] = novamat;
	lista->qtd_elem_validos++;
}
int inserirOrdenado(Lista* lista, int novamat){
	int busca;
	if(cheia(lista)==1){
		return 0;
	}
	busca = inserirPosDesejada(lista, novamat, buscaSeqOrd(lista)+1);
	if(busca == 0){
		return 0;
	}
	return busca;
}
int inserirPosDesejada(Lista *lista, int novamat, int pos){
	int i;
	if(cheia(lista)==1 || pos-1 > MAX || pos-1<0){
		return 0;
	}
	for(i=lista->qtd_elem_validos-1;i>=0;i--){
		lista->matriculas[i+1] = lista->matriculas[i];
	}
	lista->matriculas[pos] = novamat;
	lista->qtd_elem_validos++;
}
int buscaSeqOrd(Lista* lista, int valor){
	int i;
	for(i=0;i<lista->qtd_elem_validos;i++){
		if(lista->matriculas[i]>=valor){
			if(lista->matriculas[i]==valor){
				return i;
			}
		}
	}
	return 0;
}

int excluirPelaPos(Lista* lista, int pos){//excluir contando do zero
	int i;
	if(vazia(lista)==1){
		return 0;
	}
	for(i=pos;i<lista->qtd_elem_validos-1;i++){
		lista->matriculas[i] = lista->matriculas[i+1];
	}
	lista->qtd_elem_validos--;
	return 1;
}
int excluirPeloValor(Lista* lista, int valor){
	int i;
	if(vazia(lista)==1){
		return 0;
	}
	int pos = buscaSeqOrd(lista, valor);
	for(i=pos;i<lista->qtd_elem_validos-1;i++){
		lista->matriculas[i] = lista->matriculas[i+1];
	}
	lista->qtd_elem_validos--;
	return 1;
}
int alterarPeloValor(Lista* lista, int valor, int novamat){
	int i;
	if(vazia(lista)==1){
		return 0;
	}
	int pos = buscaSeqOrd(lista, valor);
	lista->matriculas[pos] = novamat;
	return 1;
}
void liberar(Lista* lista){
	lista->qtd_elem_validos = 0;
	free(lista);
}

int main(){
	Lista *l1;
	l1 = inicializarLista();
	printf("\ncheia: %d", cheia(l1));
	printf("\nvazia: %d\n", vazia(l1));
	inserirFim(l1, 4);
	inserirInicio(l1, 1);
	inserirFim(l1,5);
	inserirPosDesejada(l1,3,1);
	inserirOrdenado(l1, 2);
	imprimir(l1);
	printf("\ncheia: %d", cheia(l1));
	printf("\nvazia: %d\n", vazia(l1));
	printf("\nexcluindo do fim: ");
	excluirPelaPos(l1, l1->qtd_elem_validos);
	imprimir(l1);
	printf("\nexcluindo do inicio: ");
	excluirPelaPos(l1, 0);
	imprimir(l1);
	printf("\nexcluindo pelo valor: ");
	excluirPeloValor(l1, 3);
	imprimir(l1);
	printf("\nalterando valor: ");
	alterarPeloValor(l1, 4, 666);
	imprimir(l1);
	liberar(l1);
	return 0;
}
