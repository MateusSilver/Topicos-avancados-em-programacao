#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;

string a[N];
vector<string> tree(4*N);

long long int valor_nulo = 0;


long long int merg(string x, string y){
    return strcmp(x,y) != 0 ? 1 : 0;
}

void build(long long int p,long long int tl,long long int tr){
    if(tl == tr){
        tree[p] = a[tl];
    } else {
        long long int tmid = (tl+tr)/2;
        build(2*p, tl,tmid);
        build(2*p+1, tmid+1, tr);
        tree[p] += merg(tree[2*p], tree[2*p+1]);
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
    cin >> n;

    for(long long int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    query(1,1,n,1,n);


    return 0;
}
