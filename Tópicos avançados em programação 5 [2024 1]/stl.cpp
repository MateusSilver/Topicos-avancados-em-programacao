#include <bits/stdc++.h>
using namespace std;

set<int> val;
val.insert(2);
val.erase(3);
val.find(3);
if(val.find(3) != val.end()){
    cout << "3 está na arvore";
}
val.size();
for(int x:val){// andando em todos os elementos, tudo é balanceado
// o menor é o begin
int data = *val.begin();//val.begin() é um ponteiro
}
set<double> val2;
set<vector<int>> val3;
set<set<int>> val4;

//inserindo dados repetidos:
multiset<int> n;
n.insert(1);
n.insert(1);
for(int x:n){
    cout << x << "\n";
}
// o erase deleta todos os iguais no multiset
// para deletar um 1 apenas
n.erase(n.find(1));

// exlucluir o menor cara
n.erase(n.begin());

// map
// também tem arvore por tras, porem tem coisa diferente,
map<chave, valor> dt;
map<int, string> dt;
// é um vetor dinamico, na posição 2 tem um "abacaxi" e na 3 tem "frango frito"
// usamos
dt[2] = "abacaxi";
dt[100000] = "frango frito";
// voce pode
map<vector<int>, int> dm;
dm[{1,2,3}] = 3;
//usamos as funções de vector neste também
vector<int> x;
x.push_back(3);
dm[x] = "frango frito";

x.first
x.second

// heap
// priority_queue

priority_queue<int> pq;
pq.push(1);
pq.push(2);
pq.push(300);

pq.pop();
pq.top();
// assim como o set, está sempre ordenado.
// para consultar a menor ainda é mais rapido que set
