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

int elementos_validos(LISTA *m){
	int tam=0;
	int i = m->inicio;
	while(i != -1){
		tam++;
		i = m->elementos[i].proximo;
	}
	return tam;
}

int cheia(LISTA *m){
	if(elementos_validos(m) == MAX){
		return 1;
	}else{
		return 0;
	}
}
int vazia(LISTA *m){
	if(elementos_validos(m) == 0){
		return 1;
	}else{
		return 0;
	}
}

int obterNo(LISTA * m){
	int disp = m->disponivel;
	if(m->disponivel != -1){
		m->disponivel = m->elementos[disp].proximo;
	}
	return disp;
}
int inserir(LISTA *m, int novo_valor){
	if(m->disponivel == -1){
		return 0;
	}
	int i = m->inicio;
	int pos_inserir = -1;
	while((i!=-1)&&(novo_valor > m->elementos[i].valor)){
		pos_inserir = i;
		i = m->elementos[i].proximo;
	}
	if((i!=-1)&&(novo_valor == m->elementos[pos_inserir].valor)){
		return 0;
	}
	i = obterNo(m);
	m->elementos[i].valor = novo_valor;
	if(pos_inserir == -1){
		m->elementos[i].proximo = m->inicio;
		m->inicio = i;
	}else{
		m->elementos[i].proximo = m->elementos[pos_inserir].proximo;
		m->elementos[pos_inserir].proximo = i;
	}
	return 1;
}

void inserirInicio(LISTA *lista, int novovalor) {
    int novoIndice = obterNo(lista);
    ELEMENTO *novo = &(lista->elementos[novoIndice]);
    lista->elementos[novoIndice].valor = novovalor;
    lista->elementos[novoIndice].proximo = lista->inicio;
    lista->inicio = novoIndice;
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
int buscar_sequencial(LISTA *m, int valor);
int inserir_entre(LISTA *m, int novo_valor, int predecessor) {
    int busca = buscar_sequencial(m, predecessor);
    if (busca == -1) {
        return 0; // Valor predecessor não encontrado na lista
    }

    int novo_indice = obterNo(m);
    m->elementos[novo_indice].valor = novo_valor;
    m->elementos[novo_indice].proximo = m->elementos[busca].proximo;
    m->elementos[busca].proximo = novo_indice;

    return 1;
}

void exibir_elementos(LISTA *m){
	int i = m->inicio;
	while(i != -1){
		printf("\nLista: %d", m->elementos[i].valor);
		i = m->elementos[i].proximo;
	}
}
void alocarNo(LISTA *m, int i){
	m->elementos[i].proximo = m->disponivel;
	m->disponivel = i;
}
int excluir(LISTA *m, int elem){
	int i = m->inicio;
	int anterior = -1;
	while(i!=-1 && m->elementos[i].valor < elem){
		anterior = i;
		i = m->elementos[i].proximo;
	}
	if(i!=-1 && m->elementos[i].valor != elem){
		return 0;
	}
	if(anterior == -1){
		m->inicio = m->elementos[i].proximo;
	}else{
		m->elementos[anterior].proximo = m->elementos[i].proximo;
	}
	alocarNo(m,i);
	return 1;
}

void excluirInicio(LISTA *lista) {
    if (lista->inicio == -1) {
        return; // Lista vazia
    }

    int indice_excluir = lista->inicio;
    lista->inicio = lista->elementos[indice_excluir].proximo;
    alocarNo(lista, indice_excluir);
}

void excluirFim(LISTA *lista) {
    if (lista->inicio == -1) {
        return; // Lista vazia
    }

    int anterior = -1;
    int atual = lista->inicio;
    while (lista->elementos[atual].proximo != -1) {
        anterior = atual;
        atual = lista->elementos[atual].proximo;
    }

    if (anterior == -1) {
        lista->inicio = -1;
    } else {
        lista->elementos[anterior].proximo = -1;
    }

    alocarNo(lista, atual);
}

int excluir_posicao(LISTA *m, int posicao) {
	int count;
    if (posicao < 0 || posicao >= MAX) {
        return 0; // Posição inválida
    }

    int i = m->inicio;
    int anterior = -1;

    // Percorre a lista até a posição desejada
    for (count = 0; count < posicao; count++) {
        if (i == -1) {
            return 0; // Posição inválida (posição maior que o número de elementos)
        }
        anterior = i;
        i = m->elementos[i].proximo;
    }

    // Remove o elemento da posição atual
    if (anterior == -1) {
        m->inicio = m->elementos[i].proximo;
    } else {
        m->elementos[anterior].proximo = m->elementos[i].proximo;
    }

    // Libera o nó removido para reutilização
    m->elementos[i].proximo = m->disponivel;
    m->disponivel = i;

    return 1; // Exclusão bem-sucedida
}


int alterar_valor(LISTA *m, int valor, int novovalor){
	int i = m->inicio;
	while (i != -1 && m->elementos[i].valor < novovalor) {
	    if (m->elementos[i].valor == valor) {
	        excluir(m, valor);
	        inserir(m, novovalor);
		return 1;
	   
	    }
		i = m->elementos[i].proximo;
	}
	return 0;
}

int buscar_ordenada(LISTA *m, int valor) {
    int i = m->inicio;
    while (i != -1 && m->elementos[i].valor < valor) {
        i = m->elementos[i].proximo;
    }
    if (i != -1 && m->elementos[i].valor == valor) {
        return i; // Aluno encontrado, retorna o índice na lista
    }
    return -1; // Aluno não encontrado
}
int buscar_sequencial(LISTA *m, int valor) {
    int i = m->inicio;
    while (i != -1) {
        if (m->elementos[i].valor == valor)
            return i; // Aluno encontrado, retorna o índice na lista
        i = m->elementos[i].proximo;
    }
    return -1; // Aluno não encontrado
}
void liberar_lista(LISTA *m){
	free(m);
}
int main(int argc, char *argv[]) {
	LISTA *m = inicializar_estrutura();
	if(m == NULL){
		printf("erro na alocacao");
	}
	printf("\n--------ANTES--------\n");
	printf("\nelem validos: %d", elementos_validos(m));
	printf("\nvazia: %d", vazia(m));
	printf("\ncheia: %d", cheia(m));
	
	inserir(m,1);
	inserir(m,2);
	inserir(m,3);
	
	printf("\n-----DPS DE ADD--------\n");
	printf("\nelem validos: %d", elementos_validos(m));
	printf("\nvazia: %d", vazia(m));
	printf("\ncheia: %d", cheia(m));
	exibir_elementos(m);
	//printf("\nbusca ordenada sequencial: encontrado em %d", buscar_sequencial(m, 2));
	//printf("\nbusca ordenada: encontrado em %d", buscar_ordenada(m, 2));
	printf("\n------EXCLUINDO--------\n");
	excluir(m,2);
	exibir_elementos(m);
	printf("\n------ALTERANDO--------\n");
	alterar_valor(m,1,1234);
	exibir_elementos(m);
	printf("\n------inserindo no fim--------\n");
    inserirFim(m, 666);
    exibir_elementos(m);
    printf("\n------inserindo no inicio--------\n");
    inserirInicio(m, 0);
    exibir_elementos(m);
    printf("\n------inserindo numa posicao especifica--------\n");
    inserir_entre(m, 2, 0);
    exibir_elementos(m);
    excluirInicio(m);
    excluirFim(m);
    printf("\n------excluindo inicio e fim--------\n");
    exibir_elementos(m);
    printf("\n-\n");
    excluir_posicao(m,1);
    exibir_elementos(m);
    printf("\nbusca ordenada sequencial: encontrado em %d", buscar_sequencial(m, 2));
    liberar_lista(m);
	return 0;
}

