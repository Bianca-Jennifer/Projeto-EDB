#include "menu.h"
#include "cardapio.h"
#include "lista.h"

void menu(No **cabeca) {
    int numero;

    while(1) {
        printf("\n");
        printf("1. Adicionar pedido\n");
        printf("2. Remover pedido\n");
        printf("3. Exibir pedido\n");
        printf("4. Enviar pedido\n");
        printf("\n");
        printf("Escolha uma opção para prosseguir: ");

        scanf("%d", &numero);

        switch (numero) {
            case 1: 
                clear();
                adicionar_pedido_inicio(cabeca);
                break;
            case 2:
                remover_pedido();
                break;
            case 3:
                clear();
                exibir_pedido(*cabeca);
                break;
            case 4:
                enviar_pedido();
                break;
            default:
                clear();
                printf("Opção inválida. Por favor, tente novamente.\n");
        }

    }
}

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}