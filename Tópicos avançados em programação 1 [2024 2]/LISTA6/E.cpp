#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

// lista 6 - E
// achar dois numeros binarios que XOR de n para cada n

void xor_bits(int n){
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            if( (i^j) == n){
                cout << i << " " << j << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int n;
    cin >> t;

    while(t--){
        cin >> n;
        xor_bits(n);
    }
}

