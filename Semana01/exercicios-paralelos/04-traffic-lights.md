# 4. Traffic Lights

**Fonte:** CSES Problem Set — Sorting and Searching — Task 1163
**Link:** https://cses.fi/problemset/task/1163
**Dificuldade:** médio
**Conceito treinado:** `set` ordenado para achar vizinhos (predecessor e sucessor) de um
ponto numa reta, mantendo a estrutura atualizada a cada inserção.

## Enunciado (tradução livre)
Uma rua vai da posição `0` até a posição `x`. Semáforos são colocados, um de cada vez, em
`n` posições inteiras distintas, todas estritamente entre `0` e `x`. Depois de cada
inserção, informe o comprimento do maior trecho da rua sem nenhum semáforo.

## Entrada
- Primeira linha: `x` e `n`.
- Segunda linha: as `n` posições dos semáforos, na ordem de inserção.

## Saída
Após cada inserção, o comprimento do maior trecho sem semáforo.

## Limites
- 1 ≤ x ≤ 10^9
- 1 ≤ n ≤ 2·10^5
- 0 < posição < x

## Exemplo
Entrada:
```
8 3
3 6 2
```
Saída:
```
5 3 3
```

## Perguntas-guia
- Dado um ponto novo `p`, como achar em O(log n) o ponto imediatamente à esquerda e à direita dele?
- Quais trechos deixam de existir e quais passam a existir quando `p` é inserido?
