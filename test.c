
#include <stdio.h>
#include <assert.h>
#include <string.h>

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

// Protótipos das funções testadas.
void inicializar(Semaforo *s);
void atualizar(Semaforo *s, unsigned int segundos);
unsigned int obterTempoEstado(Estado estado);
const char* obterNomeEstado(Estado estado);
int estadoMudou(Estado atual, Estado anterior);

int main() {
    Semaforo semaforo;

    // Teste 1: estado inicial.
    inicializar(&semaforo);

    assert(semaforo.estado == VERMELHO);
    assert(semaforo.tempo_decorrido == 0);

    printf("Teste 1: Estado inicial - OK\n");

    // Teste 2: transição do vermelho para verde.
    atualizar(&semaforo, 29);
    assert(semaforo.estado == VERMELHO);

    atualizar(&semaforo, 1);
    assert(semaforo.estado == VERDE);

    printf("Teste 2: Vermelho para verde - OK\n");

    // Teste 3: transição do verde para amarelo.
    atualizar(&semaforo, 25);

    assert(semaforo.estado == AMARELO);

    printf("Teste 3: Verde para amarelo - OK\n");

    // Teste 4: transição do amarelo para vermelho.
    atualizar(&semaforo, 5);

    assert(semaforo.estado == VERMELHO);

    printf("Teste 4: Amarelo para vermelho - OK\n");

    // Teste 5: ciclo completo de 60 segundos.
    inicializar(&semaforo);
    atualizar(&semaforo, 60);

    assert(semaforo.estado == VERMELHO);
    assert(semaforo.tempo_decorrido == 0);

    printf("Teste 5: Ciclo completo - OK\n");

    // Teste 6: tempos dos estados e alternativa default.
    assert(obterTempoEstado(VERMELHO) == 30);
    assert(obterTempoEstado(VERDE) == 25);
    assert(obterTempoEstado(AMARELO) == 5);
    assert(obterTempoEstado((Estado)99) == 0);

    printf("Teste 6: Tempos dos estados e default - OK\n");

    // Teste 7: nomes dos estados e alternativa default.
    assert(strcmp(obterNomeEstado(VERMELHO), "VERMELHO") == 0);
    assert(strcmp(obterNomeEstado(VERDE), "VERDE") == 0);
    assert(strcmp(obterNomeEstado(AMARELO), "AMARELO") == 0);
    assert(strcmp(obterNomeEstado((Estado)99), "DESCONHECIDO") == 0);

    printf("Teste 7: Nomes dos estados e default - OK\n");

    // Teste 8: atualização sem completar o tempo do estado.
    inicializar(&semaforo);
    atualizar(&semaforo, 10);

    assert(semaforo.estado == VERMELHO);
    assert(semaforo.tempo_decorrido == 10);

    printf("Teste 8: Atualizacao sem transicao - OK\n");

    // Teste 9: múltiplas transições em uma atualização.
    inicializar(&semaforo);
    atualizar(&semaforo, 56);

    assert(semaforo.estado == AMARELO);
    assert(semaforo.tempo_decorrido == 1);

    printf("Teste 9: Multiplas transicoes - OK\n");

    printf("\nTodos os testes foram aprovados!\n");

    return 0;
}
