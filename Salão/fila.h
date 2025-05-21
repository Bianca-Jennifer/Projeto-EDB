#ifndef FILA_H
#define FILA_H

#include "lista.h"
#include <stdbool.h>

void iniciar_fila(Fila *f);
void enviar_pedido(Fila *f, No **cabeca);
void exibir_fila(Fila *f);
bool esta_vazia(Fila *f);
void remover_na_fila(Fila *f);
void busca_geral_na_fila(Fila *f);
void busca_por_mesa_na_fila(Fila *f);
void busca_na_fila(Fila *f);
//void liberar_fila(Fila *f);
#endif