#include "fila.h"

void iniciar_fila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void adicionar_na_fila(Fila *f, No *cabeca) {
    if(esta_vazia(f)) {
        f->inicio = cabeca;
    } else {
        f->fim->proximo = cabeca;
    }

    No *anterior = NULL;
    No *atual = cabeca;

    while(atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    f->fim = atual;
}

void exibir_fila(Fila *f) {
    if(esta_vazia(f)) {
        printf("--> A fila está vazia!\n");
        return;
    }

    No *temp = f->inicio;
    while(temp != NULL) {
        printf("%s\n", temp->prato);
        temp = temp->proximo;
    }
}

bool esta_vazia(Fila *f) {
  return f->inicio == NULL;
}