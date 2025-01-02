#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
bitset<10000010> prime;
vector<int> primelist;
int quant[3000];

void criaPrimos(int n){
    prime.set();
    prime[0] = prime[1] = 0;
    for(int i = 2; i < n; i++){
        if(prime[i]){
            for(int j = i+i; j < n; j+=i){
                prime[j] = 0;

            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(prime[i]){
            primelist.push_back(i);
        }
    }
}

set<int> fatoresprimos(int n){
    set<int> f;
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


    int n;
    cin >> n;
    int quase = 0;
    criaPrimos(3000);
    for(int i = 0; i<n; i++){
        if(quant[i]){
            quase++;
        }
    }

    cout << quase << "\n";

    return 0;
}


