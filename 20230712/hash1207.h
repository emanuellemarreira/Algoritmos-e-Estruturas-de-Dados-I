#ifndef HASH1207_H_INCLUDED
#define HASH1207_H_INCLUDED
#define M 11

typedef struct No{
	int valor;
	struct No* proximo;	
}No;

typedef No* hash[M];

void inicializarHash(hash t);
int m_hash(int valor);
int inserirHash(hash t, int valor);
int busca(hash t, int valor);
void imprimirHash(hash t);


#endif
