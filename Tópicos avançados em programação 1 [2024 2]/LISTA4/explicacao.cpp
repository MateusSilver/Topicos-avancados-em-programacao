/** union find, 2 conjuntos completamente diferentes */
/** unir eles e achar algo */
/**
perguntas:
1. unir U e V?
2. U e V estão conectados?

inicio:
supondo que os grafos só apontam pra eles mesmos
=> rep[1]   rep[2]  rep[3]  rep[4]
=> 1        2       3       4

faça um vetor dos nos.

fazer uma conexão U-V, o U deixa de apontar pra si e aponta pra v.
se u e v estão conectados u aponta pra v.
se W aponta pra U e U aponta pra V, U e V estão conectados.

mas pra comer tempo, todos apontam pro representante máximo
ou seja W aponta pro representante de U e não pra U, logo U->V e W->V
asim logo todos estarao apontando pra um só se estiverem no mesmo grupo.
grupos disjuntos apontam cada um para um representante diferente.

se U e V tiverem apontando pro mesmo lugar então eles estão conectados.

*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;
int rep[MAXN];//representantes de cada indice
int qtd[MAXN];// quantidade no grupo de cada indice

void set_(int x){// começa apontando pra sim mesmo
    rep[x] = x;
    qtd[x] = 1;
}

int find_(int x){// encontra o representante
    if(rep[x] == x) return x;
    else return rep[x] = find_(rep[x]);// todos apontam pro representante
}

void unite_(int a, int b){
    // pega representante A e une com representante B, dois conjuntos agora são um
    a = find_(a);
    b = find_(b);
    if(a == b) return;
    if(qtd[b] < qtd[a]) swap(a,b);
    rep[a] = b;
    qtd[b] += qtd[a];
}

int main(){
    //DSU ou union/find;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;// nos e entradas de relações
    for(int i = 1; i <= n; i++){
        set_(i);
    }
    while(q--){
        int t, u, v;//t=0 => une, t=1 => estão no mesmo grupo
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
