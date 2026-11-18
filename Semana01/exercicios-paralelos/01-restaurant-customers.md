# 1. Restaurant Customers

**Fonte:** CSES Problem Set — Sorting and Searching — Task 1619
**Link:** https://cses.fi/problemset/task/1619
**Dificuldade:** fácil (seção Sorting and Searching do CSES)
**Conceito treinado:** transformar intervalos em eventos (entrada/saída), ordenar e varrer.

## Enunciado (tradução livre)
São dados os horários de chegada e saída de `n` clientes de um restaurante. Qual é o
número máximo de clientes presentes no restaurante ao mesmo tempo?

## Entrada
- Primeira linha: `n`, o número de clientes.
- Próximas `n` linhas: dois inteiros `a` e `b`, horário de chegada e de saída de um cliente.
- Todos os horários de chegada e saída são distintos.

## Saída
Um inteiro: o número máximo de clientes presentes simultaneamente.

## Limites
- 1 ≤ n ≤ 2·10^5
- 1 ≤ a < b ≤ 10^9

## Exemplo
Entrada:
```
3
5 8
2 4
3 9
```
Saída:
```
2
```

## Perguntas-guia
- Se eu listar todos os "acontecimentos" no tempo, em que ordem preciso processá-los?
- Por que não dá para percorrer o tempo minuto a minuto?