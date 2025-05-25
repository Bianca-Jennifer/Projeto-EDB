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

void adicionar_pedido_inicio(No **cabeca, int identificador_mesa); // Adiciona um novo nó ao início da lista.
void adicionar_pedido_fim(No **cabeca, int identificador_mesa); // Adiciona um novo nó ao fim da lista.
void adicionar_pedido_meio(No **cabeca, int identificador_mesa); // Adiciona um novo nó na posição escolhida pelo usuário, caso
                                                                 // ela não esteja vazia.
void remover_pedido_inicio(No **cabeca); // Remove o primeiro nó da lista.
void remover_pedido_meio(No **cabeca); // Remove o nó da posição escolhida pelo usuário, caso ela não esteja vazia.
void remover_pedido_fim(No **cabeca); // Remove o último nó da lista
void exibir_pedido(No *cabeca); // Imprime todos os pedidos feitos atualmente, exibindo uma lista numerada com o tipo e nome de cada prato.
const char* converte_prato(int numero); // Converte o número do item do cardápio no nome do prato.
void reiniciar_lista(No **cabeca); // Esvazia a lista.
bool lista_unitaria(No *cabeca); // Verifica se a lista possui apenas um elemento.

#endif