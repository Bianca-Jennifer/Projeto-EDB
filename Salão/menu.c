#include "menu.h"
#include "cardapio.h"
#include "lista.h"
#include "fila.h"

void menu(Fila *f, No **cabeca) {
    int numero_menu, numero_salao, numero_cozinha, numero_adicionar, numero_remover;
    int numero_menu_adicionar = -1;
    int numero_menu_remover = -1;

    clear();

    do {
        printf("\n");
        printf("1. Salão\n");
        printf("2. Cozinha\n");
        printf("0. Sair do programa\n");
        printf("\n");
        printf("Escolha uma opção para prosseguir: ");

        scanf("%d", &numero_menu);

        switch(numero_menu) {
            case 1:
                clear();

                int identificador_mesa;
                printf("Digite o número da mesa: ");
                scanf("%d",&identificador_mesa);
                do {
                    printf("\n");
                    printf("============== Mesa %d ==============\n", identificador_mesa);
                    printf("1. Adicionar pedido\n");
                    printf("2. Remover pedido\n");
                    printf("3. Exibir pedido\n");
                    printf("4. Enviar pedido\n");
                    printf("0. Voltar ao menu inicial\n");
                    printf("\n");
                    printf("Escolha uma opção para prosseguir: ");

                    scanf("%d", &numero_salao);

                    switch (numero_salao) {
                        case 1: 
                            clear();

                            if(*cabeca == NULL) {
                                adicionar_pedido_inicio(cabeca, identificador_mesa);
                            }

                            do {
                                printf("\n");
                                printf("1. Adicionar pedido no início\n");
                                printf("2. Adicionar pedido no meio\n");
                                printf("3. Adicionar pedido no fim\n");
                                printf("0. Voltar ao menu\n");
                                printf("\n");
                                printf("Escolha uma opção para prosseguir: ");

                                scanf("%d", &numero_adicionar);

                                switch(numero_adicionar) {
                                    case 1:
                                        clear();
                                        adicionar_pedido_inicio(cabeca, identificador_mesa);
                                        break;
                                    case 2: 
                                        clear();
                                        //adicionar_pedido_meio(cabeca, identificador_mesa);
                                        break;
                                    case 3:
                                        clear();
                                        adicionar_pedido_fim(cabeca, identificador_mesa);
                                        break;
                                    case 0:
                                        numero_menu_adicionar = 0;
                                        clear();
                                        break;
                                    default:
                                        clear();
                                        printf("Opção inválida. Por favor, tente novamente.\n");
                                }
                            } while (numero_menu_adicionar != 0);
                            break;       
                        case 2:
                            clear();

                            do {
                                if(*cabeca == NULL) {
                                    remover_pedido_inicio(cabeca);
                                    numero_menu_remover = 0;
                                    break;
                                }

                                printf("\n");
                                printf("1. Remover pedido no início\n");
                                printf("2. Remover pedido no meio\n");
                                printf("3. Removerr pedido no fim\n");
                                printf("0. Voltar ao menu\n");
                                printf("\n");
                                printf("Escolha uma opção para prosseguir: ");

                                scanf("%d", &numero_remover);

                                switch(numero_remover) {
                                    case 1:
                                        clear();
                                        remover_pedido_inicio(cabeca);
                                        break;
                                    case 2: 
                                        clear();
                                        //remover_pedido_meio(cabeca);
                                        break;
                                    case 3:
                                        clear();
                                        remover_pedido_fim(cabeca);
                                        break;
                                    case 0:
                                        numero_menu_remover = 0;
                                        clear();
                                        break;
                                    default:
                                    clear();
                                    printf("Opção inválida. Por favor, tente novamente.\n");
                                }
                            } while (numero_menu_remover != 0);
                            break;
                        case 3:
                            clear();
                            exibir_pedido(*cabeca);
                            break;
                        case 4:
                            clear();
                            enviar_pedido(f, cabeca);
                            numero_salao = 0;
                            break;
                        case 0:
                            if(*cabeca != NULL) {
                                clear();
                                printf("--> O pedido ainda não foi enviado à cozinha. Finalize o pedido antes de voltar ao menu inicial.\n");
                                numero_salao = -1;
                                break;
                            }
                            else {
                                numero_salao = 0;
                                clear();
                                break;
                            }
                        default:
                            clear();
                            printf("Opção inválida. Por favor, tente novamente.\n");
                    }
                } while(numero_salao != 0);
                break;
            case 2:
                clear();
                do {
                    printf("\n");
                    printf("1. Exibir pedidos na cozinha\n");
                    printf("2. Remover pedido na cozinha\n");
                    printf("3. Verificar pedido na cozinha\n");
                    printf("0. Voltar ao menu principal\n");
                    printf("\n");
                    printf("Escolha uma opção para prosseguir: ");
                    
                    scanf("%d", &numero_cozinha);

                    switch(numero_cozinha) {
                        case 1:
                            clear();
                            exibir_fila(f);
                            break;
                        case 2:
                            clear();
                            remover_na_fila(f);
                            break;
                        case 3:
                            clear();
                            busca_na_fila(f);
                            clear();
                            break;          
                        case 0:
                            numero_cozinha = 0;
                            clear();
                            break;
                        default:
                            clear();
                            printf("Opção inválida. Por favor, tente novamente.\n");
                    }
                } while(numero_cozinha != 0);
                break;
            case 3:
                numero_menu = 0;
        } 
    } while(numero_menu != 0);
}

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    printf("Pressione Enter para voltar.\n");
    getchar();
}