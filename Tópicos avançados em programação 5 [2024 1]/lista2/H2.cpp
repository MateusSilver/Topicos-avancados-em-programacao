#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    int v[n];

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int maior = *max_element(v, v+n);
    int indicemaior;

    int o = 0;
    while(o<n){
        if(v[o] == maior){
            indicemaior = o;
            break;
        }
        o++;
    }

    int aux;
    for(int i = 0; i < n; i++){
        if(indicemaior == i){
            aux = v[i];
            v[i] = 0;
            cout << *max_element(v, v+n) << endl;
            v[i] = aux;
        } else {
            cout << maior << endl;
        }
    }
}
