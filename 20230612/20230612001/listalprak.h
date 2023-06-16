#ifndef LISTALPRAK_h_INCLUDED
#define LISTALPRAK_H_INCLUDED

typedef struct No {
    int valor;
    struct No* anterior;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;
void inicializar_lista(Lista* lista);
void inserir_elemento(Lista* lista, int valor);
void inserir_emk(Lista* lista, No* inserir);
int buscar_maior_elemento(Lista* lista);
No* buscaElem_e_Pred(Lista* m, int valor, No** pred);
No* remover_elemento(Lista* lista, int valor) {
void armazenar_maior_elemento(Lista* L, Lista* K);
void imprimir_lista(Lista* lista);

#endif
