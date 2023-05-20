#ifndef RETANGULO_H_INCLUDED
#define RETANGULO_H_INCLUDED
typedef struct{
	float larg;
	float alt;
	float comp;
}RETANGULO;

RETANGULO *cria_retangulo();
int tam(RETANGULO *ret);
int area(RETANGULO *ret);
int volume(RETANGULO *ret);
void libera(RETANGULO *ret);

#endif
