# 2. Two TVs

**Fonte:** Codeforces — Educational Codeforces Round 27 — Problema 845C
**Link:** https://codeforces.com/problemset/problem/845/C
**Dificuldade:** rating 1500
**Conceito treinado:** eventos ordenados no tempo com recursos limitados; tratar com cuidado
o que acontece quando dois eventos caem no mesmo instante.

## Enunciado (resumo em português)
Polycarp quer assistir a `n` programas de TV. O programa `i` começa no instante `l_i` e
termina no instante `r_i`. Ele tem **duas** TVs. Cada TV mostra apenas um programa por vez,
e, se um programa termina exatamente no instante em que outro começa, os dois **não** podem
ser mostrados na mesma TV. Ele consegue assistir a todos os `n` programas usando só as duas TVs?

## Entrada
- Primeira linha: `n`.
- Próximas `n` linhas: `l_i` e `r_i`.

## Saída
`YES` se for possível, `NO` caso contrário.

## Limites
- 1 ≤ n ≤ 2·10^5
- 0 ≤ l_i < r_i ≤ 10^9

## Exemplos
Entrada:
```
3
1 2
2 3
4 5
```
Saída:
```
YES
```

Entrada:
```
4
1 2
2 3
2 3
1 2
```
Saída:
```
NO
```

> Resumo escrito de memória (o site bloqueou a leitura automática). Confira os detalhes
> no enunciado original.

## Perguntas-guia
- Quando um fim e um início ocorrem no mesmo instante, qual deve vir primeiro na sua ordenação? Por quê?
