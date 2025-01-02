// verificando o menor elemento >0 que não está no conjunto
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
    int x = 0;
    while(valores.find(x) != valores.end()){
        x++;
    }
    cout << x << "\n";
    return 0;
}

