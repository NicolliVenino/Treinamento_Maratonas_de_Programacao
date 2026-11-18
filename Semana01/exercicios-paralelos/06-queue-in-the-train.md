# 6. Queue in the Train

**Fonte:** Codeforces Round #594 (Div. 1) — Problema 1239C (também Div. 2 — 1248E)
**Link:** https://codeforces.com/problemset/problem/1239/C
**Dificuldade:** rating 2300
**Conceito treinado:** simulação dirigida a eventos com várias estruturas ao mesmo tempo
(fila de prioridade de eventos, fila de espera, `set` de índices), regras de desempate
por menor índice e tempos grandes (`long long`).

## Enunciado (resumo em português)
Há `n` assentos numa fileira de um trem, numerados de 1 a `n` da esquerda para a direita,
e o passageiro `i` está sentado no assento `i`. À esquerda do assento 1 há um único tanque de
água quente. No instante `t_i` o passageiro `i` fica com vontade de ir buscar água. Cada
passageiro usa o tanque por exatamente `p` minutos e depois volta imediatamente ao assento.

Ninguém gosta de ficar em pé na fila. Por isso, quando o passageiro `i` quer ir, ele olha
para os assentos `1..i-1`: se **algum deles está vazio** (alguém à esquerda já está na fila),
ele espera sentado; caso contrário, ele vai para a fila. Se no mesmo instante vários
passageiros puderem ir, só o **mais à esquerda** (menor índice) vai; os outros esperam.
A fila do tanque é atendida em ordem de chegada.

Para cada passageiro, determine o instante em que ele recebe a água (termina de usar o tanque).

## Entrada
- Primeira linha: `n` e `p`.
- Segunda linha: `t_1, ..., t_n`.

## Saída
`n` inteiros: o instante em que cada passageiro recebe a água.

## Limites
- 1 ≤ n ≤ 10^5
- 1 ≤ p ≤ 10^9
- 0 ≤ t_i ≤ 10^9

## Exemplo
Entrada:
```
5 314
0 310 942 628 0
```
Saída:
```
314 628 1256 942 1570
```

> Resumo escrito de memória (o site bloqueou a leitura automática). O enunciado original
> tem detalhes importantes sobre **a ordem dos eventos que acontecem no mesmo instante**
> (alguém voltando ao assento × alguém decidindo ir). Leia o original antes de implementar.

## Perguntas-guia
- Quais são os tipos de evento da simulação? Para cada tipo, o que muda no estado?
- Quando dois eventos ocorrem no mesmo instante, em que ordem você deve processá-los?
- Quantas vezes, no total, cada passageiro entra e sai de cada estrutura? Isso dá qual complexidade?
