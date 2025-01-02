#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

/**
LISTA 8 - F
Dado uma lista de n-1 empregados com cada i seus respectivos chefes[i]
o primeiro é o gerente maximo
**/

const int MAXN = 2e5;
vector<int> adj[MAXN];
int quantSubordinados[MAXN];
int mark[MAXN];

void dfs(int u){
    mark[u] = 1;// marca o caminho

    for(int v: adj[u]){// anda nas possibilidades
        if(!mark[v]){// evita loops
             dfs(v);
             quantSubordinados[u] += 1+quantSubordinados[v];
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u;
    cin >> n;

    rep(i,1,n){
        cin >> u;
        adj[u-1].push_back(i);
    }
    dfs(0);

    rep(i,0,n){
        cout << quantSubordinados[i] << " ";
    }
    cout << "\n";
    return 0;
}

