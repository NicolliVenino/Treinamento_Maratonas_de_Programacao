# Exercícios paralelos — Semana 01

Lista em progressão (fácil → difícil) de problemas clássicos para treinar habilidades de
**simulação**, **processamento de eventos no tempo** e **estruturas de dados ordenadas**
(`set`/`multiset`/`priority_queue`) com critérios de desempate.

| # | Problema | Juiz | Dificuldade | Conceito treinado |
|---|----------|------|-------------|-------------------|
| 1 | [Restaurant Customers](01-restaurant-customers.md) | CSES 1619 | Fácil | Varredura de eventos ordenados no tempo |
| 2 | [Two TVs](02-two-tvs.md) | Codeforces 845C | 1500 | Eventos + recursos limitados, cuidado com empates de tempo |
| 3 | [Concert Tickets](03-concert-tickets.md) | CSES 1091 | Fácil/Médio | `multiset` + `upper_bound`, remoção dinâmica |
| 4 | [Traffic Lights](04-traffic-lights.md) | CSES 1163 | Médio | `set` ordenado, vizinhos (predecessor/sucessor) |
| 5 | [Room Allocation](05-room-allocation.md) | CSES 1164 | Médio | Eventos + fila de prioridade de recursos livres |
| 6 | [Queue in the Train](06-queue-in-the-train.md) | Codeforces 1239C | 2300 | Simulação dirigida a eventos com várias estruturas e desempate por índice |

## Como usar
- Resolva na ordem. Antes de codar, escreva à mão a sequência de eventos de um caso pequeno.
- Para cada um, anote no devlog: qual estrutura usou, por quê, e qual a complexidade frente
  aos limites (~10^8 operações/s).
- Atenção a `long long` sempre que tempos passarem de ~2·10^9.

> Os enunciados abaixo são **resumos/traduções em português**. Em caso de dúvida, o
> enunciado original no link de cada arquivo é a referência.
