#include <stdio.h>
#include <stdlib.h>
#define N 11

typedef struct{
	int valor;
}Elemento;

typedef Elemento* tbhash[N];

void inicializarHash(tbhash t){
	int i;
	for(i=0; i<N; i++){
		t[i] = NULL;
	}
}

int sondagem_linear(tbhash t, Elemento e, int *colisoes){
	int i, pos;
	for(i = 0; i<N; i++){
		pos = (e.valor + i)%N;
		if(t[pos] == NULL){
			break;
		}else{
			(*colisoes)++;
		}
	}
	return pos;
}

int sondagem_quadratica(tbhash t, Elemento e, int *colisoes){
	int i, pos;
	for(i = 0; i<N; i++){
		pos = (e.valor + i*i)%N;
		if(t[pos] == NULL){
			break;
		}else{
			(*colisoes)++;
		}
	}
	return pos;
}

int sondagem_quadratica2(tbhash t, Elemento e, int *colisoes){
	int i, pos;
	for(i = 0; i<N; i++){
		pos = (e.valor + 2*i + i*i)%N;
		if(t[pos] == NULL){
			break;
		}else{
			(*colisoes)++;
		}
	}
	return pos;
}

int hash_duplo(tbhash t, Elemento e, int *colisoes){
	int pos;
	pos = e.valor%N;
	if(t[pos] != NULL){
		pos = 7-(e.valor%7);
		(*colisoes)++;
	}
	return pos;
}

int inserirHash(tbhash t, Elemento e, int dispersao, int *colisoes){
	int pos;
	switch (dispersao){
		case 1:
			pos = sondagem_linear(t, e, colisoes);
			break;
		case 2:
			pos = sondagem_quadratica(t, e, colisoes);
			break;
		case 3:
			pos = sondagem_quadratica2(t, e, colisoes);
			break;
		case 4:
			pos = hash_duplo(t, e, colisoes);
			break;
		default:
			return 0;
	}
	while( t[pos] != NULL){
		if(t[pos]->valor == e.valor){
			return 0;//se ja existe
		}
		pos = (pos+1)%N;//proxima posicao
	}
	if(t[pos] == NULL){//encontrou espaço vazio
		t[pos] = malloc(sizeof(Elemento));
		*(t[pos]) = e;//insere
	}
	return 1;
}

void imprimeHash(tbhash t){
	int i;
	for(i = 0; i<N; i++){
		if(t[i]!=0){
			printf("%d | %d\n", i, t[i]->valor);
		}
		else{
			printf("%d | NULO\n", i);
		}
	}
}

int main(){
	int colisoes=0;
	Elemento e;
	printf("\n==Sondagem linear==\n");
	tbhash h;
	inicializarHash(h);
	e.valor = 365;
	inserirHash(h, e, 1, &colisoes);
	e.valor = 112;
	inserirHash(h, e, 1, &colisoes);
	e.valor = 180;
	inserirHash(h, e, 1, &colisoes);
	e.valor = 213;
	inserirHash(h, e, 1, &colisoes);
	e.valor = 13;
	inserirHash(h, e, 1, &colisoes);
	e.valor = 27;
	inserirHash(h, e, 1, &colisoes);
	imprimeHash(h);
	printf("\n--colisoes sondagem linear = %d--\n", colisoes);
	colisoes = 0;
	printf("\n==Sondagem quadratica==\n");
	tbhash h1;
	inicializarHash(h1);
	e.valor = 365;
	inserirHash(h1, e, 2, &colisoes);
	e.valor = 112;
	inserirHash(h1, e, 2, &colisoes);
	e.valor = 180;
	inserirHash(h1, e, 2, &colisoes);
	e.valor = 213;
	inserirHash(h1, e, 2, &colisoes);
	e.valor = 13;
	inserirHash(h1, e, 2, &colisoes);
	e.valor = 27;
	inserirHash(h1, e, 2, &colisoes);
	imprimeHash(h1);
	printf("\n--colisoes sondagem quadratica = %d--\n", colisoes);
	colisoes = 0;
	printf("\n==Sondagem quadratica 2==\n");
	tbhash h2;
	inicializarHash(h2);
	e.valor = 365;
	inserirHash(h2, e, 3, &colisoes);
	e.valor = 112;
	inserirHash(h2, e, 3, &colisoes);
	e.valor = 180;
	inserirHash(h2, e, 3, &colisoes);
	e.valor = 213;
	inserirHash(h2, e, 3, &colisoes);
	e.valor = 13;
	inserirHash(h2, e, 3, &colisoes);
	e.valor = 27;
	inserirHash(h2, e, 3, &colisoes);
	imprimeHash(h2);
	printf("\n--colisoes sondagem quadratica 2= %d--\n", colisoes);
	colisoes = 0;
	printf("\n==Hash duplo==\n");
	tbhash h3;
	inicializarHash(h3);
	e.valor = 365;
	inserirHash(h3, e, 4, &colisoes);
	e.valor = 112;
	inserirHash(h3, e, 4, &colisoes);
	e.valor = 180;
	inserirHash(h3, e, 4, &colisoes);
	e.valor = 213;
	inserirHash(h3, e, 4, &colisoes);
	e.valor = 13;
	inserirHash(h3, e, 4, &colisoes);
	e.valor = 27;
	inserirHash(h3, e, 4, &colisoes);
	imprimeHash(h3);
	printf("\n--colisoes hashduplo= %d--\n", colisoes);
	return 0;
}
