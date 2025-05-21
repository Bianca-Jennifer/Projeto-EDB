#include "lista.h"
#include "menu.h"

// Insere um prato no início da lista de pedidos
// Precisa ter um while para adicionar quantas vezes quiser
void adicionar_pedido_inicio(No **cabeca, int identificador_mesa) {
    cardapio();

    printf("Escolha um item para adicionar: ");
    int numero;
    scanf("%d", &numero);

    if(numero < 1 || numero > 15) {
        clear();
        printf("Este item não está no cardápio... Por favor, Tente novamente.\n");
        return;
    }


    No *novo_no = malloc(sizeof(No));
    if(novo_no == NULL) {
        printf("--> Erro ao alocar memória!\n");
        return;
    }

    novo_no->item = numero;
    novo_no->identificador_mesa = identificador_mesa;

    const char *prato = converte_prato(numero);
    strncpy(novo_no->prato, prato, sizeof(novo_no->prato) - 1);
    novo_no->prato[sizeof(novo_no->prato) - 1] = '\0';
    novo_no->proximo = *cabeca;
    *cabeca = novo_no;

    clear();
    printf("--> %s foi adicionado ao pedido!\n", prato);
}

void adicionar_pedido_fim(No **cabeca, int identificador_mesa) {
    if(*cabeca == NULL) {
        adicionar_pedido_inicio(cabeca, identificador_mesa);
        return;
    }

    cardapio();

    printf("Escolha um item para adicionar: ");
    int numero;
    scanf("%d", &numero);

    if(numero < 1 || numero > 15) {
        clear();
        printf("Este item não está no cardápio... Por favor, Tente novamente.\n");
        return;
    }

    No *novo_no = malloc(sizeof(No));
    if(novo_no == NULL) {
    printf("  => Erro ao alocar memória!\n");
    return;
    }

    novo_no->item = numero;
    novo_no->identificador_mesa = identificador_mesa;

    const char *prato = converte_prato(numero);
    strncpy(novo_no->prato, prato, sizeof(novo_no->prato) - 1);
    novo_no->prato[sizeof(novo_no->prato) - 1] = '\0';
    novo_no->proximo = NULL;

    No *atual = *cabeca;

    while(atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novo_no;

    clear();
    printf("--> %s foi adicionado ao pedido!\n", prato);
}

// Remove o primeiro prato da lista de pedidos
void remover_pedido_inicio(No **cabeca) {
    if(*cabeca == NULL) {
        printf("--> O Pedido está vazio.\n");
        return;
    }

    No *temp = *cabeca;
    *cabeca = (*cabeca)->proximo;
    printf("--> %s foi removido do pedido com sucesso!\n", temp->prato);
    free(temp);
}

void remover_pedido_fim(No **cabeca) {
    if(*cabeca == NULL || (*cabeca)->proximo == NULL) {
        remover_pedido_inicio(cabeca);
        return;
    }

    No *anterior = NULL;
    No *atual = *cabeca;

    while(atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = NULL;
    printf("--> %s foi removido do pedido com sucesso!\n", atual->prato);
    free(atual);
}

// Imprime todos os pratos da lista de pedidos
void exibir_pedido(No *cabeca) {
    if(cabeca == NULL) {
        printf("--> O pedido está vazio!\n");
        return;
    }

    printf("Pedido:\n");

    No *atual = cabeca;
    
    while(atual != NULL){
        printf("--> %s\n", atual->prato);
        atual = atual->proximo;
    }
}

const char* converte_prato(int numero) {
    switch(numero) {
        case 1: return "Sopa de Cebola";
        case 2: return "Salada Caesar";
        case 3: return "Bruschetta";
        case 4: return "Carpaccio de Carne";
        case 5: return "Camarão ao Alho";
        case 6: return "Lasanha à Bolonhesa";
        case 7: return "Filé Mignon com Fritas";
        case 8: return "Frango Grelhado com Legumes";
        case 9: return "Bacalhau à Gomes de Sá";
        case 10: return "Risoto de Cogumelos";
        case 11: return "Tiramisu";
        case 12: return "Cheesecake de Frutas Vermelhas";
        case 13: return "Mousse de Chocolate";
        case 14: return "Pudim de Leite";
        case 15: return "Sorvete de Baunilha com Calda de Morango";
    }
}

void reiniciar_lista(No **cabeca) {
    No *atual = *cabeca;

    while (atual != NULL) {
        No *vari_liberada = atual;
        atual = atual->proximo;
        free(vari_liberada);
    }
    *cabeca = NULL;  
}

bool lista_unitaria(No *cabeca) {
    return cabeca->proximo == NULL;
}
