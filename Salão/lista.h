#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cardapio.h"


// Estrutura do pedido
typedef struct no {
    char prato[45];
    struct no *proximo;
} No;

typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

void adicionar_pedido_inicio(No **cabeca);
void remover_pedido();
void exibir_pedido(No *cabeca);
const char* converte_prato(int numero);
void percorrer_lista(No *cabeca);

#endif