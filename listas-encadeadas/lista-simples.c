#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *proximo;
};

void imprimirLista(struct No *n) {
    printf("Lista: ");
    while (n != NULL) {
        printf("%d -> ", n->valor);
        n = n->proximo;
    }
    printf("NULL\n");
}

int main() {
    struct No *cabeca = NULL;
    struct No *segundo = NULL;
    struct No *terceiro = NULL;

    cabeca = (struct No*)malloc(sizeof(struct No));
    segundo = (struct No*)malloc(sizeof(struct No));
    terceiro = (struct No*)malloc(sizeof(struct No));

    cabeca->valor = 10;
    cabeca->proximo = segundo;

    segundo->valor = 20;
    segundo->proximo = terceiro;

    terceiro->valor = 30;
    terceiro->proximo = NULL;

    imprimirLista(cabeca);

    free(cabeca);
    free(segundo);
    free(terceiro);

    return 0;
}