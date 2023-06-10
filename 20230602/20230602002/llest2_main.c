#include <stdio.h>
#include <stdlib.h>
#include "llest2ok.h"
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
    a(&l, &la);
    printf("\n\nLISTA 2\n");
    imprimir(&la);
    inicializar(&lb);
    b(&l, &lb);
    printf("\n\nLISTA 3\n");
    imprimir(&lb);
    return 0;
}
