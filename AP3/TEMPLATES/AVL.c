#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    int h;
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

int quantidadeNos(No* raiz){
	if (raiz == NULL){
		return 0;
	}
	return quantidadeNos(raiz->esquerda)+quantidadeNos(raiz->direita)+1;
}

int maximo(int v1, int v2) {
    if (v1 > v2) {
        return v1;
    } else {
        return v2;
    }
}

int altura(No* raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        return raiz->h;
    }
}

No* rot_direita(No* no_desb) {
    No* aux;
    aux = no_desb->esquerda;
    no_desb->esquerda = aux->direita;
    aux->direita = no_desb;

    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda)) + 1;
    aux->h = maximo(altura(aux->esquerda), altura(no_desb)) + 1;
    return aux;
}

No* rot_esquerda(No* no_desb) {
    No* aux;
    aux = no_desb->direita;
    no_desb->direita = aux->esquerda;
    aux->esquerda = no_desb;
    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda)) + 1;
    aux->h = maximo(altura(aux->direita), altura(no_desb)) + 1;
    return aux;
}

No* rot_esq_direita(No* no_desb) {
    no_desb->esquerda = rot_esquerda(no_desb->esquerda);
    return rot_direita(no_desb);
}

No* rot_dir_esquerda(No* no_desb) {
    no_desb->direita = rot_direita(no_desb->direita);
    return rot_esquerda(no_desb);
}

No* inserirAVL(No* raiz, No* no) {
    if (raiz == NULL) {  //condicao de parada
        return no;
    }
    if (raiz->valor > no->valor) {//adicionar igual se quiser repetir
        raiz->esquerda = inserirAVL(raiz->esquerda, no);
        if ((altura(raiz->direita) - altura(raiz->esquerda)) == 2) {
            if (no->valor < raiz->esquerda->valor) {
                raiz = rot_direita(raiz);
            } else {
                raiz = rot_esq_direita(raiz);
            }
        }
    } else {
        if (raiz->valor < no->valor) {
            raiz->direita = inserirAVL(raiz->direita, no);
            if ((altura(raiz->direita) - altura(raiz->esquerda)) == 2) {
                if (no->valor > raiz->direita->valor) {
                    raiz = rot_esquerda(raiz);
                } else {
                    raiz = rot_dir_esquerda(raiz);
                }
            }
        }
    }
    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita)) + 1;
    return raiz;
}

void adicionaAVL(ARVORE* a, int valor) {
    No* novono = malloc(sizeof(No));
    novono->valor = valor;
    novono->h = 0;
    novono->esquerda = NULL;
    novono->direita = NULL;
    a->raiz = inserirAVL(a->raiz, novono);
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

No* encontrarMinimo(No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

No* removerAVL(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    
    if (valor < raiz->valor) {
        raiz->esquerda = removerAVL(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = removerAVL(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            No* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;
            }
            free(temp);
        } else {
            No* temp = encontrarMinimo(raiz->direita);
            raiz->valor = temp->valor;
            raiz->direita = removerAVL(raiz->direita, temp->valor);
        }
    }

    if (raiz == NULL) {
        return raiz;
    }
    
    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita)) + 1;

    int balance = altura(raiz->esquerda) - altura(raiz->direita);

    if (balance > 1) {
        if (altura(raiz->esquerda->esquerda) >= altura(raiz->esquerda->direita)) {
            raiz = rot_direita(raiz);
        } else {
            raiz = rot_esq_direita(raiz);
        }
    } else if (balance < -1) {
        if (altura(raiz->direita->direita) >= altura(raiz->direita->esquerda)) {
            raiz = rot_esquerda(raiz);
        } else {
            raiz = rot_dir_esquerda(raiz);
        }
    }

    return raiz;
}

void remover(ARVORE* a, int valor) {
    a->raiz = removerAVL(a->raiz, valor);
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

void listarNos(No* raiz){
	if(raiz!=NULL){
		printf("Endereco: %p\n", raiz);
		printf("Esquerda: %p  Direita:%p\n", raiz->esquerda, raiz->direita);
		printf("Valor: %d\n", raiz->valor);
		listarNos(raiz->esquerda);
		listarNos(raiz->direita);
	}
}

void imprimirArvore(ARVORE *a){
	listarNos(a->raiz);
}

No* pre_ordem(No* raiz){//raiz  esquerda  direita
	if(raiz == NULL){
		return NULL;
	}
	printf("%d\n", raiz->valor);
	pre_ordem(raiz->esquerda);
	pre_ordem(raiz->direita);	
}

No* in_ordem(No* raiz){//esquerda  raiz   direita
	if(raiz == NULL){
		return NULL;
	}
	in_ordem(raiz->esquerda);
	printf("%d\n", raiz->valor);
	in_ordem(raiz->direita);
}

No* pos_ordem(No* raiz){//esquerda   direita  raiz
	if(raiz == NULL){
		return NULL;
	}
	pos_ordem(raiz->esquerda);
	pos_ordem(raiz->direita);
	printf("%d\n", raiz->valor);
}



int main() {
    ARVORE a;
    inicializarArvore(&a);
    adicionaAVL(&a, 5);
    adicionaAVL(&a, 10);
    adicionaAVL(&a, 20);
    adicionaAVL(&a, 30);
    adicionaAVL(&a, 40);
    adicionaAVL(&a, 50);
    adicionaAVL(&a, 60);
    printf("\naltura = %d\n", altura(a.raiz));
    int cont = 0;
    printf("\nprofundidade = %d\n", profundidade(a.raiz, 50, cont));
    printf("\nPercurso em largura:\n");
    percorrerLargura(&a);
    printf("\nTentando adicionar repetido:\n");
    adicionaAVL(&a, 60);
    percorrerLargura(&a);
    printf("\nExcluindo 30 = \n");
    remover(&a, 30);
    percorrerLargura(&a);
    destruirArvore(a.raiz);
    return 0;
}

