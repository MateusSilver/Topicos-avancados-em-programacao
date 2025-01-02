/**
numeros primos, primos s�o diviziveis apenas por 1 e por eles mesmos
o numero divisivel por outros � um numero composto
sabendo disso, podemos testar divis�es no numero de 2 at� n-1 pra saber se ele � primo
porem podemos melhorar isso pois pares ser�o sempre divisiveis primeiro por dois.
ent�o podemos so passar pelos impares, ou melhor alias, numeros impares tambem podem ser compostos,
logo tudo se resume a testar se � divisivel por fatores primos. e n�o at� n-1, e sim at� raiz de n,
pois n = raiz de n * raiz de n. ent�o qualquer multiplica��o de numeros acima de raiz de n,
n�o vai dar em numeros abaixo de 1.
ora, se n = raiz de n * raiz de n ent�o n ao quadrado � n*n
logo precisamos andar at� i*i<=n; e n�o i<=raiz de n
n�o precisando calcular a raiz de n, que pode ser um numero fracionario
**/

/**CRIVO DE ERASTOTENES**/
#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

const int MAXN = 5e5+100;
ll primes[MAXN];
vector<ll> p;//vetor s� de primos

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

