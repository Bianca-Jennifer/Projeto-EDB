#include <stdio.h>
#include "lista.h"
#include "menu.h"
#include "fila.h"


int numero;

int main(){
    No *cabeca = NULL;

    Fila f;
    iniciar_fila(&f);

    menu(&f, &cabeca);
    return 0;
}