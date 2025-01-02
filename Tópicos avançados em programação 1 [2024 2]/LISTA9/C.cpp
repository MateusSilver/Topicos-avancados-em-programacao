#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000+1;
char M[MAXN][MAXN];
queue<pair<int, int>> propagadores;
int rodadas = 0;

#define HERE cout << "passou\n";

/**
Lista 9 - C : descubra quantos segundos demora para uma matriz estar completamente
escura, ou seja, com todos os caracteres '#', sabendo que ela se propaga em cruz a cada segundo
**/

int check(int x, int y, int n, int m){
    return (x >= 0 && x <n && y >=0 && y <m);
}

void propagaSmoke(int n, int m){
    int passo[2][4] = {{-1,0,1,0},{0,1,0,-1}};//^,>,v,<
    int x, y;
    bool mudou = false;// a ultima propagação pode não gerar resultado
    int tamFila = propagadores.size();

    for(int p = 0; p < tamFila; p++){// só propagadores da ultima camada
        pair<int, int> propagador = propagadores.front();
        propagadores.pop();
        // front << << << <<

        for(int k = 0; k < 4; k++){// analisa quatro cantos
            x = propagador.first + passo[0][k];
            y = propagador.second + passo[1][k];

            if(check(x,y,n,m) && M[x][y] == '.'){// propaga e adiciona o propagador novo
                M[x][y] = '#';
                propagadores.push(make_pair(x,y));
                mudou = true;
            }
        }
    }
    if(mudou){
        rodadas++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            cin >> M[i][j];
            if(M[i][j] == '#'){
                propagadores.push(make_pair(i,j));
            }
        }
    }
    while(!propagadores.empty()){
        propagaSmoke(n,m);
    }
    cout << rodadas;

    return 0;
}



