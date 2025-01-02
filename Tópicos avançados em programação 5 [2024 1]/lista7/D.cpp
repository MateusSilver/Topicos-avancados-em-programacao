#include <bits/stdc++.h>
using namespace std;

// fazer uma arvore de maximo
// o menor indice maior que o y
// fazer a busca binaria


const int N = 2e5;
long long int a[N];
long long int b[N];
long long int tree[4*N];
int valor_nulo = 0;

int merg(long long int x, long long int y){
    return x+y;
}

int merg2(long long int x, long long int y){
    return x-y;
}

void build(long long int p,long long int tl, long long int tr){
    if(tl == tr){
        tree[p] = a[tl];
    } else {
        long long int tmid = (tl+tr)/2;
        build(2*p, tl,tmid);
        build(2*p+1, tmid+1, tr);
        tree[p] = merg(tree[2*p], tree[2*p+1]);
    }
}

void update(long long int p, long long int tl, long long int tr, long long int pos, long long int val){
    if(tl == tr){
        tree[p] -= val;
        cout << p << endl;
    } else {
        long long int tmid = (tl+tr)/2;
        if(pos <= tmid){
            update(2*p, tl, tmid, pos, val);
        } else {
            update(2*p+1, tmid+1, tr, pos, val);
        }
        tree[p] = merg2(tree[2*p], tree[2*p+1]);
    }
}

int query(long long int p, long long int tl, long long int tr, long long int l, long long int r){
    if(l > r){
        return valor_nulo;
    }
    if(tl == l && tr == r){
        return tree[p];
    }
    long long int tmid = (tl+tr)/2;
    return merg(query(2*p, tl, tmid, l, min(r, tmid)), query(2*p+1, tmid+1, tr, max(l, tmid+1),r));
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i; i< n; i++){
        cin >> a[i];
    }
    build(1, 1, n);

    int l = 1;
    while(m--){
        cin >> b[i];
        query(1,1,n,l,l+b[i]);
        l += b[i];
    }


    return 0;
}
