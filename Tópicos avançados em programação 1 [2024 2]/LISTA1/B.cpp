#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> S;
    string entrada;

    while(n--){
        cin >> entrada;
        auto it = S.find(entrada);

        if(it == S.end()){
            S.insert(entrada);
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
