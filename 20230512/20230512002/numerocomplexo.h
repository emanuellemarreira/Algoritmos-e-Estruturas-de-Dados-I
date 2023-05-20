#ifndef NUMEROCOMPLEXO_H_INCLUDED
#define NUMEROCOMPLEXO_H_INCLUDED

typedef struct{
	float real;
	float img;
}NCOMPLEXO;

NCOMPLEXO* cria_complexo();
int soma_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3);
int subtracao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3);
int multiplicacao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3);
int divisao_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3);
void destroi_complexo(NCOMPLEXO *n1, NCOMPLEXO *n2, NCOMPLEXO *n3);

#endif


