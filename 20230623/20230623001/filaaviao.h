#ifndef FILAAVIAO_H_INCLUDED
#define FILAAVIAO_H_INCLUDED
#define MAX 100
typedef struct{
	char nome[MAX];
	int id;
}AVIAO;

typedef struct No{
    AVIAO aviao;
	struct No* proximo;	
}No;

typedef struct{
	No* inicio;
	No* fim;
}FILA;

void inicializarFila(FILA* f);
void reinicializarFila(FILA* f);
int inserirListadeEspera(FILA* f, AVIAO novo_aviao);
int excluirDaListadeEspera(FILA* f);
void imprimeFila(FILA *f);
int qtdNaFila(FILA* f);
AVIAO primeiroAviao(FILA* f);

#endif
