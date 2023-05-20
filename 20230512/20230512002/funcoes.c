#include <stdio.h>
#include <stdlib.h>
#include "numerocomplexo.h"

NCOMPLEXO* cria_complexo(){
	NCOMPLEXO *meunumero = malloc(sizeof(NCOMPLEXO));
	printf("\nparte real do numero: ");
	scanf("%f", &meunumero->real);
	printf("\nparte imaginaria do numero: ");
	scanf("%f", &meunumero->img);
	return meunumero;
}

int soma_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	if (n1== NULL || n2==NULL || n3==NULL){
		return 0;
	}
	n3->real = n1->real + n2->real;
	n3->img = n1->img + n2->img;
	return 1;
}

int subtracao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	if (n1== NULL || n2==NULL || n3==NULL){
		return 0;
	}
	n3->real = n1->real - n2->real;
	n3->img = n1->img - n2->img;
	return 1;
}
int multiplicacao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	if (n1== NULL || n2==NULL || n3==NULL){
		return 0;
	}
	n3->real = n1->real*n2->real - n1->img*n2->img; 
	n3->img = n1->real*n2->img + n1->img*n2->real;
	return 1;
}

int divisao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	NCOMPLEXO *conj = malloc(sizeof(NCOMPLEXO));
	NCOMPLEXO *num = malloc(sizeof(NCOMPLEXO));
	NCOMPLEXO *den = malloc(sizeof(NCOMPLEXO));
	if (n1== NULL || n2==NULL || n3==NULL || conj==NULL || num == NULL || den == NULL){
		return 0;
	}
	conj->real = n2->real;
	conj->img = n2->img*(-1);
	num->real = n1->real*conj->real - n1->img*conj->img; 
	num->img = n1->real*conj->img + n1->img*conj->real;
	den->real = n2->real*conj->real - n2->img*conj->img; 
	den->img = n2->real*conj->img + n2->img*conj->real;
	printf("RESULTADO: \n");
	printf("%.2f + %.2fi // %.2f + %.2fi", num->real, num->img, den->real, den->img);
	return 1;
}

void destroi_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3){
	free(n1);
	free(n2);
	free(n3);
}

