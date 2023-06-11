#ifndef LLEST3OK_H_INCLUDED
#define LLEST3OK_H_INCLUDED

#define TAMANHO_MAX 100 // Tamanho máximo da lista ligada estática

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
void remover(Lista *lista, int valor);
void imprimir(Lista *lista);
void copiarLista(Lista *l1, Lista *l2);
void concatenarLista(Lista *l1, Lista *l2);
Lista intercalarListas(Lista *l1, Lista *l2);
#endif
