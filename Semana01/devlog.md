## Objetivo da Semana
Aprender Linguagem e ferramentas: ferramentas	STL (vector, pair, set, map, priority_queue, sort, lower_bound), I/O rápido, int vs long long, complexidade.

## Meu raciocínio sozinha ao máximo:

#include <bits/stdc++.h>
using namespace std;

```
int main(){
    int num_casas, num_carros, num_pedidos;
    int carro_escolhido = 0; 
    cin >> num_casas >> num_carros >> num_pedidos; 
    vector<int> pos_carro;
    int pos;
    vector<bool> disp_carros; 
    while(num_carros--){
        cin >> pos;
        pos_carro.push_back(pos);
        // todos os carros começam como disponiveis
        disp_carros.push_back(true);
    }
    while(num_pedidos--){
        int t, origem, destino; // vou tratar cada um de uma vez
        cin >> t >> origem >> destino; 
        // preciso encontrar o carro escolhido
        
        // eu também preciso ver quando o carro vai ficar disponivel de novo, eu podia criar uma função para isso
        // mas seria tipo 
        // eu tenho o tempo de pedido 
        // eu consigo calcular o tempo de viagem por que de uma casa a outra é 1 minuto
        // seria
        // tempo de viagem = tempo de chegar ao passageiro + tempo da origem ao destino
        // t_ao_passageiro = dist (modulo da origem - pos_do_carro)
        // origem_ao_destino = modulo do destino - origem


        // eu tenho o tempo atual que é t 
        // se o tempo que o carro começou (que era o tempo atual dele) + tempo de viagem dele for menor ou igual ao instante atual ele pode ficar disponivel de novo.


        // para escolher um carro eu preciso:
        // 1) descobrir o carro de pos inicial mais prox da origem que não esteja em viagem
        // para fazer isso eu preciso:
        // 1.1) pegar todos os carros que encontram-se como disponiveis
        // 1.1.1) decretar o que é estar disponivel:
        // vou precisar declarar uma variavel de "label" para marcar se um carro foi selecionado ao não (disponivel ou não)
        // eu penso em talvez criar um struct para o carro, onde um carro tem um num, uma posição atual (que começa com a atual) e uma label de se esta disponivel ou não (se t>x)
        // mas eu acho que a proposta não é essa e pode ficar muito complexo, vou pensar
        // eu preciso atribuir uma label de disponivel em cada carro, cada carro hoje é uma chave de um vetor carros que tem uma pos
        // o que eu posso fazer ao inves de criar um struct é um outro vetor que armaneza o num do carro e se ele esta disponivel ou não. eu vou ter que fazer com que esses vetores conversem entre si em alguns momentos para atualizar a pos do carro 
        // 1.2) percorrer todos esses carros, comparar com a origem (subtracao modulo) q pegar o de menor valor
        vector<int> distancias;
        for (int i = 0; i<num_carros; i++){
            int t_passageiro = abs(origem - pos_carro[0]);
            int t_origem_destino = abs(destino - origem);
            int tempo_de_viagem = t_passageiro + t_origem_destino;
            if (tempo_de_viagem)
            if (disp_carros[i]){
                int dist = abs(origem - pos_carro[i]);
                // salvar numa lista para comparar 
                distancias.push_back(dist);
            }

        }
        int menor_distancia = *min_element(distancias.begin(), distancias.end());
        vector<int> dist_menores;

        for (int i = 0; i < static_cast<int>(distancias.size()); ++i) {
            if (distancias[i] == menor_distancia) {
                dist_menores.push_back(i);
            }
        }
        // boa, aqui eu peguei todos os indices que correspondem a menor distancia. se for só 1 eu escolho ele mesmo, se forem mais eu vou para o passo 2 

        // 2) SE existir mais de um carro na pos mais proxima da origem, eu escolho o carro que esta mais tempo esperando 
        if (dist_menores.size() > 1){
            // preciso verfificar qual carro está mais tempo esperando
            // para fazer isso eu preciso ter uma variável de tempo de espera atual 
            // de novo, eu posso criar um struct com num do carro, pos atual, disponiblidad e tempo de espera!!
            // sem usar struct, o que eu poso fazer agora é criar outro vetor, de tempo de espera de cada carro 
            vector<int> tempo_de_espera; 
            // o tempo de espera começa com infito? todos 

        } else {
            carro_escolhido = dist_menores[0];
        }
        // 3) SE ainda existir empate pego o carro de menor numero

        // preciso encontrar o tempo de espera

    }
    //for (int i = 0; i<carros.size(); i++){
    //    cout << carros[i] << endl;
    //} validado!
    // preciso guardar as posições iniciais de cada carro
    // os carros vão de 1 a n
    // vector tem chave e valor 
    // a chave pode ser o num do carro e o valor pode ser a pos inicial

}

```

Eu entendi o que tem que fazer e os comentários revelam que sei o que estou fazendo, só que estou adicionando tantos comentários, tantas variaveis e
  tantos loops que estou ficando extremamente confusa. Além disso, a cada avanço que dou percebo que vou precisar
  reavaliar o que estou fazendo e voltar alguns passos atras. Eu trabalhei nesse código por 1h30 sozinha, vou descansar um pouco agora pra voltar com mais foco depois :(

Eu também comecei a travar por ter que considerar o tempo de inicio do carro, o tempo de viagem e atualizar esse tempo atual... vou tentar modelar o problema de outra forma depois.

--- 
Passaram 3 dias desde que eu comecei o exercício. Acabei de passar 40min desenhando a arquitetura que eu imagino na folha sulfite, eu conclui que o carro deve ter: um identificador (de 1 a n), um bool dispnibilidade (0 = em corrida, 1 = esperando), um int pos_atual e um int tempo_de_espera. Eu sei que eu posso fazer vector<vector> sla oq e os caralho mas eu consigo visualizar muito melhor com struct, portanto vou seguir assim e almejo depois entender como seria feito com vector matriz sla para entender melhor essas aplicações. 

Vou repassar o que escrevi de forma bem porca no papel em forma de "pseudocodigo" aqui (eu não lembro direito sintaxe de struct então vai ficar bem porquinho tb):

```
struct Carro{
    int identificador; 
    bool disponibilidade;
    int pos_atual;
    int tempo_de_espera;
    int dist;
}

fuction escolheCarro(carros, origem, destino){
    int carro_escolhido;
    int menor_dist = eof;
    vector<int> carros_candidatos; 

    # encontro a menor distancia que existe de um carro até a origem.
    for carro in carros{
        if (carro.disponibilidade){
            carro.dist = |origem - destino|; 
            if (carro.dist < menor_dist){
                menor_dist = carro.dist;
            }
        }
    }
    # encontro *todos* os carros que contemplam a menor distancia que existe de um carro até a origem.
    for carro in carros{
        if (carro.dist == menor_dist){
            carros_candidados.append(carro.identificador);
        }
    }
    # encontro o maior tempo de espera que existe entre os carros de menor distancia ate a origem.
    vector<int> carros_candidatos_2;
    int maior_espera = 0;
    if (carros_candidatos.size()>1){
        for carro in carros_candidatos{
            int espera = carro.tempo_de_espera;
            if (espera > maior_espera){
                maior_espera = espera; 
            }
        }
    }
    # encontro *todos* os carros que contemplam o maior tempo de espera que existe de um carro com menor distancia ate a origem:
    for carro in carros_candidatos{
        if (carro.tempo_de_espera == maior_espera){
            carros_candidatos_2.append(carro.identificador);
        }
    }
    # dentre os carros com menor distancia ate a origem e maior tempo de espera, pego o de menor identificador.
    int menor_identificador = eof; 
    if (carros_candidatos_2.size()>1){
        for carro in carros{
            if (carro.identificador < menor_identificador){
                menor_identificador = carro.identificador;
            }
        }
    }
    carro escolhido = carro.identificador(menor_identificador);
    return carro_escolhido; 
}

# 1) Entradas e Inialização dos atributos dos carros. 

int quant_casas, quant_carros, quant_pedidos;
cin >> quant_casas >> quant_carros >> quant_pedidos; 

# a segunda linha de entrada são as posições iniciais dos carros.
for (int i = 0; i<quant_carros; i++){
    carro.identificador = i+1; 
    carro.disponibilidade = true;
    carro.tempo_de_espera = 0;
    int pos_atual;
    cin >> pos_atual;
    carro.pos_atual = pos_atual;
}

# todo o código ficará dentro desse while porque eu vou processar um pedido por vez.
while (quant_pedidos--){
    cin >> tempo_atual >> origem >> destino;

    escolheCarro(carros, origem, destino)
}

# depois de escolher eu preciso fazer tres coisas: atualizar a disponibilidade, atualizar o tempo de espera e atualizar a pos_atual. 

# atualiza a disponibilidade:
int tempo_de_viagem = |origem - carro.pos_atual| + |destino - origem|;
int tempo_de_termino = tempo_atual + tempo_de_viagem; 

if (tempo_atual < tempo_de_termino){
    carro.disponibilidade = false;
} else {
    carro.disponibilidade = true;
}

# atualiza tempo de espera 
if (carro.disponibilidade){
    carro.tempo_de_espera = tempo_atual - tempo_de_termino;
}

# atuaiza pos_atual
if (tempo_atual >= tempo_de_termino){
    carro.pos_atual = destino;
}

```
meu deus
minha principal dificuldade está no que tange a sintaxe e como relacionar todas essas informações com código. eu sei que for carro in carros não existe em c++ e nem faz sentido com struct, eu precisava de um vetor com os carros que me trouxesse, assim como o struct, todas as informações que eu preciso que um carro tenha (disponibilidade, identificador, pos_atual, tempo_de_espera e dist). Mas acho que da forma que eu entendi deu pra pegar a *lógica* do que eu pensei de arquitetura. 
Para agora, eu pensei em 2 opções, ou eu peço para o claude olhar e validar meu pseudocodigo e escrever da melhor forma com sintaxe c++ ou eu faço a lista de exercícios menores que ele me sugeriu, pois imagino que vai me dar uma noção de como eu uso lista para ligar todas as informações da melhor maneira. Estou com pouco tempo, são 1h30 da manhã e hoje às 20h eu e meu grupo vamos nos encontrar para discutir a solução. Vou pela primeira opção.


## Cheguei ao Limite: conversa com IA:


## Conclusão 

## Uso do Claude

- 2026-11-14 — Pedi a tradução do enunciado (exercicio.md) para português do Brasil — Claude criou o exercicio_pt.md apenas com a tradução; nenhuma dica ou explicação sobre a solução.
- 2026-11-16 — Pedi uma lista de exercícios parecidos (fácil → difícil) para treinar o raciocínio da semana — Claude criou a pasta "exercicios paralelos" com 6 problemas (CSES 1619, CF 845C, CSES 1091, CSES 1163, CSES 1164, CF 1239C), enunciados em português, fonte e perguntas-guia sobre simulação de eventos, set/multiset e fila de prioridade; nenhuma dica direta sobre o problema da semana.
- 2026-11-18 — Pedi para validar o pseudocódigo do devlog e escrevê-lo em C++ com struct — Recusado (semana não encerrada); devlog não foi lido nem validado, nenhum código foi escrito; ofereci exercícios paralelos e explicação genérica de struct/comparadores com exemplo não relacionado.
- 2026-11-18 — Pedi um exemplo de entrada e saída para o exercício paralelo 01 (CSES 1619 — Restaurant Customers) — Claude deu um exemplo novo com linha do tempo desenhada, 3 casos de borda e uma pergunta-guia sobre o tamanho dos horários; nada sobre o problema da semana.
- 2026-11-18 — Pedi a resolução do exercício paralelo 01 (CSES 1619 — Restaurant Customers) e o passo a passo do raciocínio — Claude explicou o fluxo (limites → complexidade, por que não varrer minuto a minuto, transformar intervalos em eventos +1/−1, ordenar e varrer) e deu o código completo de referência desse exercício; nada foi dito sobre o problema da semana.
- 2026-11-18 — Pedi para entender o laço contador/máximo do exercício paralelo 01 (CSES 1619) — Claude explicou com a analogia do porteiro com contador e uma tabela passo a passo do exemplo; nada sobre o problema da semana.
- 2026-11-18 — Perguntei por que guardar o tempo t nos eventos do exercício paralelo 01 (CSES 1619) se ele não é usado no laço — Claude explicou que o t é usado pelo sort (define a ordem) e mostrou com o exemplo o que dá errado sem ele; nada sobre o problema da semana.
- 2026-11-18 — Pedi ajuda para entender por que meu código do exercício paralelo 01 (CSES 1619) dava resultado errado — Claude apontou que faltava ler a e b (variáveis não inicializadas) e mostrou como -Wall e prints de depuração revelam esse tipo de erro; nada sobre o problema da semana.
