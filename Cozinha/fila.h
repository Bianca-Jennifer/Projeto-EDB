#ifndef FILA_H
#define FILA_H

#include "../Salao/lista.h"
#include <stdbool.h>

void iniciar_fila(Fila *f);//Iniciliza a fila composta por nós
void enviar_pedido(Fila *f, No **cabeca);//Adiciona a lista de pedidos na fila
void exibir_fila(Fila *f);//Exibe a fila ao expor os pratos com o identificador da mesa
bool esta_vazia(Fila *f);//Verifica se a fila está vazia
void remover_na_fila(Fila *f);//Remove o primeiro nó da fila
void busca_geral_na_fila(Fila *f);//Verifica se determinado prato existe na fila
void busca_por_mesa_na_fila(Fila *f);//Verifica se determinado prato de uma mesa x existe na fila
void busca_na_fila(Fila *f);//Função composta por "busca_geral_na_fila" e "busca_por_mesa_na_fila"
void liberar_fila(Fila *f);//Libera memória ao sair do programa
#endif