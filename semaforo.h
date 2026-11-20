
#ifndef SEMAFORO_H
#define SEMAFORO_H

// Definição dos estados do semáforo
typedef enum {
    VERMELHO,
    VERDE,
    AMARELO
} Estado;

// Tempos de duração de cada estado (em segundos)
#define TEMPO_VERMELHO 30
#define TEMPO_VERDE 25
#define TEMPO_AMARELO 5

// Estrutura que armazena os dados do semáforo
typedef struct {
    Estado estado;
    unsigned int tempo_decorrido;
} Semaforo;

// Declaração das funções do sistema
void inicializar(Semaforo *s);
void atualizar(Semaforo *s, unsigned int segundos);
void avancar(Semaforo *s);
const char *obterNomeEstado(Estado estado);
unsigned int obterTempoEstado(Estado estado);

#endif
