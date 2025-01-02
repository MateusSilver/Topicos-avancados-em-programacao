#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    vector<long long int> v;

    for(int i = 0; i < n; i++){
        int valor;
        cin >> valor;
        v.push_back(valor);
    }

    pair<long long int, long long int*> maximo;
    maximo.first = *max_element(v.begin(), v.end());
    maximo.second = max_element(v.begin(), v.end());

    long long int novo_maximo;

    int aux;
    for(int i = 0; i < n; i++){
        if(&v[i] == maximo.second()){
            v[i] = 0;
            cout << *max_element(v.begin(), v.end());
        } else {
            cout << maximo.first << endl;
        }
    }
}
