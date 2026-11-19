#include <stdio.h>

// Definição dos estados do semáforo
typedef enum {
    VERMELHO,
    VERDE,
    AMARELO
} Estado;

// Estrutura do semáforo
typedef struct {
    Estado estado;
} Semaforo;

// Inicializa o semáforo
void inicializar(Semaforo *s) {
    s->estado = VERMELHO;
}

// Avança para o próximo estado
void avancar(Semaforo *s) {
    switch (s->estado) {
        case VERMELHO:
            s->estado = VERDE;
            break;

        case VERDE:
            s->estado = AMARELO;
            break;

        case AMARELO:
            s->estado = VERMELHO;
            break;
    }
}

// Retorna o nome do estado atual
const char *obterEstado(Semaforo *s) {
    switch (s->estado) {
        case VERMELHO:
            return "Vermelho";

        case VERDE:
            return "Verde";

        case AMARELO:
            return "Amarelo";

        default:
            return "Estado inválido";
    }
}
