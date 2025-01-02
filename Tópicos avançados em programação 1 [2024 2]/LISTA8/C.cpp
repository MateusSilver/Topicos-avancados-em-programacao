#include <bits/stdc++.h>
using namespace std;

/**
Lista 8 - C
Crie um programa que dado m parentescos entre n individuos
dê o numero de familias baseada nos dados
**/



#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

const int MAXN = 5e4+10;

vector<int> adj[MAXN];
int mark[MAXN];

void dfs(int u){
    mark[u] = 1;// marca que ja foi passado
    for(int v: adj[u]){//posição do vetor adj[u], que é um vector de tamanho variavel
        if(!mark[v]){
            dfs(v);
        }
    }
}

int count_families(int n){
    int familycount = 0;
    rep(i,0,n){// procurando familias
        if(!mark[i]){// apenas membros ainda não marcados e marque a familia deles
            familycount++;
            dfs(i);
        }
    }
    return familycount;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int u, v;

    rep(i,0,m){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    cout << count_families(n) << "\n";

    return 0;
}

