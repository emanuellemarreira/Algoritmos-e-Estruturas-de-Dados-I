#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
	int matricula;
	char nome[100];
	int idade;
	int filhos;
}ALUNO;

typedef struct{ 
	ALUNO alunos;
	int proximo;
}ELEMENTO;

typedef struct{
	ELEMENTO turma[MAX];
	int inicio;
	int disponivel;
}LISTA_MATRICULA;

LISTA_MATRICULA* inicializar_estrutura(){
	int i;
	LISTA_MATRICULA *m = malloc(sizeof(LISTA_MATRICULA)) ;
	for(i=0; i<MAX-1;i++){
		m->turma[i].proximo = i+1;
	}
	m->turma[MAX-1].proximo = -1;
	m->inicio = -1;
	m->disponivel = 0;
	if(m != NULL){
		return m;
	}else{
		return NULL;
	}
}

int elementos_validos(LISTA_MATRICULA *m){
	int tam=0;
	int i = m->inicio;
	while(i != -1){
		tam++;
		i = m->turma[i].proximo;
	}
	return tam;
}

int cheia(LISTA_MATRICULA *m){
	if(elementos_validos(m) == MAX){
		return 1;
	}else{
		return 0;
	}
}
int vazia(LISTA_MATRICULA *m){
	if(elementos_validos(m) == 0){
		return 1;
	}else{
		return 0;
	}
}

int obterNo(LISTA_MATRICULA* m){
	int disp = m->disponivel;
	if(m->disponivel != -1){
		m->disponivel = m->turma[disp].proximo;
	}
	return disp;
}
int inserir_aluno(LISTA_MATRICULA *m, ALUNO novo_aluno){
	if(m->disponivel == -1){
		return 0;
	}
	int i = m->inicio;
	int pos_inserir = -1;
	while((i!=-1)&&(novo_aluno.matricula > m->turma[i].alunos.matricula)){
		pos_inserir = i;
		i = m->turma[i].proximo;
	}
	if((i!=-1)&&(novo_aluno.matricula == m->turma[pos_inserir].alunos.matricula)){
		return 0;
	}
	i = obterNo(m);
	m->turma[i].alunos = novo_aluno;
	if(pos_inserir == -1){
		m->turma[i].proximo = m->inicio;
		m->inicio = i;
	}else{
		m->turma[i].proximo = m->turma[pos_inserir].proximo;
		m->turma[pos_inserir].proximo = i;
	}
	return 1;
}

void inserirInicio(LISTA_MATRICULA *lista, ALUNO novoaluno) {
    int novoIndice = obterNo(lista);
    ELEMENTO *novo = &(lista->turma[novoIndice]);
    lista->turma[novoIndice].alunos = novoaluno;
    lista->turma[novoIndice].proximo = lista->inicio;
    lista->inicio = novoIndice;
}

void inserirFim(LISTA_MATRICULA *lista, ALUNO novoaluno) {
    int novoIndice = obterNo(lista);
    ELEMENTO *novo = &(lista->turma[novoIndice]);
	lista->turma[novoIndice].alunos = novoaluno;
	lista->turma[novoIndice].proximo = -1;

    if (lista->inicio == -1) {
        lista->inicio = novoIndice;
    } else {
        ELEMENTO *ultimo = &(lista->turma[lista->inicio]);
        while (ultimo->proximo != -1) {
            ultimo = &(lista->turma[ultimo->proximo]);
        }
        ultimo->proximo = novoIndice;
    }
}

int inserir_aluno_entre(LISTA_MATRICULA *m, ALUNO novo_aluno, int matricula_predecessor) {
    int i = m->inicio;
    while (i != -1 && m->turma[i].alunos.matricula != matricula_predecessor) {
        i = m->turma[i].proximo;
    }
    if (i == -1) {
        return 0; // Matrícula do predecessor não encontrada
    }

    int novo_indice = obterNo(m);
    m->turma[novo_indice].alunos = novo_aluno;
    m->turma[novo_indice].proximo = m->turma[i].proximo;
    m->turma[i].proximo = novo_indice;

    return 1;
}

void exibir_elementos(LISTA_MATRICULA *m){
	int i = m->inicio;
	while(i != -1){
		printf("\nALUNO %d", i);
		printf("\nCODIGO: %d", m->turma[i].alunos.matricula);
		printf("\nNOME: %s", m->turma[i].alunos.nome);
		printf("\nIDADE: %d", m->turma[i].alunos.idade);
		i = m->turma[i].proximo;
	}
}
void alocarNo(LISTA_MATRICULA *m, int i){
	m->turma[i].proximo = m->disponivel;
	m->disponivel = i;
}
int excluir_aluno(LISTA_MATRICULA *m, int cod){
	int i = m->inicio;
	int anterior = -1;
	while(i!=-1 && m->turma[i].alunos.matricula < cod){
		anterior = i;
		i = m->turma[i].proximo;
	}
	if(i!=-1 && m->turma[i].alunos.matricula != cod){
		return 0;
	}
	if(anterior == -1){
		m->inicio = m->turma[i].proximo;
	}else{
		m->turma[anterior].proximo = m->turma[i].proximo;
	}
	alocarNo(m,i);
	return 1;
}

void excluirInicio(LISTA_MATRICULA *lista) {
    if (lista->inicio == -1) {
        return; // Lista vazia
    }

    int indice_excluir = lista->inicio;
    lista->inicio = lista->turma[indice_excluir].proximo;
    alocarNo(lista, indice_excluir);
}

void excluirFim(LISTA_MATRICULA *lista) {
    if (lista->inicio == -1) {
        return; // Lista vazia
    }

    int anterior = -1;
    int atual = lista->inicio;
    while (lista->turma[atual].proximo != -1) {
        anterior = atual;
        atual = lista->turma[atual].proximo;
    }

    if (anterior == -1) {
        lista->inicio = -1;
    } else {
        lista->turma[anterior].proximo = -1;
    }

    alocarNo(lista, atual);
}

int excluir_posicao(LISTA_MATRICULA *m, int posicao) {
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
        i = m->turma[i].proximo;
    }

    // Remove o elemento da posição atual
    if (anterior == -1) {
        m->inicio = m->turma[i].proximo;
    } else {
        m->turma[anterior].proximo = m->turma[i].proximo;
    }

    // Libera o nó removido para reutilização
    m->turma[i].proximo = m->disponivel;
    m->disponivel = i;

    return 1; // Exclusão bem-sucedida
}


int alterar_matricula(LISTA_MATRICULA *m, int cod, int novocod){
	int i = m->inicio;
	while (i != -1 && m->turma[i].alunos.matricula < cod) {
		i = m->turma[i].proximo;
	}
	if (i != -1 && m->turma[i].alunos.matricula == cod) {
		ALUNO novoaluno;
		novoaluno.matricula = novocod;
		novoaluno.idade = m->turma[i].alunos.idade;
		strcpy(novoaluno.nome,m->turma[i].alunos.nome);
		excluir_aluno(m, cod);
		inserir_aluno(m, novoaluno);
		return 1;
	}
	return 0;
}

int buscar_aluno_ordenada(LISTA_MATRICULA *m, int matricula) {
    int i = m->inicio;
    while (i != -1 && m->turma[i].alunos.matricula < matricula) {
        i = m->turma[i].proximo;
    }
    if (i != -1 && m->turma[i].alunos.matricula == matricula) {
        return i; // Aluno encontrado, retorna o índice na lista
    }
    return -1; // Aluno não encontrado
}
int buscar_aluno_sequencial(LISTA_MATRICULA *m, int matricula) {
    int i = m->inicio;
    while (i != -1) {
        if (m->turma[i].alunos.matricula == matricula) {
        return i; // Aluno encontrado, retorna o índice na lista
    }
        i = m->turma[i].proximo;
    }
    
    return -1; // Aluno não encontrado
}
void liberar_lista(LISTA_MATRICULA *m){
	free(m);
}
int main(int argc, char *argv[]) {
	LISTA_MATRICULA *m = inicializar_estrutura();
	if(m == NULL){
		printf("erro na alocacao");
	}
	printf("\n--------ANTES--------\n");
	printf("\nelem validos: %d", elementos_validos(m));
	printf("\nvazia: %d", vazia(m));
	printf("\ncheia: %d", cheia(m));
	ALUNO aluno1;
    aluno1.matricula = 1;
    aluno1.filhos = 0;
    aluno1.idade = 19;
    strcpy(aluno1.nome, "alberto");

    ALUNO aluno2;
    aluno2.matricula = 2;
    aluno2.filhos = 1;
    aluno2.idade = 38;
    strcpy(aluno2.nome, "beatriz");

    ALUNO aluno3;
    aluno3.matricula = 3;
    aluno3.filhos = 0;
    aluno3.idade = 90;
    strcpy(aluno3.nome, "carlos");

	inserir_aluno(m,aluno1);
	inserir_aluno(m,aluno2);
	inserir_aluno(m,aluno3);
	printf("\n-----DPS DE ADD--------\n");
	printf("\nelem validos: %d", elementos_validos(m));
	printf("\nvazia: %d", vazia(m));
	printf("\ncheia: %d", cheia(m));
	exibir_elementos(m);
	printf("\nbusca ordenada sequencial: encontrado em %d", buscar_aluno_sequencial(m, aluno2.matricula));
	printf("\nbusca ordenada: encontrado em %d", buscar_aluno_ordenada(m, aluno2.matricula));
	printf("\n------EXCLUINDO--------\n");
	excluir_aluno(m,2);
	exibir_elementos(m);
	printf("\n------ALTERANDO--------\n");
	alterar_matricula(m,1,1234);
	exibir_elementos(m);
	printf("\n------inserindo no fim--------\n");
	ALUNO aluno4;
    aluno4.matricula = 4;
    aluno4.filhos = 0;
    aluno4.idade = 30;
    strcpy(aluno4.nome, "daniel");
    inserirFim(m, aluno4);
    exibir_elementos(m);
    printf("\n------inserindo no inicio--------\n");
	ALUNO aluno5;
    aluno5.matricula = 0;
    aluno5.filhos = 0;
    aluno5.idade = 31;
    strcpy(aluno5.nome, "elisa");
    inserirInicio(m, aluno5);
    /*printf("\n------inserindo numa posicao especifica--------\n");
	ALUNO aluno6;
    aluno6.matricula = 1;
    aluno6.filhos = 2;
    aluno6.idade = 33;
    strcpy(aluno6.nome, "francisco levi");
    inserir_aluno_entre(m, aluno6, aluno5.matricula);
    exibir_elementos(m);
    excluirInicio(m);
    excluirFim(m);
    printf("\n------excluindo inicio e fim--------\n");*/
    exibir_elementos(m);
    //printf("\nbusca ordenada sequencial: encontrado em %d", buscar_aluno_sequencial(m, aluno5.matricula));
    printf("\n-\n");
    excluir_posicao(m,1);
    exibir_elementos(m);
    liberar_lista(m);
	return 0;
}

