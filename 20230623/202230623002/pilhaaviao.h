#ifndef PILHAAVIAO_H_INCLUDED
#define PILHAAVIAO_H_INCLUDED
#define MAX 100
typedef struct{
	int cod;
	char nome[MAX];
}AVIAO;

typedef struct No{
	AVIAO aviao;
	struct No* proximo;
}No;

typedef struct{
	No* topo;
}PILHA

void inicializarPilha(PILHA* p);
void reinicializarPilha(PILHA* p);
int inserirHangar(PILHA* p, AVIAO novo_aviao);
int excluirHangar(PILHA* p);
int excluirHangarPelaPosicao(PILHA* p, int posicao);
void imprimePilha(PILHA *p);
AVIAO primeiroAviao(PILHA* p);

#endif
