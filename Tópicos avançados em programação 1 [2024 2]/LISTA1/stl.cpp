#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = 0; i<n; i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    v.front(); // valor do primeiro
    v.back(); // valor do ultimo
    v.size(); // tamanho

    v.push_back(1); // insere 1 no fim
    v.push_back(2); // insere 2 no fim: 1,2

    // pares

    typedef pair<int, int> pi;
    vector<pi> F;
    F[0].first;
    F[0].second;
    //posso fazer v[i] se eu conheço o tamanho

    // listas encadeadas
    list<int> L;
    L.front();
    L.back();
    L.size();

    L.push_front(); // insere no começo
    L.push_back(); // insere no fim
    L.pop_front(); // remove no começo
    L.pop_back(); // remove no fim

    L.begin(); // começo
    L.end(); // fim

    L.reverse(); // inverte
    L.sort(); // ordena em crescente
    L.unique(); // remove repetidos

    L.clear(); // destroi a lista

    // pilha
    stack<int> P;
    P.push();// insere antes de todas
    P.pop(); // remove a primeira de todas
    P.top(); // ve o primeiro elemento
    P.size(); //tamanho da pilha

    // iteradores, normal e reverso
    list<int>::iterator it;
    it = L.begin();

    list<int>::reverse_iterator rt;
    rt = L.end();
    // quando rt++, anda pra tras
    // funciona pra tudo

    // fila
    queue<int> Q;
    Q.push(); // adiciona no fim
    Q.pop(); // remove no começo

    // set
    // não repete elementos
    set<int> S;
    S.insert(0);// insere no set
    S.erase(0);// remove tudo no set

    return 0;
}
