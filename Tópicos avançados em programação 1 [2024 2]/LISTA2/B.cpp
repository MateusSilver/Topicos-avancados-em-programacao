#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b) for(int i=a; i<b; i++)

vector<ll> a;
ll t;

bool f(ll x){
    ll inf = 1e18;
    ll sum = 0;

    int n = a.size();

    loop(i,0,n){
        sum += x/a[i];
        if(sum > inf){
            return true;
        }
    }
    return sum>=t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int entrada;

    cin >> n;
    cin >> t;

    loop(i,0,n){
        cin >> entrada;
        a.push_back(entrada);
    }

    ll rs;
    ll l = 1ll;
    ll r = 1e18;

    while(l<=r){
        ll mid = (l+r) >> 1ll;// divide por 2 corta o ultimo bit
        if(f(mid)){
            r = mid-1;
            rs = mid;
        } else {
            l = mid+1;
        }
    }
    cout << rs << "\n";
}
