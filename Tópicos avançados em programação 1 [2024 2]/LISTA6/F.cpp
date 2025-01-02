#include <bits/stdc++.h>
using namespace std;

// lista 6 - F
// conte a quantidade de bits em posicoes pares de um numero
// conte a quantidade de bits em posicoes impares de um numero
/** exiba o numero i = quantidade de numeros entre M e N + 1,
em que a diferença entre quantidade de numeros em
posicoes pares e numeros em posições impares e K.
**/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int maskOdd  = 1431655765; // 0101010101...1
    int maskEven = 2863311530; // 1010101010...0

    int t;
    long long m, n;
    int k;
    cin >> t;


    while(t--){
        cin >> m >> n >> k;
        vector<long long> diferencas;

        for(long long i = m; i<=n; i++){
            int evens = i&maskEven;// pega bits pares do i
            int odds = i&maskOdd;//pega bits impares do i

            if(abs(__builtin_popcount(evens) - __builtin_popcount(odds)) == k){
                diferencas.push_back(i);
            }
        }
        cout << diferencas.size() << "\n";
    }

    return 0;
}

