#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

void iniciar_fila(Fila *f);
void adicionar_na_fila(Fila *f, No *cabeca);
void exibir_fila(Fila *f);
bool esta_vazia(Fila *f);

#endif