#include <stdlib.h>
#include <stdio.h>
#include "hash1207.h"


int main(){
	hash h;
	inicializarHash(h);
	inserirHash(h, 12);
	inserirHash(h, 44);
	inserirHash(h, 13);
	inserirHash(h, 88);
	inserirHash(h, 23);
	inserirHash(h, 94);
	inserirHash(h, 11);
	inserirHash(h, 39);
	inserirHash(h, 20);
	inserirHash(h, 16);
	inserirHash(h, 5);
	imprimirHash(h);
	
	return 0;
}
