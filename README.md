# Máquina de Estados: Simulação de um Semáforo em C

Trabalho prático em que uma máquina de estados simples é implementada em C e validada por testes automatizados de estados, transições e caminhos.

**Instituição:** Universidade Católica de Brasília  
**Curso:** Ciência da Computação  
**Autor:** Gabriel da Silva Campos

## Sobre o projeto

O sistema simula um semáforo com três estados que se repetem em ciclo. A mudança de um estado para o seguinte acontece quando o tempo do estado atual termina.

### Estados

| Estado | Duração |
|---|---|
| Vermelho (E1) | 30 segundos |
| Verde (E2) | 25 segundos |
| Amarelo (E3) | 5 segundos |

O semáforo sempre inicia no **Vermelho** e completa um ciclo a cada 60 segundos.

### Transições

| Transição | Estado atual | Evento | Condição | Próximo estado |
|---|---|---|---|---|
| T1 | Vermelho | EV1 – Término do vermelho | Após 30 segundos | Verde |
| T2 | Verde | EV2 – Término do verde | Após 25 segundos | Amarelo |
| T3 | Amarelo | EV3 – Término do amarelo | Após 5 segundos | Vermelho |

## Estrutura dos arquivos

```
.
├── semaforo.c   # Lógica da máquina de estados
├── main.c       # Simulação em tempo real
├── test.c       # Testes automatizados
└── README.md
```

| Arquivo | Responsabilidade |
|---|---|
| `semaforo.c` | Define os estados, os tempos e as funções de inicialização, atualização e transição. |
| `main.c` | Executa a simulação, controla a passagem do tempo e mostra cada mudança de estado na tela. |
| `test.c` | Contém os testes automatizados, escritos com `assert`. |

### Funções de `semaforo.c`

| Função | O que faz |
|---|---|
| `inicializar(Semaforo *s)` | Define o estado inicial como vermelho e zera o tempo decorrido. |
| `atualizar(Semaforo *s, unsigned int segundos)` | Soma os segundos ao tempo decorrido e avança de estado sempre que a duração do estado atual é atingida. Pode fazer mais de uma transição em uma só chamada. |
| `avancar(Semaforo *s)` | Passa para o próximo estado (Vermelho → Verde → Amarelo → Vermelho). |
| `obterTempoEstado(Estado estado)` | Retorna a duração de cada estado. Para um estado inválido, retorna `0`. |
| `obterNomeEstado(Estado estado)` | Retorna o nome do estado como texto. Para um estado inválido, retorna `"DESCONHECIDO"`. |

## Como compilar e executar

Os comandos abaixo usam o `gcc` e funcionam em Linux, macOS e Windows (com MinGW).

### Simulação do semáforo

```bash
gcc main.c semaforo.c -o semaforo
./semaforo
```

No Windows, execute `semaforo.exe`. A simulação roda sem parar, então use `Ctrl + C` para encerrar.

Exemplo de saída:

```
=== SIMULACAO DE SEMAFORO ===
Estado atual: VERMELHO
Estado atual: VERDE        (após 30 segundos)
Estado atual: AMARELO      (após mais 25 segundos)
Estado atual: VERMELHO     (após mais 5 segundos)
```

### Testes automatizados

```bash
gcc test.c semaforo.c -o test
./test
```

Se todos os testes passarem, a saída é:

```
Teste 1: Estado inicial - OK
Teste 2: Vermelho para verde - OK
Teste 3: Verde para amarelo - OK
Teste 4: Amarelo para vermelho - OK
Teste 5: Ciclo completo - OK
Teste 6: Tempos dos estados e default - OK
Teste 7: Nomes dos estados e default - OK
Teste 8: Atualizacao sem transicao - OK
Teste 9: Multiplas transicoes - OK

Todos os testes foram aprovados!
```

Se algum teste falhar, o programa é interrompido pelo `assert` e indica a linha do erro.

## Testes

| Teste | O que verifica |
|---|---|
| 1 | Estado inicial: vermelho, com tempo decorrido igual a zero. |
| 2 | Transição de vermelho para verde, aos 30 segundos. |
| 3 | Transição de verde para amarelo, aos 25 segundos. |
| 4 | Transição de amarelo para vermelho, aos 5 segundos. |
| 5 | Ciclo completo de 60 segundos, voltando ao vermelho com o contador zerado. |
| 6 | Duração de cada estado e valor padrão (`default`) para estado inválido. |
| 7 | Nome de cada estado e texto padrão (`default`) para estado inválido. |
| 8 | Atualização sem transição, quando o tempo ainda não terminou. |
| 9 | Múltiplas transições em uma única atualização. |

## Complexidade ciclomática de McCabe

Cada função foi analisada separadamente. Nos `switch`, cada `case` conta como uma decisão e o `default` não conta.

| Função | Estruturas de decisão | V(G) |
|---|---|---|
| `main()` | 1 `while` e 1 `if` | 3 |
| `atualizar()` | 1 `while` | 2 |
| `avancar()` | `switch` com 3 casos, sem `default` | 4 |
| `obterTempoEstado()` | `switch` com 3 casos e `default` | 4 |
| `obterNomeEstado()` | `switch` com 3 casos e `default` | 4 |
| `inicializar()` | Nenhuma | 1 |
| **Total** | | **18** |

## Observações

- No Windows, a espera de um segundo usa `Sleep()` (`windows.h`). Nos demais sistemas, usa `sleep()` (`unistd.h`).
- O estado do semáforo é guardado em uma `struct Semaforo`, com o estado atual (`enum Estado`) e o tempo decorrido em segundos.
