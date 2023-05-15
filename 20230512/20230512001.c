#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float larg;
	float alt;
	float comp;
}RETANGULO;

//inicializacao
RETANGULO *cria_retangulo(){
	RETANGULO *ret = malloc(sizeof(RETANGULO));
	ret->larg = 2;
	ret->alt = 3;
	ret->comp = 4;
	return ret;
}

void tam(RETANGULO *ret){
	printf("larg = %.2f\n", ret->larg);
	printf("alt = %.2f\n", ret->alt);
	printf("comp = %.2f\n", ret->comp);
}
void area(RETANGULO *ret){
	float area = ret->alt*ret->larg;
	printf("\narea = %.2f", area);
}
void volume(RETANGULO *ret){
	float volume = ret->alt*ret->larg*ret->comp;
	printf("\nvolume = %.2f", volume);
}

void libera(RETANGULO *ret){
	free(ret);
}

int main(){
	RETANGULO *meuret;
	meuret = cria_retangulo();
	tam(meuret);
	area(meuret);
	volume(meuret);
	libera(meuret);
	return 0;
}

