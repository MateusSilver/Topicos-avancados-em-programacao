#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+100;
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

 int count_components(int n){
    int atual_component = rep[1];
    for(int i = 1; i <=n; i++){
        if(rep[i] != atual_component){
            unions -= 1;
        }
    }
    return n-unions;
 }

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        set_(i);
    }
    while(m--){
        cin >> a >> b;
        unite_(a,b);
        cout << count_components(n) << " " << count_size() << "\n";
    }
}
