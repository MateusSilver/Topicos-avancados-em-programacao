#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
const int k = 450;
typedef long long ll;

struct query{
    ll l, r, idx;
};

bool comp(query x, query y){
    if(x.l/k == y.l/k){
        if((x.l/k)%2 == 1){
            return x.r > y.r;
        }
        return x.r < y.r;
    }
    return x.l/k < y.l/k;
}


vector<ll> ans;
vector<query> queries;
ll a[N], s = 0;

void add(ll x){
    s += a[x];
}

void rmv(ll x){
    s -= a[x];
}

int calc(){
    return s;
}


void solve(){
    sort(queries.begin(), queries.end(), comp);
    //cout << "sorted\n";
    ans.resize(queries.size());
    ll i = 0, j = -1;

    for(auto at:queries){
        ll l, r, idx;
        l = at.l;
        r = at.r;
        idx = at.idx;
        //cout << "walking indexes\n";
        while(j < r) {
            j++;
            add(j);
        }
        while(j > r) {
            rmv(j);
            j--;
        }
        while(i < l) {
            rmv(i);
            i++;
        }
        while(i > l) {
            i--;
            add(i);
        }
        ans[idx] = calc();
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;

    for(ll i = 0; i< n; i++){
        cin >> a[i];
    }

    for(ll i = 0; i< q; i++){
        query aux;
        cin >> aux.l >> aux.r;
        aux.l--;
        aux.r--;
        aux.idx = i;
        queries.push_back(aux);
    }

    solve();
    //cout << "solved\n";
    for(ll i = 0; i< q; i++){
        cout << ans[i] <<  endl;
    }
    return 0;
}
