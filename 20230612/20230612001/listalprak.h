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
int buscar_maior_elemento(Lista* lista);
void remover_elemento(Lista* lista, No* no);
void armazenar_maior_elemento(Lista* L, Lista* K);
void imprimir_lista(Lista* lista);

#endif

