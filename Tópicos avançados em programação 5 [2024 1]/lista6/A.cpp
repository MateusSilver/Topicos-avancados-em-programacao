// verificar se todos são distintos
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    set<int> valores;
    int new_val;

    for(int i=0; i<n; i++){
        cin >> new_val;
        valores.insert(new_val);
    }
    if(valores.size() != n){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}

