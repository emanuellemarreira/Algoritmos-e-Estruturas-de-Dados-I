#ifndef HASHVETOR_H_INCLUDED
#define HASHVETOR_H_INCLUDED
#define N 51

typedef struct{
	int cod_pac;
	char nome[100];
	int idade;
	char CPF[100];
}PACIENTE;

typedef PACIENTE* tbhash[N];

void inicializarHash(tbhash t);
int dispersao_hash(int cod_pac);
int inserirHash(tbhash t, PACIENTE p);
PACIENTE* busca(tbhash t, int cod_pac);
void imprimeHash(tbhash t);
int excluir(tbhash t, int cod_pac);

#endif
