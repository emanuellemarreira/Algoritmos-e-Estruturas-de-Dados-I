#include <stdio.h>
#include <stdlib.h>
#include "listalprak.h"
int main() {
    Lista L, K;
    inicializar_lista(&L);
    inicializar_lista(&K);

    inserir_elemento(&L, 5);
    inserir_elemento(&L, 2);
    inserir_elemento(&L, 8);
    inserir_elemento(&L, 3);
    inserir_elemento(&L, 1);

    printf("Lista L antes da remocao: ");
    imprimir_lista(&L);

    while (L.inicio != NULL) {
        armazenar_maior_elemento(&L, &K);
    }

    printf("Lista L apos a remocao: ");
    imprimir_lista(&L);

    printf("Lista K apos a remocao: ");
    imprimir_lista(&K);

    return 0;
}
