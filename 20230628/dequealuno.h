#ifndef DEQUEALUNO_H_INCLUDED
#define DEQUEALUNO_H_INCLUDED
#define MAX 100
typedef struct{
	char nome[MAX];
}ALUNO;

typedef struct No{
    ALUNO aluno;
	struct No* anterior;
	struct No* proximo; 	
}No;
//circular
typedef struct{
	No* cabeca;
}DEQUE;

void inicializarDeque(DEQUE *d);
void reinicializarDeque(DEQUE *d);
int inserirInicio(DEQUE *d, ALUNO novo_aluno);
int inserirFim(DEQUE* d, ALUNO novo_aluno);
int excluirInicio(DEQUE* d);
int excluirFim(DEQUE* d);
No* returnInicio(DEQUE* d);
No* returnFim(DEQUE* d);
void imprimirDeque(DEQUE* d);
No* procurarNo(DEQUE* d, int pos);
int exibeDouI(DEQUE* d, int pos, char ordem);


#endif
