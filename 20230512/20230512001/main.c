#include "retangulo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	RETANGULO *meuret;
	if(meuret == NULL){
		return -1;
	}
	meuret = cria_retangulo();
	tam(meuret);
	area(meuret);
	volume(meuret);
	libera(meuret);
	return 0;
}

