#include "fila.h"
#include "../Base/menu.h"
#include "string.h"


// Inicializa a fila vazia com seu início e fim apontando para o NULL.
void iniciar_fila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}


void enviar_pedido(Fila *f, No **cabeca) {

    // Verifica se a lista está vazia.
    if (*cabeca == NULL) {
        printf("--> Seu pedido está vazio.\n");
        return;
    }

    // Define um nó de controle que recebe o início da lista.
    No *atual = *cabeca;

    // While para percorrer a lista alocando memória para atribuir os valores do nó atual
    // para o novo nó.
    while (atual != NULL) {
        No *novo_no = (No *)malloc(sizeof(No));
        if (!novo_no){
            printf("--> Erro ao alocar memória!\n");
            return;
        }

        
        novo_no->item = atual->item;
        novo_no->proximo = NULL;
        novo_no->identificador_mesa = atual->identificador_mesa;
        strcpy(novo_no->prato, atual->prato);
        novo_no->tipo = atual->tipo;
        
        // Verifica se a lista está vazia. Se sim, o início e fim da fila recebem o novo nó. Caso
        // não esteja, o próximo item do final da lista recebe o novo nó e o fim aponta para ele.
        if (esta_vazia(f)){
            f->inicio = novo_no;
            f->fim = novo_no;
        }else{
            f->fim->proximo = novo_no;
            f->fim = novo_no;
        }
        
        // O nó atual recebe o próximo nó da lista encadeada.
        atual = atual->proximo;
    }

    printf("--> O pedido foi enviado para a cozinha!\n");
    reiniciar_lista(cabeca);
}

void exibir_fila(Fila *f) {

    // Verific se a fila está vazia.
    if(esta_vazia(f)) {
        printf("--> Não há nenhum pedido sendo preparado na cozinha...\n");
        return;
    }

    // Define um nó para percorrer a lista e imprimir para cada item o seu tipo, nome e a mesa
    // em que ele foi pedido.
    printf("Pedidos sendo preparados na cozinha:\n");
    No *temp = f->inicio;
    while(temp != NULL) {
        printf("--> [%c] %s -------- [Mesa %d]\n", temp->tipo, temp->prato, temp->identificador_mesa);
        temp = temp->proximo;
    }
}

// Verifica se a fila está vazia.
bool esta_vazia(Fila *f) {
  return f->inicio == NULL;
}


void remover_na_fila(Fila *f){

    // Verifica se a fila está vazia.
    if(esta_vazia(f)){
        printf("--> Não há nenhum pedido na cozinha!\n");
        return;
    }
    
    // Define uma variável temporária para receber o início da fila e o início da fila recebe
    // o próximo nó.
    No *temp = f->inicio;
    f->inicio = f->inicio->proximo;

    free(temp); // Libera a variável temp, removendo o primeiro nó da fila.

    printf("--> Pedido removido!\n");
    return;
}

void busca_por_mesa_na_fila(Fila *f){
    
    // Lê o número da mesa e do item que está sendo buscado.
    int identificador_mesa;
    printf("Digite o número da mesa: ");
    scanf("%d", &identificador_mesa);
    printf("\n\n");
    int item;
    cardapio();
    printf("\nDigite o item que deseja verificar: ");
    scanf("%d", &item);

    // Verifica se a fila está vazia.
    if(esta_vazia(f)) {
        printf("--> Não há nenhum pedido na cozinha!\n");
        return;
    }

    // Define uma variável temporária que recebe o início da fila. Define também um vetor para receber o nome do prato
    // e uma variável contadora para contar quantos itens foram achados.
    No *temp = f->inicio;
    char prato[45];
    int cond_cont = 0;

    // While para percorrer a fila e comparar os atributos item e número da mesa de cada nó com os passados pelo usuário.
    // Caso sejam iguais, é incrementado 1 na variável contadora e copia o nome do prato do nó para a variável prato.
    while(temp != NULL){
        if (temp->item == item & temp->identificador_mesa == identificador_mesa) {
            cond_cont++;
            if (cond_cont) strcpy(prato, temp->prato);
        }
        temp = temp->proximo; // A variável temporária recebe o próximo nó.
    }

    clear();

    // Caso a variável contadora seja zero, não há o pedido buscado na fila. Caso contrário, imprime quantos itens foram
    // encontrados, exibindo o nome e a mesa em que foi pedido.
    if (cond_cont == 0) {
        printf("--> O pedido não existe na cozinha!\n");
    } else {
        if (cond_cont == 1) {
            printf("\n1 pedido encontrado!\n");
            printf("--> %s -------- Mesa %d\n", prato, identificador_mesa);

        } else {
            printf("\n%d pedidos encontrados!\n", cond_cont);
            printf("--> %s -------- Mesa %d\n", prato, identificador_mesa);

        }
    }
}

void busca_geral_na_fila(Fila *f) {

    // Exibe o cardápio e o item que se deseja verificar.
    int item;
    cardapio();
    printf("\nDigite o item que deseja verificar: ");
    scanf("%d", &item);

    clear();

    // Verifica se a fila está vazia.
    if(esta_vazia(f)){
    printf("--> Não há nenhum pedido na cozinha!\n");
    return;
    }

    // Define uma variável temporária que recebe o início da fila. Define também um vetor para receber o nome do prato
    // e uma variável contadora para contar quantos itens foram achados.
    No *temp = f->inicio;
    char prato[45];
    int cond_cont = 0;

    // While para percorrer a fila e comparar o atributo item de cada nó com o passados pelo usuário.
    // Caso sejam iguais, é incrementado 1 na variável contadora e copia o nome do prato do nó para a variável prato,
    // imprimindo cada item que for encontrado.
    while(temp != NULL){
        if (temp->item == item) {
            cond_cont++;
            if (cond_cont) strcpy(prato, temp->prato);
            printf("%d.--> %s -------- Mesa %d\n", cond_cont, prato, temp->identificador_mesa);
        }
        temp = temp->proximo;
    }

    // Caso a variável contadora seja igual a 0, o pedido não existe na cozinha.
    if (cond_cont == 0) {
        printf("--> O pedido não existe na cozinha!\n");
    } 
}

void busca_na_fila(Fila *f){

    // Switch case para qual busca o usuário deseja realizar.
    int op;
    do {
        printf("\n");
        printf("1. Busca geral\n");
        printf("2. Busca por mesa\n");
        printf("0. Voltar\n");
        printf("\nEscolha uma opção para prosseguir: ");

        scanf("%d",&op);
        //while
        switch(op) {
            case 1:
                clear();
                busca_geral_na_fila(f);
                break;
            case 2: 
                clear();
                busca_por_mesa_na_fila(f);
                break;
            case 0:
                break;
            default:
                clear();
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
    } while(op != 0);
}

void liberar_fila(Fila *f) {
    
    // Define um nó para percorrer a fila.
    No *atual = f->inicio;

    // Percorre toda a fila armazenando o nó atual em um nó temporário e atribuindo ao atual o próximo nó e liberando
    // O conteúdo do nó temporário.
    while(atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    // O início e fim da fila recebem NULL para garantir que a fila esteja vazia.
    f->inicio = NULL;
    f->fim = NULL;
}