
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Declaração dos estados.
typedef enum {
    VERMELHO,
    VERDE,
    AMARELO
} Estado;

// Estrutura do semáforo.
typedef struct {
    Estado estado;
    unsigned int tempo_decorrido;
} Semaforo;

// Protótipos das funções.
void inicializar(Semaforo *s);
void atualizar(Semaforo *s, unsigned int segundos);
const char* obterNomeEstado(Estado estado);
int estadoMudou(Estado atual, Estado anterior);

int main() {
    Semaforo semaforo;
    Estado estadoAnterior;

    // Inicializa o semáforo.
    inicializar(&semaforo);

    printf("=== SIMULACAO DE SEMAFORO ===\n");
    printf("Estado atual: %s\n",
           obterNomeEstado(semaforo.estado));

    // Mantém a execução contínua.
    while (1) {
        estadoAnterior = semaforo.estado;

        // Aguarda um segundo.
#ifdef _WIN32
        Sleep(1000);
#else
        sleep(1);
#endif

        // Atualiza o tempo do semáforo.
        atualizar(&semaforo, 1);

        // Verifica se ocorreu uma mudança de estado.
     if (semaforo.estado != estadoAnterior) {
    printf("Estado atual: %s\n",
           obterNomeEstado(semaforo.estado));
}
    }

    return 0;
}
