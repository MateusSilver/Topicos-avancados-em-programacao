#include <bits/stdc++.h>
using namespace std;

// lista 6 - C
// swap bits 1º com 2º e 3º com 4º etc

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maskOdd  = 1431655765; // 0101010101...1
    int maskEven = 2863311530; // 1010101010...0

    int t, n;
    cin >> t;


    while(t--){
        cin >> n;
        int evens = n&maskEven;// pega bits pares do n
        int odds = n&maskOdd;//pega bits impares do n

        evens = evens>>1;
        odds = odds<<1;

        cout << (evens|odds) << "\n";
    }

    return 0;
}

