# 3. Concert Tickets

**Fonte:** CSES Problem Set — Sorting and Searching — Task 1091
**Link:** https://cses.fi/problemset/task/1091
**Dificuldade:** fácil/médio
**Conceito treinado:** `multiset` com busca do "maior elemento ≤ x" e remoção dinâmica.

## Enunciado (tradução livre)
Há `n` ingressos para um show, cada um com um preço. Em seguida chegam `m` clientes, um
de cada vez. Cada cliente informa o preço máximo que aceita pagar e recebe o ingresso de
**maior preço que não ultrapasse** esse máximo. Esse ingresso é retirado (não pode ser
vendido de novo). Se não houver ingresso possível, o cliente fica sem ingresso.

## Entrada
- Primeira linha: `n` e `m`.
- Segunda linha: os `n` preços dos ingressos.
- Terceira linha: os `m` preços máximos dos clientes, na ordem de chegada.

## Saída
Para cada cliente, o preço pago, ou `-1` se ficar sem ingresso.

## Limites
- 1 ≤ n, m ≤ 2·10^5
- 1 ≤ preços ≤ 10^9

## Exemplo
Entrada:
```
5 3
5 3 7 8 5
4 8 3
```
Saída:
```
3
8
-1
```

## Perguntas-guia
- Qual a diferença entre `lower_bound` e `upper_bound` num `multiset`? Qual dos dois te dá o "maior ≤ x"?
- Por que `ms.erase(valor)` é perigoso num `multiset` e `ms.erase(iterador)` não é?
