#include <bits/stdc++.h>
using namespace std;


const long long int N = 5e5 + 10;
long long int a[N], bits[N];

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
        if(valor != a[x]){
            bits[x]++;
        }
        x += (x& - x);
    }
}


int main(){
    int n;
    long long int m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        update(i,a[i]);
    }
    bits[0] = 0;
    int l, r;
    while(m--){
        cin >> l >> r;
        cout << feenwick(r) - feenwick(l-1) << endl;
    }
    return 0;
}
