#include <bits/stdc++.h>
using namespace std;

const long long int N = 2e5 + 10;
long long int a[N], bits[N];
long long int maximo =-1;

long long int feenwick(int x){
    long long int soma = 0;
    while(x){
        soma += bits[x];
        x -= (x& - x);
    }
    return soma;
}

void update(int x,long long int valor){
    while(x<N){
        if(x > maximo){
            maximo = x;
        }
        bits[x] += valor;
        x += (x& - x);
    }
}


int main(){
    int n, t;
    cin >> n >> t;
    int v[n];
    for(int i; i < n; i++){
        cin >> v[i];
        update(i,v[i]);
    }
    bits[0] = 0;
    int soma = 0;
    for(int i = 0; i<=maximo; i++){
        if(v[i] == t){
            soma++;
        }
    }
    cout << soma << endl;
}
