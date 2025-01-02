#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

/*
cria um grafo com os caracrteres que formam palavras como sugestão de continuação
o automcomplete dos programas de digitação
*/

const int N = 5*1e5+10;
const int K = 10+1;

struct no {
    bool fim;
    int prox[26];//posiçoes no alfabeto na tabela ASCII pode ser 'z' - 'A'+1 se quiser maiusculas e minusculas
};

no trie[N * K];//proximo index
int tam = 0;

void addTrie(string& s){
    int no = 0;
    for(char c : s){
        int pos = c-'a';
        if(trie[no].prox[c-'a'] == 0){
            tam++;
            trie[no].prox[c-'a'] = tam;
        }
        no = trie[no].prox[c-'a'];
    }
    trie[no].fim = true;
}

void dfs(int u, string& s){
    if(trie[u].fim){
        cout << s << "\n";
    }

    rep(i,0,26){
        if(trie[u].prox[i] != 0){
            s.push_back((char)('a'+i));
            dfs(trie[u].prox[i],s);
            s.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> s;
        addTrie(s);
    }
    cin >> t;
    int no = 0;
    for(char c : t){
        int pos = c-'a';
        if(trie[no].prox[c-'a'] == 0){
            return 0;
        }
        no = trie[no].prox[c-'a'];
    }
    dfs(no,t);

    return 0;
}

