#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    set<int> v;
    int entrada;

    while(n--){
        cin >> entrada;
        if(v.find(entrada) != v.end()){
            v.erase(entrada);
        } else {
            v.insert(entrada);
        }
    }
    cout << v.size() << endl;
}
