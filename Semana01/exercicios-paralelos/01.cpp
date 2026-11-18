#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<pair<int, int>> eventos;
    while(n--){
        int a, b; 
        cin >> a >> b;
        eventos.push_back({a, +1});
        eventos.push_back({b, -1});
    }

    sort(eventos.begin(), eventos.end());

    int atual = 0;
    int melhor = 0; 

    for (auto [t, delta] : eventos){
        atual += delta; 
        melhor = max(melhor, atual);
    }
    cout << melhor << endl;
    
}