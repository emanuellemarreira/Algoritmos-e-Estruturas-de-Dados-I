#ifndef RETANGULO_H_INCLUDED
#define RETANGULO_H_INCLUDED
typedef struct{
	float larg;
	float alt;
	float comp;
}RETANGULO;

RETANGULO *cria_retangulo();
void tam(RETANGULO *ret);
void area(RETANGULO *ret);
void volume(RETANGULO *ret);
void libera(RETANGULO *ret);

#endif
