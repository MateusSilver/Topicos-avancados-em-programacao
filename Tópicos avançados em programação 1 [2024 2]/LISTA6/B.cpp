#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n;
    int q;

    cin >> q;
    while(q--){
        cin >> n;
        cout << (unsigned int)~n << "\n";
    }

    return 0;
}

