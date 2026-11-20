
#include <stdio.h>

typedef enum {
    VERMELHO,
    VERDE,
    AMARELO
} Estado;

typedef struct {
    Estado estado;
    unsigned int tempo_decorrido;
} Semaforo;

// Retorna a duração de cada estado.
unsigned int obterTempoEstado(Estado estado) {
    switch (estado) {
        case VERMELHO:
            return 30;

        case VERDE:
            return 25;

        case AMARELO:
            return 5;

        default:
            return 0;
    }
}

// Retorna o nome do estado atual.
const char* obterNomeEstado(Estado estado) {
    switch (estado) {
        case VERMELHO:
            return "VERMELHO";

        case VERDE:
            return "VERDE";

        case AMARELO:
            return "AMARELO";

        default:
            return "DESCONHECIDO";
    }
}

// Inicializa o semáforo no estado vermelho.
void inicializar(Semaforo *s) {
    s->estado = VERMELHO;
    s->tempo_decorrido = 0;
}

// Avança para o próximo estado.
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

// Atualiza o tempo e realiza as transições necessárias.
void atualizar(Semaforo *s, unsigned int segundos) {
    s->tempo_decorrido += segundos;

    while (s->tempo_decorrido >= obterTempoEstado(s->estado)) {
        s->tempo_decorrido -= obterTempoEstado(s->estado);
        avancar(s);
    }
}
