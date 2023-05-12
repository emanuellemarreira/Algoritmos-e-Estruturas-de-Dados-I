#include <stdio.h>
#include <string.h>

typedef struct{
	char dn[10];
	char cpf[14];
	char nome[100];
}PESSOA;

void preenche(PESSOA *eu){
	strcpy(eu->nome,"Emanuelle");
	strcpy(eu->dn,"15/02/2004");
	strcpy(eu->cpf,"060.389.672-30");
}

void imprime(PESSOA eu){
	printf("nome: %s\n", eu.nome);
	printf("dn: %s\n", eu.dn);
	printf("cpf: %s\n", eu.cpf);
}

int main(){
	PESSOA euuu;
	preenche(&euuu);
	imprime(euuu);
	
	return 0;
}
