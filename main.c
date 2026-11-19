#include <stdio.h>
#include "semaforo.c"

int main() {
    Semaforo semaforo;

    inicializar(&semaforo);

    printf("Estado inicial: %s\n",
           obterEstado(&semaforo));

    for (int i = 0; i < 6; i++) {
        avancar(&semaforo);

        printf("Novo estado: %s\n",
               obterEstado(&semaforo));
    }

    return 0;
}
