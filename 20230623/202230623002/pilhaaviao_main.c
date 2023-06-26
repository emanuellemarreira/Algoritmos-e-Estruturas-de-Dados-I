#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaaviao.h"

int main(){
	PILHA p;
	inicializarPilha(&p);
	
	AVIAO a;
	a.cod = 13;
	strcpy(a.nome, "1 GOL");
	inserirHangar(&p, a);
	a.cod = 20;
	strcpy(a.nome, "2 AZUL");
	inserirHangar(&p, a);
	a.cod = 22;
	strcpy(a.nome, "3 AMERICAN AIRLINES");
	inserirHangar(&p, a);
	a.cod = 123;
	strcpy(a.nome, "4 AIR FORCE");
	inserirHangar(&p, a);
	a.cod = 222;
	strcpy(a.nome, "5 AIR JORDAN");
	inserirHangar(&p, a);
	
	printf("\n==avioes na pilha de espera==\n");
	imprimePilha(&p);
	
	AVIAO primeiroaviao = primeiroAviao(&p);
	printf("\ndados do primeiro aviao da pilha: %d | %s ", primeiroaviao.cod, primeiroaviao.nome);
	
	printf("\nDecolagem: \n");
	//excluirHangar(&p);
	excluirHangarPelaPosicao(&p,3);
	imprimePilha(&p);
	
	reinicializarPilha(&p);
	return 0;
}
