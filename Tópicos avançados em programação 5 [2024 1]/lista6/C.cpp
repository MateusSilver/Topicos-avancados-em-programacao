// valores do conjunto que não estão repetidos
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int soma;
    cin >> n;

    set<vector<int>> sequencias;
    int tam, item;

    for(int i=0; i<n; i++){
        cin >> tam;
        vector<int> new_sequencia;

        while(tam--){
            cin >> item;
            new_sequencia.push_back(item);
        }
        if(sequencias.find(new_sequencia) != sequencias.end()){
            soma++;
        }
        sequencias.insert(new_sequencia);
    }
    cout << n-soma << "\n";
    return 0;
}

