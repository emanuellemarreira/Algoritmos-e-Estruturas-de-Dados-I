#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} ARVORE;

void inicializarArvore(ARVORE* a) {
    a->raiz = NULL;
}

void destruirArvore(No* a) {
    if (a != NULL) {
        destruirArvore(a->direita);
        destruirArvore(a->esquerda);
        free(a);
    }
}

No* inserirNo(No* raiz, No* no) {
    if (raiz == NULL) {
        return no;
    }//sem valores repetidos
    if (no->valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, no);
    }
    else if (no->valor > raiz->valor){
    	raiz->direita = inserirNo(raiz->direita, no);
	}
	else{
		return no;
	}
   /* 
   if (no->valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, no);
    } else {//o igual entra aqui e pode add iguais na direita
        raiz->direita = inserirNo(raiz->direita, no);
    }*/
    return raiz;
}

void adiciona(ARVORE* a, No* no) {
    a->raiz = inserirNo(a->raiz, no);
}

void adicionarArvore(ARVORE* a, int valor) {
    No* novono = malloc(sizeof(No));
    novono->valor = valor;
    novono->esquerda = NULL;
    novono->direita = NULL;
    adiciona(a, novono);
}

No* buscarNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscarNo(raiz->esquerda, valor);
    } else {
        return buscarNo(raiz->direita, valor);
    }
}

No* buscar(ARVORE* a, int valor) {
    return buscarNo(a->raiz, valor);
}

void excluirNo(ARVORE* a, int valor) {
    No* meuno = a->raiz;
    No* pai = NULL;
    while (meuno != NULL && meuno->valor != valor) {
        pai = meuno;
        if (valor < meuno->valor) {
            meuno = meuno->esquerda;
        } else {
            meuno = meuno->direita;
        }
    }
    if (meuno == NULL) {
        return;
    }

    // folha
    if (meuno->esquerda == NULL && meuno->direita == NULL) {
        if (pai == NULL) {
            a->raiz = NULL;
        } else if (pai->esquerda == meuno) {
            pai->esquerda = NULL;
        } else {
            pai->direita = NULL;
        }
        free(meuno);
    }
    // um filho
    else if (meuno->esquerda == NULL || meuno->direita == NULL) {
        No* filho;
        if (meuno->esquerda != NULL) {
            filho = meuno->esquerda;
        } else {
            filho = meuno->direita;
        }
        if (pai == NULL) {
            a->raiz = filho;
        } else if (pai->esquerda == meuno) {
            pai->esquerda = filho;
        } else {
            pai->direita = filho;
        }
        free(meuno);
    }
    // dois filhos
    else {
        No* pai_sucessor = meuno;
        No* sucessor = meuno->esquerda;
        while (sucessor->direita != NULL) {
            pai_sucessor = sucessor;
            sucessor = sucessor->direita;
        }
        meuno->valor = sucessor->valor;
        if (pai_sucessor->esquerda == sucessor) {
            pai_sucessor->esquerda = sucessor->esquerda;
        } else {
            pai_sucessor->direita = sucessor->esquerda;
        }
        free(sucessor);
    }
}

void percorrerLargura(ARVORE* a) {
    if (a->raiz == NULL) {
        return;
    }

    No* fila[100];
    int inicio = 0;
    int fim = 0;
    fila[fim++] = a->raiz;

    while (inicio != fim) {
        No* noAtual = fila[inicio++];
        printf("%d ", noAtual->valor);

        if (noAtual->esquerda != NULL) {
            fila[fim++] = noAtual->esquerda;
        }

        if (noAtual->direita != NULL) {
            fila[fim++] = noAtual->direita;
        }
    }
}

int maior(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int altura(No* raiz) {
    if (raiz == NULL) {
        return -1;
    }
    int altura_esquerda = altura(raiz->esquerda);
    int altura_direita = altura(raiz->direita);
    return maior(altura_esquerda, altura_direita) + 1;
}

int profundidade(No* raiz, int valor, int cont) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->valor == valor) {
        return cont;
    }
    if (valor < raiz->valor) {
        cont++;
        return profundidade(raiz->esquerda, valor, cont);
    } else {
        cont++;
        return profundidade(raiz->direita, valor, cont);
    }
}

int main() {
    ARVORE minhaArvore;
    inicializarArvore(&minhaArvore);

    adicionarArvore(&minhaArvore, 9);
    adicionarArvore(&minhaArvore, 5);
    adicionarArvore(&minhaArvore, 3);
    adicionarArvore(&minhaArvore, 6);
    adicionarArvore(&minhaArvore, 7);
    adicionarArvore(&minhaArvore, 14);
    adicionarArvore(&minhaArvore, 12);
    adicionarArvore(&minhaArvore, 10);
    adicionarArvore(&minhaArvore, 15);
    printf("\naltura = %d\n", altura(minhaArvore.raiz));
    int cont = 0;
    printf("\nprofundidade = %d\n", profundidade(minhaArvore.raiz, 14, cont));
    printf("\nPercurso em largura:\n");
    percorrerLargura(&minhaArvore);
    printf("\nTentando adicionar repetido:\n");
    adicionarArvore(&minhaArvore, 15);
    percorrerLargura(&minhaArvore);
    excluirNo(&minhaArvore, 7);
    printf("\nexcluindo folha = ");
    percorrerLargura(&minhaArvore);
    excluirNo(&minhaArvore, 12);
    printf("\nexcluindo com 1 filho = ");
    percorrerLargura(&minhaArvore);
    excluirNo(&minhaArvore, 5);
    printf("\nexcluindo com 2 filho = ");
    percorrerLargura(&minhaArvore);
    destruirArvore(minhaArvore.raiz);
    return 0;
}

