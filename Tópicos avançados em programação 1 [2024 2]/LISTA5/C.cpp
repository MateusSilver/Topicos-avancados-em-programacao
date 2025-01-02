#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<=b; i++)

const int MAXN = 1e5+100;
long long A[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    rep(i,1,n){
        cin >> A[i];
    }
    int q;
    cin >> q;

    int option, k;
    long long x;

    rep(i,1,q){
        cin >> option;

        if(option == 1){
            cin >> k >> x;
            A[k] = x;
        }
        if(option == 2) {
            cin >> k;
            cout << A[k] << "\n";
        }
    }

    return 0;
}

