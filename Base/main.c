#include <stdio.h>
#include "../Salao/lista.h"
#include "menu.h"
#include "../Cozinha/fila.h"

int numero;

int main(){
    No *cabeca = NULL;

    Fila f;
    iniciar_fila(&f);

    menu(&f, &cabeca);
    return 0;
}