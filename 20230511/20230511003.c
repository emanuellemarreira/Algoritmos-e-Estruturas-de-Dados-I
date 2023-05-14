#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}DATA ;

void preenche(DATA *date){
	printf("dia? ");
	scanf("%d", &date->dia);
	printf("mes? ");
	scanf("%d", &date->mes);
	printf("ano? ");
	scanf("%d", &date->ano);
}

void imprime(DATA *date){
	printf("%d / %d / %d", date->dia, date->mes, date->ano);
}

int main(){
	DATA *date = malloc (sizeof(DATA));
	preenche(date);
	imprime(date);
	return 0;
}
