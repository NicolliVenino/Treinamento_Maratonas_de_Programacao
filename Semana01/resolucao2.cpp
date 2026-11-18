#include <bits/stdc++.h>
using namespace std;

int main(){
    int num_casas, num_carros, num_pedidos;
    int carro_escolhido = 0;
    cin >> num_casas >> num_carros >> num_pedidos;
    vector<int> pos_carro;
    int pos;
    vector<bool> disp_carros;
    vector<int> distancias;
    while(num_carros--){
        cin >> pos;
        pos_carro.push_back(pos);
        disp_carros.push_back(true);
    }
    while(num_pedidos--){
        int t, origem, destino;
        cin >> t >> origem >> destino;
        for (int i = 0; i<num_carros; i++){
            if (disp_carros[i]){
                int dist = abs(origem - pos_carro[i]);
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
        if (dist_menores.size() > 1){
        } else {
            carro_escolhido = dist_menores[0];
        }
    }
}