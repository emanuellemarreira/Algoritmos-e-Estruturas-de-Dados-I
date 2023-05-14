#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char frase[100];
	char carac;
}FRASE;

void preenche(FRASE *f){
	printf("digite a frase: ");
	scanf(" %100[^\n]", f->frase);
	printf("digite o caracter: ");
	scanf(" %c", &f->carac);
}

void verifica(FRASE f){
	int i, flag=0;
	for(i=0;i<=strlen(f.frase);i++){e
		if(f.frase[i] == f.carac){
			printf("SIM");
			flag = 1;
			break;
		}
	}
	if(flag==0){
		printf("NAO");
	}
}

int main(){
	FRASE *f = malloc(sizeof(FRASE));
	preenche(f);
	verifica(*f);
	return 0;
}
