#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//O(log n) tempo
//espaço linear

ll fib(ll x){
    if (!x) return 0;
    ll sv[2] = {x&1, !(x&1)};
    int i = x-1;
    while(i){
        i--;
        sv[i&1] = sv[!(i&1)] + sv[i&1];
    }
    return sv[0];
}

int32_t main()
{
    for (int i = 0; i < 10; i++)
        cout << fib(i) << '\n';
    return 0;
}


