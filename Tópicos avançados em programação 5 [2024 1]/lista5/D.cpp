#include <bits/stdc++.h>
using namespace std;


const long long int N = 3e5 + 10;
long long int a[N], bits[N];

long long int feenwick(int x){
    long long int soma = 0;
    while(x){
        soma ^= bits[x];
        x -= (x& - x);
    }
    return soma;
}

void update(int x,long long int valor){
    while(x<N){
        bits[x] ^= valor;
        x += (x& - x);
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        update(i,a[i]);
    }
    bits[0] = 0;
    int l, r, k;
    while(m--){
        cin >> k >> l >> r;
        if(k == 2){
            cout << (feenwick(r) ^ feenwick(l-1)) << endl;
        } else {
            if(k == 1){
                update(l,r);
            }
        }
    }
    return 0;
}


