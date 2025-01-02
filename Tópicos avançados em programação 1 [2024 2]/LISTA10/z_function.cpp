#include <bits/stdc++.h>
using namespace std;

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

    //string s("abacaba");
    //string t("ab");
    string s, t;
    cin >> s >> t;

    string z = t+'#'+s;//magia
    vector<int> res = z_function(z);
    //conta o numeros em z = t.size();
    int quant = 0;
    for(int i : res){
        if(i == t.size()){
            quant++;
        }
    }
    //cout << s << "\n";
    //cout << z << "\n";
    for(int i : res){
        cout << i << " ";
    }
    cout << "\n";
    cout <<  quant;
}
