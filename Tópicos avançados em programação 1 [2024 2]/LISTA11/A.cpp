
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

/*
Lista 11 - A : dadas n palavras e seus pesos nos textos, procure por elas nos m textos e some o peso

*/

int main(){
    int n, m;
    cin >> n >> m;

    pair<string, int> s[n];
    string t[m];

    rep(i,0,n){
        string entrada;
        cin >> entrada;

        s[i].first = entrada;

        cin >> s[i].second;
    }
    rep(i,0,n){
        cout << s[i].first << " " << s[i].second << "\n";
    }

    rep(i, 0, m){
        string entrada;
        while(entrada != "."){
            cin >> entrada;
            t[i] += " "+entrada;
        }

    }

    rep(i,0,n){
        cout << t[i] << "\n";
    }

    int total[m];
    rep(i,0,m){//anda em t
        total[i] = 0;
        for(int j = 0; j<n; j++){
            int sizeT = t[i].find(" "+s[j].first+" ");
            //cout << "find in " <<  sizeT << "\n";
            while(sizeT != -1){//procura as palavras em s
                //cout << "find in " <<  sizeT << "\n";
                cout << "apagando trecho do tamanho " << s[j].first.size() <<  "\n";
                t[i].erase(remove(t[i].begin(), t[i].end(), " "+s[j].first+" "), t[i].end());
                total[i] += s[j].second;
                sizeT = t[i].find(" "+s[j].first+" ");
            }
        }
    }
    rep(i,0,n){
        cout << t[i] << "\n";
    }
    rep(i,0,m){
        cout << total[i] << "\n";
    }
    return 0;
}
