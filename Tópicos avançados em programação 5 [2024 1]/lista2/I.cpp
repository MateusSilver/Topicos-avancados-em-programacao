#include <bits/stdc++.h>
using namespace std;

const int N = 1e18 + 1;

int main(){
    long long int n;
    cin >> n;
    int i = 1;
    long long int J = n+1;// log maior
    int gastos = 0; // yen

    // log maior dividido pra outros menores
    while(J-i>=0 && i<=n){
        //cout << "corta J de tamanho " << i << endl;
        J = J - i;
        i++;
    }
    gastos = 1 + (n-(i-1));// 1 yen do maior n+1 e outros dos n
    cout << gastos;
}
