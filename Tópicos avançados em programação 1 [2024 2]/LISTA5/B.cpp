#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define rep(j,a,b) for(int j = a; j<b; j++)

vector<string> S;
set<string> T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string entrada;

    rep(i,0,n){
        cin >> entrada;
        S.push_back(entrada);
    }
    // em set para tirar repetições
    rep(i,0,m){
        cin >> entrada;
        T.insert(entrada);
    }

    int quant = 0;

    rep(i,0,n){
        string sub = S[i].substr(S[i].size()-3);
        // set count função tranquila pra buscar quantidades
        if(T.count(sub) > 0){
            quant++;
        }
    }
    cout << quant << "\n";

    return 0;
}

