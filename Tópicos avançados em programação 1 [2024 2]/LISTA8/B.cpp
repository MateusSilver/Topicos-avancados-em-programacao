#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll v[n];
    rep(i,0,n){
        cin >> v[i];
    }

    int index = 0;
    while(n--){
        if(v[n] > v[index]){
            index = n;
        }
    }
    cout << index+1 << "\n";

    return 0;
}

