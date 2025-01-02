// verificar se tem problemas suficientes para adicionar de um set a outro
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int faltas = 0;

    multiset<long long int> candidatos;
    long long int new_candidato;

    for(int i=0; i<n; i++){
        cin >> new_candidato;
        candidatos.insert(new_candidato);
    }

    multiset<long long int> problemas;
    long long int new_problema;

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        cin >> new_problema;
        if(candidatos.find(new_problema) != candidatos.end()){
            candidatos.erase(candidatos.find(new_problema));
            problemas.insert(new_problema);
        } else {
            faltas++;
        }
    }
    if(faltas != 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    return 0;
}

