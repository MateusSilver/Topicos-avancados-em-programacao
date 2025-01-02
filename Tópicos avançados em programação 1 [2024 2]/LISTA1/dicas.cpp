#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int v[n];
    rep(i,1,n){
        cin >> v[i];
    }

    /*
    while(cin >> a){}
    */
    rep(i,1,n){
        cout << v[i] << "\n";
    }

    return 0;
}
