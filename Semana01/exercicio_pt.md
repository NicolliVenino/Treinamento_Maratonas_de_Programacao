# L. Berland.Taxi
limite de tempo por teste: 3 segundos

limite de memória por teste: 256 megabytes

A Berland.Taxi é uma nova empresa de táxi, com k carros, que começou a operar há pouco tempo na capital de Berland. A capital tem n casas dispostas em uma linha reta, numeradas de 1 (mais à esquerda) a n (mais à direita), e a distância entre duas casas vizinhas quaisquer é a mesma.

Você deve ajudar a empresa a organizar todas as corridas de táxi que chegam ao longo do dia, de acordo com as seguintes regras:

Todos os carros estão disponíveis para buscar passageiros. Inicialmente, o j-ésimo carro está localizado ao lado da casa de número x<sub>j</sub> no instante 0.
Todos os carros têm a mesma velocidade. Qualquer carro leva exatamente 1 minuto para ir entre as casas vizinhas i e i + 1.
O i-ésimo pedido de corrida de táxi chega no instante t<sub>i</sub>, solicitando que um passageiro seja buscado na casa a<sub>i</sub> e deixado na casa b<sub>i</sub>. Os pedidos de corrida são dados em ordem crescente de t<sub>i</sub>. Todos os t<sub>i</sub> são distintos.

Quando um pedido de corrida é recebido no instante t<sub>i</sub>, o operador da Berland.Taxi designa um carro para ele da seguinte forma:

- Dentre os carros que estão disponíveis no momento, o operador designa o carro mais próximo do ponto de embarque a<sub>i</sub>. Nem é preciso dizer que, se um carro já está em uma corrida com um passageiro, ele não estará disponível para nenhuma corrida até que esse passageiro seja deixado no respectivo destino.
- Se houver vários carros nessa condição, o operador escolherá aquele que está esperando há mais tempo, desde que ficou disponível.
- Se ainda houver vários carros nessa condição, o operador escolherá aquele de menor número.

Depois que um carro é designado para o pedido de corrida:

- O motorista imediatamente começa a dirigir da posição atual até a casa a<sub>i</sub>.
- Assim que o carro chega à casa a<sub>i</sub>, o passageiro é imediatamente embarcado e o motorista começa a dirigir até a casa b<sub>i</sub>.
- Assim que a casa b<sub>i</sub> é alcançada, o passageiro é deixado e o carro fica disponível para novas corridas, parado ao lado da casa b<sub>i</sub>.
- É permitido que vários carros estejam ao lado da mesma casa no mesmo instante, seja esperando por pedidos de corrida, seja apenas passando por ali.

Se não houver carros disponíveis no instante t<sub>i</sub> em que um pedido de corrida chega, então:

- O i-ésimo passageiro terá que esperar até que um carro fique disponível.
- Quando um carro ficar disponível, o operador o designará imediatamente a esse pedido de corrida.
- Se vários carros ficarem disponíveis ao mesmo tempo enquanto o passageiro espera, o operador escolherá um deles de acordo com as regras descritas acima.

O operador processa os pedidos de corrida um por um. Portanto, se vários passageiros estiverem esperando que carros fiquem disponíveis, o operador não passará ao processamento do (i + 1)-ésimo pedido até que um carro seja designado ao i-ésimo pedido.

Sua tarefa é escrever um programa que processe a lista dada de m pedidos de corrida de táxi. Para cada pedido, você deve descobrir qual carro será designado a ele e quanto tempo o passageiro terá que esperar até a chegada do carro. Observe que, se já houver um carro na casa a<sub>i</sub>, o tempo de espera correspondente será 0.

### Entrada
A primeira linha da entrada contém os inteiros n, k e m (2 ≤ n ≤ 2·10<sup>5</sup>, 1 ≤ k, m ≤ 2·10<sup>5</sup>) — o número de casas, o número de carros e o número de pedidos de corrida de táxi. A segunda linha contém os inteiros x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>k</sub> (1 ≤ x<sub>i</sub> ≤ n) — as posições iniciais dos carros. x<sub>i</sub> é o número da casa em que o i-ésimo carro está localizado inicialmente. É permitido que mais de um carro esteja ao lado da mesma casa inicialmente.

As m linhas seguintes contêm as informações dos pedidos de corrida. Cada pedido é representado pelos inteiros t<sub>j</sub>, a<sub>j</sub> e b<sub>j</sub> (1 ≤ t<sub>j</sub> ≤ 10<sup>12</sup>, 1 ≤ a<sub>j</sub>, b<sub>j</sub> ≤ n, a<sub>j</sub> ≠ b<sub>j</sub>), onde t<sub>j</sub> é o instante, em minutos, em que o pedido é feito, a<sub>j</sub> é a casa onde o passageiro deve ser buscado e b<sub>j</sub> é a casa onde o passageiro deve ser deixado. Os pedidos de corrida são dados em ordem crescente de t<sub>j</sub>. Todos os t<sub>j</sub> são distintos.

### Saída
Imprima m linhas: a j-ésima linha deve conter dois números inteiros, a resposta para o j-ésimo pedido de corrida — o número do carro designado pelo operador e o tempo de espera do passageiro.

Exemplos


| # | Entrada | Saída |
|---|---------|-------|
| 1 | <pre>10 1 2<br>3<br>5 2 8<br>9 10 3</pre> | <pre>1 1<br>1 5</pre> |
| 2 | <pre>5 2 1<br>1 5<br>10 3 5</pre> | <pre>1 2</pre> |
| 3 | <pre>5 2 2<br>1 5<br>10 3 5<br>20 4 1</pre> | <pre>1 2<br>2 1</pre> |

### Nota

No primeiro exemplo, um pedido chega no instante 5 e o carro precisa ir da casa 3 até a casa 2 para buscar o passageiro. Portanto, o tempo de espera será 1 e a corrida será concluída no instante 5 + 1 + 6 = 12. O segundo pedido chega no instante 9, então o passageiro terá que esperar o carro ficar disponível no instante 12, e depois o carro precisa de mais 2 minutos para ir da casa 8 até a casa 10. Assim, o tempo total de espera é 3 + 2 = 5.

No segundo exemplo, os carros 1 e 2 estão à mesma distância do primeiro passageiro e têm o mesmo "tempo de espera desde que ficaram disponíveis". O carro 1 vence o desempate segundo as regras, por ter o menor número. Ele chegará à casa 3 no instante 3, então o tempo de espera será 2.
