
#include <stdio.h>
#include <assert.h>

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

int main() {
    Semaforo semaforo;

    // Teste 1: estado inicial.
    inicializar(&semaforo);
    assert(semaforo.estado == VERMELHO);
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
    atualizar(&semaforo, 60);
    assert(semaforo.estado == VERMELHO);
    assert(semaforo.tempo_decorrido == 0);
    printf("Teste 5: Ciclo completo - OK\n");

    printf("\nTodos os testes foram aprovados!\n");

    return 0;
}
