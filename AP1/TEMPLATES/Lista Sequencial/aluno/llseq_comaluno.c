#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    int codigo;
    char nome[100];
    int idade;
    int filhos;
} Aluno;

typedef struct {
    int qtd_elem_validos;
    Aluno matriculas[MAX];
} Lista;

Lista* inicializarLista() {
    Lista* m = malloc(sizeof(Lista));
    if (m != NULL) {
        m->qtd_elem_validos = 0;
    }
    return m;
}

int tamanho(Lista* lista) {
    if (lista == NULL) {
        return 0;
    } else {
        return lista->qtd_elem_validos;
    }
}

int cheia(Lista* lista) {
    if (lista == NULL) {
        return 0;
    }
    if (lista->qtd_elem_validos == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int vazia(Lista* lista) {
    if (lista == NULL) {
        return 0;
    }
    if (lista->qtd_elem_validos == 0) {
        return 1;
    } else {
        return 0;
    }
}

void imprimir(Lista* lista) {
    int i;
    for (i = 0; i < lista->qtd_elem_validos; i++) {
        printf("\nNome: %s", lista->matriculas[i].nome);
        printf("\nCodigo: %d", lista->matriculas[i].codigo);
        printf("\nIdade: %d", lista->matriculas[i].idade);
        printf("\nFilhos: %d", lista->matriculas[i].filhos);
        printf("\n--------\n");
    }
}

int inserirFim(Lista* lista, Aluno novoaluno) {
    if (cheia(lista) == 1) {
        return 0;
    }
    lista->matriculas[lista->qtd_elem_validos] = novoaluno;
    lista->qtd_elem_validos++;
    return 1;
}

int inserirInicio(Lista* lista, Aluno novoaluno) {
    int i;
    if (cheia(lista) == 1) {
        return 0;
    }
    for (i = lista->qtd_elem_validos - 1; i >= 0; i--) {
        lista->matriculas[i + 1] = lista->matriculas[i];
    }
    lista->matriculas[0] = novoaluno;
    lista->qtd_elem_validos++;
    return 1;
}

int inserirPosDesejada(Lista* lista, Aluno novoaluno, int pos) {
    int i;
    if (cheia(lista) == 1 || pos >= MAX || pos < 0) {
        return 0;
    }
    for (i = lista->qtd_elem_validos - 1; i >= pos; i--) {
        lista->matriculas[i + 1] = lista->matriculas[i];
    }
    lista->matriculas[pos] = novoaluno;
    lista->qtd_elem_validos++;
    return 1;
}

int buscaSeqOrd(Lista* lista, int codaluno) {
    int i;
    for (i = 0; i < lista->qtd_elem_validos; i++) {
        if (lista->matriculas[i].codigo >= codaluno) {
            if (lista->matriculas[i].codigo == codaluno) {
                return i;
            }
        }
    }
    return -1;
}

int buscaSequencial(Lista* lista, int codaluno) {
    int i;
    for (i = 0; i < lista->qtd_elem_validos; i++) {
        if (lista->matriculas[i].codigo == codaluno) {
            return i;
        }
    }
    return -1;
}

int inserirOrdenado(Lista* lista, Aluno novoaluno) {
    int busca, i;
    if (cheia(lista) == 1) {
        return 0;
    }
    busca = buscaSequencial(lista, novoaluno.codigo);
    if (busca != -1) {
        return 0;
    }
    for (i = 0; i < lista->qtd_elem_validos; i++) {
        if (lista->matriculas[i].codigo > novoaluno.codigo) {
            inserirPosDesejada(lista, novoaluno, i);
            return 1;
        }
    }
    return inserirFim(lista, novoaluno);
}

int busca_binaria_iterativa(Lista* lista, int codaluno) {
    if (lista == NULL) {
        return 0;
    }
    int primeiro = 0, meio = -1, ultimo = lista->qtd_elem_validos - 1, comp = 0;
    printf("\nBUSCA BINARIA ITERATIVA\n");
    while (primeiro <= ultimo) {
        meio = primeiro + (ultimo - primeiro) / 2;
        comp++;
        if (codaluno == lista->matriculas[meio].codigo) {
            printf("\nvalor encontrado em lista[%d]", meio);
            printf("\nquantidade de comparacoes necessarias: %d\n", comp);
            return 1;
        } else {
            comp++;
            if (codaluno > lista->matriculas[meio].codigo) {
                primeiro = meio + 1;
            } else {
                comp++;
                ultimo = meio - 1;
            }
        }
    }
    printf("\nvalor nao encontrado!");
    return 0;
}

int excluirPelaPos(Lista* lista, int pos) {
    int i;
    if (vazia(lista) == 1 || pos >= lista->qtd_elem_validos || pos < 0) {
        return 0;
    }
    for (i = pos; i < lista->qtd_elem_validos - 1; i++) {
        lista->matriculas[i] = lista->matriculas[i + 1];
    }
    lista->qtd_elem_validos--;
    return 1;
}

int excluirPeloValor(Lista* lista, int codaluno) {
    int i;
    if (vazia(lista) == 1) {
        return 0;
    }
    int pos = buscaSeqOrd(lista, codaluno);
    if (pos == -1) {
        return 0;
    }
    for (i = pos; i < lista->qtd_elem_validos - 1; i++) {
        lista->matriculas[i] = lista->matriculas[i + 1];
    }
    lista->qtd_elem_validos--;
    return 1;
}

int alterarPeloValor(Lista* lista, int codaluno, Aluno novoaluno) {
    int i;
    if (vazia(lista) == 1) {
        return 0;
    }
    int pos = buscaSeqOrd(lista, codaluno);
    if (pos == -1) {
        return 0;
    }
    lista->matriculas[pos] = novoaluno;
    return 1;
}

void liberar(Lista* lista) {
    lista->qtd_elem_validos = 0;
    free(lista);
}

int main() {
    Lista* l1;
    l1 = inicializarLista();
    //printf("\ncheia: %d", cheia(l1));
    //printf("\nvazia: %d\n", vazia(l1));
    Aluno aluno1;
    aluno1.codigo = 1;
    aluno1.filhos = 0;
    aluno1.idade = 19;
    strcpy(aluno1.nome, "alberto");

    Aluno aluno2;
    aluno2.codigo = 2;
    aluno2.filhos = 1;
    aluno2.idade = 38;
    strcpy(aluno2.nome, "beatrizo");

    Aluno aluno3;
    aluno3.codigo = 3;
    aluno3.filhos = 0;
    aluno3.idade = 90;
    strcpy(aluno3.nome, "carlos");

    Aluno aluno4;
    aluno4.codigo = 4;
    aluno4.filhos = 2;
    aluno4.idade = 23;
    strcpy(aluno4.nome, "daniel");

    Aluno aluno5;
    aluno5.codigo = 5;
    aluno5.filhos = 2;
    aluno5.idade = 45;
    strcpy(aluno5.nome, "emanuel");

    inserirFim(l1, aluno4);
    inserirInicio(l1, aluno1);
    inserirFim(l1, aluno5);
    inserirPosDesejada(l1, aluno3, 2);
    inserirOrdenado(l1, aluno2);
    imprimir(l1);
    //printf("\ncheia: %d", cheia(l1));
    //printf("\nvazia: %d\n", vazia(l1));
    printf("\nbusca seq ordenada: %d", buscaSeqOrd(l1, aluno4.codigo));
    printf("\nbusca sequencial: %d", buscaSequencial(l1, aluno4.codigo));
    printf("\nbusca binaria: %d", busca_binaria_iterativa(l1, aluno4.codigo));
    printf("\nexcluindo do fim: ");
    excluirPelaPos(l1, l1->qtd_elem_validos - 1);
    imprimir(l1);
    printf("\nexcluindo do inicio: ");
    excluirPelaPos(l1, 0);
    imprimir(l1);
    printf("\nexcluindo pelo valor: ");
    excluirPeloValor(l1, aluno4.codigo);
    imprimir(l1);
    printf("\nalterando valor: ");
    Aluno novoaluno;
    novoaluno.codigo = 5;
    novoaluno.filhos = 2;
    novoaluno.idade = 45;
    strcpy(novoaluno.nome, "novo carlos");
    alterarPeloValor(l1, aluno3.codigo, novoaluno);
    imprimir(l1);
    liberar(l1);
    return 0;
}

