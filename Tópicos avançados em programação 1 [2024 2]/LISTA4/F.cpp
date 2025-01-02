#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;
int rep[MAXN];
int qtd[MAXN];
unordered_map<string, int> name_to_id;
int id_counter = 0;

void set_(int x){
    rep[x] = x;
    qtd[x] = 1;
}

int find_(int x){
    if(rep[x] == x) return x;
    else return rep[x] = find_(rep[x]);// todos apontam pro representante
}

void unite_(int a, int b){
    // pega representante a e une com representante b
    a = find_(a);
    b = find_(b);
    if(a == b) return;
    if(qtd[b] < qtd[a]) swap(a,b);
    rep[a] = b;
    qtd[b] += qtd[a];
}

int get_id(string name){// usando unordered map pra criar strings com id para union find
    if(name_to_id.find(name) == name_to_id.end()){
        name_to_id[name] = id_counter;
        set_(id_counter);
        id_counter++;
    }
    return name_to_id[name];
}

int main(){
    //dsu ou union/find;
    //problema D
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    scanf("%d", &q);

    while(q--){
        name_to_id.clear();
        id_counter = 0;
        scanf("%d", &n);
        int id1, id2;
        while(n--){
            char a[21], b[21];
            scanf("%s %s", a ,b);

            id1 = get_id(a);
            id2 = get_id(b);

            unite_(id1,id2);
            printf("%d\n", qtd[find_(id1)]);
        }

    }
    return 0;
}
