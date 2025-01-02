#include <bits/stdc++.h>
using namespace std;

/**
Lista 8 - A
(a+b)*(c-d)
**/

vector<int> adj[MAXN];

void dfs(int u){
    cout << u << "\n";
    mark[u] = 1;// marca que ja foi passado
    for(int v: adj[u]){//posição do vetor adj[u], que é um vector de tamanho variavel
        if(!mark[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // formas de representar grafos
    // matrizes de adjacencia
    int n, m; // arestas
    // n vertices
    int Adjacencia[m][n];

    // lista de adjacencias
    vector<list<bool>> adjacencia;
    // list<list<int>>, list<list<bool>> adjacencias;
    // vector<int> adjacencicas[maxn];

    // adjacencias do 0 -> 2, 3
    // adjacencias do 1 -> 3, 5
    // adjacencias do 2 -> 0, 5, 7, 8
    // ...

    // andando no grafo
    // DFS, busca em profundidade
    // anda no grafo de ponto em ponto até o fim
    // adj 1 -> 2,3
    // chama adj(2) -> adj(adj(2)) -> adj(adj(adj(2)))

    // exemplo com matriz
    int n, m;
    cin >> n >> m;
    for(int i = 0; i< m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);



    // um grafo sem ciclos é uma arvore
    // as vezes os grafos são subdivididos e alguns vertices não se encontram
    // voce tem então subgrafos


