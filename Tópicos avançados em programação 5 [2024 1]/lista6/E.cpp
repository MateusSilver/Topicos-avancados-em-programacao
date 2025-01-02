// substituir valores e somar em sequencia
#include <bits/stdc++.h>
using namespace std;



int main(){
    long long int n;
    long long int soma = 0;
    cin >> n;

    map<long long int, long long int> valores;
    long long int new_valor;

    for(long long int i=0; i<n; i++){
        cin >> new_valor;

        valores[new_valor]++;
        soma += new_valor;
        //cout << soma << endl;
        //cout << valores[new_valor] << endl;
    }

    long long int q;
    long long int val_a_remover, val_a_inserir;
    cin >> q;

    for(long long int i=0; i<q; i++){
        cin >> val_a_remover >> val_a_inserir;
        //cout << soma << "+" << val_a_inserir*valores[val_a_inserir] << endl;
        //cout << soma << "-" << val_a_remover*valores[val_a_remover] << endl;

        soma -= (valores[val_a_remover])*(val_a_remover);
        soma += (valores[val_a_remover])*(val_a_inserir);

        valores[val_a_inserir] += valores[val_a_remover];
        valores[val_a_remover] = 0;




        cout << soma << endl;
    }

    return 0;
}


