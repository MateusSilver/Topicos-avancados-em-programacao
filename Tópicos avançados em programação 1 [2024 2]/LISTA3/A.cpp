#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAXN = 1e6;

int cnt[30];

int polindromo(string s){
    unordered_map<char, int> quant;
    for(int i = 0; i < s.size(); i++){
        quant[s[i]]++;
    }
    int impar = 0;
    for(int i = 0; i < s.size(); i++){
        if(quant[s[i]] % 2 != 0){
            impar++;
        }
    }
    if(impar > 1){
        return 0;
    }
    return 1;
}

int main(){
    string buffer;
    int pref[MAXN];
    cin >> buffer;
    for(char c : buffer){
        cnt[c - 'A']++;
    }
    int isodd = -1;
    for(int i = 0; i<26; i++){
        if(cnt[i]&1){// ultimo bit == 1 ou seja impar
            if(isodd != -1){
                cout << "NO SOLUTION\n";
                return 0;
            }
            isodd = i;
        }
    }
    if(isodd != -1){// INDICE DO IMPAR, tirar pra ficar no meio
        cnt[isodd]--;
    }

    string ans;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < cnt[i]; j+=2){
            ans.push_back(i+'A');
        }
    }
    if(isodd != -1){
        ans.push_back(isodd+'A');// adiciona impar
    }
    for(int i = 25; i >= 0; i--){
        for(int j = 0; j < cnt[i]; j+=2){
            ans.push_back(i+'A');
        }
    }

    cout << ans << "\n";
    return 0;
}
