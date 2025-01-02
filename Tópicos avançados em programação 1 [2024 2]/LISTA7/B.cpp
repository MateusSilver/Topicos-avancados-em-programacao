#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
7-B crie uma função recursiva F em que F(0) = 1 F(K) = k*F(K-1)
**/

ll f(ll n){
    if(n==0) return 1;
    return n*f(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    cout << f(n);
    return 0;
}

