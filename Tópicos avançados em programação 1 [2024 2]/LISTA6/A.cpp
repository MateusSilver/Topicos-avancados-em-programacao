#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n >> i;

    if(n&(1<<i)){
        cout << "true\n";
        return 0;
    }
    cout << "false\n";
    return 0;
}
