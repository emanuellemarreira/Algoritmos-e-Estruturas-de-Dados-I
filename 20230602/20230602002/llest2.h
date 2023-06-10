#ifndef LLEST2OK_H_INCLUDED
#define LLEST2OK_H_INCLUDED
#define TAMANHO_MAX 100
typedef struct {
    int valor;
    int proximo; // Índice do próximo elemento na lista
} No;

typedef struct {
    No elementos[TAMANHO_MAX];
    int inicio; // Índice do primeiro elemento na lista
    int livre; // Índice do próximo espaço livre na lista
} Lista;

void inicializar(Lista *lista);
int obterNoLivre(Lista *lista);
void inserirFim(Lista *lista, int valor);
void inserirInicio(Lista *lista, int valor);
void remover(Lista *lista, int valor);
void imprimir(Lista *lista);
void a(Lista *l, Lista *l1);
void b(Lista *l, Lista *l1);

#endif

