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

void adicionar_pedido_inicio(No **cabeca);
void remover_pedido();
void exibir_pedido(No *cabeca);
void enviar_pedido();
const char* converte_prato(int numero);

#endif