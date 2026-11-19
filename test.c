#include <stdio.h>
#include <assert.h>
#include "semaforo.c"

void testarEstadoInicial() {
    Semaforo s;
    inicializar(&s);

    assert(s.estado == VERMELHO);
    printf("Teste de estado inicial: OK\n");
}

void testarTransicoes() {
    Semaforo s;
    inicializar(&s);

    avancar(&s);
    assert(s.estado == VERDE);

    avancar(&s);
    assert(s.estado == AMARELO);

    avancar(&s);
    assert(s.estado == VERMELHO);

    printf("Teste de transicoes: OK\n");
}

void testarCicloCompleto() {
    Semaforo s;
    inicializar(&s);

    for (int i = 0; i < 3; i++) {
        avancar(&s);
    }

    assert(s.estado == VERMELHO);
    printf("Teste de ciclo completo: OK\n");
}

int main() {
    testarEstadoInicial();
    testarTransicoes();
    testarCicloCompleto();

    printf("\nTodos os testes passaram!\n");

    return 0;
}
