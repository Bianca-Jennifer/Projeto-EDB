#include <stdio.h>

const char* prato(int numero);

int main() {
    int numero;
    printf("Escolha um prato para adicionar: ");
    scanf("%d", &numero);
    printf("%s foi adicionado ao pedido\n", prato(numero));
    return 0;
}

const char* prato(int numero) {
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
        default: return "Este item não está no cardápio!";
    }
}