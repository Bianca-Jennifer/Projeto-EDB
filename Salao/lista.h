#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cardapio.h"

// Estrutura do pedido
typedef struct no {
    int item;
    char prato[45];
    int identificador_mesa;
    char tipo;
    struct no *proximo;
} No;

typedef struct fila {
    No *inicio;
    No *fim;
} Fila;

void adicionar_pedido_inicio(No **cabeca, int identificador_mesa);
void adicionar_pedido_fim(No **cabeca, int identificador_mesa);
void adicionar_pedido_meio(No **cabeca, int identificador_mesa);
void remover_pedido_inicio(No **cabeca);
void remover_pedido_meio(No **cabeca);
void remover_pedido_fim(No **cabeca);
void exibir_pedido(No *cabeca);
const char* converte_prato(int numero);
void percorrer_lista(No *cabeca);
void reiniciar_lista(No **cabeca);
bool lista_vazia(No **cabeca);
bool lista_unitaria(No *cabeca);

#endif