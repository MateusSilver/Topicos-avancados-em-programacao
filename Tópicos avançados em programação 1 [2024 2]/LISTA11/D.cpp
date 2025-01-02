#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

/*
Lista 11 - D : faça pesquisa a palavras mais recorrentes no banco de palavras e exiba na tela a palavra e sua frequencia
*/

const int N = 5*1e5+10;
const int K = 10+1;

struct no {
    pair<bool, int> fim;
    int prox[26];//posiçoes no alfabeto na tabela ASCII pode ser 'z' - 'A'+1 se quiser maiusculas e minusculas
    no(){//garantindo que os dados são inicialmente corretos
        fim.first = false;
        fim.second = 0;
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
        no = trie[no].prox[pos];
    }
    trie[no].fim.first = true;
    trie[no].fim.second++;
}

pair<string, int> buscaPalavraMaisFrequente(int u, string& s){
    if(u == 0){
        return {"",0};
    }
    string palavraMaisFrequente = s;
    int contador = trie[u].fim.second;

    rep(i,0,26){
        if(trie[u].prox[i] != 0){
            s.push_back('a'+i);
            pair<string, int> busca = buscaPalavraMaisFrequente(trie[u].prox[i], s);
            if(busca.second > contador || (busca.second == contador && busca.first < palavraMaisFrequente)){
                palavraMaisFrequente = busca.first;
                contador = busca.second;
            }
            s.pop_back();
        }
    }
    return make_pair(palavraMaisFrequente,contador);
}

void dfs(int u, string& s){
    if(trie[u].fim.first){
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
        int achado = 1;

        for(char c : t[i]){
            int pos = c-'a';

            if(trie[no].prox[pos] == 0){
                achado = 0;
                break;
            }

            no = trie[no].prox[pos];
        }
        if(!achado){// não tem o prefixo
            cout << "-1\n";
        } else{
            string prefixo = t[i];
            pair<string, int> achada = buscaPalavraMaisFrequente(no, prefixo);

            if(achada.second == 0){// não tem palavras com o prefixo
                cout << "-1\n";
            } else {
                cout << achada.first << " " << achada.second << "\n";
            }
        }
    }
    return 0;
}


