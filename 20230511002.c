#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nome[100];
	char cpf[100];
	char dn[100];
	int idade;
	
}PESSOA;

void preenche(PESSOA *eu){
	strcpy(eu->nome,"Emanuelle");
	strcpy(eu->dn,"15/02/2004");
	strcpy(eu->cpf,"060.389.672-30");
	eu->idade=19;
}

void imprime(PESSOA eu){
	printf("nome: %s\n", eu.nome);
	printf("dn: %s\n", eu.dn);
	printf("cpf: %s\n", eu.cpf);
	printf("idade: %d\n", eu.idade);
}

int main(){
	PESSOA *euuu = malloc (sizeof(PESSOA));
	preenche(euuu);
	imprime(*euuu);
	
	return 0;
}
