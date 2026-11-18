# 5. Room Allocation

**Fonte:** CSES Problem Set — Sorting and Searching — Task 1164
**Link:** https://cses.fi/problemset/task/1164
**Dificuldade:** médio
**Conceito treinado:** processar chegadas em ordem de tempo mantendo uma fila de prioridade
de "recursos" (quartos) e decidir qual recurso entregar a cada pedido.

## Enunciado (tradução livre)
Um hotel tem `n` hóspedes, cada um querendo um quarto só para si. Cada hóspede tem um dia
de chegada e um dia de saída. Dois hóspedes podem usar o mesmo quarto se o primeiro sair
**antes** do dia em que o segundo chega. Qual o número mínimo de quartos necessário para
acomodar todos? Mostre também em qual quarto fica cada hóspede.

## Entrada
- Primeira linha: `n`.
- Próximas `n` linhas: `a` e `b`, dia de chegada e de saída do hóspede.

## Saída
- Primeira linha: `k`, o número mínimo de quartos.
- Segunda linha: o quarto de cada hóspede, na ordem da entrada (quartos numerados de 1 a `k`).
  Qualquer alocação válida é aceita.

## Limites
- 1 ≤ n ≤ 2·10^5
- 1 ≤ a ≤ b ≤ 10^9

## Exemplo
Entrada:
```
3
1 2
2 4
4 4
```
Saída:
```
2
1 2 1
```

## Perguntas-guia
- Ao ordenar os hóspedes por chegada, você perde o índice original. Como recuperá-lo para imprimir a resposta?
- Que informação sobre os quartos ocupados você precisa consultar rapidamente a cada chegada?
