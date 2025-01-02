#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
const long long MAXN = 1e6;
vector<bool> prime(MAXN+1,1);
vector<long long> primelist;

void criaPrimos(long long n){
    prime[0] = prime[1] = 0;
    long long maximo = sqrt(n)+1;
    for(long long i = 4; i <= maximo; i+=2){
        if(prime[i]){
            for(long long j = i*i; j < maximo; j+=i){
                prime[j] = 0;
            }
        }
    }
    for(long long i = 2; i <= maximo; i++){
        if(prime[i]){
            primelist.push_back(i);
        }
    }
}

set<long long> fatoresprimos(long long n){
    set<long long> f;
    int i = 0;
    int p = primelist[i];
    while(p*p <= n){
        while(n%p == 0){
            n /= p;
            f.insert(p);
        }
        i++;
        p = primelist[i];
    }
    if(n != 1){
        f.insert(n);
    }
    return f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    long long n;
    cin >> n;
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    criaPrimos(n);

    set<long long> fatores = fatoresprimos(n);
    for(const int& fator : fatores){
        cout << fator << "\n";
    }

    return 0;
}

