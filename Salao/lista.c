#include "lista.h"
#include "../Base/menu.h"

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

    // A variável prato recebe a função de converter número para o nome do prato e esse contaúdo é copiado
    // para o atributo prato do novo nó, completando os caracteres restantes com caracter nulo. O ponteiro
    // do novo nó aponta para o cabeça atual e o cabeça recebe o novo nó, pois agora esse nó é o primeiro
    // elemento da lista.
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

    // A variável prato recebe a função de converter número para o nome do prato e esse contaúdo é copiado
    // para o atributo prato do novo nó, completando os caracteres restantes com caracter nulo. O ponteiro
    // do novo nó aponta para o NULL, pois esse nó agora é o último da lista.
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
    // e o contador i seja menor que a posição para que o próximo seja o item a ser adicionado.
    while(atual != NULL && i < posicao) {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    // Verifica se o atual (que recebe cabeça) é igual a NULL. Se sim, a lista está vaiza e não é possível
    // adicionar no meio da lista.
    if(atual == NULL) {
        clear();
        printf("Posição inválida!\n");
        return;
    }

    // Exibe cardápio e lê entrada do item que será adicionado, caso a entrada tenha sido validada.
    clear();
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
    if(numero >= 1 && numero <= 5) {
        novo_no->tipo = 'E';
    } else if (numero >= 6 && numero <= 10) {
        novo_no->tipo = 'P';
    } else if (numero >= 11 && numero <= 15) {
        novo_no->tipo = 'S';
    }

    // Atribui o item e o identificador da mesa do novo pedido.
    novo_no->item = numero;
    novo_no->identificador_mesa = identificador_mesa;

    // A variável prato recebe a função de converter número para o nome do prato e esse contaúdo é copiado
    // para o atributo prato do novo nó, completando os caracteres restantes com caracter nulo. O ponteiro
    // do novo nó aponta pro atual.
    const char *prato = converte_prato(numero);
    strncpy(novo_no->prato, prato, sizeof(novo_no->prato) - 1);
    novo_no->prato[sizeof(novo_no->prato) - 1] = '\0';
    novo_no->proximo = atual;

    // Verifica se anterior é diferente de nulo. Caso seja, o próximo do nó anterior aponta pro novo nó. Mas,
    // caso o anterior for NULL, o cabeça recebe o novo nó.
    if(anterior != NULL) {
        anterior->proximo = novo_no;
    } else {
        *cabeca = novo_no;
    }

    // Limpa o terminal e imprime que o pedido foi adicionado.
    clear();
    printf("--> %s foi adicionado ao pedido!\n", prato);
}

void remover_pedido_inicio(No **cabeca) {

    // Verifica se a lista está vazia. Se estiver, não tem como remover um item.
    if(*cabeca == NULL) {
        printf("--> O Pedido está vazio.\n");
        return;
    }

    // Define uma variável temp para receber o cabeça e o cabeça recebe o próximo de cabeça, liberando
    // a variável temp, removendo o item do início da lista.
    No *temp = *cabeca;
    *cabeca = (*cabeca)->proximo;
    printf("--> %s foi removido do pedido com sucesso!\n", temp->prato);
    free(temp);
}

void remover_pedido_meio(No **cabeca) {

    // Exibe o pedido atual através da função exibir pedido e lê a posição em que o item será removido.
    int posicao;
    exibir_pedido(*cabeca);
    printf("\nEscolha uma posição para remover o prato: ");
    scanf("%d", &posicao);

    // Verifica se a posição que o usuário quer remover é o início do pedido. Caso seja, a função
    // remover pedido no início é chamada.
    if(posicao == 0 || posicao == 1) {
        clear();
        remover_pedido_inicio(cabeca);
        return;
    }

    // Define dois nós de controle para um item anterior e um posterior ao novo nó que será adicionado.
    No *anterior = NULL;
    No *atual = *cabeca;
    int i = 1;

    // Laço para chegar ao nó anterior a posição escolhida. A condição de parada é que o atual não seja nulo
    // e o contador i seja menor que a posição para que o próximo seja o item a ser adicionado.
    while (atual != NULL && i < posicao){
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    // Verifica se o atual (que recebe cabeça) é igual a NULL. Se sim, a lista está vaiza e não é possível
    // remover no meio da lista.
    if (atual == NULL){
        clear();
        printf("Posição inválida!\n");
        return;
    }

    // O próximo do anterior aponta para o próximo do atual e libera o atual, removendo ele do meio da lista.
    anterior->proximo = atual->proximo;
    clear();
    printf("--> %s foi removido do pedido com sucesso!\n", atual->prato);
    free(atual);
}

void remover_pedido_fim(No **cabeca) {

    // Verifica se a lista está vazia ou se ela possui apenas um elemento. Caso sim, a função de remover pedido
    // no início é chamada.
    if(*cabeca == NULL || (*cabeca)->proximo == NULL) {
        remover_pedido_inicio(cabeca);
        return;
    }

    // Define dois nós de controle para um item anterior e um posterior ao novo nó que será adicionado.
    No *anterior = NULL;
    No *atual = *cabeca;

    // Laço para chegar até o último nó da lisa.
    while(atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    // O próximo do nó anterior aponta para o NULL e libera o atual, removendo o último elemento da lista.
    anterior->proximo = NULL;
    printf("--> %s foi removido do pedido com sucesso!\n", atual->prato);
    free(atual);
}

void exibir_pedido(No *cabeca) {

    // Verifica se a lista está vazia.
    if(cabeca == NULL) {
        printf("--> O pedido está vazio!\n");
        return;
    }

    // Define um nó e uma variável contadora para percorrer a lista através do while e incrementando a variável
    // contadora (para exibir a quantidade de elementos na litsa) e, para cada item, é impressa sua posição, o
    // tipo do prato e seu nome.
    printf("Pedido atual:\n");
    No *atual = cabeca;
    int i = 1;
    while(atual != NULL){
        printf("    %d. [%c] %s\n", i, atual->tipo, atual->prato);
        atual = atual->proximo;
        i++;
    }
}

// Função que recebe o número (item do prato no cardápio) e retorna o nome do prato atribuído a cada valor pelo
// switch case.
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

    // Define uma varíavel para percorrer a lista. Enquanto ela for diferente de NULL, será atribuído o nó atual
    // a uma variável temporária e a atual recebe o próximo nó. Ao final, libera a variável temporária que armazenava
    // o conteúdo do nó atual. Fazendo isso até que a lista esteja completamente vazia.
    No *atual = *cabeca;
    while (atual != NULL) {
        No *vari_liberada = atual;
        atual = atual->proximo;
        free(vari_liberada);
    }
    *cabeca = NULL;  
}

// Verifica se a lista tem apenas um elemento, vendo se o próximo de cabeça aponta para o NULL.
bool lista_unitaria(No *cabeca) {
    return cabeca->proximo == NULL;
}