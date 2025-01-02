#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;

long long int a[N];
long long int tree[4*N];

long long int valor_nulo = 2e12;


long long int merg(long long int x, long long int y){
    return min(x,y);
}

void build(long long int p,long long int tl,long long int tr){
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
        tree[p] = val;
    } else {
        long long int tmid = (tl+tr)/2;
        if(pos <= tmid){
            update(2*p, tl, tmid, pos, val);
        } else {
            update(2*p+1, tmid+1, tr, pos, val);
        }
        tree[p] = merg(tree[2*p], tree[2*p+1]);
    }
}

long long int query(long long int p, long long int tl, long long int tr, long long int l,long long int r){
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
    long long int n, q;
    cin >> n >> q;

    for(long long int i =1; i<= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);

    int opt;
    long long int k, u, l, r;

    while(q--){
        cin >> opt;

        if(opt == 1){
            cin >> k >> u;
            update(1,1,n,k,u);

        } else{
            if(opt == 2){
                cin >> l >> r;
                cout << query(1,1,n,l, r) << endl;

            }
        }
    }



    return 0;
}
