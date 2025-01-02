#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
char M[MAXN][MAXN];

#define HERE cout << "passou\n";

/**
Lista 9 - A : localize a palavra 'snuke' no caça-palavras e
printe as posições em sequencia dela na tela
**/

int check(int x, int y, int n, int m){
    return (x >= 0 && x <n && y >=0 && y <m);
}

vector<pair<int, int>> anda(int i, int j, int n, int m){
    int passo[2][8] = {{0,-1,-1,-1,0,1,1,1},{-1,-1,0,1,1,1,0,-1}};//<,^<,^,^>,>,>v,v,<v
    int x, y;
    char str[5] = {'s','n','u','k','e'};
    vector<pair<int , int>> resultado;

    for(int k = 0; k < 8; k++){
        x = i;
        y = j;

        for(int p = 0; p < 5; p++){
            if(!check(x,y,n,m) || M[x][y] != str[p]){
                break;
            }
            resultado.push_back(make_pair(x,y));
            x += passo[0][k];
            y += passo[1][k];
        }
        if(resultado.size() == 5){
            return resultado;
        } else {
            resultado.clear();
        }
    }
    return resultado;
}

void printPairs(vector<pair<int, int>> res){

    for(int i = 0; i < res.size(); i++){
        pair<int, int> atual = res[i];
        cout << atual.first+1 << " " << atual.second+1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<pair<int, int>> res;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            cin >> M[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            res = anda(i, j, n, m);
            if(res.size() != 0){
                printPairs(res);
            }
        }
    }
    return 0;
}

