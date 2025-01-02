#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

/*
Lista 11 - c : faça um banco de palavras e para cada caso de pesquisa devolva o numero de palavras que contenham o prefixo
*/

const int N = 5*1e5+10;
const int K = 10+1;

struct no {
    pair<bool, int> fim;
    int sugestoes;
    int prox[26];//posiçoes no alfabeto na tabela ASCII pode ser 'z' - 'A'+1 se quiser maiusculas e minusculas
    no(){//garantindo que os dados são inicialmente corretos
        fim.first = false;
        fim.second = 0;
        sugestoes = 0;
    }
};

no trie[N * K];//proximo index
int tam = 0;


void addTrie(string& s){
    int no = 0;
    for(char c : s){
        int pos = c-'a';
        if(trie[no].prox[pos] == 0){
            tam++;
            trie[no].prox[pos] = tam;
        }
        trie[no].sugestoes++;
        no = trie[no].prox[pos];
    }
    trie[no].fim.first = true;
    trie[no].fim.second++;
    trie[no].sugestoes++;
}

int dfs(int u, string& s){
    int contador = trie[u].fim.second;

    rep(i,0,26){
        if(trie[u].prox[i] != 0){
            s.push_back('a'+i);
            contador += dfs(trie[u].prox[i], s);
            s.pop_back();
        }
    }

    return contador;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n, m;

    cin >> n >> m;
    rep(i,0,n){
        cin >> s;
        addTrie(s);
    }

    vector<string> t(m);
    for(int i = 0; i<m; i++){
        cin >> t[i];
    }

    for(int i = 0; i<m; i++){
        int no=0;
        int achado = 1;

        for(char c : t[i]){
            int pos = c-'a';

            if(trie[no].prox[pos] == 0){
                achado = 0;
                break;
            }

            no = trie[no].prox[pos];
        }
        if(!achado){
            cout << "0\n";
        } else{
            if(achado){
                cout << trie[no].sugestoes << "\n";
            }
        }
    }
    return 0;
}


