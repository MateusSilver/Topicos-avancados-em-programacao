#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;
int rep[MAXN];
int qtd[MAXN];

void set_(int x){
    rep[x] = x;
    qtd[x] = 1;
}

int find_(int x){
    if(rep[x] == x) return x;
    else return rep[x] = find_(rep[x]);// todos apontam pro representante
}

void unite_(int a, int b){
    // pega representante a e une com representante b
    a = find_(a);
    b = find_(b);
    if(a == b) return;
    if(qtd[b] < qtd[a]) swap(a,b);
    rep[a] = b;
    qtd[b] += qtd[a];
}

int main(){
    //dsu ou union/find;
    //problema D
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        set_(i);
    }
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t==0){
            unite_(u,v);
        } else {
            bool ans;
            ans = find_(u) == find_(v);
            cout << ans << "\n";
        }
    }

}
