// algoritmo de MO
// resolvendo queryes de perguntas sobre range especifico
// L e R
// i e j ponteiros se movem
// somando j e depois subtraindo i
// --------------------------------------------
//            ^i                        ^j
// divide l/ constante k.
// a ordem fica entre k's
// pensando no j:
// --------------------------------------------
// | k    |   k     |    k   |     k    |   k  |
// e  em cada bloco os pares l,r podem ir até n.
// fica como n/k * k vezes que o bloco se mexe.
// o i fica andando dentro desses blocos no maximo k posições
// ----------------------------------------------
// se os blocos estão em k's diferentes ele vai andar no maximo 2k.
// dentro de um bloco as perguntas vao andar no maixmo k vezes entre si,
// então i = O(k*n) e j = O(2(n/k * n)), entao temos (k + n/k)*n.


// fazendo calculos de derivada a velocidade fica raiz de n * n;
// pensando que temos n= q queries, temos qn de velocidade.

// se eu tiver de andar pra tras com i, eu somo. e se eu tiver de andar pra tras com j eu diminuo.
// esse metodo resolve um pouco mais lento que algumas coisas mas resolve coisas grandes e especificas

// e se eu quiser saber quantos elementos distintos temos de l até r?

// 1 2 3 4 1 2 5 7
// ----------------
// i             j
// criar um set ou map e contar somente os distintos, removendo quando a quantidade deles for 0.



// os blocos k pares nos ordenamos crescente e os impares ordenamos decrescentes
// o problema vai ficar mais ou menos assim:
#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
const int k = 450; // raiz de 20500

struct query{
    int idx, l, r;
};

bool comp(query x, query y){
    if (x.l/k == y.l/k){
        if((x.l/k)%2 == 1){
            return x.r > y.r;
        }
        return x.r < y.r;
    }
    return x.l/k < y.l/k;
}

typedef long long ll;
vector<ll> ans;
vector<query> queries;
ll a[N], s = 0;

void add(int x){
    s += a[x];
}

void rmv(int x){
    s -= a[x];
}

int calc(){
    return s;
}

void solve(){
    sort(queries.begin(), queries.end(), cmp);
    ans.resize(queries.size());
    int i = 0, j = -1;

    for(auto at:queries){
        itn l, r, idx;
        l = at.l;
        r = at.r;
        idx = at.idx;

        while(j < r) {
            j++;
            add(j);
        }
        while(j > r) {
            j++;
            rmv(j);
        }
        while(i < l) {
            rmv(i);
            i--;
        }
        while(i > l) {
            add(i);
            i++;
        }
        ans[idx] = calc();
    }
}


int main(){
    int n, q;
    cin >> n >> q;

    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    for(int i = 0; i< q; i++){
        query aux;
        cin >> aux.l >> aux.r;
        aux.idx = i;
        queries.push_back(aux);
    }
    solve();
    for(i = 0; i< q; i++){
        cout << ans[i] <<  '\n';
    }

}




