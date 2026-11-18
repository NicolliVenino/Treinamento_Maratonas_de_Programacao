#include <bits/stdc++.h>
using namespace std;

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