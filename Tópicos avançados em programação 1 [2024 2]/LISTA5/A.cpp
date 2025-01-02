#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;

    if(a%b == 0){
        cout << a/b << "\n";
    } else cout << (a/b)+1;

    return 0;
}
