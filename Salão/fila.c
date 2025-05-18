#include "fila.h"

void iniciar_fila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enviar_pedido(Fila *f, No *cabeca) {
    if(cabeca == NULL) {
        printf("--> Seu pedido está vazio.\n");
        return;
    }
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

    printf("--> Seu pedido foi enviado para a cozinha!\n");
}

void exibir_fila(Fila *f) {
    if(esta_vazia(f)) {
        printf("--> Não há nenhum pedido sendo preparado na cozinha...\n");
        return;
    }

    printf("Pedidos sendo preparados na cozinha:\n");

    No *temp = f->inicio;
    while(temp != NULL) {
        printf("--> %s\n", temp->prato);
        temp = temp->proximo;
    }
}

bool esta_vazia(Fila *f) {
  return f->inicio == NULL;
}