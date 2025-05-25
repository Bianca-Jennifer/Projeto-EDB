#include "lista.h"
#include "menu.h"

void adicionar_pedido_inicio(No **cabeca, int identificador_mesa) {

    // Exibe cardápio e lê entrada do item que será adicionado.
    cardapio();
    printf("Escolha um item para adicionar: ");
    int numero;
    scanf("%d", &numero);

    // Verifica se o número lido é válido (se o item está no cardápio).
    if(numero < 1 || numero > 15) {
        clear();
        printf("Este item não está no cardápio... Por favor, Tente novamente.\n");
        return;
    }

    // Aloca memória para o novo item.
    No *novo_no = malloc(sizeof(No));
    if(novo_no == NULL) {
        printf("--> Erro ao alocar memória!\n");
        return;
    }

    // Define o tipo do prato de acordo com o intervalo em que o item está.
    if (numero >= 1 && numero <= 5) {
        novo_no->tipo = 'E'; // Entrada
    } else if (numero >= 6 && numero <= 10) {
        novo_no->tipo = 'P'; // Prato principal
    } else if (numero >= 11 && numero <= 15) {
        novo_no->tipo = 'S'; // Sobremasa
    }

    // Atribui o item e o identificador da mesa do novo pedido.
    novo_no->item = numero;
    novo_no->identificador_mesa = identificador_mesa;

    // Cria uma variável char contante que recebe uma função para converter
    // o item no nome do prato.
    const char *prato = converte_prato(numero);

    // Copia o conteúdo da variável prato para o atributo prato do novo nó e completa com o caracter nulo.
    strncpy(novo_no->prato, prato, sizeof(novo_no->prato) - 1);
    novo_no->prato[sizeof(novo_no->prato) - 1] = '\0';
    novo_no->proximo = *cabeca;
    *cabeca = novo_no;

    // Limpa o terminal e imprime que o pedido foi adicionado.
    clear();
    printf("--> %s foi adicionado ao pedido!\n", prato);
}

void adicionar_pedido_fim(No **cabeca, int identificador_mesa) {

    // Verifica se a lista está vazia. Caso esteja, a função de adicionar pedido no início é chamada.
    if(*cabeca == NULL) {
        adicionar_pedido_inicio(cabeca, identificador_mesa);
        return;
    }

    // Exibe cardápio e lê entrada do item que será adicionado.
    cardapio();
    printf("Escolha um item para adicionar: ");
    int numero;
    scanf("%d", &numero);

    // Verifica se o número lido é válido (se o item está no cardápio).
    if(numero < 1 || numero > 15) {
        clear();
        printf("Este item não está no cardápio... Por favor, Tente novamente.\n");
        return;
    }

    // Aloca memória para o novo item.
    No *novo_no = malloc(sizeof(No));
    if(novo_no == NULL) {
        printf("  => Erro ao alocar memória!\n");
        return;
    }

    // Define o tipo do prato de acordo com o intervalo em que o item está.
    if (numero >= 1 && numero <= 5) {
        novo_no->tipo = 'E'; // Entrada
    } else if (numero >= 6 && numero <= 10) {
        novo_no->tipo = 'P'; // Prato principal
    } else if (numero >= 11 && numero <= 15) {
        novo_no->tipo = 'S'; // Sobremasa
    }

    // Atribui o item e o identificador da mesa do novo pedido.
    novo_no->item = numero;
    novo_no->identificador_mesa = identificador_mesa;

    // Copia o conteúdo da variável prato para o atributo prato do novo nó e completa com o caracter nulo.
    const char *prato = converte_prato(numero);
    strncpy(novo_no->prato, prato, sizeof(novo_no->prato) - 1);
    novo_no->prato[sizeof(novo_no->prato) - 1] = '\0';
    novo_no->proximo = NULL;

    // Define um novo No para percorrer a lista até o próximo elemento aponte pro NULL. Quando isso ocorrer,
    // o próximo nó do nó atual recebe o novo nó, inserindo ele no final da lista.
    No *atual = *cabeca;
    while(atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo_no;

    // Limpa o terminal e imprime que o pedido foi adicionado.
    clear();
    printf("--> %s foi adicionado ao pedido!\n", prato);
}

void adicionar_pedido_meio(No **cabeca, int identificador_mesa) {

    // Exibe o pedido atual através da função exibir pedido e lê a posição em que o item será adicionado.
    int posicao;
    exibir_pedido(*cabeca);
    printf("\nEscolha uma posição para adicionar o prato: ");
    scanf("%d", &posicao);

    // Verifica se a posição que o usuário quer adicionar é o início do pedido. Caso seja, a função
    // adicionar pedido no início é chamada.
    if(posicao == 0 || posicao == 1) {
        clear();
        adicionar_pedido_inicio(cabeca, identificador_mesa);
        return;
    }

    // Define dois nós de controle para um item anterior e um posterior ao novo nó que será adicionado.
    No *anterior = NULL;
    No *atual = *cabeca;
    int i = 1; // Variável contadora para garantir que o novo nó seja adicionado na posição correta.

    // Laço para chegar ao nó anterior a posição escolhida. A condição de parada é que o atual não seja nulo
    // e o contador i seja menor que a posição.
    while(atual != NULL && i < posicao) {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    // 
    if(atual == NULL) {
        clear();
        printf("Posição inválida!\n");
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
        printf("--> Erro ao alocar memória!\n");
        return;
    }

    if(numero >= 1 && numero <= 5) {
        novo_no->tipo = 'E';
    } else if (numero >= 6 && numero <= 10) {
        novo_no->tipo = 'P';
    } else if (numero >= 11 && numero <= 15) {
        novo_no->tipo = 'S';
    }

    novo_no->item = numero;
    novo_no->identificador_mesa = identificador_mesa;

    const char *prato = converte_prato(numero);
    strncpy(novo_no->prato, prato, sizeof(novo_no->prato) - 1);
    novo_no->prato[sizeof(novo_no->prato) - 1] = '\0';
    novo_no->proximo = atual;

    if(anterior != NULL) {
        anterior->proximo = novo_no;
    } else {
        *cabeca = novo_no;
    }

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

void remover_pedido_meio(No **cabeca) {
    int posicao;
    
    exibir_pedido(*cabeca);
    printf("\nEscolha uma posição para remover o prato: ");
    scanf("%d", &posicao);

    if(posicao == 0 || posicao == 1) {
        clear();
        remover_pedido_inicio(cabeca);
        return;
    }

    No *anterior = NULL;
    No *atual = *cabeca;
    int i = 1;

    while (atual != NULL && i < posicao){
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    if (atual == NULL){
        clear();
        printf("Posição inválida!\n");
        return;
    }

    anterior->proximo = atual->proximo;
    clear();
    printf("--> %s foi removido do pedido com sucesso!\n", atual->prato);
    free(atual);
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

    printf("Pedido atual:\n");

    No *atual = cabeca;
    int i = 1;
    
    while(atual != NULL){
        printf("    %d. [%c] %s\n", i, atual->tipo, atual->prato);
        atual = atual->proximo;
        i++;
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
