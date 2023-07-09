#ifndef HASHLISTA_H_INCLUDED
#define HASHLISTA_H_INCLUDED
#define N 51

typedef struct{
	int cod_pac;
	char nome[20];
	char CPF[12];
	int idade;
}PACIENTE;

typedef struct No{
    PACIENTE paciente;
    struct No* proximo;
}No;

typedef No* tbhash[N];

void inicializarHash(tbhash t);
int m_hash(int cod_pac);
int inserirHash(tbhash t, PACIENTE p);
PACIENTE* busca(tbhash t, int cod_pac);
void imprimeHash(tbhash t);

#endif
