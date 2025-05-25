#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Base/cardapio.h"

// Definição da lista simplesmente encadeada de pedidos, que contém: item 
// do prato, nome do prato, tipo do prato (entrada [E], prato principal [P], 
// sobremesa [S]), mesa em que foi pedido e um ponteiro para o próximo
// elemento da lista.
typedef struct no {
    int item;
    char prato[45];
    char tipo;
    int identificador_mesa;
    struct no *proximo;
} No;

//--------------------------------------------------------------------------

// Definição da fila de pedidos com os elementos da lista encadeada.
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
void reiniciar_lista(No **cabeca);
bool lista_unitaria(No *cabeca);

#endif