#include "fila.h"
#include "menu.h"
#include "string.h"

void iniciar_fila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enviar_pedido(Fila *f, No **cabeca) {

    if (*cabeca == NULL) {
        printf("--> Seu pedido está vazio.\n");
        return;
    }

    No *atual = *cabeca;
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
        
        if (esta_vazia(f)){
            f->inicio = novo_no;
            f->fim = novo_no;
        }else{
            f->fim->proximo = novo_no;
            f->fim = novo_no;
        }

        atual = atual->proximo;
    }

    printf("--> O pedido foi enviado para a cozinha!\n");
    reiniciar_lista(cabeca);
}

void exibir_fila(Fila *f) {
    if(esta_vazia(f)) {
        printf("--> Não há nenhum pedido sendo preparado na cozinha...\n");
        return;
    }

    printf("Pedidos sendo preparados na cozinha:\n");

    No *temp = f->inicio;
    while(temp != NULL) {
        printf("--> [%c] %s -------- [Mesa %d]\n", temp->tipo, temp->prato, temp->identificador_mesa);
        temp = temp->proximo;
    }
}

bool esta_vazia(Fila *f) {
  return f->inicio == NULL;
}

void remover_na_fila(Fila *f){
  if(esta_vazia(f)){
    printf("  => Não há nenhum pedido na cozinha!\n");
    return;
  }
 
  No *temp = f->inicio;

  f->inicio = f->inicio->proximo;

  if(f->inicio == NULL)
    f->fim = NULL;

  free(temp);

  printf("--> Pedido removido!\n");
 
  return;
}

void busca_por_mesa_na_fila(Fila *f){

    int identificador_mesa;
    printf("Digite o número da mesa: ");
    scanf("%d", &identificador_mesa);
    printf("\n\n");

    int item;
    cardapio();
    printf("\nDigite o item que deseja verificar: ");
    scanf("%d", &item);

    if(esta_vazia(f)){
    printf("--> Não há nenhum pedido na cozinha!\n");
    return;
    }
  
    No *temp = f->inicio;
    char prato[45];

    int cond_cont = 0;
    while(temp != NULL){
        if (temp->item == item & temp->identificador_mesa == identificador_mesa) {
            cond_cont++;
            if (cond_cont) strcpy(prato, temp->prato);
        }
        temp = temp->proximo;
    }

    clear();

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

    int item;
    cardapio();
    printf("\nDigite o item que deseja verificar: ");
    scanf("%d", &item);

    clear();

    if(esta_vazia(f)){
    printf("--> Não há nenhum pedido na cozinha!\n");
    return;
    }

    No *temp = f->inicio;
    char prato[45];

    
    int cond_cont = 0;
    while(temp != NULL){
        if (temp->item == item) {
            cond_cont++;
            if (cond_cont) strcpy(prato, temp->prato);
            printf("%d.--> %s -------- Mesa %d\n", cond_cont, prato, temp->identificador_mesa);
        }
        temp = temp->proximo;
    }

    if (cond_cont == 0) {
        printf("--> O pedido não existe na cozinha!\n");
    } 
}

void busca_na_fila(Fila *f){
    int op;

    do {
        printf("\n");
        printf("1. Busca geral\n");
        printf("2. Busca por mesa\n");
        printf("0. Voltar\n");
        printf("\nEscolha uma opção para prosseguir: \n");

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

/*void liberar_fila(Fila *f) {
    if(esta_vazia(f)) {
        printf("--> Não há nenhum pedido sendo preparado na cozinha!\n");
        return -1;
    }

    No *temp = f->inicio;

    int valor = temp->
}*/
