#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)
#define ll long long

const int MAXN = 2*1e5+100;
ll A[MAXN];
ll PREF[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    loop(i,0,n){
        cin >> A[i];
    }

    PREF[0] = A[0];
    //cout << PREF[0] << "\t";
    loop(i,1,n){
        PREF[i] = A[i] + PREF[i-1];
        //cout << PREF[i] << "\t";
    }
    //cout << "\n";

    int l,r;
    while(m--){
        cin >> l >> r;
        if(l>1){
            cout << PREF[r-1] - PREF[l-2] << "\n";
        } else {
            cout << PREF[r-1] << "\n";
        }
    }
    return 0;
}
