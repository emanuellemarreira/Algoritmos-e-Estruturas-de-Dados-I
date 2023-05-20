#include <stdio.h>
#include <stdlib.h>
#include "numerocomplexo.h"
int main(){
	NCOMPLEXO *n1, *n2;
	int ask;
	n1 = cria_complexo();
	n2 = cria_complexo();
	NCOMPLEXO *n3 = malloc(sizeof(NCOMPLEXO));
	
	printf("o que deseja fazer?\n");
	printf("(1)SOMA\n(2)SUBTRACAO\n(3)MULTIPLICACAO\n(4)DIVISAO\n");
	scanf("%d", &ask);
	if(ask == 1){
		soma_complexo(n1,n2,n3);
		printf("\nRESULTADO = %.2f + %.2fi", n3->real, n3->img);
	}
	if(ask == 2){
		subtracao_complexo(n1,n2,n3);
		printf("\nRESULTADO = %.2f + %.2fi", n3->real, n3->img);
	}
	if(ask == 3){
		multiplicacao_complexo(n1,n2,n3);
		printf("\nRESULTADO = %.2f + %.2fi", n3->real, n3->img);
	}
	if(ask == 4){
		divisao_complexo(n1,n2,n3);
	}
	destroi_complexo(n1,n2,n3);
}
