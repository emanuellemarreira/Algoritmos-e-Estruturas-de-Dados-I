#ifndef HASH1007_H_INCLUDED
#define HASH1007_H_INCLUDED
#define N 11

typedef struct{
	int valor;
}Elemento;

typedef Elemento* tbhash[N];

void inicializarHash(tbhash t);
int sondagem_linear(tbhash t, Elemento e);
int sondagem_quadratica(tbhash t, Elemento e);
int sondagem_quadratica2(tbhash t, Elemento e);
int hash_duplo(tbhash t, Elemento e);
void imprimeHash(tbhash t);


#endif
