#include <bits/stdc++.h>
using namespace std;
/*
typedef struct height {
    int altura;
    int indice;
    int total;
}height;*/

int main(){
    int n, m;
    cin >> n >> m;

    int alunos[n];
    pair <int, int> alturas[m];
    int totais[m];

    int i, j;
    for(i=0; i<n; i++){
        cin >> alunos[i];
    }
    for(i=0; i<m; i++){
        cin >> alturas[i].first;
        alturas[i].second = i;
    }
    sort(alunos, alunos+n);
    sort(alturas, alturas+m);

    int g;
    for(i=0; i<m; i++){
        g = 0;
        j = n;
        while(g<j){
            if(alunos[g] >= alturas[i].first){
                totais[alturas[i].second] = (j-g);
                cout << alunos[g] << ">" << alturas[i].second << endl;
                break;
            } else {
                g++;
            }
        }
    }
    for(i=0; i<m; i++){
        cout << totais[alturas[i].second] << endl;
    }
    return 0;
}
