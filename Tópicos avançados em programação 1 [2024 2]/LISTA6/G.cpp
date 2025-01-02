#include <bits/stdc++.h>
using namespace std;

/**
Lista 6 - G
encontre a quantidade de numeros x tal que n+x == n^x
**/
/**contar  a quantidade de 0 no bit, o resultado e 2^(qtd+1)**/

int quant = 0;

/*int sumXor(long long n){
    for(long long i = 0; i<=n; i++){
        if((n+i) == (n^i)){
            quant++;
        }
    }
    return quant;
}*/

int sumXor(long long n){
    while(n--){
        if((n&1) == 0){
            quant++;
        }
        n = n>>1;
    }
    return (1 << quant);
}
//101
 int bitCount( int n){
    int count = 0;
    for (int i=n; i!=0; i = i >> 1){
        count += i & 1;
    }
    return __builtin_popcount(n)-count;
}

int countZeroLeft(long long n){
    unsigned int i =
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mask = 4294967296;//111111111...
    // 000000100101
    // 111111111111 xor
    //--------------
    // 111111011010
    // count bits 1

    // not
    // 000000100101
    // -------------
    // 000000100101
    // 111111011010

    long long n;
    cin >> n;
    long long resultado = countZeroLeft(n);
    cout << resultado;

    //cout << sumXor(n) << "\n";
}
