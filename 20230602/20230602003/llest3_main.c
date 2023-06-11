#include <stdio.h>
#include <stdlib.h>
#include "llest3ok.h"
int main(int argc, char *argv[]) {
    Lista l, la, lb;
    inicializar(&l);
    inserirFim(&l, 1);
    inserirFim(&l, 2);
    inserirFim(&l, 3);
    inserirFim(&l, 4);
    printf("\nLISTA 1\n");
    imprimir(&l);
    inicializar(&la);
    printf("\n\nLISTA 1 - copia l2\n");
    copiarLista(&l, &la);
    imprimir(&la);
    printf("\n\nLISTA 1 concatenada com l2\n");
    concatenarLista(&l, &la);
    imprimir(&l);
    inicializar(&lb);
    printf("\n\nl1 intercalada com l2\n");
    lb = intercalarListas(&l,&la);
    imprimir(&lb);

    return 0;
}
