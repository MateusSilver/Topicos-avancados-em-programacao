#include <bits/stdc++.h>
using namespace std;

int main(){
    int de, para;
    vector<int> grafo(4,0);
    for(int i=0; i<3; i++){
        cin >> de >> para;
        grafo[de-1]++;
        grafo[para-1]++;
    }
    for(int i=0; i<4; i++){
        if(grafo[i] == 0 || grafo[i] > 2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

