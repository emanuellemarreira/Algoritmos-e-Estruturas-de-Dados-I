#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float real;
	float img;
}NCOMPLEXO;

NCOMPLEXO* cria_complexo(){
	NCOMPLEXO *meunumero = malloc(sizeof(NCOMPLEXO));
	printf("\nparte real do numero: ");
	scanf("%f", &meunumero->real);
	printf("\nparte imaginaria do numero: ");
	scanf("%f", &meunumero->img);
	return meunumero;
}

void soma_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	n3->real = n1->real + n2->real;
	n3->img = n1->img + n2->img;
}

void subtracao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	n3->real = n1->real - n2->real;
	n3->img = n1->img - n2->img;
}

void multiplicacao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	n3->real = n1->real*n2->real - n1->img*n2->img; 
	n3->img = n1->real*n2->img + n1->img*n2->real;
}

void divisao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	NCOMPLEXO *conj = malloc(sizeof(NCOMPLEXO));
	NCOMPLEXO *num = malloc(sizeof(NCOMPLEXO));
	NCOMPLEXO *den = malloc(sizeof(NCOMPLEXO));
	conj->real = n2->real;
	conj->img = n2->img*(-1);
	num->real = n1->real*conj->real - n1->img*conj->img; 
	num->img = n1->real*conj->img + n1->img*conj->real;
	den->real = n2->real*conj->real - n2->img*conj->img; 
	den->img = n2->real*conj->img + n2->img*conj->real;
	printf("RESULTADO: \n");
	printf("%.2f + %.2fi // %.2f + %.2fi", num->real, num->img, den->real, den->img);
	
}

void destroi_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	free(n1);
	free(n2);
	free(n3);
}

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
