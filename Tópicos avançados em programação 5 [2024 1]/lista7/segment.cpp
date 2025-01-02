#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int a[N];
int tree[4*N];
int valor_nulo = 0;

// faça tambem uma função para o tree[p] = tre[2*p] + tree[] isso chamamos função merg
int merg(int x, int y){
    return x+y;
}

// p = indice atual onde eu estou, tl e tr é o meu segmento.
void build(int p, int tl, int tr){
    if(tl == tr){
        tree[p] = a[tl];
    } else {
        int tmid = (tl+tr)/2;
        build(2*p, tl,tmid);
        build(2*p+1, tmid+1, tr);
        tree[p] = tree[2*p] + tree[2*p+1];
    }
}

//atualiza e sobe atualizando os pais.
void update(int p, int tl, int tr, int pos, int val){
    if(tl == tr){
        tree[p] = val;
    } else {
        int tmid = (tl+tr)/2;
        if(pos <= tmid){
            update(2*p, tl, tmid, pos, val);
        } else {
            update(2*p+1, tmid+1, tr, pos, val);
        }
        tree[p] = tree[2*p] + tree[2*p+1];
    }
}

int query(int p, int tl, int tr, int l, int r){
    // precisamos retornar um valor nulo se o segmento não existe, depende da situação que estamos calculando
    // em soma:
    if(l > r){
        return valor_nulo;
    }
    if(tl == l && tr == r){
        return tree[p];
    }
    int tmid = (tl+tr)/2;
    return query(2*p, tl, tmid, l, min(r, tmid)) + query(2*p+1, tmid+1, tr, max(l, tmid+1),r);
}


int main(){
    // como representa a arvore de segmentos
    // uma arvore perfeita
    // essa arvore usamos potencias de 2, com filhos sendo n*2 e n*2 +1
    // com isso fazemos um vetor pra representar a estrutura
    int n;
    cin >> n;
    for(int i; i< n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    // constroi a arvore a partir do vetor.





    return 0;
}
