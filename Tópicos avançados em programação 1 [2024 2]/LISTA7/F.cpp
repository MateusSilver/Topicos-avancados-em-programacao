#include <bits/stdc++.h>
using namespace std;

/**
Lista 7 - F
dado cada caso de teste,
com dois numeros, dê o nimimo multiplo comum
 e maximo divisor comum de cada
**/

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

ll gcd(ll a, ll b){
    return b ? gcd(b,a%b) : a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll A, B;
        cin >> A >> B;

        cout << lcm(A,B) << " " << gcd(A,B) << "\n";

    }

    return 0;
}
