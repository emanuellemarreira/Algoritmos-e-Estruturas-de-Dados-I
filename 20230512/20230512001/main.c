#include "retangulo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	RETANGULO *meuret;
	meuret = cria_retangulo();
	if(meuret == NULL){
		return -1;
	}
	tam(meuret);
	area(meuret);
	volume(meuret);
	libera(meuret);
	return 0;
}

