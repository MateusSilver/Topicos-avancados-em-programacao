#include <bits/stdc++.h>
using namespace std;

/*
Lista 10 - E : encontra quantas vezes ocorre uma substring em uma string s

*/

const int MAXN = 10e6+10;
int Z[MAXN];

void z_function(string s){
    int n = s.size();

    int l, r;
    l=r=0;

    for(int i = 1; i<n; i++){
        if(i < r){
            Z[i] = min(r-i,Z[i-l]);
        }

        while(Z[i] + i < n && s[Z[i]] == s[i+Z[i]]){
            Z[i]++;
        }
        if(i + Z[i] > r){
            r=i+Z[i];
            l=i;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string s;
    string t;
    cin >> s >> t;

    string z = t+'#'+s;
    z_function(z);
    //conta o numeros em z = t.size();
    int quant = 0;
    for(int i : Z){
        if(i == t.size()){
            quant++;
        }
    }
    //cout << s << "\n";
    //cout << z << "\n";
    //for(int i : res){
      //  cout << i << " ";
    //}
    //cout << "\n";
    cout <<  quant;
}
