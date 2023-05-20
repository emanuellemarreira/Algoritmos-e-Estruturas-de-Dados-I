#include "retangulo.h"
#include <stdio.h>
#include <stdlib.h>

//inicializacao
RETANGULO *cria_retangulo(){
	RETANGULO *ret = malloc(sizeof(RETANGULO));
	


	ret->larg = 2;
	ret->alt = 3;
	ret->comp = 4;
	return ret;
}

int tam(RETANGULO *ret){
	if(ret == NULL){
		return 0;
	}
	printf("larg = %.2f\n", ret->larg);
	printf("alt = %.2f\n", ret->alt);
	printf("comp = %.2f\n", ret->comp);
	return 1;
}
int area(RETANGULO *ret){
	if(ret == NULL){
		return 0;
	}
	float area = ret->alt*ret->larg;
	printf("\narea = %.2f", area);
	return 1;
}
int volume(RETANGULO *ret){
	if(ret == NULL){
		return 0;
	}
	float volume = ret->alt*ret->larg*ret->comp;
	printf("\nvolume = %.2f", volume);
	return 1;
}

void libera(RETANGULO *ret){
	free(ret);
}
