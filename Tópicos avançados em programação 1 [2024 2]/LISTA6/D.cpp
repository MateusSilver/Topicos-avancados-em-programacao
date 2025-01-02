#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

// lista 6 - D
// inverter binario de um numero inteiro sem sinal 32 bits

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    unsigned int n;
    cin >> t;

    unsigned int result = 0;
    while(t--){
        cin >> n;

        result = 0;
        for(int i=1; i<=32; i++){
            if(n&(1<<(i-1))){
                result = result | (1 << (32-i));
            }
        }
        cout << result << "\n";
    }
}
