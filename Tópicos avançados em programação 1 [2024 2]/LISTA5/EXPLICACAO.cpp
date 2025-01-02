/**
numeros primos, primos são diviziveis apenas por 1 e por eles mesmos
o numero divisivel por outros é um numero composto
sabendo disso, podemos testar divisões no numero de 2 até n-1 pra saber se ele é primo
porem podemos melhorar isso pois pares serão sempre divisiveis primeiro por dois.
então podemos so passar pelos impares, ou melhor alias, numeros impares tambem podem ser compostos,
logo tudo se resume a testar se é divisivel por fatores primos. e não até n-1, e sim até raiz de n,
pois n = raiz de n * raiz de n. então qualquer multiplicação de numeros acima de raiz de n,
não vai dar em numeros abaixo de 1.
ora, se n = raiz de n * raiz de n então n ao quadrado é n*n
logo precisamos andar até i*i<=n; e não i<=raiz de n
não precisando calcular a raiz de n, que pode ser um numero fracionario
**/

/**CRIVO DE ERASTOTENES**/
#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

const int MAXN = 5e5+100;
ll primes[MAXN];
vector<ll> p;//vetor só de primos

int main(){
    for(ll i = 2; i<MAXN; i++) primes[i] = true;
    for(ll i=2; i*i<MAXN; i++){
        if(primes[i] == true){
            for(ll j = 2*i; j<MAXN; j+=i){
                primes[j] = false;
            }
        }
    }
    for(ll i = 2; i<MAXN; i++){
        if(primes[i]==true){
            p.push_back(i);
        }
    }

    p[0] = 2;
    p[1] = 3;
    for(ll i = 0; i<MAXN; i++){
        cout << p[i] << " ";
    }
    return 0;
}

