#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

/**
LISTA 8 - D
dado uma lista de n interesses amorosos, onde i interesse gosta de f[i] interesse
descubra se há triangulos amorosos (subgrafos com tamanho 3)
**/

const int MAXN = 5000+10;
vector<int> adj[MAXN];
int mark[MAXN];

bool dfs(int u, int inicio, int tamanho){
    mark[u] = 1;// marca que ja foi passado

    if(tamanho == 2){// se está na 2 vamos verificar se fecha o triangulo
        for(int v: adj[u]){// opções pra fechar
            if(v == inicio){
                return true;
            }
        }
    } else {
        for(int v: adj[u]){// anda nas possibilidades
            if(!mark[v] && dfs(v,inicio, tamanho+1)){// anda até o fim nos não marcados
                return true;// se tiver triangulo volta na recursão e retorna true
            }
        }
    }
    mark[u] = 0;// desmarca para a proxima iteração
    return false;// não entrou no triangulo
}

bool procura_triangulos(int n){
    rep(i,0,n){
        if(dfs(i,i,0)){// analisa todos os vertices
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u;
    cin >> n;

    rep(i,0,n){
        cin >> u;
        adj[i].push_back(u-1);
        adj[u-1].push_back(i);
    }

    if(procura_triangulos(n)){
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}
