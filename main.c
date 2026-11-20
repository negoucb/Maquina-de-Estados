
#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Declarações compartilhadas com semaforo.c.
typedef enum {
    VERMELHO,
    VERDE,
    AMARELO
} Estado;

typedef struct {
    Estado estado;
    unsigned int tempo_decorrido;
} Semaforo;

void inicializar(Semaforo *s);
void atualizar(Semaforo *s, unsigned int segundos);
const char* obterNomeEstado(Estado estado);
unsigned int obterTempoEstado(Estado estado);

int main() {
    Semaforo semaforo;
    Estado estadoAnterior;

    inicializar(&semaforo);

    printf("=== SIMULACAO DE SEMAFORO ===\n");
    printf("Estado atual: %s\n",
           obterNomeEstado(semaforo.estado));

    while (1) {
        estadoAnterior = semaforo.estado;

#ifdef _WIN32
        Sleep(1000);
#else
        sleep(1);
#endif

        atualizar(&semaforo, 1);

        if (semaforo.estado != estadoAnterior) {
            printf("Estado atual: %s\n",
                   obterNomeEstado(semaforo.estado));
        }
    }

    return 0;
}
