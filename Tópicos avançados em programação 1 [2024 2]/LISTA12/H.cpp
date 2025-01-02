#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)

/**
LISTA 12 - H : Faça testes onde analisa duas strings e retorna as posições onde a segunda foi encontrada na primeira
**/


vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n,0);

    int l, r;
    l=r=0;

    for(int i = 0; i<n; i++){
        if(i < r){
            z[i] = min(r-i,z[i-l]);
        }

        while(z[i] + i < n && s[z[i]] == s[i+z[i]]){
            z[i]++;
        }
        if(i + z[i] > r){
            r=i+z[i];
            l=i;
        }
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int n;
    cin >> n;
    while(n--){
        cin >> s >> t;

        string z = t+'#'+s;
        vector<int> res = z_function(z);

        int quant = 0;
        vector<int> indices;
        rep(i,0,res.size()){
            if(res[i] == t.size()){
                indices.push_back(i-t.size());//correção do indice
                quant++;
            }
        }
        if(indices.size() == 0){
            cout << "\nNot Found\n\n";
            continue;
        }


        cout << quant << "\n";
        for(int ind : indices){
            cout << ind << " ";
        }
        cout << "\n";
    }
    return 0;
}

