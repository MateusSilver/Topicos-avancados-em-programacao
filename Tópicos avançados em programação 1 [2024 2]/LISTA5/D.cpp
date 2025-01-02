#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5+100;
bitset<10000010> primes;
vector<ll> p;//vetor só de primos

int main(){
    primes.set();
    primes[0] = 0;
    primes[1] = 0;
    for(ll i=2; i*i<MAXN; i++){
        if(primes[i] == 1){
            for(ll j = i*i; j<MAXN; j+=i){
                primes[j] = 0;
            }
        }
    }
    for(ll i = 2; i<MAXN; i++){
        if(primes[i]){
            p.push_back(i);
        }
    }

    int n;
    cin >> n;

    for(int i = 0; i <n; i++){
        cout << p[i] << " ";
    }

    return 0;
}


