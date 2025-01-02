#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

/*
LISTA 11 - B : cria um grafo com os caracrteres que formam palavras como sugestão de continuação
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
vector<string> respostas;

void addTrie(string& s){
    int no = 0;
    for(char c : s){
        int pos = c-'a';
        if(trie[no].prox[pos] == 0){
            tam++;
            trie[no].prox[pos] = tam;
        }
        no = trie[no].prox[pos];
    }
    trie[no].fim = true;
}

void dfs(int u, string& s){
    if(trie[u].fim){
        respostas.push_back(s);
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

    string s;
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> s;
        addTrie(s);
    }
    int m;
    cin >> m;
    vector<string> t(m);
    for(int i = 0; i<m; i++){
        cin >> t[i];
    }

    for(int i = 0; i<m; i++){
        int no=0;
        int vazio = 0;

        for(char c : t[i]){
            int pos = c-'a';

            if(trie[no].prox[pos] == 0){
                vazio = 1;
                break;
            }
            no = trie[no].prox[pos];
        }
        cout << "Case #"<<i+1<<":\n";
        if(vazio){
            cout << "No match.\n";
        } else{
            dfs(no, t[i]);
        }
        no=0;
        for(string res : respostas){
            if(res != t[i]){
                cout << res << "\n";
            }
        }
        respostas.clear();
    }

    return 0;
}


